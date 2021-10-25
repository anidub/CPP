#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>

using namespace std;
/*
 * https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/
In a deck of cards, each card has an integer written on it.
Return true if and only if you can choose X >= 2 such that it is possible to split the entire deck into 1 or more groups of cards, where:
Each group has exactly X cards.
All the cards in each group have the same integer.
Example 1:
Input: deck = [1,2,3,4,4,3,2,1]
Output: true
Explanation: Possible partition [1,1],[2,2],[3,3],[4,4].

Input: deck = [1,1,2,2,2,2]
Output: true
Explanation: Possible partition [1,1],[2,2],[2,2].
https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/discuss/372172/Easy-C%2B%2B-solution-using-GCD-beats-95-100
 */

int gcd(int a, int b) {
	if(a == 0)
		return b;
	else
		return gcd(b%a, a);
}

bool hasGroupsSizeX(vector<int>& deck) {
	if(deck.size() == 0) return false;
	if(deck.size() < 2) return false;

	unordered_map<int, int> umap;
	for(int& i: deck) {
		umap[i]++;
	}

	int noOfGroups = umap.begin()->second;
	for(auto it = umap.begin(); it != umap.end(); it++) {
		if(it->second < 2)
			return false;
		noOfGroups = gcd(noOfGroups, it->second);
	}
	return noOfGroups >= 2;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(2);nums.push_back(3);nums.push_back(4);
	nums.push_back(4);nums.push_back(3);nums.push_back(2);nums.push_back(1);

	cout << hasGroupsSizeX(nums) << endl;
}

*/
