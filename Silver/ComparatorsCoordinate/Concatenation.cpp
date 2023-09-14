#include<bits/stdc++.h>
// https://codeforces.com/problemset/problem/632/C

using namespace std;


bool comp (const string &a, const string &b){return (a+b) < (b+a);}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;

    vector<string> vt (N);
    for(int i = 0; i < N; i++) cin >> vt[i];
    sort(vt.begin(), vt.end(), comp);

    string resp = "";

    for (auto &&i : vt)
        resp += i;
    
    cout << resp;
    return 0;
}
