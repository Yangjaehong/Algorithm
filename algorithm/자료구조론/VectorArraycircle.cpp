#include <string>
#include <iostream>
using namespace std;

class RuntimeException
{
private:
    string errMsg;

public:
    RuntimeException(const string& err) : errMsg(err)
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
    IndexOutOfBounds(const string& err) : RuntimeException(err)
    {
    }
};

typedef int Elem;
class ArrayVector
{
public:
    ArrayVector();
    ~ArrayVector();
    int size() const;
    bool empty() const;
    Elem& operator[](int i);
    Elem& elemAtRank(int i) throw(IndexOutOfBounds);
    void removefront();
    void removeback();
    void insertfront(const Elem& e);
    void insertback(const Elem& e);
    const Elem& front() const;
    const Elem& back() const;
    void reserve(int N);

private:
    Elem* S;
    int capacity;
    int r, f;
    int n;
};

ArrayVector::ArrayVector() {
    capacity;
    f = 0;
    r = 0;
    n = 0;
    S = new Elem[NULL];
}

ArrayVector::~ArrayVector() {
    delete[] S;
}
int ArrayVector::size() const
{
    return n;
}

bool ArrayVector::empty() const
{
    return size() == 0;
}

Elem& ArrayVector::operator[](int i)
{
    return S[i];
}


void ArrayVector::reserve(int N)
{
    if (capacity >= N)
        return;
    Elem* B = new Elem[N];
    for (int j = 0; j < n; j++)
        B[j] = S[j];
    if (S != NULL)
        delete[] S;
    S = B;
    capacity = N;
}

Elem& ArrayVector::elemAtRank(int i) throw(IndexOutOfBounds)
{
    try {
        if (i < 0 || i >= n) throw IndexOutOfBounds("illegal index in function at()");
        return S[i];
    }
    catch (IndexOutOfBounds& obj) {
        cout << obj.getMessage() << endl;
    }

}

void ArrayVector::insertfront(const Elem& e)
{
    if (n >= capacity)
        reserve(max(1, 2 * capacity));
    if (f == 0) {
        f = capacity - 1;
        S[f] = e;
        n++;
    }
    else {
        f = f - 1;
        S[f] = e;
        n++;
    }
   

}

void ArrayVector::removefront()
{
    f = (f + 1) % capacity;
    n--;
}

void ArrayVector::insertback(const Elem& e) {
    if (n >= capacity)
        reserve(max(1, 2 * capacity));
    r = (r + 1) % capacity;
    S[r] = e;
    n++;
}
void ArrayVector::removeback()
{
    if (r == 0) r = capacity - 1;

    else {
        r = r - 1;
    }
    n--;
}

const Elem& ArrayVector::front() const {
    return S[f];
}

const Elem& ArrayVector::back() const {
    return S[r];
}



int main()
{
    ArrayVector a;
    a.insertback(4);
    a.insertback(2);
    a.insertfront(1);
    a.insertfront(3);
    for (int i = 0; i < a.size(); i++) {
        cout << a.elemAtRank(i) << " ";
    }


    return 0;
}