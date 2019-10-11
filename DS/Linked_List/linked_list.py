class LinkedList:
    """Defines a Singly Linked List.
    attributes: head
    """

    def __init__(self):
        """Create a new list with a Sentinel Node"""
        self.head=ListNode()


    def insert(self,x,p):
        """Insert element x in the position after p"""
        temp=ListNode()
        temp.data=x
        temp.next=p.next
        p.next=temp


    def delete(self,p):
        """Delete the node following node p in the linked list."""
        if self.head is None:
            return
        temp=self.head
        if p==self.head:
            self.head=temp.next
            temp=None
            return
        while(p):
            temp=temp.next
            p=p.next
            if temp is None:
                return
        if temp is None:
            return
        if temp.next is None:
            return
        next=temp.next.next
        temp.next=next
        temp=None


    def printlist(self):
        """ Print all the elements of a list in a row."""
        temp=self.head
        while(temp):
            print(temp.data,)
            temp=temp.next


    def insertAtIndex(self, x, position):
        start = self.head
        if position == 0:
            return ListNode(x, self.head)
        while position > 1:
            self.head = self.head.next
            position -= 1
        self.head.next = ListNode(x, self.head.next)
        return start


    def search(self,x):
        """Search for value x in the list. Return a reference to the first node with value x; return None if no such node is found."""
        temp=self.head
        while(temp):
            if(temp.data==x):
                return temp
            else:
                temp=temp.next



    def len(self):
        """Return the length (the number of elements) in the Linked List."""
        count=0
        temp=self.head
        while(temp is not None):
            count+=1
            temp=temp.next
        return count


    def isEmpty(self):
        """Return True if the Linked List has no elements, False otherwise."""
        temp=self.head
        if(temp is None):
            return True
        else:
            return False



class ListNode:
    """Represents a node of a Singly Linked List.
    attributes: value, next.
    """
    def __init__(self,val=None,nxt=None):
        self.data=val
        self.next=nxt
#def main():
L = LinkedList()
L.insert(10,L.head)
print('List is: ',L.printlist())
L.insert(12,L.head.next)
print('List is: ',L.printlist())
L.insert(2,L.head)
print('List is: ',L.printlist())
print('Size of L is ',L.len())
L.delete(L.head)
print('List is: ',L.printlist())
L.delete(L.head.next)
print('List is: ',L.printlist())
print('List is empty?',L.isEmpty())
print('Size of L is ',L.len())
L.delete(L.head)
print('List is empty?',L.isEmpty())
print('Size of L is ',L.len())
L.insertAtIndex(2,0)
L.insertAtIndex(1,0)
L.insertAtIndex(4,2)
L.insertAtIndex(3,2)
print('List is: ',L.printlist())
