#include<bits/stdc++.h>

#define Max 200000

using namespace std;
using ll = long long;
using vl = ll[Max];

// https://cses.fi/problemset/task/1661/

vl arry;
ll qntd = 0;
map<ll, int> m;

int main(int argc, char const *argv[])
{
    ll n, x;
    cin >> n >> x;

    arry[0] = 0;
    m[0]++;

    for (ll i = 1; i <= n; i++)
    {
        cin >> arry[i];
        arry[i] += arry[i-1];

        ll diff = arry[i] - x;
        qntd += m[diff];
        m[diff + x]++;
    }
    
    cout << qntd << "\n";
    return 0;
}
