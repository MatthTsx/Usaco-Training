#include<bits/stdc++.h>
// http://www.usaco.org/index.php?page=viewproblem2&cpid=104

// #define MaxN 1000000
#define MaxK 25000

using namespace std;
using ll = long long;
// using vt = ll[MaxN];


int main(int argc, char const *argv[])
{
    int N, K;
    cin >> N >> K;
    vector<int> v (N);

    // memset(prefix, 0, MaxN);
    for (int i = 0; i < K; i++) // O(n)
    {
        int ini, fin;
        cin >> ini >> fin;
        for (ll j = ini; j <= fin; j++)
        {
            v[j-1] ++;
        }
    }

    sort(v.begin(), v.end()); // O(n log(n))

    cout << v[(int) ceil(N / 2)];
    return 0;
}
