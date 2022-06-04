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
/*https://www.educative.io/courses/grokking-the-coding-interview/gx2OqlvEnWG
 * https://leetcode.com/problems/subsets/
 * Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
TC: Since, in each step, the number of subsets doubles as we add each element to all the existing subsets, therefore, we will have a total of O(2^N)
subsets, where ‘N’ is the total number of elements in the input set. And since we construct
a new subset from an existing set, therefore, the time complexity of the above algorithm will be O(N*2^N)
 */
class Subsets {
 public:
	//TC: O(N * 2^N) SC: O(N*2^N)
  vector<vector<int>> findSubsets(const vector<int>& nums) {
    vector<vector<int>> subsets;
    subsets.push_back(vector<int>());

    for(int num : nums) {
      int n = subsets.size();
      for(int i = 0; i < n; i++) {
        subsets.push_back(subsets[i]);
        subsets.back().push_back(num);
      }
    }
    return subsets;
  }
};

/*
int main(int argc, char* argv[]) {
	Subsets ss;
  vector<vector<int>> result = ss.findSubsets(vector<int>{1, 3});
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }

  result = ss.findSubsets(vector<int>{1, 5, 3});
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}*/
