#include<bits/stdc++.h>
// http://www.usaco.org/index.php?page=viewproblem2&cpid=716
#define FOR(i,N,ini) for(int i = ini; i < N; i++)
using namespace std;
typedef pair<int,int> pii;

struct Road{
    int x1, x2, y1, y2;
    bool operator<(const Road& other) const {return tie(other.x1,other.x2,other.y1,other.y2) < tie(x1,x2,y1,y2);}
};

int N, K, R;
int pl_1, pl_2, pl_3, pl_4; // placeholders
vector<vector<int>> grid;
vector<vector<bool>> visited;
set<Road> Roads;
// vector<vector<pii>> Roads;
vector<pii> Cows_Coords;

void getInputs(){
    cin >> N >> K >> R;
    grid = vector<vector<int>> (N, vector<int> (N, 0));
    visited = vector<vector<bool>> (N, vector<bool> (N, false));
    FOR(i,R,0){
        cin >> pl_1 >> pl_2 >> pl_3 >> pl_4;
        Roads.insert({--pl_1,--pl_3,--pl_2,--pl_4});
        Roads.insert({pl_3,pl_1,pl_4,pl_2});
    }
    FOR(i,K,0){
        cin >> pl_1 >> pl_2;
        pl_1--; pl_2--;
        Cows_Coords.push_back({pl_1,pl_2});
        grid[pl_1][pl_2] = true;
    }
}

int floodFill(int r, int c, int prevR, int prevC){
    if((r < 0 || r >= N || c < 0 || c >= N) || visited[r][c] || Roads.count({r,prevR,c,prevC})) return 0;
    visited[r][c] = true;
    int cows = grid[r][c];

    cows += floodFill(r+1, c, r, c);
    cows += floodFill(r-1, c, r, c);
    cows += floodFill(r, c+1, r, c);
    cows += floodFill(r, c-1, r, c);

    return cows;
}

void solve(){
    getInputs();

    vector<int> pairs;
    int resp = 0;
    for (auto &&i : Cows_Coords)
    {
        if(visited[i.first][i.second]) continue;
        int ff = floodFill(i.first, i.second, i.first, i.second);
        if(ff != 0) pairs.push_back(ff);
    }
    
    FOR(i, pairs.size(), 0)
        FOR(j, pairs.size(), i+1)
            resp += pairs[i] * pairs[j];
    cout << resp;
}

int main(int argc, char const *argv[])
{
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
