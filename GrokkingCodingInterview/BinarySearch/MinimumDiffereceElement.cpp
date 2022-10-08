#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/mymvP915LY9
 * Given an array of numbers sorted in ascending order, find the element in the array that has the minimum difference with the given ‘key’.
 * Input: [4, 6, 10], key = 7
Output: 6
Explanation: The difference between the key '7' and '6' is minimum than any other number in the array
 */
class MinimumDifference {
 public:
	//TC:O(LOGN), SC:O(1)
  int searchMinDiffElement(const vector<int>& arr, int key) {
    int start = 0, end = arr.size() - 1;

    if(key < arr[start]) return arr[start];
    if(key > arr[end]) return arr[end];

    while(start <= end) {
    	int mid = start + (end - start) / 2;
    	if(key > arr[mid])
    		start = mid + 1;
    	else if(key < arr[mid])
    		end = mid - 1;
    	else
    		return arr[mid];
    }

    // at the end of the while loop, 'start == end+1' we are not able to find the element in the given array return the element which is closest to the 'key'
    if( (arr[start] - key) < (key - arr[end]))
    	return arr[start];

    return arr[end];
  }
};

/*
int main(int argc, char* argv[]) {
	MinimumDifference md;
	cout << md.searchMinDiffElement(vector<int>{4, 6, 10}, 7) << endl;
	cout << md.searchMinDiffElement(vector<int>{4, 6, 10}, 4) << endl;
	cout << md.searchMinDiffElement(vector<int>{1, 3, 8, 10, 15}, 12) << endl;
	cout << md.searchMinDiffElement(vector<int>{4, 6, 10}, 17) << endl;
}*/

