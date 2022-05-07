#include <iostream>
#include "vector_array.h"

using namespace std;

typedef char Elem;
class QuickSort{
public:
    void setVector(ArrayVector Vector){
        myData = Vector; //private 변수에 main에서 받은 vector를 저장함
    }
    
    ArrayVector getVector(){
        return myData; // vector를 돌려줌
    }

    void runSorting(); //sorting을 시작하는 함수
    void qsort(ArrayVector A, int left, int right);
    int partition(ArrayVector A, int left, int right);
    void display();
    void swap(ArrayVector A, int l, int r);

private:
    ArrayVector myData;
};

void QuickSort::runSorting(){
    cout <<"Start sorting" <<endl;
    qsort(myData,0,myData.size()-1); //private myvector와 시작점과 끝점
    display();
    cout << "Done sorting";
}

void QuickSort::swap(ArrayVector A, int l, int r){ //l과 r에 위치한 변수를 스왑
    int temp = A.at(l);
    A.at(l) = A.at(r);
    A.at(r) = temp;
}

void QuickSort::qsort(ArrayVector A, int left, int right){
    if (left < right){
        int p = partition(A, left, right);
        qsort(A, left, p - 1);
        qsort(A, p + 1, right);
    }
}

int QuickSort::partition(ArrayVector A, int left, int right){
    Elem pivot = A.at(left);
    int l = left + 1;
    int r = right;
    display();
    
    while (l <= r){
        while(l <= right && A.at(l) <= pivot ) l++;
        while (r >= (left+1) && A.at(r) >= pivot) r--;
        if(l <= r) swap(A,l,r);
    }
    swap(A,left,r);

    return r;
}

void QuickSort::display(){
    for (int i = 0; i < myData.size(); i++) cout << myData.at(i) << " ";
    cout << endl;
}

int main(){
    ArrayVector v;
    QuickSort sorting;

    int n = 0;
    cout << "How many elements do you want to sort?: ";
    cin >> n;
    cout << "Enter " << n << " elements to sort: ";

    for (int i = 0; i < n; i++){
        Elem input;
        cin >> input;
        v.insert(i, input);
    }
  
    sorting.setVector(v);
    sorting.runSorting();
    
    return 0;
}