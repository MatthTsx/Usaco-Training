#include<bits/stdc++.h>
// https://cses.fi/problemset/task/1682
using namespace std;
#define FOR(i,N,ini) for(int i =ini; i< N; i++)

int N, M;
int pl_1, pl_2; // placeholders
vector<bool> visited;
vector<vector<int>> adjs;

void getInputs(){
    cin >> N >> M;
    adjs = vector<vector<int>> (N);
    visited = vector<bool> (N, false);

    FOR(i,M,0){
        cin >> pl_1 >> pl_2;
        pl_1--; pl_2--;
        adjs[pl_1].push_back(pl_2);
    }
}

void solve(){
    getInputs();
    auto bfs = [&](int curr){
        queue<int> q;
        int qnt = 0;
        q.push(curr);
        while(!q.empty()){
            int c = q.front();
            qnt++;
            q.pop();
            visited[c] = true;
            for (auto &&i : adjs[c])
                if(!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
        }
        return qnt;
    };
    FOR(i,N,0){
        fill(visited.begin(), visited.end(), false);
        if(bfs(i) < N){
            cout << "NO\n";
            FOR(j,N,0)
                if(!visited[j]) {
                    cout << i + 1 << " " << j+1;
                    break;
                }
            return;
        }
    }
    cout << "YES";
}

int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    solve();
    return 0;
}
