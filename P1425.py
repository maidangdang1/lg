a, b, c, d = input().split()
a = int(a)
b = int(b)
c = int(c)
d = int(d)
ans = c * 60 + d - (a * 60 + b)
hour = int(ans / 60)
minute = ans % 60
print(hour, minute)
