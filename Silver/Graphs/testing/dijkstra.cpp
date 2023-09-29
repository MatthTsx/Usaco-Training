#include<bits/stdc++.h>
// Test
using namespace std;
#define FOR(i,N,ini) for(int i=ini;i<N;i++)
#define f first
#define s second

int N, M;
int pl_1, pl_2, pl_3;
vector<unordered_map<int,int>> adjs;
vector<int> dist;
unordered_map<int,bool> visited;


void getInputs(){
    cin >> N >> M;
    dist = vector<int> (N,INT32_MAX);
    adjs = vector<unordered_map<int,int>> (N);
    FOR(i,M,0){
        cin >> pl_1 >> pl_2 >> pl_3;
        adjs[--pl_1][--pl_2] = pl_3;
        adjs[pl_2][pl_1] = pl_3;
    }
}

void dijkstra(int ind){
    priority_queue<pair<int,int>> PQ;
    dist[ind] = 0;
    PQ.push({0,ind});
    while(!PQ.empty()){
        auto vl = PQ.top();
        int cost = -vl.f;
        visited[vl.s] = true;
        PQ.pop();
        if(cost > dist[vl.second]) continue;
        for (auto &&i : adjs[vl.s])
        {
            if(visited[i.f]) continue;
            int dd = cost + i.s;
            if(dd < dist[i.first]){
                dist[i.first] = dd;
                PQ.push({-dd,i.first});
            }
        }
    }
}

void solve(){
    getInputs();
    dijkstra(0);
    for (auto &&i : dist)
    {
        cout << i << " ";
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
