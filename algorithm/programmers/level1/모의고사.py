def solution(answers):
    answer = []
    
    one = [1,2,3,4,5]
    two = [2,1,2,3,2,4,2,5]
    three = [3,3,1,1,2,2,4,4,5,5]
    o, t, th = 0, 0 ,0
    
    i,q,w,e = 0,0,0,0
    
    while True:
        if answers[i] == one[q]:
            o += 1
        if answers[i] == two[w]:
            t += 1
        if answers[i] == three[e]:
            th += 1
        
        i+=1
        q+=1
        w+=1
        e+=1
        
        if q == len(one): 
            q = 0
        if w == len(two): 
            w = 0
        if e == len(three): 
            e = 0
        if i == len(answers): 
            break
        
    
    j = max(o,t,th)
    print(o,t,th)
    if o == j:
        answer.append(1)
        
    if t == j:
        answer.append(2)
        
    if th == j:
        answer.append(3)
        
    return answer