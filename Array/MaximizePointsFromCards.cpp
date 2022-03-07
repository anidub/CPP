#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_set>

using namespace std;
/*
 * https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
 * There are several cards arranged in a row, and each card has an associated number of points The points are given in the integer array cardPoints.
In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
Your score is the sum of the points of the cards you have taken.
Given the integer array cardPoints and the integer k, return the maximum score you can obtain.
Example 1:
Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.

https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/discuss/598091/C%2B%2B-with-explanation
O(k) complexity
 */

int maximizePointsFromCards(vector<int>& cardPoints, int k) {
	if(cardPoints.empty()) return 0;
	int leftSum = 0, rightSum = 0;
	int result; int n = cardPoints.size();

	for(int i = 0; i < k; i++)
		rightSum += cardPoints[n - i - 1];
	result = rightSum;
	for(int i = 0; i < k; i++) {
		leftSum += cardPoints[i];
		rightSum -= cardPoints[n - k + i];
		result = max(result, leftSum + rightSum);
	}
	return result;
}

/*
int main() {
	vector<int> cardPoints;
	cardPoints.push_back(9);cardPoints.push_back(7);cardPoints.push_back(7);cardPoints.push_back(9);
	cardPoints.push_back(7);cardPoints.push_back(7);cardPoints.push_back(9);
	cout << maximizePointsFromCards(cardPoints, 7) << endl;
	return 0;
}
*/
