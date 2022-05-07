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


typedef string Elem;
class CNode
{
    Elem elem;
    CNode *next;

    friend class CircleList;
};

class CircleList
{
public:
    CircleList()
    {
        cursor = new CNode;
    };
    ~CircleList()
    {
        delete cursor;
    };
    bool empty() const;
    int size();
    const Elem &front() const;
    const Elem &back() const;
    void advance();
    void add(const Elem &e);
    void remove();

private:
    CNode *cursor;
    int n;
};

bool CircleList::empty() const
{
    return cursor == NULL;
}

const Elem &CircleList::back() const
{
    return cursor->elem;
}

const Elem &CircleList::front() const
{
    CNode *head = new CNode;
    head = cursor->next;
    return head->elem;
}

void CircleList::advance()
{
    cursor = cursor->next;
}

void CircleList::add(const Elem &e)
{
    CNode *v = new CNode; //cursor가 tail
    v->elem = e;
    if (cursor->next == NULL) // 뒤에다 추가하는 식
    {
        cursor = v;       //현재 커서의 넥스트가 null이라는 뜻은 연결되지 않았다는 뜻(원형으로)
        v->next = cursor; //새로 추가한 노드의 next를 cursor로 설정함으로서 원형으로 연결
    }
    else
    {
        v->next = cursor->next; // 커서의 next는 현재 head를 가리키고 있고 새로 추가한 node는 끝에 붙으므로 node의 next가 head를 가리키게 해야됨
        cursor->next = v;       //현재 커서의 다음으로 새로 생기는 노드를 가리키게 함
        cursor = v;             //새로 생긴 노드(back)로 cursor 이동
    }
    n++;
}

void CircleList::remove()
{
    CNode *old = cursor->next; //앞에서부터 제거하므로 제거할 노드를 cursor의 next로 둔다.
    if (old == NULL)
    {                              //head가 비어있으면
        printf("Node is empty\n"); //비었다고 출력
    }
    else
        cursor->next = old->next; // head의 다음 노드를 head로 하기 위해서 cursor의 next를 head의 next 즉 head를 가리키게 한다.
    delete old;                   //head 삭제
    n--;
}

class LinkedQueue
{
public:
    LinkedQueue()
    {
        n = 0;
    }
    int size() const;
    bool empty() const;
    const Elem &front() const throw(QueueEmpty);
    void enqueue(const Elem &e);
    void dequeue() throw(QueueEmpty);

private:
    CircleList C;
    int n;

    friend class CircleList;
};

int LinkedQueue::size() const
{
    return n;
}

bool LinkedQueue::empty() const
{
    return size() == 0;
}

void LinkedQueue::dequeue() throw(QueueEmpty)
{
    try {
        if (empty()) throw QueueEmpty("Queue is empty!");
        C.remove();
        n--;
    }
    catch (QueueEmpty& obj) {
        cout << obj.getMessage() << endl;
    }
    
}

const Elem &LinkedQueue::front() const throw(QueueEmpty)
{
    try {
        if (empty()) throw QueueEmpty("Queue is empty!");
        return C.front();
    }
    catch (QueueEmpty& obj) {
        cout << obj.getMessage() << endl;
    }
}

void LinkedQueue::enqueue(const Elem &e)
{
    C.add(e);
    //C.advance();
    n++;
}
int main()
{
    LinkedQueue A;
    A.enqueue("Hi");
    A.enqueue("Bye");
    cout << A.front() << endl;
    A.dequeue();
    cout << A.front() << endl;
    cout << A.size() << endl;
    A.dequeue();
    A.dequeue();

    return 0;
}