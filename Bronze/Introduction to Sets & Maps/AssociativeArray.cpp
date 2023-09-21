#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define FOR(i,N) for(int i =0; i < N; i++)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll N;
    map<ll,ll> mp;
    cin >> N;

    FOR(i,N){
        int t, v1, v2;
        cin >> t >> v1;
        if(t == 1){
            cout << mp[v1] << "\n";
            continue;
        }
        cin >> v2;
        mp[v1] = v2;
    }
    return 0;
}
