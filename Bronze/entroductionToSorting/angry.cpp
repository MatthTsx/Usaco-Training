#include<bits/stdc++.h>
// http://www.usaco.org/index.php?page=viewproblem2&cpid=592

using namespace std;
#define FOR(i,N) for(int i=0; i < N; i++)
using ll = long long;

enum Direction{
    LEFT,
    RIGHT
};

set<int> cows;

int chain(int id, int qnt, Direction D, int vl = 0){
    auto curr = cows.lower_bound(id);
    if(D == LEFT) {
        if(curr == cows.begin()) return vl;
        auto next = cows.lower_bound(id - qnt);
        auto dist = distance(next, curr);
        if(dist == 0) return vl;
        return chain(*next, qnt + 1, D, vl + dist);
    }
    if(curr == --cows.end()) return vl;
    auto next = --cows.upper_bound(id + qnt);
    auto dist = distance(curr, next);
    if(dist == 0) return vl;
    return chain(*next, qnt + 1, D, vl + dist);
}

int main(int argc, char const *argv[])
{
    freopen("angry.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, maxVl = 0;
    cin >> N;

    FOR(i, N) {
        int vl;
        cin >> vl;
        cows.insert(vl);
    }

    freopen("angry.out", "w", stdout);
    for (auto &&i : cows){
        int r = chain(i,1,RIGHT);
        int l = chain(i,1,LEFT);
        // cout << "\n\n[ " << i << ": " << l << " " << r << " ]\n\n";
        maxVl = max(maxVl, r + l + 1);
    }

    cout << maxVl;
    return 0;
}
