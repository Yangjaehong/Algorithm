n = int(input())

sol = 0

if n == 1:
    sol = 10

else:
    for j in range (n):
        for i in range (0,10):
            for k in range (i,10-i):
                sol += 1

print(sol)



    