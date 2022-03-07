#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;

/*https://leetcode.com/problems/pizza-with-3n-slices/
 * There is a pizza with 3n slices of varying size, you and your friends will take slices of pizza as follows:

You will pick any pizza slice.
Your friend Alice will pick next slice in anti clockwise direction of your pick.
Your friend Bob will pick next slice in clockwise direction of your pick.
Repeat until there are no more slices of pizzas.
Sizes of Pizza slices is represented by circular array slices in clockwise direction.

Return the maximum possible sum of slice sizes which you can have.
Input: slices = [1,2,3,4,5,6]
Output: 10
Explanation: Pick pizza slice of size 4, Alice and Bob will pick slices with size 3 and 5 respectively.
Then Pick slices with size 6, finally Alice and Bob will pick slice of size 2 and 1 respectively. Total = 4 + 6.
https://leetcode.com/problems/pizza-with-3n-slices/discuss/1387298/c%2B%2B-recursion%2Bmemosition : used
https://leetcode.com/problems/pizza-with-3n-slices/discuss/547699/C%2B%2B-Simple-DP
 */

//Time: O(n^2) Space: O(n)
int maxSlicesPizzaHelper(vector<int>& a, int i, int j, vector<vector<int>>& dp, int slice) {
	if(slice == 0 || i > j) return 0;
	if(i == j) return a[i];
	if(dp[i][slice] != -1) return dp[i][slice];

	int op1 = a[i] + maxSlicesPizzaHelper(a, i+2, j, dp, slice-1);
	int op2 = maxSlicesPizzaHelper(a, i+1, j, dp, slice);

	dp[i][slice] = max(op1, op2);
	return dp[i][slice];
}


int maxSlicesPizza(vector<int>& slices) {
	if(slices.empty()) return 0;
	int n = slices.size();

	vector<vector<int>> dp1(n+1, vector<int>(n/3+1, -1));
	vector<vector<int>> dp2(n+1, vector<int>(n/3+1, -1));

	return max(maxSlicesPizzaHelper(slices, 0, n-2, dp1, n/3), maxSlicesPizzaHelper(slices, 1, n-1, dp2, n/3));
}
/*
int main() {
	vector<int> pizza;
	pizza.push_back(1);pizza.push_back(2);pizza.push_back(3);pizza.push_back(4);pizza.push_back(5);pizza.push_back(6);
	cout << maxSlicesPizza(pizza) << endl;

	return 0;
}*/
