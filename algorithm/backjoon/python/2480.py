import sys
nput=sys.stdin.readline
a=list(map(int,input().split()))

if a[0] == a[1] == a[2]:
    print(10000 + a[0] * 1000)
elif a[0] == a[1]:
    print(1000 + a[0] * 100)
elif a[0] == a[2]:
    print(1000 + a[0] * 100)
elif a[1] == a[2]:
    print(1000 + a[1] * 100)
else:
    a.sort()
    print(a[2]*100)
    
    