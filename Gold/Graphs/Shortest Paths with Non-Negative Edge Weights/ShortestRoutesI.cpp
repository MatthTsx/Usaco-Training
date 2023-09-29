#include<bits/stdc++.h>
// https://cses.fi/problemset/task/1671
using namespace std;
#define FOR(i,N,ini) for(int i = 0; i < N; i++)
using ll = long long;
constexpr ll Big = 1e18;

int N, M;
ll pl_1, pl_2, pl_3; //placeholders
vector<ll> dist;
vector<unordered_map<int,ll>> adjs;
// unordered_map<int,bool> visited;

void getInputs(){
    cin >> N >> M;
    dist = vector<ll> (N, -69);
    adjs = vector<unordered_map<int,ll>> (N);
    FOR(i,M,0){
        cin >> pl_1 >> pl_2 >> pl_3;
        adjs[--pl_1][--pl_2] = pl_3;
    }
}

void dijkstra(int ind){
    priority_queue<pair<ll,int>> PQ;
    PQ.push({0, ind});
    dist[ind] = 0;
    while(!PQ.empty()){
        // auto [cost, id] = PQ.top();
        ll cost = PQ.top().first;
        int id = PQ.top().second;
        cost *= -1;
        // visited[id] = true;
        PQ.pop();
        // if(cost > dist[id] && dist[id] != -69) continue;
        if(cost != dist[id]) continue;
        for (auto &&i : adjs[id])
        {
            // if(visited[i.first]) continue;
            ll cc = i.second + cost;
            if(cc < dist[i.first] || dist[i.first] == -69){
                dist[i.first] = cc;
                PQ.push({-cc, i.first});
            }
        }
        
    }
}

void solve(){
    getInputs();
    dijkstra(0);
    // dist[0] = 0;
    for (auto &&i : dist)
    {
        if(i == -69) cout << "0 ";
        else cout << i << " ";
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
