#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_set>

using namespace std;
/*https://leetcode.com/problems/check-if-n-and-its-double-exist/
 * Given an array arr of integers, check if there exists two integers N and M such that N is the double of M ( i.e. N = 2 * M).
 * Input: arr = [10,2,5,3]
Output: true
Explanation: N = 10 is the double of M = 5,that is, 10 = 2 * 5.
https://leetcode.com/problems/check-if-n-and-its-double-exist/discuss/708329/C%2B%2B-and-Python-solutions

 */
bool checkIfExists(vector<int>& arr) {
	if(arr.size() == 0) return false;
	unordered_set<int> unordSet;
	for(int& i : arr) {
		if(unordSet.count(2*i) || (i%2 == 0 && unordSet.count(i/2)))
			return true;
		unordSet.insert(i);
	}

	return true;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(10);nums.push_back(2);nums.push_back(5);nums.push_back(3);
	cout << checkIfExists(nums) << endl;

	return 0;
}*/
