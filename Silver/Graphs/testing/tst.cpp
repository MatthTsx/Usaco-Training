#include<bits/stdc++.h>
using namespace std;
// test
#define FOR(i,N,ini) for(int i = ini; i < N; i++)
using ll = long long;
#define f first
#define s second

unordered_map<int,bool> visited;
vector<vector<int>> grid;
vector<unordered_map<int,bool>> adjs;
void dfs(int start){
    visited[start] = true;
    // logica
    for (auto &&i : adjs[start])
    {
        if(!visited[i.first] && i.second){
            dfs(i.first);
            // logica
        }
    }
}

auto bfs = [&](int id){
    queue<int> dq;
    dq.push(id);
    while(!dq.empty()){
        auto d = dq.front();
        dq.pop();
        visited[d] = true;
        for (auto &&i : adjs[d])
        {
            if(visited[i.first] || !i.second) continue;
            dq.push(i.first);
        }
    }
};

int R, C;
vector<unordered_map<int,bool>> visited2D;
void floorFill(pair<int,int> coord){
    if((coord.f < 0 || coord.s < 0 || coord.s >= C || coord.f >= R) || visited2D[coord.f][coord.s]) return;
    // logic;
    visited2D[coord.f][coord.s] = true;
    for (auto &&i : getNeighbors(coord))
        floorFill(i);
}

vector<pair<int,int>> getNeighbors(pair<int,int> coords){
    return {
        {coords.f, coords.s+1},
        {coords.f, coords.s-1},
        {coords.f+1, coords.s},
        {coords.f-1, coords.s},
    };
}

vector<vector<ll>> dist; // inicia a 1e18 (long long) ou INT32_MAX (integer) ou número negativo, em quaso de n ter distancia negativa
int qntN; // qntidade de x (exemplo: cidades)
void floydWarshall(){
    FOR(k,qntN,0)
    FOR(i,qntN,0)
    FOR(j,qntN,0)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        // ou em caso das arestas forem bidimensionais:
        // dist[i][j] = dist[j][i] = min(dist[j][i], dist[i][k] + dist[k][j]);
}

vector<int> distD;
void dijkstra(int c){
    priority_queue<pair<ll,int>> pq;
    pq.push({0, c});
    distD[c] = 0;
    while(!pq.empty()){
        auto [cost, id] = pq.top();
        cost *= -1;
        visited[id] = true;
        for (auto &&i : adjs[id]) // suponha adjs = vector<unordered_map<int,ll>>
        {
            if(visited[i.first]) continue;
            ll value = cost + i.second;
            if(value < distD[i.first]){
                distD[i.first] = value;
                pq.push({-value, i.first});
            }
        }
    }
}

void sorting(){
    multiset<int> mts;
    auto thing = mts.upper_bound(0); // primeiro item maior que 0
    if(thing != mts.end()) cout << *thing; // caso existir esse item, o imprima
    
    auto thing2 = mts.lower_bound(0); // primeiro item maior ou igual a 0
    if(thing2 != mts.end()) cout << *thing2; // caso exista, imprima

    auto thing3 = thing;
    --thing3; // primeiro item menor que 0
    if(thing3 != mts.begin()) cout << *thing3; // caso exista, imprima

    // dequeue, queue, set, map, vector, unordered_map, priority_queue

    set<int,bool (*)(const int& f, const int& s)> se_t ([](const int& f, const int& s){return f < s;});
    
}

void prefix(){
    vector<vector<int>> prefix2D;
    int inputVal;
    prefix2D[2][2] = prefix2D[2-1][2] + prefix2D[2][2-1] - prefix2D[2-1][2-1] + inputVal; // the setup

    auto find = [&](int x, int y, int x2, int y2){
        return prefix2D[x][y] - prefix2D[x][y2] - prefix2D[x2][y] + prefix2D[x2][y2]; // the sum in the coordinates denoted
    };
}


int longest = 0;
int getDiameter(int c){
    visited[c] = true;
    int dist1 = 0, dist2 = 0;

    for (auto &&i : adjs[c])
    {
        if(visited[i.first]) continue;
        // sem pesos
        int rr = 1;
        // com:
        // int rr = i.second;
        rr += getDiameter(i.first);
        if(rr > min(dist1, dist2)){
            if(dist1 < dist2) dist1 = rr;
            else dist2 = rr;
        }
    }

    longest = max(longest, dist1 + dist2);
    return max(dist1, dist2);
}

int gcd (int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}