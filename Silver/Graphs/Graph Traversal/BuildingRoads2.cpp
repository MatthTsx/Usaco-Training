#include<bits/stdc++.h>
// https://cses.fi/problemset/task/1666/
using namespace std;
#define FOR(i,N,ini) for(int i=ini;i<N;i++)

int N, M, resp = 0, anterior = -1;
vector<vector<int>> edges;
map<int,bool> visited;
vector<pair<int,int>> resp_vt;

int p_1, p_2; //placeholders
void getInputs(){
    FOR(i,M,0){
        cin >> p_1 >> p_2;
        edges[p_1-1].push_back(p_2-1);
        edges[p_2-1].push_back(p_1-1);
    }
}

void dfs(int current){
    visited[current] = true;
    for (auto &&i : edges[current]) if(!visited[i]) dfs(i);
}

void solve(){
    cin >> N >> M;
    edges = vector<vector<int>> (N);
    getInputs();
    FOR(i,N,0){
        if(visited[i]) continue;
        resp++;
        dfs(i);
        if(anterior != -1) resp_vt.push_back({anterior+1, i+1});
        anterior = i;
    }
    cout << (resp - 1) << "\n";
    for (auto &&i : resp_vt) cout << i.first << " " << i.second << "\n";
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
