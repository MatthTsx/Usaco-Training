#include<bits/stdc++.h>
// http://www.usaco.org/index.php?page=viewproblem2&cpid=923

using namespace std;
#define Max 200
vector<vector<int>> vt (Max + 2, vector<int> (Max + 2));
vector<vector<int>> ar (Max + 2, vector<int> (Max + 2));

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    
    int N, K, resp = 0;
    cin >> N >> K;

    while(N--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        vt[y1][x1]++;
        vt[y1][x2]--;
        vt[y2][x2]++;
        vt[y2][x1]--;
    }

    for(int i = 0; i <= Max; i++)
        for(int j = 0; j <= Max; j++){
            if(i) vt[i][j] += vt[i-1][j];
            if(j) vt[i][j] += vt[i][j-1];
            if(i && j) vt[i][j] -= vt[i-1][j-1];
            int diff = K - vt[i][j];
            ar[i][j] = diff == 1 ? 1 : diff == 0 ? -1 : 0;
            if(vt[i][j] == K) resp ++;

            if(i) ar[i][j] += ar[i-1][j];
            if(j) ar[i][j] += ar[i][j-1];
            if(i && j) ar[i][j] -= ar[i-1][j-1];
        }

    // TODO: Fix this part (not for now tho)
    int big1 = 0, big2 = 0;
    for(int r = 1; r <= Max; r++){
        int maior = 0, menor = 0;
        for(int c = 1; c <= Max; c++){
            maior = max(ar[c][r], maior);
            menor = min(ar[c][r], menor);
        }
        if(abs(big1 - big2) < abs(max(big1,big2) - maior) - menor){
            if(big1 < big2) big1 = maior - menor;
            else big2 = maior - menor;
        }
    }
    resp += big1 + big2;
    cout << resp;
    // for (auto &&i : ar)
    // {
    //     for (auto &&j : i)
    //         cout << j << " ";
    //     cout << endl;
    // }
    

    return 0;
}
