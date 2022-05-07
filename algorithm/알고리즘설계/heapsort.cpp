#include <iostream>
#include <ctime>
using namespace std;

void maxHeapify(int arr[], int h, int m){ //큰수를 위로
    int v = arr[h]; //루트의 값 대입
    int j = 0; //비교하기 위한 변수
    for(j=2*h; j<=m; j=j*2){ //루트로 부터 m의 위치까지 자식들 확인
        if(j<m && arr[j]<arr[j+1]) j++; //왼쪽 자식과 오른쪽 자식을 비교한다
        //j는 값이 큰 왼쪽 또는 오른쪽 자식 노드
        if(v>=arr[j]) break; //만일 루트가 해당 자식보다 크면 break
        else arr[j/2] = arr[j]; //아니면 부모와 값을 바꿔준다
    }
    arr[j/2] = v; //찾아낸 위치에 원래 루트 값 대입
}

void minHeapify(int arr[], int h, int m){ //maxHeapify와 거의 동일
    //작은 수를 위로
    int v = arr[h];
    int j = 0;
    for(j=2*h; j<=m; j=j*2){
        if(j<m && arr[j]>arr[j+1]) j++; 
        if(v<=arr[j]) break; // 루트가 더 작을 때 break
        else arr[j/2] = arr[j];
    }
    arr[j/2] = v;
}

void minHeapSort(int arr[], int n){
    for(int i = n/2; i>=1; i--){ // sort전 heapify로 정리
        minHeapify(arr,i,n);
    }
    for(int i = n-1; i>=1; i--){ // 가장 큰수를 뒤로 이동
        //가장 큰수를 위로 올린다
        //이렇게 하면 맨 뒷 칸에서 부터 가장 큰수부터 차례대로 정렬이 된다
        swap(arr[1],arr[i+1]); //a[1]이 가장 큰 원소
        //a[1]과 a[i+1]을 교환
        //temp를 사용하지 않고 swap함수로 해결하였음
        minHeapify(arr,1,i);
    }
}

void maxHeapSort(int arr[], int n){ //minHeapSort와 동일
    for(int i = n/2; i>=1; i--){
        maxHeapify(arr,i,n);
    }
    for(int i = n-1; i>=1; i--){
        swap(arr[1],arr[i+1]);
        maxHeapify(arr,1,i);
    }
}

void Maxcheck(int a[], int n){ 
    int i, sorted;
    sorted = 1;

    for(i=0; i<n-1; i++){
        if(a[i]>a[i+1]){
            sorted = 0;
        }
        if(!sorted) {
            break;
        }
    }
    if(sorted==1){
        cout<<"MaxHeap Sorting complete!"<<endl;
    } else {
        cout<<"Error during sorting..."<<endl;
    }

}

void Mincheck(int a[], int n){ 
    int i, sorted;
    sorted = 1;

    for(i=1; i<n-1; i++){
        if(a[i]<a[i+1]){
            sorted = 0;
        }
        if(!sorted) {
            break;
        }
    }
    if(sorted==1){
        cout<<"MinHeap Sorting complete!"<<endl;
    } else {
        cout<<"Error during sorting..."<<endl;
    }

}

int main(){
    int min[11] = {0,6,2,8,1,3,9,4,5,10,7}; //정렬 확인용
    int max[11] = {0,6,2,8,1,3,9,4,5,10,7}; //정렬 확인용

    maxHeapSort(max,10);
    cout<<"MaxHeap 정렬 결과 : ";
    for(int i=1; i<11; i++){
        cout<<max[i]<<" ";
    }
    cout<<endl; 

    minHeapSort(min,10);
    cout<<"MinHeap 정렬 결과 : "; 
    for(int i=1; i<11; i++){
        cout<<min[i]<<" ";
    }
    cout<<endl;


    int n[5] = {10000, 50000, 100000, 500000, 1000000};
    
    for (int m = 0; m < 5; m++){ //n배열의 n을 모두 돌아가면서 하기 위함

        int *arr = new int[n[m]]; //n배열에 따라 동적 할당
        clock_t start, end; //시간 측정용 변수
        for(int i=0; i<n[m]+1; i++){ // n개의 난수
            if(i==0) arr[i]=0; // 0번에는 0을 넣음
            else arr[i] = rand()%n[m];
        }

        start = clock();
        minHeapSort(arr,n[m]); //minHeapSort
        end = clock();

        double timeSecond = (double)((end-start) / double(CLOCKS_PER_SEC)); //초단위로 표현하기 위함
        cout<< "MinHeap sorting (N=" << n[m] <<")time cost : "<<timeSecond<<"sec"<<endl; 
        Mincheck(arr, n[m]+1);
        
        for(int i=0; i<n[m]+1; i++){ // 앞과 동일하게 난수 새로 만듬
            if(i==0) arr[i]=0;      
            else arr[i] = rand()%n[m];
        }

        start = clock();
        maxHeapSort(arr,n[m]); //maxHeapSort호출
        end = clock();

        timeSecond = (double)((end-start) / double(CLOCKS_PER_SEC)); //초단위로 표현하기 위함
        cout<< "MaxHeap sorting (N=" << n[m] <<")time cost : "<<timeSecond<<"sec"<<endl; // 소요시간을 출력해준다.
        Maxcheck(arr, n[m]+1);
        cout << endl;

        delete[] arr;
    }
    return 0;
}