a,b = input().split()

a = int(a)
b = int(b)

def add(a, b):
    return a + b
def sub(a, b):
    return a - b
def mul(a, b):
    return a * b
def div(a, b):
    return int(a / b)
def remainder(a, b):
    return a % b
    
print(add(a,b))
print(sub(a,b))
print(mul(a,b))
print(div(a,b))
print(remainder(a,b))
