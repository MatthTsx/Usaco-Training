#include<bits/stdc++.h>
// https://atcoder.jp/contests/abc125/tasks/abc125_c

#define Max 100000
using namespace std;
using ll = long long;

ll _gcd(ll a, ll b){
    if(b == 0) return a;
    return _gcd(b, a%b);
}

int main(int argc, char const *argv[])
{
    ll N;
    cin >> N;
    vector<ll> ipts (N);
    vector<ll> v1 (N+1);
    vector<ll> v2 (N+1);
    ll maior = 1;

    v1[0] = 0;
    v2[N+1] = 0;
    
    for (ll i = 0; i < N; i++) cin >> ipts[i];
    
    for (ll i = 1; i <=N; i++)
    {
        v1[i] = _gcd(v1[i-1], ipts[i-1]);
        v2[N - i] = _gcd(v2[N - i + 1], ipts[N-i]);
    }

    for (ll i = 1; i <= N; i++)
    {
        ll gcd_ = _gcd(v1[i-1], v2[i]);
        if(gcd_ > maior) maior = gcd_;
    }
    
    cout << maior;
    return 0;
}
