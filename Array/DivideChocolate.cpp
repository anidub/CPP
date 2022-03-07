#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>

using namespace std;
/*https://www.acwing.com/solution/content/5444/
 * https://wentao-shao.gitbook.io/leetcode/array/1231.divide-chocolate
 * You have one chocolate bar that consists of some chunks. Each chunk has its own sweetness given by the array sweetness.

You want to share the chocolate with your K friends so you start cutting the chocolate bar into K+1 pieces using K cuts, each piece consists of some consecutive chunks.

Being generous, you will eat the piece with the minimum total sweetness and give the other pieces to your friends.

Find the maximum total sweetness of the piece you can get by cutting the chocolate bar optimally.

Example 1:
Input: sweetness = [1,2,3,4,5,6,7,8,9], K = 5
Output: 6
Explanation: You can divide the chocolate to [1,2,3], [4,5], [6], [7], [8], [9]

Example 2:
Input: sweetness = [5,6,7,8,9,1,2,3,4], K = 8
Output: 1
Explanation: There is only one way to cut the bar into 9 pieces.

Example 3:
Input: sweetness = [1,2,2,1,2,2,1,2,2], K = 2
Output: 5
Explanation: You can divide the chocolate to [1,2,2], [1,2,2], [1,2,2]

Constraints:
0 <= K < sweetness.length <= 10^4
1 <= sweetness[i] <= 10^5
 *
 */
bool checkSweetness(int mid, vector<int>& sweetness, int K) {
	int sum = 0, count = 0;
	for(int i = 0; i < sweetness.size(); i++) {
		sum += sweetness[i];
		if(sum >= mid) {
			sum = 0;
			count++;
			if(count > K)
				return true;
		}
	}
	return false;
}

//Time comlexity : O(nlogn)
int maximizeSweetness(vector<int>& sweetness, int K) {
	int l = 0;
	int sum = 0;
	for(int& i : sweetness)
		sum += i;
	int r = sum;

	while(l < r) {
		int mid = l + (r-l)/2;
		if(checkSweetness(mid, sweetness, K)) l = mid+1;
		else
			r = mid-1;
	}
	return l;
}
/*
int main() {
	vector<int> nums; nums.push_back(1);nums.push_back(2);nums.push_back(3);
	nums.push_back(4);nums.push_back(5);nums.push_back(6);nums.push_back(7);
	nums.push_back(8);nums.push_back(9);
	cout << maximizeSweetness(nums, 5) << endl;
	return 0;
}*/
