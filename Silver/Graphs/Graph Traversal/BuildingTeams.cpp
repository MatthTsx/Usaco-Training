#include<bits/stdc++.h>
// https://cses.fi/problemset/task/1668
using namespace std;
#define FOR(i,N,ini) for(int i=ini;i<N;i++)

int N,M;
int pl_1, pl_2; //placeholders
vector<int> people;
vector<vector<int>> vt;
vector<bool> visited;

void dfs(bool team, int c, bool& imposible){
    visited[c] = true;
    people[c] = team;

    for (auto &&i : vt[c])
    {
        if(visited[i]){
            if(people[i] == team) imposible = true;
        }else dfs(!team, i, imposible);
    }
}

void solve(){
    cin >> N >> M;
    vt = vector<vector<int>> (N);
    people = vector<int> (N);
    visited = vector<bool> (N, false);

    FOR(i,M,0){
        cin >> pl_1 >> pl_2;
        pl_1--; pl_2--;
        vt[pl_1].push_back(pl_2);
        vt[pl_2].push_back(pl_1);
    }

    bool imposible = false;
    FOR(i,N,0)
    {
        if(visited[i]) continue;
        dfs(0, i, imposible);
    }
    if(imposible) cout << "IMPOSSIBLE";
    else for (auto &&i : people) cout << i+1 << " ";
}

int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    solve();
    return 0;
}
