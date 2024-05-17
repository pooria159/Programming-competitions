def sumPairs(arr, n):
     
    sum = 0
    for i in range(n - 1, -1, -1):
        sum += i*arr[i] - (n-1-i) * arr[i]
    return sum


num_of_test = int(input())

for _ in range(num_of_test):
    n , x = map(int,input().split())
    
    s=0
    m=[]
    for i in range(n):
        m.append(list(map(int,input().split())))
    l=[]
    for i in range(x):
        l.append([])
    for i in m:
        for j in range(len(i)):
            l[j].append(i[j])
    for i in l:
        s += sumPairs(sorted(i),len(i))
    print(s)