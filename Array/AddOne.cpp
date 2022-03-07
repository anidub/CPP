#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;
/*
 *https://leetcode.com/problems/plus-one/
 * Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.
 * Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
https://leetcode.com/problems/plus-one/discuss/24374/C%2B%2B-simple
 */

vector<int> addOne(vector<int>& digits) {
    if(digits.size() == 0) return digits;
    int carry = 1;
    for(int i = digits.size()-1; i >= 0 && carry; i--) {
        int k = digits[i] + carry;
        if(k > 9){
            digits[i] = k%10;
            carry = 1;
        } else {
            digits[i] = k;
            carry = 0;
        }
    }
    if(carry) {
        //digits.insert(digits.begin(), 1);
        digits[0] = 1;//clever idea to change like this..insert is memory expensive operation
        digits.push_back(0);
    }
    return digits;
}
/*
int main() {
	vector<int> digits;
	digits.push_back(9);digits.push_back(9);
	addOne(digits);
	return 0;
}*/
