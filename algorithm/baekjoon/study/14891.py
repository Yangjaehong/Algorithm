import sys, collections
s = []
for _ in range(4):
    s.append(collections.deque(list(input())))

k = int(input())
r = [list(map(int, sys.stdin.readline().split())) for _ in range(k)]

def right(num, handle):
    if s[num][2] != s[num+1][6]:
        pass