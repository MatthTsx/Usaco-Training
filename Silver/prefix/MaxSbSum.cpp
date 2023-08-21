#include<bits/stdc++.h>
// https://cses.fi/problemset/task/1643/

using ll = long long;
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    ll mx = 0, mn = 0;
    bool setup = true;
    vector<ll> vt (N + 1);

    for (int i = 1; i <= N; i++)
    {
        cin >> vt[i];
        vt[i] += vt[i-1];

        mx = max(vt[i] - mn, mx);
        mn = min(vt[i], mn);
        if(setup){
            setup = false;
            mx = vt[i];
        }
    }
    
    cout << mx;
    return 0;
}
