#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <set>
#include <unordered_map>

using namespace std;

/*
 * https://leetcode.com/problems/kth-missing-positive-number/
 * iven an array arr of positive integers sorted in a strictly increasing order, and an integer k.
Find the kth positive integer that is missing from this array.
Example 1:
Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.

Solution explained: https://leetcode.com/problems/kth-missing-positive-number/discuss/1004437/C%2B%2B-Optimized-Solution-with-Detailed-Explanation-C%2B%2B-100Faster-0-ms
https://leetcode.com/problems/kth-missing-positive-number/discuss/783950/C%2B%2B
https://leetcode.com/problems/kth-missing-positive-number/discuss/779999/JavaC%2B%2BPython-O(logN)
 */
/*
 * https://leetcode.com/problems/kth-missing-positive-number/discuss/779999/JavaC%2B%2BPython-O(logN)
 * for left + k ?
 * Lets check example arr = [2,3,4,7,11], k = 5

In general, we found an index, where the amount of missed is more than K, this is index 4 with value 11.
At this index we have (arr[l]-(l+1)) missed numbers - 11-(4+1) = 6 numbers missed.
Here we see that 6th missed number is 10, 5th missed number is 9, 4th missed number is 8.
We can find that our missed number is arr[l]-(missedNumbers-k+1)
k=5, 5th missed number: - 11-(6-5+1) = 9

If we put missedNumbers to general formula, we will have arr[l]-((arr[l]-(l+1))-k+1)
And than by math rules we start transforming:
arr[l]-((arr[l]-(l+1))-k+1) -> arr[l]-((arr[l]-l-1)-k+1) -> arr[l]-(arr[l]-l-1-k+1) -> arr[l]-(arr[l]-l-k) -> arr[l]-arr[l]+l+k -> l+k

Here is how we came to l + k.
 */
int findKthPositive(vector<int>& arr, int k) {
	if(arr.size() == 0) return -1;
	int left = 0;
	int right = arr.size() - 1;
	while(left <= right) {
		int pivot = left + (right - left) / 2;
		if(arr[pivot] - pivot - 1 < k)
			left = pivot + 1;
		else
			right = pivot - 1;
	}
	return left + k;
}

int findKthPositiveBrute(vector<int>& arr, int k) {
	if(arr.size() == 0) return -1;
	vector<int> missing;
	int index = 0;
	for(int i = 1; i <= arr[arr.size() - 1]; i++) {
		if(i == arr[index])
			index++;
		else
			missing.push_back(i);
	}

	if(missing.size() >= k)
		return missing[k-1];
	else
		return arr[arr.size() - 1] + k - missing.size();
}
/*
int main() {
	vector<int> nums;
	nums.push_back(2);nums.push_back(3);nums.push_back(4);nums.push_back(7);nums.push_back(11);
	cout << findKthPositive(nums,5) << endl;
	cout << findKthPositiveBrute(nums,5) << endl;

	return 0;
}*/
