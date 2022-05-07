def initSkip(p):
    NUM = 95  # 검색가능한 문자의 총 개수
    M = len(p) # 패턴의 길이
    skip = [M for i in range(NUM)] #skip 함수를 모두 M값으로 초기화
    for i in range(M):
        skip[ord(p[i]) - ord(' ')] = M - i - 1  #제일 낮은 아스키코드 값을 가지는 SPACE 즉 공백을 빼서 각각의 배열 위치를 정함
    return skip # skip 배열 반환

def BoyerMoore(p, t): #보이어 무어 알고리즘
    M = len(p) #패턴의 길이
    N = len(t) #텍스트 한줄의 길이
    skip = initSkip(p) #skip배열을 만들기 위함

    i = M-1
    j = M-1

    while j >= 0: 
        while t[i] != p[j]:
            k = skip[ord(t[i]) - ord(' ')] #제일 낮은 아스키코드 값을 가지는 space 즉 공백을 빼서 각각의 배열의 위치를 찾을 수 있음 
            if M - j > k: #m-j > k일 경우 아래와 같은 연산 진행하여 i의 값을 바꿈
                i = i + M - j
            else: #아닐경우 i의 값에 k만큼 더함
                i = i + k
            if i >= N: #i가 n보다 같거나 크면 텍스트의 길이를 return
                return N
            j = M - 1
        i = i-1
        j = j-1
    return i+1 #문자열을 찾은 위치를 return 
    
p = input("Enter the pattern you want to find(12171802 양재홍) :") #찾는 문자를 입력
f = open('./RFC2616_modified.txt', 'r') #file open
line_num = 0 #라인별로 읽어오면서 line의 위치를 알기위해서 선언한 변수
line = f.read().splitlines() #read해서 line별로 잘라서 넣음
cnt = 0 #찾은 문자가 몇개인가 확인하기 위한 변수
for i in line:
    if len(i) > 2 and len(p) <= len(i) - 2: #2보다 큰것만 넣는 이유는 \n이 들어오기 때문임
        line_num += 1 #몇번째 줄인지 카운트 하는 변수
        j = 0 #앞부분의 길이를 저장해 놓기 위함
        m = len(i) #line당 문자의 길이를 m으로
        while True:
            k = BoyerMoore(p,i) #return 되는 위치를 k에 저장
            if len(i) == k: #리턴 위치가 마지막이면 break
                break
            else:
                print(f"find '{p}' (row,column) : ({line_num}, {k+j}) ") #line number와 return된 위치 출력
                cnt += 1 # 검색이 몇번 되었는지 확인하기 위함 0이면 검색실패 메시지
                if m-k > 2 and len(p) <= m-k-2:
                    j += (k+len(p)) #전의 길이를 저장해놓기 위함
                    i = i[k+len(p):] #문자열을 k즉 결과가 나온 부분 부터 끝까지해서 다시 만들어줌
                    m -= (k+len(p)) #전체 크기 또한 k를 뺀 값으로 바꿔줌
                else: break
    else: 
        line_num += 1 #검색이 안되었을 때 LINE 번호만 늘림

if cnt == 0 : print (f"'{p}'is not found") #패턴을 한나도 못찾으면 찾지 못했다고 출력
else : print (f"total number of '{p}': {cnt}") #패턴이 하나라도 나오면 그 패턴이 몇개 있는지 출력
f.close() #파일 colse
