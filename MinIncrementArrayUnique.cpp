#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_set>

using namespace std;
/*
 * https://leetcode.com/problems/minimum-increment-to-make-array-unique/
 * Given an array of integers A, a move consists of choosing any A[i], and incrementing it by 1.
Return the least number of moves to make every value in A unique.
Example 1:
Input: [1,2,2]
Output: 1
Explanation:  After 1 move, the array could be [1, 2, 3].
https://leetcode.com/problems/minimum-increment-to-make-array-unique/discuss/197713/C%2B%2B-concise-solution-O(nlogn)-complexity-with-explanation-and-example-step-by-step used
https://leetcode.com/problems/minimum-increment-to-make-array-unique/discuss/197687/JavaC%2B%2BPython-Straight-Forward
Time Complexity: O(NlogN) for sorting
Space: O(1) for in-space sort
 */
int minIncrementArrayUnique(vector<int>& A) {
	if(A.empty()) return 0;
	sort(A.begin(), A.end());
	int result = 0;
	for(int i = 1; i < A.size(); i++) {
		if(A[i] <= A[i-1]) {
			result += A[i-1]+1 - A[i];
			A[i] = A[i-1] + 1;
		}
	}
	return result;
}
/*
int main() {
	vector<int> A;
	A.push_back(3);A.push_back(2);A.push_back(1);A.push_back(2);A.push_back(1);A.push_back(7);
	cout << minIncrementArrayUnique(A) << endl;

	return 0;
}*/
