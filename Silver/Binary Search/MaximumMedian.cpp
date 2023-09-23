#include<bits/stdc++.h>
// https://codeforces.com/contest/1201/problem/C
using namespace std;
#define FOR(i,N,ini) for(int i=ini; i<N; i++)
using ll = long long;

ll N, K;
multiset<int> mts;
// FIXME: this
void solve(){
    cin >> N >> K;
    FOR(i,N,0){
        int vl;
        cin >> vl;
        mts.insert(vl);
    }

    while(K > 0){
        auto mid = mts.begin();
        advance(mid, (int) N/2);
        auto next = mts.upper_bound(*mid);

        --next;
        // if(next == mts.end()){
        // }

        ll dist = distance(mid, next) + 1;
        ll diff = *next - *mid;

        ll val = min(dist * (diff != 0 ? diff : K), K);

        FOR(i,dist,0){
            mts.insert((int) val/dist + *mid);
        }
        mts.erase(*mid);
        K -= val * dist;
        
        // for (auto &&i : mts)
        // {
        //     cout << i << " ";
        // }
        // cout << endl;
    }

    auto mid = mts.begin();
    advance(mid, (int) N/2);
    cout << *mid;
}

int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    solve();
    return 0;
}
