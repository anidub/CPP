#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/B8R83jyN3KY
 * Given a set of distinct numbers, find all of its permutations. for 1,2,3
 * {1, 2, 3}
{1, 3, 2}
{2, 1, 3}
{2, 3, 1}
{3, 1, 2}
{3, 2, 1}
https://leetcode.com/problems/permutations/
https://leetcode.com/problems/permutations/discuss/18282/backtracking-Clean-C%2B%2B-recursion-with-detailed-explanation
 */
class Permutations {
 public:
	//TC: O (N * N!) SC: O(N!)
  static vector<vector<int>> findPermutations( vector<int>& nums) {
    vector<vector<int>> result;
    DFS(result, nums, 0);
    return result;
  }

  static void DFS( vector<vector<int>> &result,  vector<int> &nums, int pos) {
    if(pos == nums.size() - 1) {
      result.push_back(nums);
    }
    for(int i = pos; i < nums.size(); i++) {
      swap(nums[i], nums[pos]);
      DFS(result, nums, pos + 1);
      swap(nums[pos], nums[i]);
    }
  }

 public: //TC: O (N * N!) SC: O(N * N!) //  USED
  static vector<vector<int>> generatePermutations(const vector<int> &nums) {
 /*   vector<vector<int>> result;
    vector<int> currentPermutation;
    generatePermutationsRecursive(nums, 0, currentPermutation, result);
    return result;
*/
	  vector<vector<int>> result;
	  vector<int> curPer;
	  generatePermutationsRecursive(nums, 0, curPer, result);
	  return result;
  }

private:
  static void generatePermutationsRecursive(const vector<int> &nums, int index,
                                      vector<int> &currentPermutation, vector<vector<int>> &result) {
	  if (index == nums.size()) {
		  result.push_back(currentPermutation);
	  } else {
		  // create a new permutation by adding the current number at every position
		  for (int i = 0; i <= currentPermutation.size(); i++) {
			  vector<int> newPermutation(currentPermutation);
			  newPermutation.insert(newPermutation.begin() + i, nums[index]);
			  generatePermutationsRecursive(nums, index + 1, newPermutation, result);
		  }
	  }
  }
};
/*
int main(int argc, char* argv[]) {
  vector<int> k = {1, 3, 5};
  vector<vector<int>> result = Permutations::generatePermutations(k);
  cout << "Here are all the permutations: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
*/
