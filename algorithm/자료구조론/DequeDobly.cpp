#include <iostream>
using namespace std;
#include <string>

class RuntimeException
{
private:
    string errMsg;

public:
    RuntimeException(const string &err) : errMsg(err)
    {
    }
    string getMessage() const
    {
        return errMsg;
    }
};

class DequeEmpty : public RuntimeException
{
public:
    DequeEmpty(const string &err) : RuntimeException(err)
    {
    }
};

typedef int Elem; 
class DNode
{ 
private:
    Elem elem;                
    DNode *prev;             
    DNode *next;             
    friend class DLinkedList;
};

class DLinkedList
{ 
public:
    DLinkedList();              
    ~DLinkedList();             
    bool empty() const;           
    const Elem &front() const;         
    const Elem &back() const;         
    void addFront(const Elem &e); 
    void addBack(const Elem &e);  
    void removeFront();         
    void removeBack();
    void display(); 
private:            
    DNode *header;  
    DNode *trailer;

protected:                             
    void add(DNode *v, const Elem &e); //v전에 새로운 노드 삽입
    void remove(DNode *v);             //v노드 제거
};
DLinkedList::DLinkedList()
{                       
    header = new DNode; 
    trailer = new DNode;
    header->next = trailer; 
    trailer->prev = header;
}

bool DLinkedList::empty() const 
{
    return (header->next == trailer);
}

const Elem &DLinkedList::front() const 
{
    return header->next->elem; // 가장 앞의 원소를 얻음
}

const Elem &DLinkedList::back() const 
{
    return trailer->prev->elem; // 가장 뒤의 원소를 얻음
}
void DLinkedList::remove(DNode *v)
{                      
    DNode *u = v->prev; 
    DNode *w = v->next; 
    u->next = w;        
    w->prev = u;
    delete v;
}

void DLinkedList::removeFront() 
{
    remove(header->next);
}

void DLinkedList::removeBack() 
{
    remove(trailer->prev);
}

// insert new node before v
void DLinkedList::add(DNode *v, const Elem &e)
{
    DNode *u = new DNode;
    u->elem = e;       
    u->next = v;      
    u->prev = v->prev;
    v->prev->next = u;
    v->prev = u;
}

void DLinkedList::addFront(const Elem &e) // add to front of list
{
    add(header->next, e);
}

DLinkedList::~DLinkedList()
{ // destructor
    while (!empty())
        removeFront(); // remove all but sentinels
    delete header;     // remove the sentinels
    delete trailer;
}

void DLinkedList::addBack(const Elem &e) // add to back of list
{
    add(trailer, e);
}

class LinkedDeque
{
public:
    LinkedDeque()
    {
        n = 0;
    }
    int size() const;
    bool empty() const;
    const Elem &front() const throw(DequeEmpty);
    const Elem &back()const throw(DequeEmpty);
    void insertfront(const Elem &e);
    void insertback(const Elem &e);
    void removefront()throw(DequeEmpty);
    void removeback()throw(DequeEmpty);

private:
    DLinkedList D;
    int n;

    friend class DLinkedList;
};

int LinkedDeque::size() const
{
    return n;
}

bool LinkedDeque::empty() const
{
    return size() == 0;
}

void LinkedDeque::insertfront(const Elem &e)
{
    D.addFront(e);
    n++;
}

void LinkedDeque::insertback(const Elem &e)
{
    D.addBack(e);
    n++;
}

void LinkedDeque::removefront()throw(DequeEmpty)
{
      try {
        if (empty()) throw DequeEmpty("Deque is empty!");
        D.removeFront();
        n--;
    }
    catch (DequeEmpty& obj) {
        cout << obj.getMessage() << endl;
        exit(1);
    }
    
    
}

void LinkedDeque::removeback()throw(DequeEmpty)
{
     try {
        if (empty()) throw DequeEmpty("Deque is empty!");
        D.removeBack();
        n--;
    }
    catch (DequeEmpty& obj) {
        cout << obj.getMessage() << endl;
        exit(1);
    }
    
}

const Elem &LinkedDeque::front()const throw(DequeEmpty)
{
     try {
        if (empty()) throw DequeEmpty("Deque is empty!");
        return D.front();
    }
    catch (DequeEmpty& obj) {
        cout << obj.getMessage() << endl;
        exit(1);
    }
}

const Elem &LinkedDeque::back()const throw(DequeEmpty)
{
    try {
        if (empty()) throw DequeEmpty("Deque is empty!");
        return D.back();
    }
    catch (DequeEmpty& obj) {
        cout << obj.getMessage() << endl;
        exit(1);
    }
}

int main()
{
    LinkedDeque A;
    A.insertfront(1);
    A.insertback(2);
    A.insertback(3);
    A.removefront();
    cout << A.back() << endl;
    A.removefront();
    A.removefront();
    A.removefront();

    return 0;
}