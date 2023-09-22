#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    multiset<int> mt;
    for(int i = 0; i < 10; i++){
        mt.insert(i);
    }

    auto thing = mt.lower_bound(6);
    auto thin2 = mt.lower_bound(3);
    // if(thing == mt.begin() || *(--thing) >= 6)
    //     cout << *thing << " " << distance(mt.lower_bound(7-1), thing);

    cout << *thing << " " << distance(thin2, thing);
    return 0;
}
