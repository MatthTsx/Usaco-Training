#include<bits/stdc++.h>
// https://codeforces.com/contest/1808/problem/B

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> anws (N,0);

    while(N--){
        int n,m;
        cin >> n >> m;
        vector<vector<int>> vt (n, vector<int> (m, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) cin >> vt[i][j];
        
        for(int i = 0; i + 1 < n; i++){
            for(int j = i + 1; j < n; j++)
                for(int b = 0; b < m; b++) anws[anws.size() - N - 1] += abs(vt[i][b] - vt[j][b]);
        }
    }

    for (auto &&i : anws)
        cout << i << '\n';
    

    return 0;
}
