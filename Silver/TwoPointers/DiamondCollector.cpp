#include<bits/stdc++.h>
// http://www.usaco.org/index.php?page=viewproblem2&cpid=643

using namespace std;

#define FOR(i,N) for (int i = 0; i < N; i++)
using ll = long long;
// bool comp(int a, int b) {return(a < b);}

struct First{
    ll qnt, ini, fin;
};

int main(int argc, char const *argv[])
{
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll N, K;
    cin >> N >> K;
    vector<ll> vls (N);
    First f1 {0,-1,-1};
    int f2 = 0;

    FOR(i, N) cin >> vls[i];
    sort(vls.begin(), vls.end());

    int in = 0, fin = 1;

    while(fin < N){
        int vl1 = vls[in], vl2 = vls[fin];
        if(vl2 - vl1 > K){
            in++;
            continue;
        }
        if(fin - in + 1 > f1.qnt){
            f1.qnt = fin - in + 1;
            f1.ini = in;
            f1.fin = fin;
        }
        fin++;
    }

    in = 0;
    fin = 1;
    while(fin < N){
        if(in >= f1.ini && fin <= f1.fin){
            in = f1.fin;
            fin = in+1;
            continue;
        }
        int vl1 = vls[in], vl2 = vls[fin];
        if(vl2 - vl1 > K){
            in++;
            continue;;
        }
        f2 = max(f2, fin - in + 1);
        fin++;
    }

    cout << f1.qnt + f2;
    return 0;
}
