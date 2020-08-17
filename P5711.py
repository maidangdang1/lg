x = int(input())
if x % 100 == 0:
    if x % 400 == 0:
        print(1)
    else:
        print(0)
else:
    if x % 4 == 0:
        print(1)
    else:
        print(0)