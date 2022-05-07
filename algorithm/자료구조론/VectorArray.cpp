#include <string>
#include <iostream>
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

typedef int Elem;
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
    void reserve(int N);

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
    try {
         if (i < 0 || i >= n) throw IndexOutOfBounds("illegal index in function at()");
         return A[i];
    }
    catch (IndexOutOfBounds& obj) {
        cout << obj.getMessage() << endl;
        exit(1); // exit(1)이 없으면 실행중에 에러가 발생해버림..
    }
 
}

void ArrayVector::erase(int i)
{
    for (int j = i + 1; j < n; j++)
        A[j - 1] = A[j];
    n--;
}

void ArrayVector::reserve(int N)
{
    if (capacity >= N)
        return;
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
        reserve(max(1, 2 * capacity));
    for (int j = n - 1; j >= i; j--)
        A[j + 1] = A[j];
    A[i] = e;
    n++;
}

int main()
{
    ArrayVector a;
    a.insert(0, 7);
    a.insert(0, 4);
    cout << a.at(1) << endl;
    a.insert(2, 2);
    a.erase(1);
    a.insert(1, 5);
    a.insert(1, 3);
    a.insert(4, 9);
    cout << a.at(2) << endl;

    cout << "show all elements in the vector :";
    for (int i = 0; i < a.size(); i++)
    {
        cout << a.at(i) << " ";
    }
    
    return 0;
}