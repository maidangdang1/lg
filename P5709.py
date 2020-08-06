m, t, s = map(int, input().split())
while s > 0:
    if t == 0:
        m = 0
        break
    s -= t
    m -=1
if m < 0:
    m = 0
print(m)