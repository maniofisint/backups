def postfix(inf, pre):
    if len(inf) == 0:
        return []
    root, inf_left, inf_right, pre_left, pre_right = seprate(inf, pre)
    right = postfix(inf_right, pre_right)
    left = postfix(inf_left, pre_left)
    out = left + right
    out.append(root)
    return out

def seprate(inf, pre):
    if len(inf) == 1:
        return inf[0], [], [], [], []
    
    root = pre[0]
    i = 0
    while inf[i] != root:
        i += 1

    inf_left = inf[:i]
    inf_right = inf[i+1:]
    pre_left = pre[1:i+1]
    pre_right = pre[i+1:]

    return root, inf_left, inf_right, pre_left, pre_right

def prnt(lis):
    for i in lis:
        print(i, end=' ')


n = int(input())
infix = list(map(int, input().split()))
prefix = list(map(int, input().split()))
Postfix = postfix(infix, prefix)
prnt(Postfix)

