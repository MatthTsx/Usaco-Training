#include<bits/stdc++.h>

using namespace std;
using ll = long long;

vector<vector<int>> v;
vector<vector<int>> v45deg;

int N, M;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int s1 = M + N - 1;
    v = vector<vector<int>> (N+1, vector<int> (M+1, 0));
    v45deg = vector<vector<int>> (s1, vector<int> (s1, 0));

    for (size_t i = 1; i <= N; i++) 
        for (size_t j = 1; j <= M; j++) cin >> v[i][j];
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            // v45deg[i][j] = v[i][j] + v45deg[i-1][j] + v45deg[i][j-1] - v45deg[i-1][j-1];
            v45deg[i+j][N - i + j - 1] = v[i+1][j+1];
        }
    
    for (auto &&i : v45deg)
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}