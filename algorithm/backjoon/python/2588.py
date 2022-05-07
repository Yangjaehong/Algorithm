num1 = int(input())
num2 = input()
print(num2[2])
print(num2[1])
print(num2[0])

for i in range(len(num2), 0, -1):
    print(num1 * int(num2[i-1]))

print(num1 * int(num2))