#include<bits/stdc++.h>
using namespace std;
#define Max 10000

using ll = long long;
using vl = ll[Max][3];

vl arry;
ll answer = 0;

// Hoof, paper, scissors
int main(int argc, char const *argv[])
{
    ll N;
    cin >> N;
    arry[0][0] = 0;
    arry[0][1] = 0;
    arry[0][2] = 0;

    for (size_t i = 1; i <= N; i++)
    {
        arry[i][0] = arry[i-1][0];
        arry[i][1] = arry[i-1][1];
        arry[i][2] = arry[i-1][2];

        char vl;
        cin >> vl;

        if(vl == 'H') arry[i][0]++;
        else if(vl == 'P') arry[i][1]++;
        else arry[i][2]++;
    }
    ll maior = 0;

    for (int i = 1; i <= N; i++)
    {
        ll mx1 = max(arry[i][0], arry[i][1]);
        mx1 = max (mx1, arry[i][2]);
        ll mx2 = max(
            arry[N][0] - arry[i][0],
            arry[N][1] - arry[i][1]
        );
        mx2 = max(mx2, arry[N][2] - arry[i][2]);
        if(mx1 + mx2 > maior) maior = mx1 + mx2;
    }

    cout << maior << "\n";
    return 0;
}
