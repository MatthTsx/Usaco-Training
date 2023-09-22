#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
	freopen("convention2.in", "r", stdin);
	freopen("convention2.out", "w", stdout);

	int cow_num;
	vector<vector<int>> cows;
	cin >> cow_num;
	for (int c = 0; c < cow_num; c++) {
		int start, duration;
		cin >> start >> duration;
		cows.push_back({c, start, duration});
	}

	// sort by arrival time
	auto cmp = [](const vector<int> &a, const vector<int> &b) {
		return a[1] < b[1];
	};
	sort(cows.begin(), cows.end(), cmp);

	int time = 0;
	int curr = 0;
	int longest_wait = 0;

	// sorted by priority so that the highest seniority starts eating first
	set<vector<int>> waiting;
	// as long as we haven't processed all cows or there are still cows waiting
	while (curr < cow_num || !waiting.empty()) {
		// this cow can be processed.
		if (curr < cow_num && cows[curr][1] <= time) {
			waiting.insert(cows[curr]);
			curr++;
			// no cow waiting, skip to the next cow.
		} else if (waiting.empty()) {
			// set time to the ending time of the next cow.
			time = cows[curr][1] + cows[curr][2];
			curr++;
		} else {
			// process the next cow
			vector<int> next = *waiting.begin();
			longest_wait = max(longest_wait, time - next[1]);

			// set the time to when this cow finishes
			time += next[2];
			waiting.erase(waiting.begin());
		}
	}

	cout << longest_wait << endl;
}