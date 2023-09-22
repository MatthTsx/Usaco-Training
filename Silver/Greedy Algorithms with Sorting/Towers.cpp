#include<bits/stdc++.h>
// https://cses.fi/problemset/task/1073
using namespace std;
#define FOR(i,N,ini) for(int i=ini;i<N;i++)
#define id second
#define size first

int N, resp = 0;
int p_1; // placeholder
vector<int> vt;
multiset<int> ongoing;

void solve(){
    cin >> N;
    vt = vector<int> (N);
    FOR(i,N,0){
        cin >> vt[i];
    }

    for (auto &&i : vt){
        auto t = ongoing.upper_bound(i);
        if(t == ongoing.end()) resp++;
        else ongoing.erase(ongoing.find(*t));
        ongoing.insert(i);
    }
    
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
