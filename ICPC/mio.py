t = int(input())
ans = list()

for i in range(t):
    q = int(input())
    x = list(map(int, input().split()))
    l = []
    bits = ''
    fbi = False
    for el in x:
        if len(l) == 0 or len(l) == 1:
            l.append(el)
            bits += '1'
            continue
        if el >= l[-1] and l[-1] >= l[-2]:
            if not fbi:
                l.append(el)
                bits += '1'
            else:
                if el <= l[0]:
                    l.append(el)
                    bits += '1'
                else:
                    bits += '0'
            continue
        if el < l[-1] and l[-1] >= l[-2]:
            if fbi:
                bits += '0'
            else:
                if el <= l[0]:
                    l.append(el)
                    bits += '1'
                    fbi = True
                else:
                    bits += '0'
            continue
        if el >= l[-1] and l[-1] < l[-2]:
            if el <= l[0]:
                l.append(el)
                bits += '1'
                fbi = True
            else:
                bits += '0'
            continue
        if el < l[-1] and l[-1] < l[-2]:
            bits += '0'
            continue
        bits += '0'
    
    ans.append(bits)

for a in ans:
    print(a)
            

