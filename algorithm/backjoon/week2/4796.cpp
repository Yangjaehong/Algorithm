#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int P, L, V, cnt = 0;
    queue<int> q;
    while (true)
    {
        int sol = 0;
        cin >> L >> P >> V;
        if (L == 0 && P == 0 && V == 0) break;
        else if (1 < L && L < P && P < V)
        {
            cnt++;
            sol = L * (V / P);
            if(V%P>L) sol += L;
            else sol += V % P;
        }
        cout << "Case " << cnt << ": " << sol << endl;
    }

    return 0;
}