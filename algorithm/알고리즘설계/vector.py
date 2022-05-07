import time #시간 측정을 위함
import random #random값을 이용하기 위함

def fibo(n):
    if n == 0: return 0
    if n == 1: return 1
    return (fibo(n-1) + fibo(n-2)) #재귀 함수 호출

n = [10, 50, 100, 150, 200] #n값을 미리 넣어둠

for num in n: #num 값에 따라 n x n 으로 맞춰서 초기화함
    arr1 = [[0]*num ]*num
    arr2 = [[0]*num ]*num
    arr3 = [[0]*num ]*num
    arr4 = [[0]*num ]*num

    
    for i in range(num):
        for j in range(num): 
            arr1[i][j] = (int(random.randrange(100)))#random값을 0부터 100까지 숫자 중 정수로 넣음
            arr2[i][j] = (int(random.randrange(100)))#random값을 0부터 100까지 숫자 중 정수로 넣음
            arr3[i][j] = (int(random.randrange(100)))#random값을 0부터 100까지 숫자 중 정수로 넣음


    #Cubic complexity
    start = time.time() #시작
    for i in range(num):
        for j in range(num):
            for k in range(num):
                arr4[k] = arr1[i][j] * arr2[i][j] * arr3[i][j]  #곱
    end = time.time() #끝

    print(f"Cubic complexity time (n = {num})= {end - start:.5f} sec") #끝에서 시작을 빼서 시간을 확인함


l = [10,20,30]
for i in l:
    start = time.time() #시작
    fibo(i) #피보나치 실행
    end = time.time() #끝
    print(f"Exponential complexity (n = {i}) = {end - start:.5f} sec")
   




