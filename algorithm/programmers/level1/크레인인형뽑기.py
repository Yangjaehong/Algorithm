def solution(board, moves):
    answer = 0
    b = []

    for j in moves:
        for i in range(len(board)):
            if board[i][j-1] != 0:
                b.append(board[i][j-1])
                board[i][j-1] = 0
                
                if len(b) > 1 and b[-1] == b[-2]:
                    b.pop(-1)
                    b.pop(-1)
                    answer += 2
                break
    
    return answer