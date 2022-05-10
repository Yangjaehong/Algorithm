sol = []
while True:
    a,b = map(int, input().split())
    if a > b : sol.append('Yes')
    elif(a == 0 and b == 0): 
        print(sol)
        for i in sol:
            print(i)
        break
    else: sol.append('No')


    
