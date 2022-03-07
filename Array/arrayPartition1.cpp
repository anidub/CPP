#include <iostream>
#include <vector>

using namespace std;
/*
 * https://leetcode.com/problems/array-partition-i/
 * Share
Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.
Example 1:
Input: nums = [1,4,3,2]
Output: 4
Explanation: All possible pairings (ignoring the ordering of elements) are:
1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
So the maximum possible sum is 4.
https://leetcode.com/problems/array-partition-i/discuss/102260/Sort-solutions-C%2B%2BPython
https://leetcode.com/problems/array-partition-i/discuss/157443/Concise-C%2B%2B

 *
 */
int arrayPairSum(vector<int>& nums) {
	if(nums.size() == 0) return {};
	//sort(nums.begin(), nums.end()); //works
	int sum = 0;
	for(int i = 0; i < nums.size()/2; i+=2) {
		sum += nums[i];
	}
	return sum;
}
//works too with different for loop
/*
 *  int arrayPairSum(vector<int>& A, int sum=0) {
        sort( A.begin(), A.end() );
        for ( auto it = A.begin();  it != A.end();  advance( it, 2 )  )
        {
            sum += *it;
        }
        return sum;
    }
 */

/*
int main() {

	return 0;
} */
