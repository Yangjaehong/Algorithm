from queue import PriorityQueue

class HuffNodes:  
    def __init__(self, symbol, freq):  
        self.symbol = symbol  
        self.freq = freq
        self.left = None
        self.right = None
        self.code = ''
        
    def inorder(self):
        if(self.left is not None):
            self.left.inorder()
        print(self.freq, end = " ")
        if (self.right is not None):
            self.right.inorder()
     
    def encoding(self, code):
        if(self.left is not None):
            self.left.encoding(self.code + '0')
        if(self.right is not None):
            self.right.encoding(self.code + '1')
            
        self.code = code
        
    def printinorder(self):
        if(self.left is not None):
            self.left.printinorder()
        if(self.symbol != ' '):
            print(self.symbol, self.code, end = " ")
            print(" ")
        if (self.right is not None):
            self.right.printinorder()
            
def huffman(n, PQ):
    for _ in range(n - 1):
        p = PQ.get()[1]
        q = PQ.get()[1]
        r = HuffNodes(' ', p.freq + q.freq)
        r.left = p
        r.right = q
        PQ.put((r.freq, r))
        
    return PQ.get()[1]

symbols = ['r','A', 'B', 'C', 'D', 'E', 'F']
freqs = [27, 15, 12, 9, 5, 10, 11]

PQ = PriorityQueue()

for i in range(len(symbols)):
    node = HuffNodes(symbols[i], freqs[i])
    PQ.put((node.freq, node))
    
root = huffman(len(symbols), PQ)

for i in range(len(symbols)):
    root.encoding('')

root.printinorder()