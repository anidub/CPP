#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/
 * Given an array nums that represents a permutation of integers from 1 to n. We are going to construct a binary search tree (BST) by inserting the elements of nums in order into an initially empty BST. Find the number of different ways to reorder nums so that the constructed BST is identical to that formed from the original array nums.

For example, given nums = [2,1,3], we will have 2 as the root, 1 as a left child, and 3 as a right child. The array [2,3,1] also yields the same BST but [3,2,1] yields a different BST.
Return the number of ways to reorder nums such that the BST formed is identical to the original BST formed from nums.

Since the answer may be very large, return it modulo 109 + 7.
Input: nums = [2,1,3]
Output: 1
Explanation: We can reorder nums to be [2,3,1] which will yield the same BST. There are no other ways to reorder nums which will yield the same BST.

Input: nums = [3,4,5,1,2]
Output: 5
Explanation: The following 5 arrays will yield the same BST:
[3,1,2,4,5]
[3,1,4,2,5]
[3,1,4,5,2]
[3,4,1,2,5]
[3,4,1,5,2]

Combination formula : C(m,n) = C(m-1,n) + C(m-1,n-1).

// in code, we use Pascal triangle to keep a table of permutations, so we can look up the table and get permutation result in O(1)
https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/discuss/819369/C%2B%2B-Just-using-recursion-very-Clean-and-Easy-to-understand-O(n2)

(((table[n - 1][left_len] * left_res) % mod) * right_res) % mod:
Let us just ignore "%mod" first, and it becomes table[n - 1][left_len] * left_res * right_res, table[n - 1][left_len]
means the number of permutation "we can change their absolute position but need to keep their relative position" which
equivalent to table[n - 1][right_len], and left_res , right_res just means the results
of the left subtree and right subtree, we multiply all the result together to get the total number of permutations.

Basically it means C(n-1, left_len) * left_res * right res

Pascal triangle keep a table of permutations:
assume C(n, k) stands for pick k out of n, then you can find the relation between permutation and Pascal triangle :
1 --C(0, 0)
1 1 --C(1, 0) C(1, 1)
1 2 1 --C(2, 0) C(2, 1) C(2, 2)
1 3 3 1 --C(3, 0) C(3, 1) C(3, 2) C(3, 3)
 */
class BNode{
public:
	int data;
	BNode *left;
	BNode *right;

	BNode(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

int numberOfWaysReorderBSTDFS(vector<int>& nums, long long mod);

vector<vector<long long>> pascalTable;
//Time: O(n^2)
int numberOfWaysReorderBST(vector<int>& nums) {
	if(nums.empty()) return 0;
	int n = nums.size();

	pascalTable.resize(n+1);

	long long mod = 1e9 + 7;

	for(int i = 0; i < n+1; i++) {
		pascalTable[i] = vector<long long>(i+1, 1);
		for(int j = 1; j < i; j++) {
			pascalTable[i][j] = (pascalTable[i-1][j-1] + pascalTable[i-1][j]) % mod;
		}
	}
	int ans = numberOfWaysReorderBSTDFS(nums, mod);
	return ans % mod - 1;
}

int numberOfWaysReorderBSTDFS(vector<int>& nums, long long mod) {
	int n = nums.size();
	if(n <= 2) return 1;

	// find left sub-sequence elements and right sub-sequence elements
	vector<int> left; vector<int> right;

	for(int i = 1; i < nums.size(); i++) {
		if(nums[i] < nums[0]) left.push_back(nums[i]);
		else right.push_back(nums[i]);
	}

	// recursion with left subtree and right subtree
	long long left_res = numberOfWaysReorderBSTDFS(left, mod) % mod;
	long long right_res = numberOfWaysReorderBSTDFS(right, mod) % mod;

	int left_len = left.size(), right_len = right.size();

	// look up table and multiple them together
	return  (((pascalTable[n-1][left_len] * left_res) % mod) * right_res) % mod;
}

/*
int main() {
	vector<int> nums({3,1,2,5,4,6});
	cout << numberOfWaysReorderBST(nums) << endl;

	return 0;
}
*/
