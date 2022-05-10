t = int(input())
for i in range(t):
    num, s = input().split()
    text = ''
    for i in s:
        print(i)
        text += int(num) * i
    print(text)