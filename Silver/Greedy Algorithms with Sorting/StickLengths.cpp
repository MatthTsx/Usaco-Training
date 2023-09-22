#include<bits/stdc++.h>
// https://cses.fi/problemset/task/1074
using namespace std;
#define FOR(i,N) for(int i=0;i<N;i++)
#define FORR(i,N) for(auto&& i : N)
using ll = long long;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll N, media, resp=0;
    cin >> N;
    multiset<int> mts;

    FOR(i, N){
        int p;
        cin >> p;
        mts.insert(p);
    }
    auto mid = mts.begin();
    advance(mid, (int) N/2);
    media = *mid;

    FORR(i, mts)
        resp += abs(media - i);

    cout << resp;
    return 0;
}
