#include<bits/stdc++.h>
// http://www.usaco.org/index.php?page=viewproblem2&cpid=416
// Files: lazy.in && lazy.out

using namespace std;
using ll = long long;
int N, K;
vector<vector<int>> input;
vector<vector<int>> vt;
vector<vector<int>> vt2;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream File;
    ofstream Output ("lazy.out");

    File.open("lazy.in", ios::in);
    File >> N >> K;

    int w = N*2-1;
    input = vector<vector<int>> (N+1, vector<int> (N+1,0));
    vt = vector<vector<int>> (w, vector<int> (w,0));
    vt2 = vector<vector<int>> (w+1, vector<int> (w+1,0));

    for (size_t i = 1; i <= N; i++)
        for (size_t j = 1; j <= N; j++){
            File >> input[i][j];
            vt[i+j-2][N - 1 -i+j] = input[i][j]; // turn 45 deg
        }
    File.close();

    for (int i = 1; i <= w; i++)
        for (int j = 1; j <= w; j++)
            vt2[i][j] = vt[i-1][j-1] + vt2[i-1][j] + vt2[i][j-1] - vt2[i-1][j-1]; // prefix vector
    
    int bigger = -1;
    bool foi = false;

    for (int i = 1; i + 2*K <= w; i++)
        for (int j = 1; j + 2*K <= w; j++)
        {
            int vl = vt2[i+2*K][j+2*K] - vt2[i+2*K][j-1] - vt2[i-1][j+2*K] + vt2[i-1][j-1]; // get the area
            if(vl > bigger || !foi) bigger = vl;
            if(!foi) foi = true;
        }
    
    Output << bigger;
    Output.close();

    return 0;
}
