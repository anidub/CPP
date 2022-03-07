#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/online-majority-element-in-subarray/
 * Design a data structure that efficiently finds the majority element of a given subarray.
The majority element of a subarray is an element that occurs threshold times or more in the subarray.
Implementing the MajorityChecker class:
MajorityChecker(int[] arr) Initializes the instance of the class with the given array arr.
int query(int left, int right, int threshold) returns the element in the subarray arr[left...right] that occurs at least threshold times, or -1 if no such element exists.
Example 1:
Input
["MajorityChecker", "query", "query", "query"]
[[[1, 1, 2, 2, 1, 1]], [0, 5, 4], [0, 3, 3], [2, 3, 2]]
Output
[null, 1, -1, 2]

Explanation
MajorityChecker majorityChecker = new MajorityChecker([1, 1, 2, 2, 1, 1]);
majorityChecker.query(0, 5, 4); // return 1
majorityChecker.query(0, 3, 3); // return -1
majorityChecker.query(2, 3, 2); // return 2

https://leetcode.com/problems/online-majority-element-in-subarray/discuss/356108/C%2B%2B-160-ms-frequency-%2B-binary-search
 */
class MajorityChecker{

unordered_map<int, vector<int>> idx;
public:
	MajorityChecker(vector<int>& arr) {
		for(int i = 0; i < arr.size(); i++)
			idx[arr[i]].push_back(i);
	}

	int query(int left, int right, int threshold) {
		for(auto& i : idx) {
			if(i.second.size() < threshold) continue;
			auto it1 = lower_bound(begin(i.second), end(i.second), left);
			auto it2 = upper_bound(begin(i.second), end(i.second), right);
			if(it2 - it1 >= threshold) return i.first;
		}
		return -1;
	}
};

/*
int main() {
	vector<int> arr; arr.push_back(1);arr.push_back(1);
	arr.push_back(2);arr.push_back(2);arr.push_back(1);arr.push_back(1);
	MajorityChecker mj(arr);
	cout << mj.query(0, 5, 4) << endl;
	cout << mj.query(0, 3, 3) << endl;
	cout << mj.query(2, 3, 2) << endl;

	return 0;
}*/
