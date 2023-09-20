#include <bits/stdc++.h>
// https://cses.fi/problemset/task/1188
using namespace std;

#define FOR(i, N) for (int i = 0; i < N; i++)

int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    string str;
    cin >> str;

    int N = str.size(), K;

    // parecido cm os das luzes
    set<int> Ones{0, N + 1};
    multiset<int> Distances;

    int __distance = 0;
    FOR(i, N)
    {
        if (str[i] == '1')
        {
            Ones.insert(i + 1);
            if (!i)
                continue;
            Distances.insert(__distance);
            __distance = 0;
            continue;
        }
        __distance++;
    }
    Distances.insert(__distance);

    cin >> K;

    FOR(i, K)
    {
        int vl;
        cin >> vl;
        auto tt = Ones.upper_bound(vl);
        auto tt2 = Ones.lower_bound(vl);
        --tt2;
        if (str[vl - 1] == '1')
        {
            cout << *tt << " " << *tt2 << " ... " << (*tt - vl - 1) << " " << (vl - *tt2 - 1) << " | " << (*tt - *tt2 - 1) << " $ " << endl;
            Distances.insert(*tt - *tt2 - 1);

            auto dist1 = Distances.find(*tt - vl - 1);
            Distances.erase(dist1);
            // Separado para não apontarem para o mesmo set
            auto dist2 = Distances.find(vl - *tt2 - 1);
            Distances.erase(dist2);
            Ones.erase(vl);
        }
        else
        {
            auto dist = Distances.find(*tt - *tt2 - 1);
            Distances.erase(dist);
            Distances.insert(*tt - vl - 1);
            Distances.insert(vl - *tt2 - 1);
            Ones.insert(vl);
        }

        cout << *(--Distances.end()) << endl;
        if (i + 1 != K)
            cout << " ";
    }

    return 0;
}
