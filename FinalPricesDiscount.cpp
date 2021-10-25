#include <iostream>
#include <vector>

using namespace std;
/*
 * https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/
 * Given the array prices where prices[i] is the price of the ith item in a shop.
 * There is a special discount for items in the shop, if you buy the ith item,
 * then you will receive a discount equivalent to prices[j] where j is the minimum index
 * such that j > i and prices[j] <= prices[i],
 *  otherwise, you will not receive any discount at all.
 *  Input: prices = [8,4,6,2,3]
Output: [4,2,4,2,3]
Explanation:
For item 0 with price[0]=8 you will receive a discount equivalent to prices[1]=4, therefore, the final price you will pay is 8 - 4 = 4.
For item 1 with price[1]=4 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 4 - 2 = 2.
For item 2 with price[2]=6 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 6 - 2 = 4.
For items 3 and 4 you will not receive any discount at all.
https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/discuss/685390/JavaC%2B%2BPython-Stack-One-Pass
 */

vector<int> finalPrices(vector<int>& prices) {
	if(prices.size() == 0) return {};
	int n = prices.size();
	vector<int> result(n,0);
	for(int i = 0; i < n; i++) {
		int j = i+1;
		while(j < n) {
			if(prices[j] <= prices[i]){
				result[i] = prices[i] - prices[j];
				break;
			}
			j++;
		}
		if(j == n)
			result[i] = prices[i];
	}
	return result;
}

//in place O(N)
vector<int> finalPricesInPlace(vector<int>& prices) {
	if(prices.size() == 0) return {};
	vector<int> stack;

	for(int i = 0; i < prices.size(); i++) {
		while(stack.size() && prices[stack.back()] >= prices[i]) {
			prices[stack.back()] -= prices[i];
			stack.pop_back();
		}
		stack.push_back(i);
	}
	for(int i : prices)
		cout << i << " ";
	return prices;
}

/*
int main() {
	vector<int> nums;
	nums.push_back(8);nums.push_back(4);nums.push_back(6);nums.push_back(2);nums.push_back(3);
	finalPricesInPlace(nums);

	return 0;
} */
