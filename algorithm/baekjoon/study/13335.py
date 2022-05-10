n, w, l = map(int, input().split())
trucks = list(map(int, input().split()))
 
b = [0] * w  
weight, t = 0, 0    
 
while b:
    out = b.pop(0)
    weight -= out
 
    if trucks:
        if weight + trucks[0] <= l:
            b.append(trucks[0])
            weight += trucks[0] 
            trucks.pop(0)  
        else: 
            b.append(0) 
    t += 1 
  
print(t)