#include<bits/stdc++.h>
// http://www.usaco.org/index.php?page=viewproblem2&cpid=668
using namespace std;
#define FOR(i,N) for(int i=0; i< N; i++)

int N;
int p_1, p_2, p_3; // placeholders
vector<unordered_map<int,bool>> canConnect;
unordered_map<int,bool> visited;

int dfs(int c){
    visited[c] = true;
    int resp = 1;
    for (auto &&i : canConnect[c])
        if(!visited[i.first] && i.second) {
            visited[i.first] = true;
            resp += dfs(i.first);
        }
    return resp;
}

void getInputs(){
    cin >> N;
    canConnect = vector<unordered_map<int,bool>> (N);

    vector<int> power (N);
    vector<pair<int,int>> coords (N);
    FOR(i,N){
        cin >> p_1 >> p_2 >> p_3;
        p_1; p_2;
        power[i] = p_3;
        coords[i] = {p_1, p_2};
    }

    FOR(i,N){
        long long _pow = pow(power[i],2);
        FOR(j,N){
            long long dist = pow(coords[i].first - coords[j].first, 2) + pow(coords[i].second - coords[j].second, 2); // Pitagoras
            if(dist <= _pow) canConnect[i][j] = true;
        }
    }
    // FOR(i, N){
    //     cout << i << ": ";
    //     for (auto &&j : canConnect[i])
    //     {
    //         if(!j.second) continue;
    //         cout << j.first << " ";
    //     }
    //     cout << endl;
    // }
}

void solve(){
    getInputs();
    int resp = 0;
    FOR(i,N){
        visited.clear();
        resp = max(resp, dfs(i));
    }
    cout << resp;
}

int main(int argc, char const *argv[])
{
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
