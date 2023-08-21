#include<bits/stdc++.h>

using namespace std;
using ll = long long;
#define Max 50001

ll arry[Max];
ll maior = 0;

int is(int index){
    for (int i = 0; i < index - maior; i++)
    {
        if( (arry[index] - arry[i])%7 == 0 ) return i;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;

    arry[0] = 0;

    for (int i = 1; i <= N; i++)
    {
        ll vl;
        cin >> vl;
        arry[i] = vl + arry[i-1];
        int is_ = is(i);
        if(is_ != -1 &&  i - is_ > maior) maior = i - is_;
    }
    
    cout << maior << "\n";
    return 0;
}
