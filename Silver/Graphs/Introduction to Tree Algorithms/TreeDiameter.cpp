#include<bits/stdc++.h>
// https://cses.fi/problemset/task/1131
using namespace std;
#define FOR(i,N,ini) for(int i = ini; i < N; i++)

vector<unordered_map<int,bool>> adjs;
unordered_map<int,bool> visited;
int longest = 0, N;
int ph_1, ph_2; // placehoolder

void getInputs(){
    cin >> N;
    adjs = vector<unordered_map<int,bool>> (N);

    FOR(i,N,1){
        cin >> ph_2 >> ph_1;
        adjs[--ph_2][--ph_1] = true;
        adjs[ph_1][ph_2] = true;
    }
}

int dfs_tree(int index){
    int dist1 = 0, dist2 = 0;
    visited[index] = true;
    for (auto &&i : adjs[index])
    {
        if(visited[i.first]) continue;
        int rr = 1;
        rr += dfs_tree(i.first);
        if(rr > min(dist1, dist2)){
            if(dist1 < dist2) dist1 = rr;
            else dist2 = rr;
        }
    }
    longest = max(longest, dist1 + dist2);
    return max(dist1, dist2);
}

void solve(){
    getInputs();
    dfs_tree(0);
    // FOR(i,N,0){
    //     visited.clear();
    //     dfs_tree(i);
    // }
    cout << longest;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
