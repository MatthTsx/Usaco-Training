#include<bits/stdc++.h>
// https://cses.fi/problemset/task/1641
using namespace std;
#define FOR(i,N) for (int i=0; i<N; i++)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;
    vector<pair<int,int>> vt (N);

    FOR(i, N){
        cin >> vt[i].first;
        vt[i].second = i+1;
    }

    sort(vt.begin(), vt.end());

    for (auto &&i : vt)
    {
        int ini = 0, fin = N-1;
        while(ini < fin){
            if(vt[ini].second == i.second) {ini++; continue;}
            if(vt[fin].second == i.second) {fin--; continue;}
            int sum = i.first + vt[ini].first + vt[fin].first;
            if(sum == K){
                vector<int> v = {i.second, vt[ini].second, vt[fin].second};
                sort(v.begin(), v.end());
                for(auto&& _v : v) cout << _v << " ";
                return 0;
            }
            if(sum > K) fin--;
            else ini++;
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}
