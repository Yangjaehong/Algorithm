a = int(input())
answer = 0

for i in range (a//5,-1,-1):
    if (a - 5 * i) % 3 == 0:
        answer = i + (a - 5 * i) // 3
        break

if answer == 0:
    answer = -1
print (answer)