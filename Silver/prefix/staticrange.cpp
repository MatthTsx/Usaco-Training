#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll arry[500000];
ll anws[500000];
int main()
{
    ll N, Q;
    cin >> N >> Q;
    
    
    arry[0] = 0;

    for (ll i = 1; i <= N; i++)
    {
        ll in;
        cin >> in;
        arry[i] = arry[i - 1] + in;
    }
    
    for (ll i = 0; i < Q; i++)
    {
        ll _ini, _fin;
        cin >> _ini >> _fin;
        anws[i] = arry[_fin] - arry[_ini];
    }
    
    for (ll i = 0; i < Q; i++)
    {
        cout << anws[i] << "\n";
    }
    

    return 0;
}
