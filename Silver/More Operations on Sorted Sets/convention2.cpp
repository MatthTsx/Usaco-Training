#include<bits/stdc++.h>
// http://www.usaco.org/index.php?page=viewproblem2&cpid=859
using namespace std;
#define FOR(i,N,ini) for(int i=ini;i<N;i++)

struct Cow{
    int initial_time, final_time, priority;
    bool operator<(const Cow& c) const {return initial_time < c.initial_time;}
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    freopen("convention2.in", "r", stdin);
    int N, resp = 0;
    cin >> N;
    
    multiset<Cow> cows {{-1,-1,-1}};
    FOR(i,N,0){
        int initial, _final;
        cin >> initial >> _final;
        cows.insert({initial, _final, i});
    }

    set<Cow> waiting;
    auto curr = cows.begin();
    int initial = curr->initial_time, final_ = curr->final_time;
    int qntd = 1, time = 0;

    int ccc = N;

    while( (qntd < N || !waiting.empty()) && ccc > 0){
        ccc--;
        auto next = cows.upper_bound({time});

        if(next != cows.begin()) next--;
        if(next == curr) next++;

        int qnt = distance(curr, next);
        auto dd = next;

        FOR(i, qnt, 0){
            waiting.insert(*dd);
            advance(dd, -1);
        }

        auto prio = waiting.end();
        if(waiting.size() > 0) prio--;
        // cout << prio->priority << " " << next->initial_time << " " << (time - prio->initial_time) << endl;

        resp = max(time - prio->initial_time, resp);
        curr = next;
        waiting.erase(*prio);
        if(prio->initial_time > time) time = prio->initial_time;
        time += prio->final_time;
        qntd++;
    }
    freopen("convention2.out", "w", stdout);
    cout << resp;
    return 0;
}
