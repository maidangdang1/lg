a, b, c = map(float, input().split())
p = (a + b + c) / 2
s = (p * (p - a) * (p - b) * (p - c)) ** 0.5
print('%.1f' %s)