#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/median-of-two-sorted-arrays/
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log(min(M,N)))
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2471/Very-concise-O(log(min(MN)))-iterative-solution-with-detailed-explanation : comments
https://www.youtube.com/watch?v=LPFhl65R7ww : well explained

Equations:
	N1 should always be smaller
	partition of n1 = x = (low + high) / 2
	partition of n2 = y = (length of n1 + length of n2 + 1) / 2 - x

	Found :
	 maxleft n1 <= minright n2
	 maxleft n2 <= minright n1

	 else if
	 	 maxleft n1 >= minright n2
	 	 move towards left in n1

	 else
	 	 move towards right in n1
 */



//O(log(min(M,N)))
double medianSortedArrays(vector<int> num1, vector<int> num2) {
	if(num1.size() > num2.size())
		return medianSortedArrays(num2, num1);

	int n1 = num1.size(), n2 = num2.size();

	int low = 0, high = n1;

	while(low <= high) {
		int cut1 = (low + high) / 2;
		int cut2 = (n1 + n2) / 2 - cut1;

		int l1 = cut1 == 0 ? INT_MIN : num1[cut1 - 1];
		int l2 = cut2 == 0 ? INT_MIN : num2[cut2 - 1];
		int r1 = cut1 == n1 ? INT_MAX : num1[cut1];
		int r2 = cut2 == n2 ? INT_MAX : num2[cut2];

		if(l1 > r2) high = cut1 - 1;
		else if(l2 > r1) low = cut1 + 1;
		else return (n1 + n2) % 2 ? min(r1, r2) : (max(l1, l2) + min(r1, r2))/2. ;
	}
	return -1;
}
/*
int main() {
	vector<int> n1 = {1,3};
	vector<int> n2 = {2};
	cout << medianSortedArrays(n1, n2) << endl;

	return 0;
}*/
