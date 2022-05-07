#include <iostream>
#include <string>
using namespace std;

class RuntimeException {
private:
    string errMsg;
public:
    RuntimeException(const string& err) : errMsg(err) {
    }
    string getMessage() const { 
        return errMsg; 
    }
};

class StackEmpty : public RuntimeException {
public:
    StackEmpty(const string& err) : RuntimeException(err) {
    }
};

class StackFull : public RuntimeException {
public:
    StackFull(const string& err) : RuntimeException(err) {
    }
};

template <typename E>
class ArrayStack {
private:
    E* S;          
    int capacity;
    int t; 
public:
    ArrayStack(int cap = 100);
    ~ArrayStack();
    int size() const;
    bool isEmpty() const;
    const E& top() const throw(StackEmpty);
    void push(const E& e) throw(StackFull);
    void pop() throw(StackEmpty);
};

template <typename E>
ArrayStack<E>::ArrayStack(int cap) {
    capacity = cap;
    t = -1;
    S = new E[cap];
}

template <typename E>
ArrayStack<E>::~ArrayStack() {
    delete[] S;
}

template <typename E>
int ArrayStack<E>::size() const {
    return t + 1;
}

template <typename E>
bool ArrayStack<E>::isEmpty() const {
    return (t == -1);
}

template <typename E>
const E& ArrayStack<E>::top() const throw(StackEmpty) {
    try {
        if (isEmpty()) throw StackEmpty("Stack is empty!");
        return S[t];
    }
    catch (StackEmpty& obj) {
        cout << obj.getMessage() << endl;
        exit(1); // exit(1)이 없으면 실행중에 에러가 발생해버림..
    }
}

template <typename E>
void ArrayStack<E>::push(const E& e) throw(StackFull) {
    try {
        if (size() == capacity) throw StackFull("Stack is full!");
        S[++t] = e;
    }
    catch (StackFull& obj) {
        cout << obj.getMessage() << endl;
        exit(1); // exit(1)이 없으면 실행중에 에러가 발생해버림..
    }
}

template <typename E>
void ArrayStack<E>::pop() throw(StackEmpty) {
    try {
        if (isEmpty()) throw StackEmpty("Stack is empty!");
        t--;
    }
    catch (StackEmpty& obj) {
        cout << obj.getMessage() << endl;
        exit(1); // exit(1)이 없으면 실행중에 에러가 발생해 버림..
    }
}

int main() {
        ArrayStack<int> A;
        A.push(7);
        A.push(13);
        cout << A.top() << endl;
        A.push(9);
        A.pop();
        A.pop();
        A.pop();
        cout << A.top() << endl;
        cout << A.top() << endl;
        ArrayStack<string> B(10);
        B.push("Bob");
        B.push("Alice");
        cout << B.top() << endl;
        B.push("Eve");
        A.pop();
        A.pop();
        B.pop();
        B.pop();
        B.pop();
        cout << B.top() << endl;
        cout << B.size() << endl;

        return 0;
}