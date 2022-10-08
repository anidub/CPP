#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_set>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/gkZNLjV2kBk
 * Given two integer arrays to represent weights and profits of ‘N’ items, we need to find a subset of these
 * items which will give us maximum profit such that their cumulative weight is not more than a given number ‘C.’
 *  Each item can only be selected once, which means either we put an item in the knapsack or we skip it.
 *  Items: { Apple, Orange, Banana, Melon }
Weights: { 2, 3, 1, 4 }
Profits: { 4, 5, 3, 7 }
Knapsack capacity: 5

Let’s try to put various combinations of fruits in the knapsack, such that their total weight is not more than 5:

Apple + Orange (total weight 5) => 9 profit
Apple + Banana (total weight 3) => 7 profit
Orange + Banana (total weight 4) => 8 profit
Banana + Melon (total weight 5) => 10 profit

This shows that Banana + Melon is the best combination as it gives us the maximum profit, and the total weight does not exceed the capacity.
 */
class Knapsack {
public:
	  int solveKnapsackRecursive(const vector<int> &profits, vector<int> &weights, int capacity) {
		  return this->knapsackRecursive(profits, weights, capacity, 0);
	  }

	  int solveKnapsackMemoization(const vector<int> &profits, vector<int> &weights, int capacity) {
		  vector<vector<int>> memo(profits.size(), vector<int>(capacity + 1, -1));
		  return this->solveKnapsackMemoization(memo, profits, weights, capacity, 0);
	  }

	  int solveKnapsackBottomUpDP(const vector<int> &profits, vector<int> &weights, int capacity) {
		  if(capacity <= 0 || profits.size() != weights.size() || profits.empty())
			  return 0;
		  int n = profits.size();
		  vector<vector<int>> dp(n, vector<int>(capacity + 1));

		  // populate the capacity=0 columns, with '0' capacity we have '0' profit
		  for(int i = 0; i < n; i++)
			  dp[i][0] = 0;

		  // if we have only one weight, we will take it if it is not more than the capacity
		  for(int c = 0; c <= capacity; c++)
			  if(weights[0] <= c)
				  dp[0][c] = profits[0];

		  for(int i = 1; i < n; i++) {
			  for(int c = 1; c <= capacity; c++) {
				  int profitInclude = 0, profitExclude = 0;

				  if(weights[i] <= c)// include the item, if it is not more than the capacity
					  profitInclude = profits[i] + dp[i - 1][c - weights[i]];

				  profitExclude = dp[i - 1][c]; // exclude the item

				  dp[i][c] = max(profitInclude, profitExclude);
			  }
		  }
		  return dp[n - 1][capacity];// maximum profit will be at the bottom-right corner.
	  }

/*Since our inner loop is iterating over c:0-->capacity, let’s see how this might affect our two required values:

When we access dp[c], it has not been overridden yet for the current iteration, so it should be fine.
dp[c-weight[i]] might be overridden if “weight[i] > 0”. Therefore we can’t use this value for the current iteration.
To solve the second case, we can change our inner loop to process in the reverse direction: c:capacity-->0.
This will ensure that whenever we change a value in dp[], we will not need it again in the current iteration.
 *
 */
	  //TC:O(N*C), SC:O(C)
	  int solveKnapsackSpaceOptimization(const vector<int> &profits, vector<int> &weights, int capacity) {
		    if (capacity <= 0 || profits.empty() || weights.size() != profits.size()) {
		      return 0;
		    }
		    int n = profits.size();

		    vector<int> dp(capacity + 1);

		    for(int c = 0; c <= capacity; c++)
		    	if(weights[0] <= c)
		    		dp[c] = profits[0];

		    for(int i = 1; i < n; i++) {
		    	for(int c = capacity; c >= 0; c--) {
		    		int profitInclude = 0, profitExclude = 0;

		    		if(weights[i] <= c)// include the item, if it is not more than the capacity
		    			profitInclude = profits[i] + dp[c - weights[i]];

		    		profitExclude = dp[c]; // exclude the item

		    		dp[c] = max(profitInclude, profitExclude);
		    	}
		    }
		    return dp[capacity];
	  }

private:
	  //TC:O(2^N), SC:o(N)
	  int knapsackRecursive(const vector<int> &profits, vector<int> &weights, int capacity, int currentIndex) {
		  if(capacity <= 0 || currentIndex >= profits.size())  // base checks
			  return 0;

		  int profitInclude = 0;

		  // recursive call after choosing the element at the currentIndex
		  if(weights[currentIndex] <= capacity)
			  profitInclude  = profits[currentIndex] + knapsackRecursive(profits, weights, capacity - weights[currentIndex], currentIndex + 1);

		  // recursive call after excluding the element at the currentIndex
		  int profitExclude = knapsackRecursive(profits, weights, capacity, currentIndex + 1);

		  return max(profitExclude, profitInclude);
	  }

	  //TC: O(N * C), SC:O(N * C)
	  //Since our memoization array dp[profits.length][capacity+1] stores the results for all subproblems,
	  //we can conclude that we will not have more than N* C subproblems (where ‘N’ is the number of items and ‘C’ is the knapsack capacity).
	  int solveKnapsackMemoization(vector<vector<int>> &memo, const vector<int> &profits, vector<int> &weights, int capacity, int currentIndex) {
		  if(capacity <= 0 || currentIndex >= profits.size())
			  return 0;

		  if(memo[currentIndex][capacity] != -1)
			  return memo[currentIndex][capacity];

		  int profitInclude = 0;
		  if(weights[currentIndex] <= capacity)
			  profitInclude = profits[currentIndex] + solveKnapsackMemoization(memo, profits, weights, capacity - weights[currentIndex], currentIndex + 1);

		  int profitExclude = solveKnapsackMemoization(memo,  profits, weights, capacity, currentIndex + 1);

		  memo[currentIndex][capacity] = max(profitInclude, profitExclude);
		  return memo[currentIndex][capacity];
	  }

};

/*
int main(int argc, char *argv[]) {
  Knapsack ks;
  vector<int> profits = {1, 6, 10, 16};
  vector<int> weights = {1, 2, 3, 5};
  int maxProfit = ks.solveKnapsackRecursive(profits, weights, 7);
  cout << "Total knapsack profit ---> " << maxProfit << endl;
  maxProfit = ks.solveKnapsackRecursive(profits, weights, 6);
  cout << "Total knapsack profit ---> " << maxProfit << endl;


  maxProfit = ks.solveKnapsackMemoization(profits, weights, 7);
    cout << "Total knapsack memo profit ---> " << maxProfit << endl;
    maxProfit = ks.solveKnapsackMemoization(profits, weights, 6);
    cout << "Total knapsack memo profit ---> " << maxProfit << endl;


    maxProfit = ks.solveKnapsackBottomUpDP(profits, weights, 7);
      cout << "Total knapsack bottom up profit ---> " << maxProfit << endl;
      maxProfit = ks.solveKnapsackBottomUpDP(profits, weights, 6);
      cout << "Total knapsack  bottom up  profit ---> " << maxProfit << endl;


      maxProfit = ks.solveKnapsackSpaceOptimization(profits, weights, 7);
        cout << "Total knapsack bottom up profit ---> " << maxProfit << endl;
        maxProfit = ks.solveKnapsackSpaceOptimization(profits, weights, 6);
        cout << "Total knapsack  bottom up  profit ---> " << maxProfit << endl;

}*/
