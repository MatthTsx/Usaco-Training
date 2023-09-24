#include<bits/stdc++.h>
// https://cses.fi/problemset/task/1668
using namespace std;
#define FOR(i,N,ini) for(int i=ini;i<N;i++)

int N,M;
int pl_1, pl_2; //placeholders
map<int,set<int>> friends;

void solve(){
    cin >> N >> M;
    vector<set<int>> vt (N);
    FOR(i,N,0) vt[0].insert(i+1);
    FOR(i,M,0){
        cin >> pl_1 >> pl_2;
        friends[pl_1].insert(pl_2);
        friends[pl_2].insert(pl_1);
    }

    for (auto &&i : friends)
    {
        
    }
    
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
