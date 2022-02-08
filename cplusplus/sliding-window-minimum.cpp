#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template<class T>
void 
sliding_window_minimum(vector<T> &arr, ll k) {
	// Complexity : O(n)
	
	deque<pair<T, ll>> SW;
	for (ll i=0; i<arr.size(); i++) {
		// anything larger than i+th element can't be the window minimum
		while (!SW.empty() && SW.back().first >= arr[i])
			SW.pop_back();
		SW.emplace_back(arr[i], i);

		// remove from front, those elements which are not a part of the window
		while (SW.front().second <= i - k) // no worries about empty since i > i - k
			SW.pop_front();

		if (i<k-1) continue; // this window has lower index outside 0
		// since the window is sorted, the first element is the window minimum
		cout << SW.front().first << " ";
	}
	cout << "\n";
}


int 
main(int argc, char const *argv[])
{
	vector<int> arr = {2, 1, 4, 5, 3, 4, 1, 2};
	sliding_window_minimum(arr, 4);
	return 0;
}