#include<bits/stdc++.h>
// http://www.usaco.org/index.php?page=viewproblem2&cpid=716
#define FOR(i,N,ini) for(int i = ini; i < N; i++)
using namespace std;
typedef pair<int,int> pii;

struct Road{
    int maxX, minX, maxY, minY;
};

int N, K, R;
int pl_1, pl_2, pl_3, pl_4; // placeholders
vector<vector<int>> grid;
vector<vector<bool>> visited;
vector<Road> Roads;
// vector<vector<pii>> Roads;
vector<pii> Cows_Coords;

void getInputs(){
    cin >> N >> K >> R;
    grid = vector<vector<int>> (N, vector<int> (N, 0));
    visited = vector<vector<bool>> (N, vector<bool> (N, false));
    FOR(i,R,0){
        cin >> pl_1 >> pl_2 >> pl_3 >> pl_4;
        pl_1--;pl_2--;pl_3--;pl_4--;
        Roads.push_back({
            max(pl_1,pl_3),
            min(pl_1,pl_3),
            max(pl_2,pl_4),
            min(pl_2,pl_4)
        });
    }
    FOR(i,K,0){
        cin >> pl_1 >> pl_2;
        pl_1--; pl_2--;
        Cows_Coords.push_back({pl_1,pl_2});
    }
}

void floodFill(int r, int c){
    if((r < 0 || r >= N || c < 0 || c >= N) || visited[r][c]) return;
    visited[r][c] = true;
    
    if(find_if(Roads.begin(), Roads.end(), [&](Road& Ro){return Ro.maxX == r+1 && Ro.minX == r && Ro.maxY == c && Ro.minY == c;}) == Roads.end())
        floodFill(r+1, c);
    if(find_if(Roads.begin(), Roads.end(), [&](Road& Ro){return Ro.maxX == r && Ro.minX == r-1 && Ro.maxY == c && Ro.minY == c;}) == Roads.end())
        floodFill(r-1, c);

    if(find_if(Roads.begin(), Roads.end(), [&](Road& Ro){return Ro.maxX == r && Ro.minX == r && Ro.maxY == c+1 && Ro.minY == c;}) == Roads.end())
        floodFill(r, c+1);
    if(find_if(Roads.begin(), Roads.end(), [&](Road& Ro){return Ro.maxX == r && Ro.minX == r && Ro.maxY == c && Ro.minY == c-1;}) == Roads.end())
        floodFill(r, c-1);
}

void solve(){
    getInputs();

    int resp = 0;
    for (auto &&i : Cows_Coords)
    {
        if(visited[i.first][i.second]) continue;
        floodFill(i.first, i.second);
        resp++;
    }
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
