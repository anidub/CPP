#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/string-to-integer-atoi/
 * Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

The algorithm for myAtoi(string s) is as follows:

Read in and ignore any leading whitespace.
Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
Return the integer as the final result.
Input: s = "   -42"
Output: -42
Explanation:
Step 1: "   -42" (leading whitespace is read and ignored)
            ^
Step 2: "   -42" ('-' is read, so the result should be negative)
             ^
Step 3: "   -42" ("42" is read in)
               ^
The parsed integer is -42.
Since -42 is in the range [-231, 231 - 1], the final result is -42.
https://leetcode.com/problems/string-to-integer-atoi/discuss/1402936/JAVA-C%2B%2B-%3A-Simple-or-Pictorial-Explanation-or-32-bit-int-or-Easy
The minimum 32-bit integer value is -2^{31} \space = \space -2147483648−2
31
  = −2147483648 denote it with INT_MIN.

We append the digits one by one to the final number.
Just like before, there could be 3 cases:

Case 1: If the current number is greater than INT_MIN / 10 = -214748364, then we can append any digit and the new number will always be greater than INT_MIN.

Case 2: If the current number is less than INT_MIN / 10 = -214748364, appending any digit will result in a number less than INT_MIN.

Case 3: If the current number is equal to INT_MIN / 10 = -214748364, then we can only append digits from 0-8, such that the new number will always be greater than or equal to INT_MIN.
Notice that cases 1 and 2 are similar for overflow and underflow. The only difference is case 3: for overflow, we can append any digit between 0 and 7, but for underflow, we can append any digit between 0 and 8.

 */
bool isDigit(char ch) {
	return ch >= '0' && ch <= '9';
}
//TC:O(N), SC:O(1)
int myStringToInteger(string s) {
	if(s.empty()) return 0;

	const int len = s.size();
	int index = 0; bool isNegative = false;

	while(index < len && s[index] == ' ') index++;// skipping white spaces

	if(index < len && s[index] == '-') {// to handle sign cases
		isNegative = true;
		index++;
	} else if(index < len && s[index] == '+') {
		isNegative = false;
		index++;
	}

	int result = 0;
	while(index < len && isDigit(s[index]) ) {
		int digit = s[index] - '0';
		 // to avoid integer overflow
		if( (result > INT_MAX / 10) || ( (result == INT_MAX / 10) && digit > 7) ) //refer solution for explanation
			return isNegative ? INT_MIN : INT_MAX;

		result = (result * 10) + digit; // adding digits at their desired place-value
		index++;
	}
	return isNegative ? -result : result;

}
/*
int main() {
	cout << myStringToInteger("   -42") << endl;
	return 0;
}*/
