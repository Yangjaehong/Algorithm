answer = input().split('-') #- 를 기준으로 읿력을 받음
sol = 0

for i in answer[0].split('+'):  # - 기준으로 앞쪽의 것들을 다시 +로 쪼갬
    sol += int(i)

for i in answer[1:]: #1 리스트 부터 마지막 까지
    for j in i.split('+'): #+로 쪼갬
        sol -= int(j)   #그리고 그걸 뺀다

print(sol)

