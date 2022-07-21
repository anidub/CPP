#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_set>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/mE53y85Wqw9
 * Given a set of positive numbers, partition the set into two subsets with minimum difference between their subset sums.
 * Input: {1, 2, 3, 9}
Output: 3
Explanation: We can partition the given set into two subsets where minimum absolute difference
between the sum of numbers is '3'. Following are the two subsets: {1, 2, 3} & {9}.

 */
class PartitionSet {
public:
	//TC:O(N ^ 2), SC: O(N)
	 int canPartitionRecursive(const vector<int> &nums) {
		 return this->canPartitionRecursive(nums, 0, 0, 0);
	 }

	 //TC:O(N * S), SC:O(N * S)
	 int canPartitionMemo(const vector<int> &nums) {
		 int n = nums.size();
		 int sum = 0;

		 for(int i : nums) sum += i;

		 vector<vector<int>> memo(n, vector<int>(sum + 1, -1));

		 return this->canPartitionMemo(memo, nums, 0, 0, 0);
	 }


private:
	 int canPartitionRecursive(const vector<int> &nums, int currentIndex, int sum1, int sum2) {
		 if(currentIndex == nums.size())
			 return abs(sum1 - sum2);

		 int diff1 = canPartitionRecursive(nums, currentIndex + 1, sum1 + nums[currentIndex], sum2);

		 int diff2 = canPartitionRecursive(nums, currentIndex + 1, sum1, sum2 + nums[currentIndex]);

		 return min(diff1, diff2);
	 }

	 int canPartitionMemo( vector<vector<int>> &memo, const vector<int> &nums, int currentIndex, int sum1, int sum2) {
		 if(currentIndex == nums.size())
			 return abs(sum1 - sum2);

		 if(memo[currentIndex][sum1] == -1) {
			 int diff1 = canPartitionMemo(memo, nums, currentIndex + 1, nums[currentIndex] + sum1 , sum2);

			 int diff2 = canPartitionMemo(memo, nums, currentIndex + 1, sum1, nums[currentIndex] + sum2);

			 memo[currentIndex][sum1] = min(diff1, diff2);
		 }
		 return memo[currentIndex][sum1];
	 }
};

/*
int main(int argc, char *argv[]) {
  PartitionSet ps;
  vector<int> num = {1, 2, 3, 9};
  cout << ps.canPartitionRecursive(num) << endl;
  cout << "memo:" << ps.canPartitionMemo(num) << endl;
  num = vector<int>{1, 2, 7, 1, 5};
  cout << ps.canPartitionRecursive(num) << endl;
  cout << "memo:" << ps.canPartitionMemo(num) << endl;
  num = vector<int>{1, 3, 100, 4};
  cout << ps.canPartitionRecursive(num) << endl;
  cout << "memo:" << ps.canPartitionMemo(num) << endl;
}
*/
