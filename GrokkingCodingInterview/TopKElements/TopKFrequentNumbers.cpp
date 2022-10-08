#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/B89rvR6XZ3J
 * Given an unsorted array of numbers, find the top ‘K’ frequently occurring numbers in it.
 * Input: [1, 3, 5, 12, 11, 12, 11], K = 2
Output: [12, 11]
Explanation: Both '11' and '12' apeared twice.
 */
class TopKFrequentNumbers {
public:
	//TC:O(N + NLOGK) SC: O(N)
	vector<int> findTopKFrequentNumbers(const vector<int> &nums, int k) {
	    vector<int> topNumbers;
	    unordered_map<int, int> numFrequencyMap;
	    for(int n : nums)
	    	numFrequencyMap[n]++;

	    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > min_heap;

	    for(auto numFreq : numFrequencyMap) {
	    	min_heap.push( {numFreq.second, numFreq.first} );
	    	if(min_heap.size() > k)
	    		min_heap.pop();
	    }

	    while(!min_heap.empty()) {
	    	topNumbers.push_back(min_heap.top().second);
	    	min_heap.pop();
	    }

	    return topNumbers;
	  }

	//TC:O(N), SC:O(N) used from leetcode
	vector<int> findTopKFrequentNumbersOptimal(const vector<int> &nums, int k) {
	    vector<int> topNumbers;
	    unordered_map<int, int> numFrequencyMap;
	    for(int n : nums)
	    	numFrequencyMap[n]++;

	    int n = nums.size() - 1;
	    vector<vector<int>> buckets(n + 1);

	    for(auto[num, freq] : numFrequencyMap)
	    	buckets[freq].push_back(num);

	    for(int i = buckets.size() - 1; i >= 0; i--) {
	    	for(int num : buckets[i]) {
	    		topNumbers.push_back(num);
	    		if(topNumbers.size() == k)
	    			return topNumbers;
	    	}
	    }
	    return topNumbers;
	}

};

/*
int main(int argc, char *argv[]) {
	TopKFrequentNumbers tfn;
  vector<int> result =
		  tfn.findTopKFrequentNumbers(vector<int>{1, 3, 5, 12, 11, 12, 11}, 2);
  cout << "Here are the K frequent numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = tfn.findTopKFrequentNumbersOptimal(vector<int>{5, 12, 11, 3, 11}, 2);
  cout << "Here are the K frequent numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}
*/
