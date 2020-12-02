class polynomial:

    class Node:
        def __init__(self,exp=None, variable=None, coefficient=None, char=None, next=None, updown=None, is_thread=False):
            self.exp = exp
            self.variable = variable
            self.coefficient = coefficient
            self.next = next
            self.updown = updown
            self.is_thread = is_thread

    def __init__(self, string):
        self.header = self._creat_list(string, None)

    def convert(self, string , updown):
        lis = self.separate(string)

        thread = self.Node(is_thread = True)
        
        for i in range(len(lis)):
            if self.is_number(lis[i][0]):
                lis[i] = self.Node(coefficient=float(lis[i][0], variable=lis[i][1], exp=lis[i][2]))
            else:
                lis[i] = self.Node(coefficient=self.convert(lis[i][0]), variable=lis[i][1], exp=lis[i][2])

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

    def separate(self, string):
        def separate_by_plus(string: str):
            lis = []
            hold = str()
            paren_counter = 0

            for i in string:
                if i == '(': paren_counter += 1
                elif i == ')': paren_counter -= 1
                elif i == '+':
                    if paren_counter == 0:
                        lis.append(hold)
                        hold = str()
                        continue

                hold += i
            lis.append(hold)
            return lis

        lis = separate_by_plus(string)

        hold = str()
        for i in range(len(lis)):
            ind = len(lis[i]) - 1 
            while ind >= 0 and lis[i][ind] != ')':
                hold = lis[i][ind] + hold
                ind -= 1
            lis[i] = [lis[i][:ind+1], hold]
            hold = str()

        var = lis[-1][1][0]

        for i in range(len(lis)):
            if len(lis[i][1]) == 0:
                lis[i] = [lis[i][0][1:-1], var, 0]
            elif len(lis[i][1]) == 1:
                lis[i] = [lis[i][0][1:-1], var, 1]
            else:
                lis[i] = [lis[i][0][1:-1], var, int(lis[i][1][2:])]

        return lis



