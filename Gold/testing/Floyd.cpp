#include<bits/stdc++.h>
// just a test for Floyd-Warshall's algorithm
using namespace std;
// constexpr long long BIG = 1e18;
constexpr long long BIG = 1e16;
#define FOR(i,N,ini) for(int i =ini;i<N;i++)
typedef pair<int,int> pii;

int N, M, Q;
int p_1, p_2, p_3; // placeholders
vector<vector<long long> > vt;
queue<pii> queries;


void getInputs(){
    cin >> N >> M >> Q;
    vt = vector<vector<long long>> (N, vector<long long> (N,BIG));
    FOR(i,M,0){
        cin >> p_1 >> p_2 >> p_3;
        p_1--; p_2--; p_3;
        vt[p_1][p_2] = p_3;
    }
    FOR(i,Q,0){
        cin >> p_1 >> p_2;
        p_1--; p_2--;
        queries.push({p_1,p_2});
    }
}

void FloydWarshall(){
    FOR(k,N,0)
        FOR(i,N,0)
            FOR(j,N,0){
                vt[i][j] = min(vt[i][j], vt[i][k] + vt[k][j]);
            }
}

void output(){
    while(!queries.empty()){
        pii c = queries.front();
        cout << vt[c.first][c.second] << endl;
        queries.pop();
    }
}

void solve(){
    getInputs();
    FloydWarshall();
    cout << endl;
    output();
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
