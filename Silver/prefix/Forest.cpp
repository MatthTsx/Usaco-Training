#include<bits/stdc++.h>

using ll = long long;
using namespace std;

int main(int argc, char const *argv[])
{
    int N, Q;
    cin >> N >> Q;
    vector<int> place_holder (N+1);
    vector<vector<int>> vt (N, place_holder);

    for (int y = 0; y < N; y++)
        for (int x = 1; x <= N; x++)
        {
            char cr;
            cin >> cr;
            vt[y][x] = vt[y][x-1];
            if(cr - 'O' == -37) vt[y][x]++;
        }
    
    vector<int> answers (Q);
    for (int q = 0; q < Q; q++)
    {
        int answer = 0, y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        int mn = min(x1,x2) - 1;
        int mx = max(x1,x2);
        for (int y = min(y1,y2) - 1; y < max(y1,y2); y++)
        {
            answer += vt[y][mx] - vt[y][mn];
        }
        answers[q] = answer;
    }
    
    for (auto &&i : answers)
        cout << i << "\n";

    return 0;
}
