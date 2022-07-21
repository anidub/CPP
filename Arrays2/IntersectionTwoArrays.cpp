#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <stack>
#include <sstream>

using namespace std;
/*https://leetcode.com/problems/intersection-of-two-arrays/
 * Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.
 Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
https://leetcode.com/problems/intersection-of-two-arrays/discuss/82001/8ms-concise-C%2B%2B-using-unordered_set : comments
 */
//TC:O(M), SC: (N)
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	if(nums1.empty() || nums2.empty()) return {};

	unordered_set<int> st(nums1.begin(), nums1.end());

	vector<int> intersections;
	for(auto n : nums2) {
		if(st.erase(n) > 0)// if n exists in set, then 1 is returned and n is erased; otherwise, 0.
			intersections.push_back(n);
	}
	return intersections;
}
/*
int main() {
	vector<int> nums1 = {1,2,2,1};
	vector<int> nums2 = {2,2};
	intersection(nums1, nums2);
	return 0;
}*/
