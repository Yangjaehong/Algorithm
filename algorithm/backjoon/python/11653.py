s = int(input())
n = 0
result = 0
for i in range(1,s+1):
    result += i
    n += 1
    if result > s:
        n -=1
        break
print(n)