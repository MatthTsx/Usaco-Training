#include<bits/stdc++.h>
// http://www.usaco.org/index.php?page=viewproblem2&cpid=944
using namespace std;
#define FOR(i,N,ini) for(int i=ini;i<N;i++)
using ll = long long;
typedef pair<int,int> pii;

struct Moo{
    int maxX = INT32_MIN,
    minX = INT32_MAX,
    maxY = INT32_MIN,
    minY = INT32_MAX;
};

int N, M;
int pl_1, pl_2; // placeholders
ll resp = INT32_MAX;
vector<Moo> moos;
vector<pii> coords;
vector<vector<int>> adjs;
vector<bool> visited;

void dfs(int curr, int moo_index){
    visited[curr] = true;
    auto& moo = moos[moo_index];
    moo.maxX = max(moo.maxX, coords[curr].first);
    moo.minX = min(moo.minX, coords[curr].first);
    moo.maxY = max(moo.maxY, coords[curr].second);
    moo.minY = min(moo.minY, coords[curr].second);

    for (auto &&i : adjs[curr]) if(!visited[i]) dfs(i, moo_index);
}

void getInputs(){
    cin >> N >> M;
    visited = vector<bool> (N, false);
    FOR(i,N,0){
        cin >> pl_1 >> pl_2;
        coords.push_back({pl_1,pl_2});
    }
    adjs = vector<vector<int>> (N);
    FOR(i,M,0){
        cin >> pl_1 >> pl_2;
        pl_1--; pl_2--;
        adjs[pl_1].push_back(pl_2);
        adjs[pl_2].push_back(pl_1);
    }
}

void solve(){
    getInputs();

    int index = -1;
    FOR(i,N,0){
        if(visited[i]) continue;
        moos.push_back({});
        index++;
        dfs(i,index);
    }
    
    for (auto &&i : moos)
    {
        resp = min(resp, (ll) (i.maxX - i.minX + 1) * 2 + (i.maxY - i.minY + 1) * 2 - 4);
        // cout << "Max: " << i.maxX << " " << i.maxY << " || Min: " << i.minX << " " << i.minY << endl;
    }
    cout << resp;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    solve();
    return 0;
}
