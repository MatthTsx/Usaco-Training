#include<bits/stdc++.h>
// http://www.usaco.org/index.php?page=viewproblem2&cpid=571
using namespace std;
#define FOR(i,N,ini) for(int i=ini;i<N;i++)

int N, resp = 0;

vector<int> Cards1;
multiset<int> Cards2;

void solve(){
    cin >> N;
    vector<int> placeholder(N*2, 0);
    FOR(i,N,0){
        int vl;
        cin >> vl;
        placeholder[vl-1] = -1;
        Cards1.push_back(vl);
    }
    FOR(i,N*2,0)
        if(placeholder[i] != -1) Cards2.insert(i+1);
    
    for (auto &&i : Cards1)
    {
        auto t = Cards2.upper_bound(i);
        if(t == Cards2.end()) continue;
        Cards2.erase(Cards2.find(*t));
        resp++;
    }
    cout << resp;
}

int main(int argc, char const *argv[])
{
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}