#include<bits/stdc++.h>
// https://codeforces.com/gym/102951/problem/B

using namespace std;
#define FOR(i,N) for(int i=0;i<N;i++)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K, sum = 0, resp = 0;
    cin >> N >> K;
    multiset<int> mts;
    FOR(i,N) {
        int p;
        cin >> p;
        mts.insert(p);
    }

    while(sum <= K && !mts.empty()){
        auto last = mts.begin();
        mts.erase(mts.find(*last));

        sum += *last;
        if(sum <= K)
            resp++;
    }


    cout << resp;
    return 0;
}
