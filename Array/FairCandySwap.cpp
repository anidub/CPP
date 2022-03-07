#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_set>
#include <numeric>

using namespace std;
/*
 * https://leetcode.com/problems/fair-candy-swap/
 * Alice and Bob have candy bars of different sizes: A[i] is the size of the i-th bar of candy that Alice has, and B[j] is the size of the j-th bar of candy that Bob has.

Since they are friends, they would like to exchange one candy bar each so that after the exchange, they both have the same total amount of candy.  (The total amount of candy a person has is the sum of the sizes of candy bars they have.)
Return an integer array ans where ans[0] is the size of the candy bar that Alice must exchange, and ans[1] is the size of the candy bar that Bob must exchange.
Input: A = [1,2,5], B = [2,4]
Output: [5,4]

Input: A = [1,1], B = [2,2]
Output: [1,2]

https://leetcode.com/problems/fair-candy-swap/discuss/163073/Concise-C%2B%2B
https://leetcode.com/problems/fair-candy-swap/discuss/856146/C%2B%2B
 */
vector<int> fairCandySwap(vector<int> A, vector<int> B) {
	if(A.size () == 0 || B.size() == 0) return {};
	int sumA = accumulate(A.begin(), A.end(), 0);
	int sumB = accumulate(B.begin(), B.end(), 0);

	int delta = sumB - sumA;

	unordered_set<int> candidates(B.begin(), B.end());

	for(auto a: A) {
		int b = a + delta/2;
		if(candidates.find(b) != candidates.end()) {
			return {a, b};
		}
	}
	return {};
}

/*
int main() {
	vector<int> A;
	vector<int> B;

	A.push_back(1);A.push_back(2);A.push_back(5);
	B.push_back(2);B.push_back(4);

	fairCandySwap(A, B);


	return 0;
}*/
