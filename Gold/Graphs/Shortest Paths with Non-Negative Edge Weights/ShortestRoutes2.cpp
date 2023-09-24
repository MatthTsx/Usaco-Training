#include<bits/stdc++.h>
// https://cses.fi/problemset/task/1672
using namespace std;
#define FOR(i,N,ini) for(int i=ini;i<N;i++)

using ll = long long;
constexpr long long BIG = 1e18;
typedef pair<int,int> pii;

int N, M, Q;
int p_1, p_2, p_3; // placeholders (beleza++)

vector<vector<ll>> vt; // distancias
queue<pii> queries;

void FloydWarshall(){
    FOR(k,N,0)
        FOR(i,N,0)
            FOR(j,N,0)
                vt[i][j] = vt[j][i] = min(vt[i][j], vt[i][k] + vt[k][j]);
}

void getInputs(){
    cin >> N >> M >> Q;
    vt = vector<vector<ll>> (N, vector<ll> (N, BIG));
    FOR(i,M,0){
        cin >> p_1 >> p_2 >> p_3;
        p_1--; p_2--;
        if(p_3 < vt[p_1][p_2]) vt[p_1][p_2] = vt[p_2][p_1] = p_3;
    }
    FOR(i,Q,0){
        cin >> p_1 >> p_2;
        p_1--; p_2--;
        queries.push({p_1,p_2});
    }
}

void output(){
    while(!queries.empty()){
        pii c = queries.front();
        queries.pop();
        if(c.first == c.second){
            cout << "0\n";
            continue;
        }
        ll vl = vt[c.first][c.second];
        if(vl == BIG) cout << -1 << "\n";
        else cout << vl << "\n";
    }
}

void solve(){
    getInputs();
    FloydWarshall();
    output();
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie(0);
    solve();
    return 0;
}
