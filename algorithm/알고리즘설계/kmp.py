next = [0] * 1000
        
def InitNext(p) : 
    m = len(p)
    next[0], j = -1, -1 #next[0]을 -1 j를 -1로 지정
    for i in range(m):
        next[i] = j
        while j >= 0 and p[i] != p[j]:
            j = next[j]
        j += 1
    
def KMP(p, t) : 
    m, n = len(p), len(t) #크기를 저장해주는 변수
    i, j = 0, 0
    InitNext(p) #함수 호출
    while j < m and i < n:
        while j >= 0 and t[i] != p[j]:
            j = next[j] #while조건에 따라 j에 next[j]의 값을 넣는다.
        i += 1
        j += 1
    if j == m:
        return i - m
    else:
        return i


#t = 'ababababcababababcaabbabababcaab'
#p = 'abababca'
t = 'This class is an algorithm design class. Therefore, students will have time to learn about algorithms and implement each algorithm themselves.'
p = 'algorithm'
    
i,k = 0,0
while True: #while문을 사용하여 패턴이 발생한 위치를 모두 출력한다.
    pos = KMP(p, t[i:]) #p와 t의 i번째부터 끝까지를 계속 kmp함수에 인자로 사용한다
    pos += k 
    i = pos + len(p) #pos에서 패턴의 길이만큼 더한다

    if i >= len(t): #i가 t의 길이보다 같거나 크면 종료
        break
    else:
        print(f'패턴이 발생한 위치: {pos}') #패턴 발생 위치 출력
    k = i
print('탐색 종료')