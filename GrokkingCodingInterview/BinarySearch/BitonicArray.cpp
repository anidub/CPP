#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/RMyRR6wZoYK
 * Find the maximum value in a given Bitonic array. An array is considered bitonic if
 *  it is monotonically increasing and then monotonically decreasing. Monotonically increasing or
 *   decreasing means that for any index i in the array arr[i] != arr[i+1].
 * Input: [1, 3, 8, 12, 4, 2]
Output: 12
Explanation: The maximum number in the input bitonic array is '12'.

 */
class MaxInBitonicArray {
public:
	//TC:O(LOGN), SC:O(1)
	int getMaximumInBitonicArray(const vector<int> &arr) {
		int start = 0, end = arr.size() - 1;

		while(start < end) {
			int mid = start + (end - start) / 2;

			if(arr[mid] > arr[mid + 1])
				end = mid;
			else
				start = mid + 1;
		}
		return arr[end];  // at the end of the while loop, 'start == end'
	}
};
/*
int main(int argc, char* argv[]) {
	MaxInBitonicArray miba;
  cout << miba.getMaximumInBitonicArray(vector<int>{1, 3, 8, 12, 4, 2}) << endl;
  cout << miba.getMaximumInBitonicArray(vector<int>{3, 8, 3, 1}) << endl;
  cout << miba.getMaximumInBitonicArray(vector<int>{1, 3, 8, 12}) << endl;
  cout << miba.getMaximumInBitonicArray(vector<int>{10, 9, 8}) << endl;
}
*/
