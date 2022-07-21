#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/gk20xz4VwpG
 * In a non-empty array of integers, every number appears twice except for one, find that single number.
Example 1:
Input: 1, 4, 2, 1, 3, 2, 3
Output: 4

Recall the following two properties of XOR:

It returns zero if we take XOR of two same numbers.
It returns the same number if we XOR with zero.
 */

class SingleNumber {
public:
	int findSingleNumber(const vector<int> &arr) {
		if(arr.empty()) return -1;
		int num = 0;
		for(int i = 0; i < arr.size(); i++) {
			num = num ^ arr[i];
		}
		return num;
	}
};
/*
int main(int argc, char* argv[]) {
	SingleNumber sn;
  cout << sn.findSingleNumber(vector<int>{1, 4, 2, 1, 3, 2, 3}) << endl;
}*/
