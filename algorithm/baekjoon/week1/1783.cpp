#include <iostream>
using namespace std;
int main()
{
    int n, m;
    int sol = 1;

    cin >> n >> m;

    if (n == 1){
        sol = 1;
    }
    else if (n == 2)
    {
        if((m+1)/2 >= 4){
            sol = 4;
        }
        else{
            sol = (m+1)/2;
        }
    }
    else
    {
        if (m <= 6)
        {
            if(m >= 4){
                sol = 4;
            }
            else sol = m;
        }
        else
        {
            sol = m - 2;
        }

    }

    cout << sol << endl;

    return 0;
}