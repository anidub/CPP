#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <map>
#include <utility>

using namespace std;

/*
 * https://www.programmersought.com/article/51894316599/
 * https://www.geeksforgeeks.org/minimum-swaps-required-group-1s-together/
 * Given a binary array data, return the minimum number of swaps required to group all 1’s present in the array together in any place in the array.
 * Input: [1,0,1,0,1]
Output: 1
Explanation:
There are 3 ways to group all 1's together:
[1,1,1,0,0] using 1 swap.
[0,1,1,1,0] using 2 swaps.
[0,0,1,1,1] using 1 swap.
The minimum is 1.
https://blog.csdn.net/fuxuemingzhu/article/details/101207781

The idea is get the window with max number of ones or with min number of zeros. so use sliding window technique to get
max number of ones. Once we get that we subtract total number of ones - this window
https://www.youtube.com/watch?v=__ZlO8_g_Fw
https://blog.csdn.net/fuxuemingzhu/article/details/101207781
https://www.geeksforgeeks.org/minimum-swaps-required-group-1s-together/
 */

int minSwap(vector<int>& data) {
	if(data.empty()) return 0;
	int numberOfOnes = accumulate(data.begin(), data.end(), 0);
	int left = -numberOfOnes;
	int right = 0;

	int one_count = 0;
	int K = 0;

	while(right < data.size()) {
		if(data[right] == 1)
			one_count++;

		if(left >= 0 && data[left] == 1)
			one_count--;

		K = max(K, one_count);
		left++; right++;
	}
	return numberOfOnes - K;
}
/*
int main () {
	vector<int> nums;
	nums.push_back(1);nums.push_back(0);nums.push_back(1);nums.push_back(0);
	nums.push_back(1);nums.push_back(0);nums.push_back(0);nums.push_back(1);
	nums.push_back(1);nums.push_back(0);nums.push_back(1);
	cout << minSwap(nums) << endl;
	return 0;
}
*/
