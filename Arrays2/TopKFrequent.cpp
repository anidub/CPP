#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/top-k-frequent-elements/
 * Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
 * Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

https://www.youtube.com/watch?v=YPTqKIgVk-k

https://leetcode.com/problems/top-k-frequent-elements/discuss/81631/3-ways-to-solve-this-problem : heap
https://leetcode.com/problems/top-k-frequent-elements/discuss/81676/C%2B%2B-O(nlogk)-and-O(n)-solutions : bucket sort
 */
//TC: O(nlogn)
vector<int> topKFrequentElements(vector<int>& nums, int k) {
	if(nums.empty()) return {};
	vector<int> result;

	unordered_map<int, int> counts;
	for(int &num : nums)
		counts[num]++;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for(auto kv : counts) {
		pq.push({kv.second, kv.first});
		while(pq.size() > k) pq.pop();
	}

	for(auto & i : counts) {
	    if(i.second >= pq.top().first) {
	    	result.push_back(i.first);
	        if(result.size() == k) {
	            break;
	        }
	    }
	}
	return result;
}
//O(N), SC  : O(n + k) n : no of elements and k  is num of buckets
vector<int> topKFrequentElementsOptimal(vector<int> &nums, int k) {
	if(nums.empty()) return {};
	vector<int> result;
	int n = nums.size();
	unordered_map<int, int> count;

	for(int &i : nums)
		count[i]++;

	vector<vector<int>> buckets(n + 1);

	for(auto [num, freq] : count) {
		buckets[freq].push_back(num);
	}

	for(int i = buckets.size() - 1; i >= 0; i--) {
		for(int num : buckets[i]) {
			result.push_back(num);
			if(result.size() == k)
				return result;
		}
	}
	return result;
}
/*
int main() {
	vector<int> nums = {1, 1, 1, 2, 2, 3};
	topKFrequentElements(nums, 2);

	return 0;
}*/
