#include<bits/stdc++.h>
// https://cses.fi/problemset/task/1674
using namespace std;
#define FOR(i,N,ini) for(int i = ini; i < N; i++)

int N;
int pl; // placeholder
vector<int> Subords;
vector<unordered_map<int,bool>> adjs;

void dfs_tree(int index){
    for (auto &&i : adjs[index])
    {
        if(!i.second) continue;
        dfs_tree(i.first);
        Subords[index] += Subords[i.first];
    }
}

void getInputs(){
    cin >> N;
    Subords = vector<int> (N, 1);
    adjs = vector<unordered_map<int,bool>> (N);
    FOR(i,N,1){
        cin >> pl;
        adjs[--pl][i] = true;
    }
}

void solve(){
    getInputs();
    dfs_tree(0);
    for (auto &&i : Subords) cout << (i - 1) << " ";
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
