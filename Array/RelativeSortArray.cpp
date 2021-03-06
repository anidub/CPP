#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

/*
 * https://leetcode.com/problems/relative-sort-array/
 * Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2.  Elements that don't appear in arr2 should be placed at the end of arr1 in ascending order.

Example 1:
Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]

https://leetcode.com/problems/relative-sort-array/discuss/803969/C%2B%2B-Sort
https://leetcode.com/problems/relative-sort-array/discuss/424592/C%2B%2B-solution-4ms-beats-92
https://www.youtube.com/watch?v=McFITbrcfWg

 */

vector<int> relativeSort(vector<int>& arr1, vector<int>& arr2) {
	vector<int> result;
	if(arr1.size() == 0 || arr2.size() == 0)
		return result;
	unordered_map<int, int> count;

	vector<int> leftOvers;
	set<int> subArray(arr2.begin(), arr2.end());//this is a compromise again o(n) if searched in array. set has o(1)

	for(int i : arr1) {
		count[i]++;
		if(subArray.count(i) == 0)
			leftOvers.push_back(i);
	}

	for(int i : arr2) {
		while(count[i]>=1){
			result.push_back(i);
			count[i]--;
		}
	}

	//sort(leftOvers.begin(), leftOvers.end()); //works

	result.insert(result.end(), leftOvers.begin(), leftOvers.end());

	return result;
}

/*
int main() {

	return 0;
}
*/
