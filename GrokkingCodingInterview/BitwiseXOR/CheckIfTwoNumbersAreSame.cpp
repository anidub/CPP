#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://www.geeksforgeeks.org/check-if-two-numbers-are-equal-without-using-arithmetic-and-comparison-operators/
 * Given two numbers, the task is to check if two numbers are equal without using Arithmetic and Comparison Operators or String functions.
 *  XOR of two numbers is 0 if the numbers are the same, otherwise non-zero.
 */
class checkNumbersSame{
public:
	//TC:O(1), SC:O(1)
	bool areSame(int a, int b) {
		if(a ^ b == 1)
			return false;
		else
			return true;
	}
};

/*
int main(){
	checkNumbersSame cns;
    cout << cns.areSame(10, 20) << endl;;
}*/

