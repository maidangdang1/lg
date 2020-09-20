b, p, k = map(int, input().split())
print(b, '^', p, " mod ", k, '=', sep = '', end = '')
s = 1
while p > 0:
    if p % 2 == 1:
        s = s * b % k
    b = b * b % k
    p = p >> 1
s %= k
print(s)
# print(b, '^', p, " mod ", k, '=', s, sep = '')
