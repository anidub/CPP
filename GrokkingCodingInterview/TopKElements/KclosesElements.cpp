#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/find-k-closest-elements/solution/
 * https://www.educative.io/courses/grokking-the-coding-interview/N8MJQNYyJPL
 * Given a sorted number array and two integers ‘K’ and ‘X’, find ‘K’ closest numbers to ‘X’ in the array.
 *  Return the numbers in the sorted order. ‘X’ is not necessarily present in the array.
 * Input: [5, 6, 7, 8, 9], K = 3, X = 7
Output: [6, 7, 8]
At each operation, calculate mid = (left + right) / 2 and compare the two elements located at arr[mid] and arr[mid + k]. If the element at arr[mid] is closer to x,
 then move the right pointer. If the element at arr[mid + k] is closer to x, then move the left pointer. Remember, the smaller element always wins when there is a tie.
 */
class KclosestNumbers {
public:
	//TC:O(LOG(N-K)), SC:O(1)
	vector<int> findClosestElements(const vector<int> &A, int k, int x) {
		if(A.empty()) return {};

		int left = 0, right = A.size() - k;

		while(left < right) {
			int mid = left + (right - left) / 2;

			if(x - A[mid] > A[mid + k] - x)
				left = mid + 1;// If the element at arr[mid + k] is closer to x, then move the left pointer.
			else
				right = mid;//If the element at arr[mid] is closer to x, then move the right pointer
		}
		return vector<int>(A.begin() + left, A.begin() + left + k);//At the end of the binary search, we have located the leftmost index for the final answer.
	}
};
/*
int main(int argc, char *argv[]) {
	KclosestNumbers kcn;
  vector<int> result = kcn.findClosestElements(vector<int>{5, 6, 7, 8, 9}, 3, 7);
  cout << "'K' closest numbers to 'X' are: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = kcn.findClosestElements(vector<int>{2, 4, 5, 6, 9}, 3, 6);
  cout << "'K' closest numbers to 'X' are: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}
*/
