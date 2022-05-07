#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;

void printArray(int arr[], int n) //배열을 출력하기 위함
{   
    
   for (int i=0; i < n; i++)
       cout << arr[i] << " ";
   cout << "\n";
}

void oddevensort(int arr[],int n){
    bool isSorted = false;
     while (!isSorted)
    {
        isSorted = true;

        //cout << "odd index" << endl; 주석처리한 부분은 값을 입력 하였을 때 정렬이 어떻게 되는지 보기 위함
                //printArray(arr, n );
        for (int i=1; i<=n-2; i=i+2) //2씩 증가 시키면서 odd
        {
            if (arr[i] > arr[i+1])
             {
                swap(arr[i], arr[i+1]);
                isSorted = false;
              }
        }
        
      
        //cout << "even index" << endl; 주석처리한 부분은 값을 입력하였을 때 어떻게 정렬 되는지 보기 위함
                //printArray(arr, n);
        for (int i=0; i<=n-2; i=i+2) //2씩 증가 시킴 even
        {
            if (arr[i] > arr[i+1])
            {
                swap(arr[i], arr[i+1]);
                isSorted = false;
                
            }
        }
    }
}

void checksort(int a[], int n) { //이전 과제에서 이용했던 체크 솔트를 그대로 가져와 씀
   int i, sorted;
   sorted = 1;
   for (int i = 0; i <n-1; i++)
   {
      if (a[i] > a[i+1]) {
         sorted = 0;
      }
      if (!sorted) {
         break;
         }
   }
   if (sorted) {
      cout << "sort complete " << endl;
   }
   else {
      cout << "sort error!!" << endl;
      }
}

int main(){
    srand((unsigned int)time(0));
    int n=0;
    cin >> n; //n의 값을 입력으로 받음
    int *arr = new int[n];
    for (int i = 0; i < n; i++){  //랜덤값을 부여함
        arr[i] = rand() % n;
    }

    /*for(int i = 0; i < n; i++){ 직접입력하는 부분을 주석 처리함
        cin >> arr[i];
    }*/

    clock_t start, end; //시간을 위한 변수 선언
    
    start = clock(); //시작시간
    oddevensort(arr,n); //sort
    end = clock();  //끝시간
    double timeSecond = (double)((end-start) / double(CLOCKS_PER_SEC)); //초단위로 표현하기 위함

    //cout <<"Final result" << endl; 직접 입력하여 확인하는 용을 주석 처리함
    //printArray(arr,n);

    cout <<"Check sort" << endl;
    checksort(arr,n);
    cout << timeSecond << "Sec"<< endl;
    delete[] arr;
    return 0;
}