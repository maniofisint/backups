
def RB_Insert_Fixup(T,z):
    while z.p.color == 'RED':
        if z.parent is z.parent.parent.left:
            y = z.parent.parent.right
            if y.color == 'RED':
                z.parent.color = 'BLACK'
                y.color = 'BLACK'
                z.parent.parent.color = 'RED'
                z = z.parent.parent
            elif z is z.parent.right:
                z = z.parent
                Left_rotate(T, z)
            else:
                z.parent.color = 'BLACK'
                z.parent.parent.color = 'RED'
                Right_rotate(T, z.parent.parent)
        else:
            y = z.parent.parent.left
            if y.color == 'RED':
                z.parent.color = 'BLACK'
                y.color = 'BLACK'
                z.parent.parent.color = 'RED'
                z = z.parent.parent
            elif z is z.parent.left:
                z = z.parent
                Right_rotate(T, z)
            else:
                z.parent.color = 'BLACK'
                z.parent.parent.color = 'RED'
                Left_rotate(T, z.parent.parent)

def Right_rotate(T,z):
    pass

def Left_rotate(T, z):
    pass