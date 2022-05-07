from itertools import permutations


n = int(input())
a = list(map(int, input().split())) #숫자
k = list(map(int, input().split())) 

list(permutations(a, n))
print(a)
for j in range(len(a)):
    max = a[j]
    for i in range(len(a)):
        if k[0] > 0:
            max += a[i]
            k[0] -= 1
        elif k[1] > 0:
            max -= a[i]
            k[1] -= 1
        elif k[2] > 0:
            max *= a[i]
            k[2] -= 1
        elif k[3] > 0:
            max /= a[i]
            k[3] -= 1

    
        


