#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/subdomain-visit-count/
 * A website domain "discuss.leetcode.com" consists of various subdomains. At the top level, we have "com", at the next level, we have "leetcode.com" and at the lowest level, "discuss.leetcode.com". When we visit a domain like "discuss.leetcode.com", we will also visit the parent domains "leetcode.com" and "com" implicitly.

A count-paired domain is a domain that has one of the two formats "rep d1.d2.d3" or "rep d1.d2" where rep is the number of visits to the domain and d1.d2.d3 is the domain itself.
For example, "9001 discuss.leetcode.com" is a count-paired domain that indicates that discuss.leetcode.com was visited 9001 times.
Given an array of count-paired domains cpdomains, return an array of the count-paired domains of each subdomain in the input. You may return the answer in any order.
Example 1:

Input: cpdomains = ["9001 discuss.leetcode.com"]
Output: ["9001 leetcode.com","9001 discuss.leetcode.com","9001 com"]
Explanation: We only have one website domain: "discuss.leetcode.com".
As discussed above, the subdomain "leetcode.com" and "com" will also be visited. So they will all be visited 9001 times.

https://leetcode.com/problems/subdomain-visit-count/discuss/121738/C%2B%2BJavaPython-Easy-Understood-Solution
 */
vector<string> subdomainVisits(vector<string>& cpdomains) {
	if(cpdomains.empty()) return {};
	unordered_map<string, int> count;
	for(auto cd : cpdomains) {
		int i = cd.find(" ");
		int n = stoi(cd.substr(0, i));
		string s = cd.substr(i+1);

		for(int i = 0; i < s.length(); i++) {
			if(s[i] == '.')
				count[s.substr(i+1)] += n;
		}
		count[s] += n;
	}

	vector<string> res;
	for(auto k : count) {
		res.push_back(to_string(k.second) + " " + k.first);
	}
	return res;
}
/*
int main() {
	vector<string> cpdomains = {"9001 discuss.leetcode.com"};
	vector<string> result = subdomainVisits(cpdomains);
	for(auto k : result)
		cout << k << endl;
	return 0;
}*/
