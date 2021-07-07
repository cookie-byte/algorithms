class Node():
    def __init__(self, value):
        self.data = value
        self.next = None

class Linkedlist():
    def __init__(self):
        self.head = None

    def insert_end(self,value):
        node = Node(value)
        if(self.head==None):
            self.head = node
        else:
            cur = self.head
            while(cur.next):
                cur = cur.next
            cur.next = node

    def insert_head(self,value):
        node = Node(value)
        if(self.head==None):
            self.head = node
        else:
            node.next = self.head
            self.head = node

    def insert_pos(self,value,position):
        length = self.length()
        if (position > length or position < 1):
            print(str(position)+' position does not exist')
            return
        else:
            node = Node(value)
            if(self.head==None):
                self.head = node
            else:
                i=0
                cur = self.head
                while(i<position-2):
                    cur = cur.next
                    i+=1
                node.next = cur.next
                cur.next = node

    def delete_end(self):
        if(self.head==None):
            return
        else:
            cur = self.head
            while(cur.next.next):
                cur = cur.next
            cur.next = None

    def delete_head(self):
        if(self.head==None):
            return
        else:
            self.head = self.head.next

    def delete_val(self,value):
        if(self.head==None):
            return
        elif(self.head.data == value):
            self.head = self.head.next
        else:
            pre = self.head
            cur = self.head.next
            while(cur):
                if(cur.data==value):
                    pre.next = cur.next
                    break
                else:
                    pre = cur
                    cur = cur.next
            if(cur == None):
                print('Element not found')

    def delete_pos(self,position):
        length = self.length()
        if (position > length or position < 1):
            print(str(position)+' position does not exist')
            return
        else:
            if(self.head==None):
                return
            else:
                i=0
                cur = self.head
                while(i<position-2):
                    cur = cur.next
                    i+=1
                cur.next = cur.next.next

    def traverse(self):
        if self.head == None:
            return None
        cur = self.head
        print('Elements are :', end=' ')
        while(cur):
            print(cur.data,end=' ')
            cur = cur.next
        print()

    def length(self):
        if self.head == None:
            return 0
        cur = self.head
        i = 0
        while(cur):
            i +=1
            cur = cur.next
        return i

lis = Linkedlist()
lis.insert_head(1)
lis.insert_head(1)
lis.insert_head(2)
lis.insert_head(2)
lis.insert_head(2)
lis.insert_head(3)
lis.insert_head(3)
lis.insert_pos(7,7)
lis.insert_pos(9,7)
lis.insert_pos(8,7)
lis.insert_end(4)
print('Length of list is : '+ str(lis.length()))
lis.traverse()
d='Y'
while(True):
    d = input('Do you want to delete (Y/N) \n')
    if d=='Y' or d=='y':
        lis.delete_val(5)
        lis.traverse()
    else:
        break


