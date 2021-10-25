#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/
 * Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.
Example 1:
Input: arr = [5,5,4], k = 1
Output: 1
Explanation: Remove the single 4, only 5 is left.
https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/discuss/686891/C%2B%2B-map-%2B-priority_queue
Time: O(n + i log m), where m is unique elements, and i - number of elements we need to remove.
Memory: O(m) for the hash map and heap.
https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/discuss/686258/C%2B%2B-Min-Heap
 */

 int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
	 if(arr.empty()) return 0;
	 unordered_map<int, int> umap;

	 for(int& i : arr) {
		 umap[i]++;
	 }

	 priority_queue<int, vector<int>, greater<int>> pq;
	 for(auto& f : umap) {
		 pq.push(f.second);
	 }

	 while(k >= 0) {
		 k = k - pq.top();
		 if(k >= 0) //important
			 pq.pop();
	 }
	 return pq.size();
 }
/*
 int main() {
	 vector<int> nums;
	 nums.push_back(5);nums.push_back(5);nums.push_back(4);

	 cout << findLeastNumOfUniqueInts(nums, 1) << endl;
	 return 0;
 }*/
