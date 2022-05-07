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


typedef int Elem;
class CNode
{
    Elem elem;
    CNode *next;

    friend class SLinkedList;
};

class SLinkedList
{
public:
    SLinkedList()
    {
        head = new CNode;
    };
    ~SLinkedList()
    {
        delete head;
    };
    bool empty() const;
    int size();
    const Elem &front() const;
    void addfront(const Elem &e);
    void removefront();

private:
    CNode *head;
};

bool SLinkedList::empty() const
{
    return head == NULL;
}

const Elem &SLinkedList::front() const
{
    return head->elem;
}

void SLinkedList::addfront(const Elem &e)
{
    CNode *v = new CNode; //새로운 노드 생성
    v->elem = e;          //데이터를 저장
    v->next = head;       //현재는 head가 v뒤에 있음
    head = v;             //v가 이제 head가 됌
}

void SLinkedList::removefront()
{
    CNode *old = head;  //현재 head를 old에 저장
    head = old->next;   //이전 head를 건너뜀
    delete old;         //이전 head를 삭제
}

class LinkedStack
{
public:
    LinkedStack()
    {
        n = 0;
    }
    int size() const;
    bool empty() const;
    const Elem &top() const throw(StackEmpty);
    void push(const Elem &e);
    void pop() throw(StackEmpty);

private:
    SLinkedList S;
    int n;

    friend class SLinkedList;
};

int LinkedStack::size() const
{
    return n;
}

bool LinkedStack::empty() const
{
    return size() == 0;
}

const Elem &LinkedStack::top() const throw(StackEmpty)
{   
    try {
        if (empty()) throw StackEmpty("Stack is empty!");
        return S.front();
    }
    catch (StackEmpty& obj) {
        cout << obj.getMessage() << endl;
    }
    
}

void LinkedStack::push(const Elem &e)
{
    ++n;
    S.addfront(e);
}

void LinkedStack::pop() throw(StackEmpty)
{
    try {
        if (empty()) throw StackEmpty("Stack is empty!");
        --n;
        S.removefront();
    }
    catch (StackEmpty& obj) {
        cout << obj.getMessage() << endl;
    }
}
int main()
{
    LinkedStack S;
    S.push(4);
    S.push(5);
    cout << S.top() << " " << S.size() << endl;
    S.pop();
    cout << S.top() << " " << S.size() << endl;
    S.pop();
    S.top();

    return 0;
}