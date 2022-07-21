#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>
#include <unordered_set>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/restore-ip-addresses/
 *A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.
Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]

 *https://leetcode.com/problems/restore-ip-addresses/discuss/30972/WHO-CAN-BEAT-THIS-CODE
 */
//Time Complexity = O(3^4*N), Space Complexity = O(N)
/*Time Complexity is O(3^4N) because we are running 4 nested loops of size 3, therefore 3^4 and
  inside the nested loop we are concatenating the string which takes O(N). Therefore total time complexity is O(3^4N)=O(81*N)~O(N).
Space complexity is O(N) because we are using string ans to concatenate A, B, C, and D.
 */
vector<string> restoreIPAddresses(string s) {
	vector<string> res;
	string ans;

	for(int a = 1; a <= 3; a++) {
		for(int b = 1; b <= 3; b++) {
			for(int c = 1; c <= 3; c++) {
				for(int d = 1; d <= 3; d++) {
					if(a + b + c + d == s.length()) {
						int A = stoi(s.substr(0, a));
						int B = stoi(s.substr(a, b));
						int C = stoi(s.substr(a + b , c));
						int D = stoi(s.substr(a + b + c, d));

						if(A <= 255 && B <= 255 && C <= 255 && D <= 255) {
							ans = to_string(A) + "." + to_string(B) + "." + to_string(C) + "." + to_string(D);
							if(ans.length() == s.length() + 3)
								res.push_back(ans);
						}
					}
				}
			}
		}
	}
	return res;
}
/*
int main() {
	restoreIPAddresses("25525511135");

	return 0;
}*/
