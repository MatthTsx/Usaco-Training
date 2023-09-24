#include<bits/stdc++.h>
// http://www.usaco.org/index.php?page=viewproblem2&cpid=644
using namespace std;
#define FOR(i,N,ini) for(int i=ini;i<N;i++)

int N,M,K;
int a,b; // placeholders
vector<bool> visited;
unordered_map<int,bool> closed; // is faster for less complex inputs
// vector<bool> closed; // using vector is faster for more complex inputs
map<int, vector<int>> adjs;

int nodes = 0;

void dfs(int node){
    if(visited[node] || closed[node]) return;

    nodes++;
    visited[node] = true;
    for (auto &&i : adjs[node])
        if(!visited[i]) dfs(i);
}

void getInputs(){
    cin >> N >> M;
    visited = vector<bool> (N+1);
    // closed = vector<bool> (N+1);
    FOR(i,M,0){
        cin >> a >> b;
        adjs[a].push_back(b);
        adjs[b].push_back(a);
    }
}

void checkIfConnected(int minus){
    if(nodes == N - minus) cout << "YES\n";
    else cout << "NO\n";
}

void solve(){
    getInputs();

    deque<int> ord;
    FOR(i,N,0){
        cin >> a;
        ord.push_back(a);
    }

    dfs(1);
    checkIfConnected(false);

    FOR(i,N-1,0){
        nodes = 0;
        closed[ord.front()] = true;
        fill(visited.begin(), visited.end(), false);
        // visited.clear();

        dfs(ord.back());
        checkIfConnected(i+1);
        ord.pop_front();
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    freopen("closing.in","r",stdin);
    freopen("closing.out","w",stdout);
    solve();
    return 0;
}
