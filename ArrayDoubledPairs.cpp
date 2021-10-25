#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/array-of-doubled-pairs/
 * Given an array of integers arr of even length, return true if and only if it is possible to reorder it such that arr[2 * i + 1] = 2 * arr[2 * i] for every 0 <= i < len(arr) / 2.
 * Input: arr = [4,-2,2,-4]
Output: true
Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4] or [2,4,-2,-4]
https://leetcode.com/problems/array-of-doubled-pairs/discuss/203183/JavaC%2B%2BPython-Match-from-the-Smallest-or-Biggest-100
 */
//O(N)
bool canReorderedDoubled(vector<int>& arr) {
	if(arr.empty()) return true;
	unordered_map<int, int> count;

	for(int& i : arr)
		count[i]++;

	vector<int> keys;
	for(auto& it : count) {
		keys.push_back(it.first);
	}

	sort(keys.begin(), keys.end(), [](int i, int j){return abs(i) < abs(j);});

	for(int& x : keys){
		if(count[x] > count[2 * x])
			return false;
		count[2 * x] -= count[x];
	}
	return true;

}
/*
int main() {
	vector<int> arr;
	arr.push_back(4);arr.push_back(-2);arr.push_back(2);arr.push_back(-4);
	cout << canReorderedDoubled(arr) << endl;

	return 0;
}*/
