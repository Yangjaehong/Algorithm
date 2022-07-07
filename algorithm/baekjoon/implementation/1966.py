a = []
b = []
index = int(input())
num = 0
while True:
    target = 0
    if index == num:
        break
    
    n, m = map(int, input().split()) #n = 문서 개수, m = 찾을 문서
    a = list(map(int, input().split()))
    b = list(map(int, range(n))) #기존의 위치정보
    
    
    target = a[m]
    target_index = b[m]
    i = 0
    cnt = 0
    while True:
        temp = 0
        if a.index(max(a)) == 0:
            cnt += 1
            if a[0] == target and b[0] == target_index:
                break
            a.pop(0)
            b.pop(0)
            
        else:
            temp = a[0]
            a.pop(0)
            a.append(temp)
            temp = b[0]
            b.pop(0)
            b.append(temp)
        
    print(cnt)
    num += 1
