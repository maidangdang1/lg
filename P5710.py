x = int(input())
if x % 2 == 0:
    flag1 = 1
else:
    flag1 = 0
if x > 4 and x <= 12:
    flag2 = 1
else:
    flag2 = 0
if flag1 + flag2 == 2:
    A = 1
else:
    A = 0
if flag1 + flag2 >= 1:
    Uim = 1
else:
    Uim = 0
if flag1 + flag2 == 1:
    eight = 1
else:
    eight = 0
if flag1 + flag2 == 0:
    girl = 1
else:
    girl = 0
print(A, Uim, eight, girl)