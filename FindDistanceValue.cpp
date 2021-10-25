#include <iostream>
#include <vector>

using namespace std;

/*
 * https://leetcode.com/problems/find-the-distance-value-between-two-arrays/
 *
 * Given two integer arrays arr1 and arr2, and the integer d,
 * return the distance value between the two arrays.

The distance value is defined as the number of elements arr1[i]
 such that there is not any element arr2[j] where |arr1[i]-arr2[j]| <= d.
 Input: arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2
Output: 2
For arr1[0]=4 we have:
|4-10|=6 > d=2
|4-9|=5 > d=2
|4-1|=3 > d=2
|4-8|=4 > d=2
For arr1[1]=5 we have:
|5-10|=5 > d=2
|5-9|=4 > d=2
|5-1|=4 > d=2
|5-8|=3 > d=2
For arr1[2]=8 we have:
|8-10|=2 <= d=2
|8-9|=1 <= d=2
|8-1|=7 > d=2
|8-8|=0 <= d=2

https://www.youtube.com/watch?v=uEDL-o3ws9Q
https://leetcode.com/problems/find-the-distance-value-between-two-arrays/discuss/556187/C%2B%2B-Binary-Search
 *
 * https://leetcode.com/problems/find-the-distance-value-between-two-arrays/discuss/613199/C%2B%2B-Memory-and-Runtime-Efficient
 */

//optimum nlogm
int findDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
	if(arr1.size() == 0 || arr2.size() == 0)
		return 0;
	int result = 0;
	//sort(arr2.begin(), arr2.end()); works

	for(int n : arr1) {
		int i = 0, j = arr2.size() - 1;
		if(n > arr2[i] && n < arr2[j]) {
			while(i+1 < j) {
				int mid = (i+j)/2;
				if( abs(n - arr2[mid]) <= d){
					i = mid;
					j = mid;
				} else if(n < arr2[mid]) {
					j = mid;
				} else {
					i = mid;
				}
			}
		}
		result += (abs(n - arr2[i]) > d && abs(n - arr2[j]) > d) ? 1 : 0;
	}
	return result;
}

int findDistance(vector<int>& arr1, vector<int>& arr2, int d) {
	if(arr1.size() == 0 && arr2.size() == 0)
		return 0;
	int result = 0;

	for(int n : arr1) {
		bool flag = true;
		for(int m : arr2) {
			if(abs(n - m) <= d){
				flag = false;
				break;
			}
		}
		if(flag)
			result++;
	}
	return result;
}
/*
int main() {


	return 0;
}
*/
