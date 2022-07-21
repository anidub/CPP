#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/R1ppNG3nV9R
 * Given a sorted array, create a new array containing squares of all the numbers of the input array in the sorted order.
 * Input: [-2, -1, 0, 2, 3]
Output: [0, 1, 4, 4, 9]
 */
//TC: O(N), SC: O(1)
vector<int> makeSquares(const vector<int> &arr) {
	if(arr.empty()) return {};
	int n = arr.size() - 1; int right = n - 1, left = 0;
	vector<int> squares(n);
	int highestSqIdx = n - 1;

	while(left <= right) {
		int leftSq = arr[left] * arr[left];
		int rightSq = arr[right] * arr[right];

		if(leftSq > rightSq) {
			squares[highestSqIdx--] = leftSq;
			left++;
		} else {
			squares[highestSqIdx--] = rightSq;
			right--;
		}
	}
	return squares;
}
/*
int main() {
	  vector<int> result = makeSquares(vector<int>{-2, -1, 0, 2, 3});
	  for (auto num : result) {
	    cout << num << " ";
	  }
	  cout << endl;

	  result = makeSquares(vector<int>{-3, -1, 0, 1, 2});
	  for (auto num : result) {
	    cout << num << " ";
	  }
	  cout << endl;

	return 0;
}*/
