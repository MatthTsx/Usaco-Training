#include<bits/stdc++.h>
// https://cses.fi/problemset/task/1629
using namespace std;
#define FOR(i,N) for(int i=0;i<N;i++)
using ll = long long;

struct p_ii{
    ll start, end;
    bool operator<(const p_ii& p1) const {
        if(p1.end == end) return start < p1.start;
        return end < p1.end;
    }
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, resp=0, atualTime = -1;
    cin >> N;
    multiset<p_ii> mts;

    FOR(i,N){
        int p, _p;
        cin >> p >> _p;
        mts.insert({p, _p});
    }

    for (auto &&i : mts)
        if(i.start >= atualTime){
            atualTime = i.end;
            resp++;
        }
    
    cout << resp;
    return 0;
}
