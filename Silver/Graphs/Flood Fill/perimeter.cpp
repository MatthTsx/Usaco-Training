#include<bits/stdc++.h>
// http://www.usaco.org/index.php?page=viewproblem2&cpid=895
using namespace std;
#define FOR(i,N,ini) for(int i = ini; i < N; i++)

int N, maxArea = 0, Perimeter = 0;
char pl_1; // placeholder
vector<vector<int>> grid;
vector<pair<int,int>> coords;
vector<vector<bool>> visited;


void getInputs(){
    cin >> N;
    visited = vector<vector<bool>> (N, vector<bool> (N, false));
    grid = vector<vector<int>> (N, vector<int> (N));
    FOR(i,N,0)
        FOR(j,N,0){
            cin >> pl_1;
            grid[i][j] = pl_1;
            if(pl_1 == '#') coords.push_back({i,j});
        }
}



void FloodFill(int r, int c, int color, int& area, int& peri){
    if((r < 0 || r >= N || c < 0 || c >= N) || visited[r][c] || grid[r][c] != color) return;
    visited[r][c] = true;
    area ++;
    if(r+1 >= N) peri++;
    else if (grid[r+1][c] != color) peri++;

    if(r-1 < 0) peri++;
    else if (grid[r-1][c] != color) peri++;

    if(c+1 >= N) peri++;
    else if (grid[r][c+1] != color) peri++;

    if(c-1 < 0) peri++;
    else if (grid[r][c-1] != color) peri++;
    

    FloodFill(r+1,c,color,area, peri);
    FloodFill(r-1,c,color,area, peri);
    FloodFill(r,c+1,color,area, peri);
    FloodFill(r,c-1,color,area, peri);
}

void solve(){
    getInputs();
    for (auto &&i : coords)
    {
        if(visited[i.first][i.second]) continue;
        int area = 0;
        int peri = 0;
        FloodFill(i.first, i.second, grid[i.first][i.second], area, peri);
        if(area == maxArea) Perimeter = min (Perimeter, peri);
        else if (area > maxArea){
            maxArea = area;
            Perimeter = peri;
        }
    }
    cout << maxArea << " " << Perimeter;
}

int main(int argc, char const *argv[])
{
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
