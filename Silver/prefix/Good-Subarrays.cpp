#include<bits/stdc++.h>
// https://codeforces.com/contest/1398/problem/C

#define MaxTests 1000
using namespace std;
using ll = long long;
using vt = ll[MaxTests];

vt answer;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    for (int loop = 1; loop <= t; loop++)
    {
        ll qnt;
        string str_arry;
        cin >> qnt >> str_arry;
        vector<int> v (qnt+1);
        map<ll,int> seen;
        seen[0] = 1;

        ll resp = 0;

        for (ll i = 1; i <= qnt; i++)
        {
            string s;
            s = str_arry[i-1];
            v[i] = v[i-1] + stoi(s);
            resp += seen[v[i] - i];
            ++seen[v[i] - i];
        }
        answer[loop-1] = resp;
    }
    
    for (ll i = 0; i < t; i++)
    {
        cout  << answer[i] << "\n";
    }

    return 0;
}
