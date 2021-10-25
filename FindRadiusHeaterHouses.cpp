#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>

using namespace std;
/*
 * https://leetcode.com/problems/heaters/
 * Winter is coming! During the contest, your first job is to design a standard heater with a fixed warm radius to warm all the houses.
Every house can be warmed, as long as the house is within the heater's warm radius range.
Given the positions of houses and heaters on a horizontal line, return the minimum radius standard of heaters so that those heaters could cover all houses.
Notice that all the heaters follow your radius standard, and the warm radius will the same.

Example 1:

Input: houses = [1,2,3], heaters = [2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.
https://leetcode.com/problems/heaters/discuss/95889/simple-C%2B%2B-solution
https://leetcode.com/problems/heaters/discuss/95887/C%2B%2B-clean-solution-with-explanation : not great soln but for understanding
 */
int findRadiusHeaterHouses(vector<int> heaters, vector<int> houses) {
	if(houses.empty() || heaters.empty()) return 0;
	int radius = 0, index  = 0;
	sort(houses.begin(), houses.end());
	sort(heaters.begin(), heaters.end());

	for(int i = 0; i < houses.size(); i++) {
		while(index+1 < heaters.size() && abs(heaters[index+1] - houses[i]) <= abs(heaters[index] - houses[i]))
			index++;
		radius = max(radius, abs(heaters[index] - houses[i]));
	}
	return radius;
}
/*
int main() {
	vector<int> houses; houses.push_back(1);houses.push_back(2);houses.push_back(3);
	vector<int> heaters; heaters.push_back(2);

	cout << findRadiusHeaterHouses(heaters, houses) << endl;
	return 0;
}*/
