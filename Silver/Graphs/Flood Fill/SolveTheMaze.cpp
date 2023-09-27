#include<bits/stdc++.h>
// https://codeforces.com/contest/1365/problem/D
using namespace std;
#define FOR(i,N,ini) for(int i =ini; i < N; i++)
typedef pair<int,int> pii;
#define x first
#define y second

int N, re, ideal;
int pl_1, pl_2; // placeholders
char pl_3;
vector<vector<bool>> visited;
vector<vector<char>> grid;
vector<pii> Bads;

vector<pii> getNeighbors(pii coords){
    return {
        {coords.x + 1, coords.y},
        {coords.x - 1, coords.y},
        {coords.x, coords.y + 1},
        {coords.x, coords.y - 1},
    };
}

void floodFill(pii c, int& r){
    if((c.x < 0 || c.x >= pl_1 || c.y < 0 || c.y >= pl_2) || visited[c.x][c.y] || grid[c.x][c.y] == '#') return;
    visited[c.x][c.y] = true;
    if(grid[c.x][c.y] == 'G') r++;

    for (auto &&i : getNeighbors(c))
        floodFill(i, r);
}

bool exilateBad(){
    for (auto &&b : Bads)
        for (auto &&i : getNeighbors(b))
        {
            if(i.x < 0 || i.y < 0 || i.x >= pl_1 || i.y >= pl_2) continue;
            if(grid[i.x][i.y] == 'G') return false;
            else if (grid[i.x][i.y] == '.') grid[i.x][i.y] = '#';
        }
    
    return true;
}

void solve(){
    cin >> N;
    while(N--){
        cin >> pl_1 >> pl_2;
        ideal = 0; re = 0;
        Bads.clear();
        visited = vector<vector<bool>> (pl_1, vector<bool> (pl_2, false));
        grid = vector<vector<char>> (pl_1, vector<char> (pl_2));
        FOR(i,pl_1, 0)
            FOR(j,pl_2,0){
                cin >> pl_3;
                grid[i][j] = pl_3;
                if(pl_3 == 'B') Bads.push_back({i,j});
                else if (pl_3 == 'G') ideal++;
            }
        if(!exilateBad()) cout << "NO\n";
        else {
            floodFill({pl_1-1,pl_2-1}, re);
            if(re == ideal) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}