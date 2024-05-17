def check(v, adj):
    neighbors = set(adj[v])
    for u in adj[v]:
        cnt = 0
        for w in adj[u]:
            if w in neighbors:
                cnt += 1
        if cnt >= 2:
            return True
    return False

n, m = map(int, input().split())
adj = [[] for _ in range(n + 1)]
for i in range(m):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)
for i in range(1, n + 1):
    if len(adj[i]) >= 3 and check(i, adj):
        print("YES")
        break
else:
    print("NO")