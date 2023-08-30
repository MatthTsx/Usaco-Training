#include<bits/stdc++.h>
// http://www.usaco.org/index.php?page=viewproblem2&cpid=919
// Files: paintbarn.in && paintbarn.out

#define Max 1000
using namespace std;
using v = int[Max+1][Max+1];
int N, K;
v vt;

int main(){
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    while(N--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        vt[y1][x1]++;
        vt[y1][x2]--;
        vt[y2][x2]++;
        vt[y2][x1]--;
    }

    int resp = 0;
    for (int i = 0; i <= Max; i++)
        for (int j = 0; j <= Max; j++)
        {
            if(i) vt[i][j] += vt[i-1][j];
            if(j) vt[i][j] += vt[i][j-1];
            if(i && j) vt[i][j] -= vt[i-1][j-1];
            // cout << vt[i][j] << " ";
            if(vt[i][j] == K) resp++;
        }
    cout << resp;
}