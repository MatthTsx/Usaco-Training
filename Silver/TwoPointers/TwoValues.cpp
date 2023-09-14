#include<bits/stdc++.h>
// https://cses.fi/problemset/task/1640

using namespace std;
#define FOR(i,N) for (int i = 0; i < N; i++)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, x, resp = 0;
    cin >> N >> x;
    vector<pair<int,int>> values (N);

    FOR(i, N) {
        cin >> values[i].first;
        values[i].second = i+1;
    };

    sort(values.begin(), values.end());

    int ini = 0, fin = N-1;
    while(ini < fin){
        int sum = values[ini].first + values[fin].first;
        if(sum == x){
            resp++;
            cout << min(values[ini].second, values[fin].second) << " " << max(values[fin].second, values[ini].second) << endl;
            return 0;
        }
        if(sum > x) fin--;
        else ini++;
    }

    cout << "IMPOSSIBLE";
    return 0;
}
