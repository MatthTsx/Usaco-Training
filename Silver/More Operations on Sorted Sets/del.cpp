#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

struct Log
{
    int day, cow, change;
};

int main()
{
    std::ifstream read("measurement.in");

    int n;
    int g;
    read >> n >> g;

    vector<Log> log(n);
    std::map<int, int> cows;
    for (Log &l : log)
    {
        read >> l.day >> l.cow >> l.change;
        cows[l.cow] = g;
    }
    std::sort(log.begin(), log.end(),
              [](const Log &l1, const Log &l2)
              { return l1.day < l2.day; });

    std::map<int, int> milk_prod{{g, n}};

    int changeAmt = 0;
    for (Log l : log)
    {
        int milk_amt = cows[l.cow];
        bool was_top = milk_amt == milk_prod.rbegin()->first;
        int prev_count = milk_prod[milk_amt];
        // remove the previous milk production number
        milk_prod[milk_amt]--;
        if (milk_prod[milk_amt] == 0)
        {
            milk_prod.erase(milk_amt);
        }

        // update the milk production amounts
        milk_amt += l.change;
        cows[l.cow] = milk_amt;
        milk_prod[milk_amt]++;

        bool is_top = milk_amt == milk_prod.rbegin()->first;
        int curr_count = milk_prod[milk_amt];
        if (was_top)
        {
            if (is_top && curr_count == prev_count)
            {
                continue;
            }
            /*
             * if it was the highest and now it's not or there are now
             * multiple highest cows, then FJ needs to change the portrait
             */
            changeAmt++;
        }
        else if (is_top)
        {
            /*
             * if it wasn't at the highest but now it is,
             * then FJ needs to change the portrait also
             */
            changeAmt++;
        }
    }

    std::ofstream("measurement.out") << changeAmt << endl;
}