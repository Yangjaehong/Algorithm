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

class QueueEmpty : public RuntimeException {
public:
    QueueEmpty(const string& err) : RuntimeException(err) {
    }
};

class Queuefull : public RuntimeException {
public:
    Queuefull(const string& err) : RuntimeException(err) {
    }
};

template <typename E>
class ArrayQueue {
private:
    E* S;          
    int capacity;
    int r,f; 
public:
    ArrayQueue(int cap = 100);
    ~ArrayQueue();
    int size() const;
    bool empty() const;
    const E& front() const throw(QueueEmpty);
    void enqueue(const E& e) throw(Queuefull);
    void dequeue() throw(QueueEmpty);
};

template <typename E>
ArrayQueue<E>::ArrayQueue(int cap) {
    capacity = cap;
    f = 0;
    r = 0;
    S = new E[cap];
}

template <typename E>
ArrayQueue<E>::~ArrayQueue() {
    delete[] S;
}

template <typename E>
int ArrayQueue<E>::size() const {
    return (r-f+capacity)%capacity;
}

template <typename E>
bool ArrayQueue<E>::empty() const {
    return r == f;
}

template <typename E>
const E& ArrayQueue<E>::front() const throw(QueueEmpty) {
    try {
        if (empty()) throw QueueEmpty("Queue is empty!");
        return S[(f+1)%capacity];
    }
    catch (QueueEmpty& obj) {
        cout << obj.getMessage() << endl;
        exit(1); // exit(1)이 없으면 실행중에 에러가 발생해버림..
    }
}

template <typename E>
void ArrayQueue<E>::enqueue(const E& e) throw(Queuefull) {
    try {
        if (size() == capacity) throw Queuefull("Queue is full!");
        r = (r+1) % capacity;
        S[r] = e;
    }
    catch (Queuefull& obj) {
        cout << obj.getMessage() << endl;
        exit(1); // exit(1)이 없으면 실행중에 에러가 발생해버림..
    }
}

template <typename E>
void ArrayQueue<E>::dequeue() throw(QueueEmpty) {
    try {
        if (empty()) throw QueueEmpty("Queue is empty!");
        f = (f+1) % capacity;
    }
    catch (QueueEmpty& obj) {
        cout << obj.getMessage() << endl;
        exit(1); // exit(1)이 없으면 실행중에 에러가 발생해 버림..
    }
}

int main() {
        ArrayQueue<int> A;
        A.enqueue(7);
        A.enqueue(13);
        cout << A.front() << endl;
        A.enqueue(9);
        A.dequeue();
        A.dequeue();
        A.dequeue();
        cout << A.front() << endl;
        
       

        return 0;
}