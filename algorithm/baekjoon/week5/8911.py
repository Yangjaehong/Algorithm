j = int(input())
cnt = 0

while True:
    cnt += 1
    n = 0
    xx, yy = [], []

    graph = list(input())
    x, y = 0, 0
    xx.append(0)
    yy.append(0)

    for i in graph:
        if i == 'L':
            n += 1
        elif i == 'R':
            if n == 0:
                n = 3
            else:
                n -= 1
        elif i == 'F':
            if n % 4 == 0:
                y = y + 1
                yy.append(y)
            elif n % 4 == 1:
                x = x - 1
                xx.append(x)
            elif n % 4 == 2:
                y = y - 1
                yy.append(y)
            elif n % 4 == 3:
                x = x + 1
                xx.append(x)
        elif i == 'B':
            if n % 4 == 0:
                y = y - 1
                yy.append(y)
            elif n % 4 == 1:
                x = x + 1
                xx.append(x)
            elif n % 4 == 2:
                y = y + 1
                yy.append(y)
            elif n % 4 == 3:
                x = x - 1
                xx.append(x)

    if min(xx) == max(xx):
        gx = abs(max(xx))
    if min(yy) == max(yy):
        gy = abs(max(yy))
    if min(xx) == 0:
        gx = abs(max(xx))
    if min(yy) == 0:
        gy = abs(max(yy))
    if min(xx) == 0 and max(xx) == 0:
        gx = 0
    if min(yy) == 0 and max(yy) == 0:
        gy = 0

    gx = abs(max(xx)) - abs(min(xx))
    gy = abs(max(yy)) - abs(min(yy))

    print(abs(gx * gy))

    if j == cnt:
        break