import math

inp = input().split(' ')
n = int(inp[0])
k = int(inp[1])
mod = 1000000007
res = (math.factorial(n))/(math.factorial(k)*math.factorial(n-k))
print(res)
print(res%mod)