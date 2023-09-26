#include<bits/stdc++.h>
// https://cses.fi/problemset/task/1192
using namespace std;
#define FOR(i,N,ini) for(int i = ini; i< N; i++)

int N, M, resp = 0;
char pl_1;
vector<vector<int>> grid;
vector<vector<bool>> visited;
vector<pair<int,int>> coords;


void getInputs(){
    cin >> N >> M;
    grid = vector<vector<int>> (N, vector<int> (M));
    visited = vector<vector<bool>> (N, vector<bool> (M));
    FOR(i, N, 0)
        FOR(j, M, 0){
            cin >> pl_1;
            grid[i][j] = pl_1;
            if(pl_1 == '.') coords.push_back({i,j});
        }
}

void floodFill(int r, int c, int color){
    if((r < 0 || r >= N || c < 0 || c >= M) || visited[r][c] || grid[r][c] != color)
        return;
    visited[r][c] = true;
    floodFill(r + 1, c, color);
    floodFill(r - 1, c, color);
    floodFill(r, c - 1, color);
    floodFill(r, c + 1, color);
}

void solve(){
    getInputs();
    for (auto &&i : coords)
    {
        if(visited[i.first][i.second]) continue;
        resp++;
        floodFill(i.first, i.second, grid[i.first][i.second]);
    }
    cout << resp;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
