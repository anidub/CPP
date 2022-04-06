#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <stack>

using namespace std;
/*https://leetcode.com/problems/cutting-ribbons/
 *ou are given an integer array ribbons, where ribbons[i] represents the length of the ith ribbon, and an integer k. You may cut any of the ribbons into any number of segments of positive integer lengths, or perform no cuts at all.

For example, if you have a ribbon of length 4, you can:
Keep the ribbon of length 4,
Cut it into one ribbon of length 3 and one ribbon of length 1,
Cut it into two ribbons of length 2,
Cut it into one ribbon of length 2 and two ribbons of length 1, or
Cut it into four ribbons of length 1.
Your goal is to obtain k ribbons of all the same positive integer length. You are allowed to throw away any excess ribbon as a result of cutting.

Return the maximum possible positive integer length that you can obtain k ribbons of, or 0 if you cannot obtain k ribbons of the same length.

Input: ribbons = [9,7,5], k = 3
Output: 5
Explanation:
- Cut the first ribbon to two ribbons, one of length 5 and one of length 4.
- Cut the second ribbon to two ribbons, one of length 5 and one of length 2.
- Keep the third ribbon as it is.
Now you have 3 ribbons of length 5.

https://leetcode.com/problems/cutting-ribbons/discuss/1341147/Binary-Search-with-Explanation-or-C%2B%2B
 *
 */
bool isPossible(vector<int> &ribbons, int len, int k);

//TC: O(N) : to count total
int maxLengthOfRibbons(vector<int>& ribbons, int k) {
	if(ribbons.empty()) return 0;
	long long total = 0;
	for(int &ribbon : ribbons) total += ribbon;

	if (total < k) return 0;

	int low = 1; //min length of ribbon
	int high = total / k; //max length of ribbon possible

	int ans = 0, mid;
	while(low <= high) {
		mid = low + (high - low)/2;
		if(isPossible(ribbons, mid, k)) {
			ans = mid;
			low = mid + 1;
		} else
			high = mid - 1;
	}
	return ans;
}

bool isPossible(vector<int> &ribbons, int len, int k) {
	int count = 0;
	for(int &ribbon : ribbons) {
		count += ribbon / len;
		if(count >= k) return true;
	}
	return false;
}
/*
int main() {
	vector<int> ribbons = {9,7,5};
	cout << maxLengthOfRibbons(ribbons,  3) << endl;


	return 0;
}*/
