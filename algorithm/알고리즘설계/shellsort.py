import random
import time

def Checksort(a, n): # 정렬 체크 함수
    sorted = True
    for i in range(1, n):
        if a[i - 1] > a[i] :
            sorted = False
        if not sorted :
            break
    if(sorted):
        print("정렬 완료")
    else :
        print("정렬 오류!")

def Shellsort(l) :
    n = len(l) #list 크기
    h = 1
    while h < n : # 첫번째 h 계산
        h = 3 * h # 증가식

    while h > 0 : # 부분 배열의 삽입정렬 실행
        for i in range(h, n) :
            temp = l[i]
            j = i - h
            while j >= 0 and l[j] > temp : # 삽입정렬
                l[j + h] = l[j]
                j -= h # 1gap 씩 줄여가며 비교
            l[j + h] = temp
        h //= 3 # 감소식

n = [100000, 500000, 1000000, 5000000, 10000000] # 입력

for i in n:
    x = []
    x = random.sample(range(i), i) #n까지 n개의 난수 생성

    start = time.time() #시간측정
    Shellsort(x)
    end = time.time() #시간측정

    print(f'증가식 : 3h, 감소식 : h/3 쉘 정렬 실행 시간 (N = {i}): {end - start}초')
    Checksort(x, i)