#include <bits/stdc++.h>
// http://www.usaco.org/index.php?page=viewproblem2&cpid=713
// FIles name: cowqueue.in && cowqueue.out

using namespace std;

int main(int argc, char const *argv[])
{
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out","w",stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, resp = 0;
    cin >> N;
    vector<pair<int,int>> cows (N);

    for(int i = 0; i < N; i++) cin >> cows[i].first >> cows[i].second;
    sort(cows.begin(), cows.end());
    
    // for(int i = 0; i < N-1; i++){
    //     if(cows[i].first + cows[i].second > cows[i+1].first) resp += ( cows[i].second - (cows[i+1].first - cows[i].first) );
    // }
    // resp += cows[N-1].first + cows[N-1].second;

    for (auto &&i : cows)
    {
        if(resp > i.first) resp += i.second;
        else resp = i.first + i.second;
    }
    

    cout << resp;
    return 0;
}
