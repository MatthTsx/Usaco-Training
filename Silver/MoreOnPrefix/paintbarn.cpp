#include<bits/stdc++.h>
// http://www.usaco.org/index.php?page=viewproblem2&cpid=919
// Files: paintbarn.in && paintbarn.out
using namespace std;
#define Max 1000

using v = int[Max+2][Max+2];
v vt;

int N, K;

int main(){
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> K;

    while(N--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = y1; i < y2; i++)
        {
            vt[i][x1]++;
            vt[i][x2]--;
        }
    }
    int resp = 0;
    for (size_t i = 1; i <= Max; i++)
        for (size_t j = 1; j <= Max; j++)
        {
            if(vt[i][j] == K) resp++;
            vt[i][j+1] += vt[i][j];
        }
        
    cout << resp;
}
