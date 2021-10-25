#include <iostream>
#include <vector>

using namespace std;
/*
 * https://leetcode.com/problems/mean-of-array-after-removing-some-elements/
 * Given an integer array arr, return the mean of the remaining integers
 * after removing the smallest 5% and the largest 5% of the elements.
Answers within 10-5 of the actual answer will be considered accepted.
Input: arr = [1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3]
Output: 2.00000
Explanation: After erasing the minimum and the maximum values of this array,
all elements are equal to 2, so the mean is 2.
https://leetcode.com/problems/mean-of-array-after-removing-some-elements/discuss/898740/C%2B%2B-Simple-Sort-Solution
https://leetcode.com/problems/mean-of-array-after-removing-some-elements/discuss/900529/C%2B%2B-O(n)-nth_element

 */

double trimMean(vector<int>& arr) {
	double result = 0.0;
	if(arr.size() == 0)
		return result;
	int size = arr.size();
	if(size < 20) return result;
	//sort(arr.begin(), arr.end()); works

	int sum = 0;
	for(int i = size/20; i < (size - size/20); i++) {
		sum += arr[i];
	}

	return (double) sum/ (size - (2*size/20));
}
/*
int main () {

	return 0;
}*/
