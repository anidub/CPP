#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_set>
#include <utility>

using namespace std;
/*
https://www.educative.io/courses/grokking-the-coding-interview/N767x7VoYmK
Given two sorted arrays in descending order, find ‘K’ pairs with the largest sum where each pair consists of numbers from both the arrays.
Input: L1=[9, 8, 2], L2=[6, 3, 1], K=3
Output: [9, 3], [9, 6], [8, 6]
Explanation: These 3 pairs have the largest sum. No other pair has a sum larger than any of these.

*/
typedef pair<int, int> pi;

class LargestPairs {
 public:
  struct ValueCompareMinHeap {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
      return a.first + a.second  > b.first + b.second;
    }
  };

  //TC:O(N * M * LOGK), SC:O(K)
  vector<pair<int, int>> findKLargestPairs(const vector<int> &nums1, const vector<int> &nums2, int k) {
	  	vector<pair<int, int>> result;
        priority_queue<pi, vector<pi>, ValueCompareMinHeap> minHeap;

        for(int i = 0; i < min((int)nums1.size(), k); i++) {
            for(int j = 0; j < min((int)nums2.size(), k); j++) {

                if(minHeap.size() < k) {
                	minHeap.push({nums1[i], nums2[j]});
                } else if(nums1[i] + nums2[j] > minHeap.top().first + minHeap.top().second) {//, if a pair is bigger than the top (smallest) pair in the heap,
                	//we can remove the smallest pair and insert this pair in the heap.
                	minHeap.pop();
                	minHeap.push({nums1[i], nums2[j]});
                }
            }
        }

        while(!minHeap.empty()) {
            auto cur = minHeap.top(); minHeap.pop();
            result.push_back({cur.first, cur.second});
        }
        return result;
  }

/*https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
  https://leetcode.com/problems/find-k-pairs-with-smallest-sums/discuss/84568/c%2B%2B-priority_queue-solution

 	 time complexity: O(m * n logk)
 	 space complexity O(k)
 */
 struct ValueCompareMaxHeap {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
      return a.first + a.second  < b.first + b.second;
    }
  };
  vector<pair<int, int>> findKSmallestPairs(const vector<int> &nums1, const vector<int> &nums2, int k) {
    vector<pair<int, int>> result;
        priority_queue<pi, vector<pi>, ValueCompareMinHeap> maxHeap;

        for(int i = 0; i < min((int)nums1.size(), k); i++) {
            for(int j = 0; j < min((int)nums2.size(), k); j++) {

                if(maxHeap.size() < k) {
                    maxHeap.push({nums1[i], nums2[j]});
                } else if(nums1[i] + nums2[j] < maxHeap.top().first + maxHeap.top().second) {
                    maxHeap.pop();
                    maxHeap.push({nums1[i], nums2[j]});
                }
            }
        }

        while(!maxHeap.empty()) {
            auto cur = maxHeap.top(); maxHeap.pop();
            result.push_back({cur.first, cur.second});
        }
        return result;
  }
};

/*
int main(int argc, char *argv[]) {
	LargestPairs lp;
  auto result = lp.findKLargestPairs({9, 8, 2}, {6, 3, 1}, 3);
  cout << "Pairs with largest sum are: ";
  for (auto pair : result) {
    cout << "[" << pair.first << ", " << pair.second << "] " << endl;
  }

  result = lp.findKSmallestPairs({9, 8, 2}, {6, 3, 1}, 3);
    cout << "Pairs with smallest sum are: ";
    for (auto pair : result) {
      cout << "[" << pair.first << ", " << pair.second << "] ";
    }
}
*/
