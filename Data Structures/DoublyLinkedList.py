class Node: 
 
    def __init__(self, data): 
        self.data = data 
        self.next = None
        self.prev = None
  
 
class DoublyLinkedList: 
  
    def __init__(self): 
        self.head = None
  
    def pushfirst(self,new_data):#to add a new node in the beginning of the list 
        new_node = Node(new_data)
        new_node.next = self.head
        
        if self.head is not None: 
                self.head.prev = new_node 
                
        self.head = new_node    
 

    def pushafter(self,prev_node,new_node):
        if prev_node is None :
            print "The given previous node cannot be None"
            return     
        
        prev_node.next = new_node
        new_node.next = prev_node.next
        new_node.prev = prev_node
        
        if new_node.next is not None:
            new_node.next.prev = new_node
        
 
    
    def pushlast(self,new_data):
        new_node = Node(new_data)
        
        if self.head is None:
            new_node.prev = None
            self.head = new_node
            return 

        last = self.head
        while(last.next is not None):
            last = self.next
            
        last.next = new_node
        new_node.prev = last
        
    llist = DoublyLinkedList() 
  
llist.pushlast(6) 
  

llist.pushfirst(7) 
  

llist.pushfirst(1) 
  

llist.pushlast(4) 
  
llist.pushafter(llist.head.next, 8) 
