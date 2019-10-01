class Node():
    def __init__(self, value):
        self.data = value
        self.next = None
        self.prev = None

class Linkedlist():
    def __init__(self):
        self.head = None
        self.tail = None

    def insert_end(self,value):
        node = Node(value)
        if(self.head==None):
            self.head = node
            self.tail = node
        else:
            cur = self.head
            while(cur.next):
                cur = cur.next
            cur.next = node
            self.tail = node
            node.prev = cur

    def insert_head(self,value):
        node = Node(value)
        if(self.head==None):
            self.head = node
            self.tail = node
        else:
            node.next = self.head
            self.head.prev = node
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
                self.tail = node
            else:
                i=0
                cur = self.head
                while(i<position-2):
                    cur = cur.next
                    i+=1
                node.next = cur.next
                node.prev = cur
                cur.next.prev = node
                cur.next = node

    def delete_end(self):
        if(self.head==None):
            return
        else:
            cur = self.tail
            cur.prev.next = None
            self.tail = cur.prev

    def delete_head(self):
        if(self.head==None):
            return
        else:
            self.head = self.head.next
            self.head.prev=None

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
                    if pre.next:
                        cur.next.prev = pre
                    else:
                        self.tail = pre
                    cur.next = cur.prev = None
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
                if(cur.next):
                    cur.next.prev = cur
                else:
                    self.tail = cur

    def traverse(self):
        if self.head == None:
            return None
        cur = self.head
        print('Elements are :', end=' ')
        while(cur):
            print(cur.data,end=' ')
            cur = cur.next
        print()

    def revtraverse(self):
        if self.head == None:
            return None
        cur = self.tail
        print('Elements are :', end=' ')
        while(cur):
            print(cur.data, end=' ')
            cur = cur.prev
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
lis.revtraverse()
lis.delete_end()
print('Length of list is : '+ str(lis.length()))
lis.traverse()
lis.revtraverse()
lis.delete_head()
print('Length of list is : '+ str(lis.length()))
lis.traverse()
lis.revtraverse()
lis.delete_val(2)
print('Length of list is : '+ str(lis.length()))
lis.traverse()
lis.revtraverse()
lis.delete_pos(8)
print('Length of list is : '+ str(lis.length()))
lis.traverse()
lis.revtraverse()

