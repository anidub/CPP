#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>
#include <unordered_set>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/koko-eating-bananas/
 * Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

https://leetcode.com/problems/koko-eating-bananas/discuss/1703687/JavaC%2B%2B-A-very-very-well-detailed-explanation
 */

bool canEatBananas(vector<int> &piles, int k, int h);

//O(N * log(M)) where N is no of piles & M is range of K (left to right), SC: O(1)
int minEatingSpeed(vector<int>& piles, int h) {
	int left = 1;
	int right = 100000000; //range in question.Binary search between [1, 10^9] or [1, max(piles)] to find the result.

	while(left <= right) {
		int mid = left + (right - left) / 2;

		if(canEatBananas(piles, mid, h)) right = mid - 1;
		else left = mid + 1;
	}
	return left;
}

bool canEatBananas(vector<int> &piles, int k, int h) {
	int hours = 0;
	for(int pile : piles) {
		int div = pile / k;
		hours += div;
		if(pile % k != 0) hours++;
	}
	return hours <= h;
}

/*
int main() {
	vector<int> piles = {3 ,6 ,7, 11};
	cout << minEatingSpeed(piles, 8) << endl;

	return 0;
}*/
