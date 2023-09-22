#include <bits/stdc++.h>
// http://www.usaco.org/index.php?page=viewproblem2&cpid=763
using namespace std;
#define FOR(i, N, ini) for (int i = ini; i < N; i++)
#define FORR(i, N) for (auto &&i : N)

struct LOG
{
    int day, id, dif;
    bool operator<(LOG &l) { return day < l.day; }
};

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    int N, G;
    cin >> N >> G;

    vector<LOG> logs(N);
    multiset<int> mts{G};
    map<int, pair<int, bool>> cows;
    int biggest = G, qnt = 1, resp = 0, alone_id = 0;

    FOR(i, N, 0)
    cin >> logs[i].day >> logs[i].id >> logs[i].dif;

    sort(logs.begin(), logs.end());

    FORR(i, logs)
    {
        if (cows[i.id].second == true)
            mts.erase(mts.find(*mts.lower_bound(cows[i.id].first)));
        if (!cows[i.id].second)
        {
            cows[i.id].first = G;
            cows[i.id].second = true;
            if (i.dif < 0 && biggest == G)
                resp++;
        }
        cows[i.id].first += i.dif;
        mts.insert(cows[i.id].first);

        if (*--mts.end() != biggest)
        {
            biggest = *--mts.end();
            qnt = mts.count(biggest);
            if (alone_id == i.id && *--mts.end() == cows[i.id].first && qnt == 1)
            {
            }
            else
                resp++;
            if (qnt != 1)
                continue;
            auto ff = find_if(cows.begin(), cows.end(), [biggest](const pair<int, pair<int, int>> &el)
                              { return el.second.first == biggest; });
            alone_id = ff->first;
            continue;
        }
        if (mts.count(biggest) != qnt)
        {
            qnt = mts.count(biggest);
            alone_id = 0;
            resp++;
        }
    }
    cout << resp;
}