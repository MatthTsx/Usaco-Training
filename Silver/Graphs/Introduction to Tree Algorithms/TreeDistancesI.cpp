#include<bits/stdc++.h>
// https://cses.fi/problemset/task/1132
using namespace std;
#define FOR(i, N, ini) for(int i=0;i<N;i++)

int N;
int pl_1, pl_2;
vector<unordered_map<int,bool>> adjs;
unordered_map<int,bool> visited;

void getInputs(){
    cin >> N;
    adjs = vector<unordered_map<int,bool>> (N);
    FOR(i,N,1){
        cin >> pl_1 >> pl_2;
        adjs[--pl_1][pl_2] = true;
        adjs[pl_2][pl_1] = true;
    }
}
void solve(){
    getInputs();
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
