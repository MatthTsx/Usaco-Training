#include<bits/stdc++.h>
using namespace std;
#define FOR(i,N) for(int i =0;i<N;i++)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    map<int,int> mp;
    cin >> N;

    FOR(i,N){
        int id;
        cin >> id;
        mp[id]++;
    }

    cout << mp.size();
    return 0;
}
