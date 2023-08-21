#include<bits/stdc++.h>
// http://www.usaco.org/index.php?page=viewproblem2&cpid=715

#define Max 100000
using namespace std;
using ll = long long;
using vt = ll[Max];

vt prefix_sum;
vt placeHolder;
ll cnt = -1;

int main(int argc, char const *argv[])
{
    int N,B,K;
    cin >> N >> B >> K;

    for(int i = 1; i <= N; i++) placeHolder[i] = 1;
    for (int i = 0; i < K; i++)
    {
        int index;
        cin >> index;
        placeHolder[index] = 0;
    }

    prefix_sum[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        prefix_sum[i] = prefix_sum[i - 1] + placeHolder[i];
        if(i >= B){
            ll value = B - (prefix_sum[i] - prefix_sum[i - B]);
            if(value < cnt || cnt == -1) cnt = value;
        };
    }

    cout << cnt;
    return 0;
}