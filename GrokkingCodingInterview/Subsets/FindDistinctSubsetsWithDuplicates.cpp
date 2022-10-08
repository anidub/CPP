#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <unordered_map>
#include <queue>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/7npk3V3JQNr
 * https://leetcode.com/problems/subsets-ii/
 * Given a set of numbers that might contain duplicates, find all of its distinct subsets.
 * Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
 */
class SubsetWithDuplicates {
 public:
	////TC: O(N * 2^N) SC: O(N * 2^N)
  vector<vector<int>> findSubsets(vector<int>& nums) {
    vector<vector<int>> subsets;
    subsets.push_back(vector<int>());
    sort(nums.begin(), nums.end());
    int start;

    for(int i = 0; i < nums.size(); i++) {
      int end = subsets.size();
      if(i == 0 || nums[i] != nums[i-1])
        start = 0;
      for(; start < end; start++) {
        vector<int> current = subsets[start];
        current.push_back(nums[i]);
        subsets.push_back(current);
      }
    }

    return subsets;
  }
};

/*
int main(int argc, char* argv[]) {
  vector<int> vec = {1, 3, 3};
  SubsetWithDuplicates swd;
  vector<vector<int>> result = swd.findSubsets(vec);
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }

  vec = {1, 5, 3, 3};
  result = swd.findSubsets(vec);
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
*/
