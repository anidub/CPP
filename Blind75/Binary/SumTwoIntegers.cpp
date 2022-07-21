#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/sum-of-two-integers/
 * Given two integers a and b, return the sum of the two integers without using the operators + and -
 *
 * Input: a = 1, b = 2
Output: 3

 * https://leetcode.com/problems/sum-of-two-integers/discuss/132479/Simple-explanation-on-how-to-arrive-at-the-solution : well explained
 * https://leetcode.com/problems/sum-of-two-integers/discuss/2191597/C%2B%2B-with-example-of-bit-manipulation
 *
 * LEFT SHIFT : (X << Y) : X * (2 ^ Y)
 * RIGHT SHIFT : (X >> Y) : X / (2 ^ Y)
 */
class SumOfTwoIntegers{
public:
	int getSum(int a, int b) {
		uint32_t carry = 0; // uint32_t is imp consider case a : 1 &  : -1

		while(b != 0) {
			carry = (a & b);
			a = a ^ b;
			b = (carry) << 1;
		}
		return a;
	}
};
/*
int main() {
	SumOfTwoIntegers st;
	cout << st.getSum(1, 2) << endl;

}
*/
