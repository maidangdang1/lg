n = input()
n = int(n)
# temp = 0
a = input().split()
for i in range(n):
    a[i] = int(a[i])
    # temp += a[i]
q = input()
q = int(q)
for i in range(q):
    m = input()
    m = int(m)
    while m >= 0:
        s = 0
        for j in range(n):
            s += a[j] ^ m
        if s <= m:
            print(m)
            break
        m -= 1
    if s > m:
        print(-1)