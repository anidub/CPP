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
/*https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
 * You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.
Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation:
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"
https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/discuss/392933/JavaC%2B%2BPython-Two-Pointers-and-Stack-Solution
 */

//Time O(N) for one pass Space O(N)
string removeAdjacentDuplicates(string s, int k) {
	if(s.empty()) return "";
	string res;

	vector<pair<int, char>> stack = {{0, '#'}};;

	for(char c : s) {
		if(stack.back().second != c)
			stack.push_back({1, c});
		else {
			stack.back().first++;
			if(stack.back().first == k)
				stack.pop_back();
		}
	}
	for(auto& p : stack)
		res.append(p.first, p.second);//string& string::append (size_type num, char c) hence appends p.first times p.seconds

	return res;
}

/*
int main() {
	cout << removeAdjacentDuplicates("deeedbbcccbdaa", 3) << endl;

	return 0;
}*/
