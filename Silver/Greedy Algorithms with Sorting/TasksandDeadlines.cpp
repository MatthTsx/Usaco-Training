#include<bits/stdc++.h>
// https://cses.fi/problemset/task/1630
using namespace std;
#define FOR(i,N,ini) for(int i=ini;i<N;i++)
using ll = long long;

struct Task{
    int time, deadline;
    bool operator<(const Task& t) const { return time < t.time;}
};

int N, pl_chld1, pl_chld2;
ll points = 0, curr_time = 0;
multiset<Task> mts;
void solve(){
    cin >> N;
    FOR(i,N,0){
        cin >> pl_chld1 >> pl_chld2;
        mts.insert({pl_chld1, pl_chld2});
    }

    for (auto &&i : mts)
    {
        // cout << i.time << " " << i.deadline << endl;
        curr_time += i.time;
        points += i.deadline - curr_time;
    }
    cout << points;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
