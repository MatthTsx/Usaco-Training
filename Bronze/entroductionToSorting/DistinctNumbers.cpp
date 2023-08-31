#include<bits/stdc++.h>
// https://cses.fi/problemset/task/1621

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, resp = 0;
    cin >> N;
    map<int,int> mp;

    while(N--) {
        int vl;
        cin >> vl;
        if(!mp[vl]) resp++;
        mp[vl]++;
    }

    cout << resp;
}