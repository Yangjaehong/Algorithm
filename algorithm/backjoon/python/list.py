from code import compile_command


array = [1,5,2,6,3,7,4]
commandes = [[2, 5, 3], [4, 4, 1], [1, 7, 3]]
answer = []
set = []
for i in range(len(commandes)):
    l = commandes[i][0]
    r = commandes[i][1]
    k = commandes[i][2]
    set = array[l-1:r]
    set.sort()
    answer.append(set[k-1])
    set.clear()
print(answer)