#include <iostream>
#include <vector>

using namespace std;
/*
 * https://leetcode.com/problems/count-largest-group/
 * Given an integer n. Each number from 1 to n is grouped according to the sum of its digits.

Return how many groups have the largest size.
Example 1:
Input: n = 13
Output: 4
Explanation: There are 9 groups in total, they are grouped according sum of its digits of numbers from 1 to 13:
[1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9]. There are 4 groups with largest size.
https://leetcode.com/problems/count-largest-group/discuss/695877/C%2B%2B-and-Python-solutions
https://leetcode.com/problems/count-largest-group/discuss/671815/c%2B%2B-easy-solution...
 */
int getSum(int n) {
	int sum = 0;
	while(n > 0) {
		sum += n%10;
		n = n/10;
	}
	return sum;
}
int countLargestGroup(int n) {
	vector<int> frequency(37,0); //37 coz max num is 9999 so sum of its digits = 36
	for(int i = 1; i <= n; i++) { // <= since n needs to be included
		++frequency[getSum(i)];
	}

	int maxSize = 0;
	//maxsize = *max_element(frequency.begin(), frequency.end()); works use this
	int result = 0;
	for(int i = 0; i < frequency.size(); i++) {
		if(frequency[i] == maxSize)
			result++;
	}
	return result;
}

/*
int main() {
	return 0;
}*/
