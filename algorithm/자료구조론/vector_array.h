#include <string>
using namespace std;
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

class IndexOutOfBounds : public RuntimeException
{
public:
    IndexOutOfBounds(const string &err) : RuntimeException(err)
    {
    }
};

typedef char Elem;
class ArrayVector
{
public:
    ArrayVector();
    int size() const;
    bool empty() const;
    Elem &operator[](int i);
    Elem &at(int i) throw(IndexOutOfBounds);
    void erase(int i);
    void insert(int i, const Elem &e);
    void set(int i, const Elem &e) throw(IndexOutOfBounds);
    void insertDoubling(int N);
    void insertIncremental(int N); 

private:
    int capacity;
    int n;
    Elem *A;
};

ArrayVector::ArrayVector()
    : capacity(0), n(0), A(NULL) {}

int ArrayVector::size() const
{
    return n;
}

bool ArrayVector::empty() const
{
    return size() == 0;
}

Elem &ArrayVector::operator[](int i)
{
    return A[i];
}

Elem &ArrayVector::at(int i) throw(IndexOutOfBounds)
{
    try
    {
        if (i < 0 || i >= n)
            throw IndexOutOfBounds("illegal index in function at()");
        return A[i];
    }
    catch (IndexOutOfBounds &obj)
    {
        cout << obj.getMessage() << endl;
        exit(1);
    }
}

void ArrayVector::erase(int i)
{
    for (int j = i + 1; j < n; j++)
        A[j - 1] = A[j];
    n--;
}



void ArrayVector::insertDoubling(int N)
{
    if (capacity >= N)
        return;
    N = N * 2;
    Elem *B = new Elem[N];
    for (int j = 0; j < n; j++)
        B[j] = A[j];
    if (A != NULL)
        delete[] A;
    A = B;
    capacity = N;
}

void ArrayVector::insertIncremental(int N){
    if (capacity >= N)
        return;

    N = N + 100;
    Elem *B = new Elem[N];
    for (int j = 0; j < n; j++)
        B[j] = A[j];
    if (A != NULL)
        delete[] A;
    A = B;
    capacity = N;
}

void ArrayVector::insert(int i, const Elem &e)
{
    if (n >= capacity)
        insertDoubling(max(1,capacity));
    for (int j = n - 1; j >= i; j--)
        A[j + 1] = A[j];
    A[i] = e;
    n++;
}

void ArrayVector::set(int i, const Elem &e) throw(IndexOutOfBounds)
{
    try
    {
        if (i < 0 || i >= n)
            throw IndexOutOfBounds("illegal index in function set()");
        A[i] = e;
    }
    catch (IndexOutOfBounds &obj)
    {
        cout << obj.getMessage() << endl;
        exit(1);
    }
}
