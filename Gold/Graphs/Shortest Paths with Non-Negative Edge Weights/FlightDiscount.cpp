#include<bits/stdc++.h>
// https://cses.fi/problemset/task/1195
using namespace std;
using ll = long long;
constexpr ll Big = 1e18;
typedef unordered_map<int, ll> mil;

mil adjs;
vector<ll> dist;
int N, M, discountTarget = 0;

int N, M;