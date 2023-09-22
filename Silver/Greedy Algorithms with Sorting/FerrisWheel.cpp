#include<bits/stdc++.h>
// https://cses.fi/problemset/task/1090

using namespace std;
#define FOR(i,N,ini) for(int i = ini;i < N;i++)

int N, K, qnt = 0, resp = 0;
vector<int> vt;

void solve(){
    cin >> N >> K;

    vt = vector<int> (N, 0);
    multiset<bool> gangorr;

    FOR(i,N,0) cin >> vt[i];
    int ini = N-1, fin = 0;
    sort(vt.begin(), vt.end());

    while(fin < ini){
        if(vt[fin] + vt[ini] > K) --ini;
        else {
            resp++;
            gangorr.insert(true);
            gangorr.insert(true);
            --ini;
            fin++;
        }
    }
    resp += N - gangorr.count(true);
    cout << resp;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
