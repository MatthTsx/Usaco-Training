#include<bits/stdc++.h>

// https://cses.fi/problemset/task/1662

#define Max 200000
using namespace std;
using ll = long long;
using vt = ll[Max];

vt arry;
map<ll,int> seen;
ll qntd = 0;

int main(int argc, char const *argv[])
{
    ll N;
    cin >> N;

    arry[0] = 0;
    seen[0] = 1;

    for (ll i = 1; i <= N; i++)
    {
        cin >> arry[i];
        arry[i] %= N;
        arry[i] += arry[i-1];
        arry[i] = (arry[i] + N) % N;
        
        qntd += seen[arry[i]];
        seen[arry[i]]++;
    }
    
    cout << qntd;
    return 0;
}
