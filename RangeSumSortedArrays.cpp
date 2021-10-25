#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/
 *Given the array nums consisting of n positive integers. You computed the sum of all non-empty continous subarrays from
 *Given the array and then sort them in non-decreasing order, creating a new array of n * (n + 1) / 2 numbers.
Return the sum of the numbers from index left to index right (indexed from 1), inclusive, in the new array. Since the
answer can be a huge number return it modulo 10^9 + 7.
Example 1:
Input: nums = [1,2,3,4], n = 4, left = 1, right = 5
Output: 13
Explanation: All subarray sums are 1, 3, 6, 10, 2, 5, 9, 3, 7, 4.
After sorting them in non-decreasing order we have the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index le = 1 to ri = 5 is 1 + 2 + 3 + 3 + 4 = 13.

https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/discuss/730748/C%2B%2B-or-Simple-solution
https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/discuss/730511/C%2B%2B-priority_queue-solution
 */

//brute force not scalable // works
int rangeSumSorted(vector<int>& nums, int left, int right, int n) {
	vector<int> subArrays;

	for(int i = 0; i < n; i++) {
		int sum = 0;
		for(int j = i; j < n; j++) {
			sum += nums[j];
			subArrays.push_back(sum);
		}
	}

	sort(subArrays.begin(), subArrays.end());

	int result = 0; int mod = 1000000007;
	for(int i = left - 1; i < right; i++) {
		cout << result << endl;
		result = (result + subArrays[i])%mod;
	}
	return result%mod;
}

int rangeSumPQueue(vector<int>& nums, int n, int left, int right) {
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;

	for(int i = 0; i < n; i++) {
		pq.push({nums[i], i+1});
	}

	int result = 0; int mod = 1e9+7;
	for(int i = 1; i <= right; i++) {
		auto p = pq.top();
		pq.pop();
		if(i >= left) {
			result = (result + p.first)%mod;
		}
		if(p.second < n) {
			p.first = p.first + nums[p.second];
			p.second++;
			pq.push(p);
		}
	}
	return result;
}

int rangeSumCpp(vector<int>& nums, int n, int left, int right) {
    vector<int> subs;
    for (auto i = 0; i < nums.size(); ++i)
        for (auto j = i, sum = 0; j < nums.size(); ++j)
            subs.push_back(sum += nums[j]);
    nth_element(begin(subs), begin(subs) + left - 1, end(subs));
    nth_element(begin(subs) + left, begin(subs) + right, end(subs));
    return accumulate(begin(subs) + left - 1, begin(subs) + right, 0, [](int s, int i)
        { return (s + i) % 1000000007; });
}

/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(2);nums.push_back(3);nums.push_back(4);
	cout << rangeSumSorted(nums, 4, 1, 5) << endl;
	//cout << rangeSumPQueue(nums, 4, 1, 5) << endl;

	return 0;
}*/
