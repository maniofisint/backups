class lisp:

    class Node:
        def __init__(self, char, next, updown):
            self.char = char
            self.next = next
            self.updown = updown
            self.is_threat = False

    def __init__(self, string):
        self.header = self._creat_list(string, None)

    def _creat_list(self, string , updown):
        head = self.Node(None, None, updown)
        threat = self.Node(None, head, None)
        threat.is_threat = True
        head.next = threat

        for i in range(1, len(string)-1):
            if string[i] == '(':
                newString = str()
                newString += '('
                Pcount = 1
                while Pcount > 0:
                    i += 1
                    if string[i] == '(':
                        Pcount += 1
                    elif string[i] == ')':
                        Pcount -= 1
                    newString += string[i]

                newNode = self.Node (None, None, None)
                newList = self._creat_list(newString, newNode)
                newNode.updown = newList
                self.insert_last(head, newNode)

            else:
                newNode = self.Node(string[i], None, None)
                self.insert_last(head, newNode)

        return head

    def insert_last(self, head, q):
        p = head
        while not p.next.is_threat:
            p = p.next
        hold = p.next
        p.next = q
        q.next = hold
    
    def print_list(self):
        print('(', end='')
        p = self.header.next

        while p is not self.header :
            
            if p.char is not None:              #on a character
                print(p.char, end='')
                p = p.next

            else:
                if p.updown is not None:       #should go down
                    p = p.updown
                else:
                    if p.is_threat:             #should go up
                        print(')', end='')            
                        p = p.next.updown.next if p.next is not self.header else p.next
                    else:                      #p is a header
                        print('(', end='')
                        p = p.next
        
        print(')')



