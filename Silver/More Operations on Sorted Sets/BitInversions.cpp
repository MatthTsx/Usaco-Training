#include <bits/stdc++.h>
// https://cses.fi/problemset/task/1188
using namespace std;
// TODO: WRONG
#define FOR(i, N, ini) for (int i = ini; i < N; i++)
#define one first
#define zero second

pair<multiset<int>, multiset<int>> Distances{{0}, {0}};
pair<set<int>, set<int>> BitsLocation{{0}, {0}};

void getFirstDistances(string str)
{
    bool zeroAtual = false;
    int dist = 0;
    FOR(i, (int)str.size() + 1, 1)
    {
        char c = str[i - 1];
        if (c == '0')
        {
            if (zeroAtual)
                dist++;
            else
            {
                if (dist)
                    Distances.one.insert(dist);
                dist = 1;
                zeroAtual = true;
            }
            BitsLocation.zero.insert(i);
        }
        else
        {
            BitsLocation.one.insert(i);
            if (!zeroAtual)
                dist++;
            else
            {
                if (dist)
                    Distances.zero.insert(dist);
                dist = 1;
                zeroAtual = false;
            }
        }
        Distances.zero.insert(0);
        Distances.one.insert(0);
    }
    if (zeroAtual)
        Distances.zero.insert(dist);
    else
        Distances.one.insert(dist);
}

void handleZero(int vl)
{
    auto point_front = BitsLocation.one.upper_bound(vl);
    auto point_back = point_front;
    point_back--;
    int distance_ = *point_front - *point_back - 1;
    if (distance_)
    {
        auto ds = Distances.zero.find(*point_front - *point_back - 1);
        Distances.zero.erase(ds);
        Distances.zero.insert(vl - *point_back - 1);
        Distances.zero.insert(*point_front - vl - 1);
    }
    auto point_front2 = BitsLocation.zero.upper_bound(vl);
    auto point_back2 = point_front2;
    point_back2--;
    point_back2--;

    int distance2_ = *point_front2 - *point_back2 - 1;
    if (distance2_)
    {
        auto p1 = Distances.one.find(*point_front2 - vl - 1), p2 = Distances.one.find(vl - *point_back2 - 1);
        if (*p1 > 0)
            Distances.one.erase(p1);
        if (*p2 > 0)
            Distances.one.erase(p2);
        Distances.one.insert(distance2_);
    }
    else
    {
        Distances.one.insert(1);
    }
    BitsLocation.zero.erase(vl);
    BitsLocation.one.insert(vl);
}

void handleOne(int vl)
{
    auto point_front = BitsLocation.zero.upper_bound(vl);
    auto point_back = point_front;
    point_back--;
    int distance_ = *point_front - *point_back - 1;
    if (distance_)
    {
        auto ds = Distances.one.find(*point_front - *point_back - 1);
        Distances.one.erase(ds);
        Distances.one.insert(vl - *point_back - 1);
        Distances.one.insert(*point_front - vl - 1);
    }
    auto point_front2 = BitsLocation.one.upper_bound(vl);
    auto point_back2 = point_front2;
    point_back2--;
    point_back2--;

    int distance2_ = *point_front2 - *point_back2 - 1;
    if (distance2_)
    {
        auto p1 = Distances.zero.find(*point_front2 - vl - 1), p2 = Distances.zero.find(vl - *point_back2 - 1);
        if (*p1 > 0)
            Distances.zero.erase(p1);
        if (*p2 > 0)
            Distances.zero.erase(p2);
        Distances.zero.insert(distance2_);
    }
    else
    {
        Distances.zero.insert(1);
    }
    BitsLocation.one.erase(vl);
    BitsLocation.zero.insert(vl);
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    getline(cin, str);
    int N = str.size(), M;
    cin >> M;

    Distances.zero.insert(N + 1);
    Distances.one.insert(N + 1);
    BitsLocation.zero.insert(N + 1);
    BitsLocation.one.insert(N + 1);
    getFirstDistances(str);

    FOR(i, M, 0)
    {
        int vl;
        cin >> vl;
        bool isInitialZero = str[vl - 1] == '0';
        if (isInitialZero)
            handleZero(vl);
        else
            handleOne(vl);
        cout << max(*(-- --Distances.zero.end()), *(-- --Distances.one.end())) << " ";
    }

    return 0;
}
