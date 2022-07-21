#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <string.h>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/top-k-frequent-elements/
 * Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
 * Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
 */
class TopKFrequent {
public:
	//TC:O(NLOGK), SC:O(N +K)
	vector<int> topKFrequent(vector<int>& nums, int k) {
		if(nums.empty()) return {};
		vector<int> result;

		unordered_map<int, int> numFreqMap;
		for(int i = 0; i < nums.size(); i++) {
			numFreqMap[nums[i]]++;
		}

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > min_heap;

		for(auto entry : numFreqMap) {
			min_heap.push({entry.second, entry.first});
			if(min_heap.size() > k) min_heap.pop();
		}

		while(!min_heap.empty()) {
			result.push_back(min_heap.top().second);
			min_heap.pop();
		}
		return result;
	}

	//TC:O(N), SC:O(N)
	vector<int> topKFrequentOptimal(vector<int>& nums, int k) {
		if(nums.empty()) return {};
		vector<int> result;
		int n = nums.size();

		unordered_map<int, int> numFreq;
		for(int &i : nums)
			numFreq[i]++;

		vector<vector<int>> buckets(n + 1);
		for(auto [num, freq] : numFreq) {
			buckets[freq].push_back(num);
		}

		for(int i = buckets.size() - 1; i >= 0; i--) {
			for(int num : buckets[i]) {
				result.push_back(num);
				if(result.size() == k) return result;
			}
		}
		return result;
	}
};
/*
int main() {
	TopKFrequent tf;
	vector<int> nums = {1,1,1,2,2,3};
	tf.topKFrequentOptimal(nums, 2);

	return 0;
}
*/
