#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>
#include <unordered_map>

using namespace std;
/*
 * https://leetcode.com/problems/count-good-meals/
 * A good meal is a meal that contains exactly two different food items with a sum of deliciousness equal to a power of two.
You can pick any two different foods to make a good meal.
Given an array of integers deliciousness where deliciousness[i] is the deliciousness of the i​​​​​​th​​​​​​​​ item of food, return the number of different good meals you can make from this list modulo 109 + 7.
Note that items with different indices are considered different even if they have the same deliciousness value.
Example 1:

Input: deliciousness = [1,3,5,7,9]
Output: 4
Explanation: The good meals are (1,3), (1,7), (3,5) and, (7,9).
Their respective sums are 4, 8, 8, and 16, all of which are powers of 2.
https://leetcode.com/problems/count-good-meals/discuss/999120/C%2B%2B-hashmap
 */
//Time : O(21n), Space : O(n)
int countGoodMeals(vector<int>& meals) {
	if(meals.empty()) return 0;
	int n = meals.size();
	unordered_map<int, int> mp;
	int result = 0, M = 1e9 + 7;
	mp[meals[0]]++;

	for(int i = 1; i < n; i++) {
		for(int p = 0; p <= 21; p++) {
			int target = (int)pow(2, p) - meals[i];
			if(mp.find(target) != mp.end()) {
				result += mp[target] % M;
				result = result % M;
			}
		}
		mp[meals[i]]++;
	}
	return result;
}
/*
int main() {
	vector<int> meals;
	meals.push_back(1);meals.push_back(3);meals.push_back(5);meals.push_back(7);meals.push_back(9);
	cout << countGoodMeals(meals) << endl;

	return 0;
}*/
