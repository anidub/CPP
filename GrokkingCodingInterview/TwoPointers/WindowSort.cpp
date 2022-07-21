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
/*https://www.educative.io/courses/grokking-the-coding-interview/N8rOAP6Lmw6
 *Given an array, find the length of the smallest subarray in it which when sorted will sort the whole array.
 *Given Input: [1, 3, 2, 0, -1, 7, 10]
Output: 5
Explanation: We need to sort only the subarray [1, 3, 2, 0, -1] to make the whole array sorted
 */
//TC:O(N)
int minWindowSort(const vector<int> &arr) {
	if(arr.empty()) return 0;

	int low = 0, high = arr.size() - 1;

	while(low < arr.size() - 1 && arr[low] <= arr[low + 1])
		low++;

	if(low == arr.size() - 1) return 0;

	while(high > 0 && arr[high - 1]  <= arr[high])
		high--;

	int minNum = INT_MAX, maxNum = INT_MIN;

	for(int i = low; i <= high; i++) {
		minNum = min(minNum, arr[i]);
		maxNum = max(maxNum, arr[i]);
	}

	while(low > 0 && arr[low - 1] > minNum)
		low--;

	while(high < arr.size() - 1 && arr[high + 1] < maxNum)
		high++;

	return high - low + 1;
}
/*
int main() {
	  cout << minWindowSort(vector<int>{1, 2, 5, 3, 7, 10, 9, 12}) << endl;
	  cout << minWindowSort(vector<int>{1, 3, 2, 0, -1, 7, 10}) << endl;
	  cout << minWindowSort(vector<int>{1, 2, 3}) << endl;
	  cout << minWindowSort(vector<int>{3, 2, 1}) << endl;

	return 0;
}*/
