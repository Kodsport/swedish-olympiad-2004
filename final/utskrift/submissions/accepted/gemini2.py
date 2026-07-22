import sys
n = int(input())
k = int(input())
w = [input().strip() for _ in range(k)]
dp = [float('inf')] * (k + 1)
p = [-1] * (k + 1)
dp[k] = 0
for i in range(k - 1, -1, -1):
    c = 0
    for j in range(i, k):
        c += len(w[j])
        l = c + (j - i)
        d = abs(n - l)
        v = max(d, dp[j + 1])
        if v <= dp[i]:
            dp[i] = v
            p[i] = j + 1
curr = 0
while curr < k:
    nxt = p[curr]
    print(*(w[curr:nxt]))
    curr = nxt

