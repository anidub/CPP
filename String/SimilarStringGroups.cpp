#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>
#include <unordered_set>

using namespace std;
/*https://leetcode.com/problems/similar-string-groups/
 * Two strings X and Y are similar if we can swap two letters (in different positions) of X, so that it equals Y. Also two strings X and Y are similar if they are equal.

For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".

Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group even though they are not similar.  Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

We are given a list strs of strings where every string in strs is an anagram of every other string in strs. How many groups are there?
Input: strs = ["tars","rats","arts","star"]
Output: 2

https://leetcode.com/problems/similar-string-groups/discuss/1412619/C%2B%2B-Bruteforce-then-Union-Find-O(N2-*-M)-20ms-Clean-and-Concise

 */

class UnionFindSimiStrGrp {
vector<int> parent;
vector<int> size;
public:
UnionFindSimiStrGrp(int n) {
	parent.resize(n);
	size.resize(n, 1);
	for(int i = 0; i < n; i++) parent[i] = i;
}

int Find(int u) {
	if(u == parent[u]) return u;
	return parent[u] = Find(parent[u]);
}

bool Union(int u, int v) {
	int pu = Find(u), pv = Find(v);
	if(pu == pv) return false;
	if(size[pu] < size[pv]) {
		size[pv] += size[pu];
		parent[pu] = pv;
	} else {
		size[pu] += size[pv];
		parent[pv] = pu;
	}
	return true;
}
};

bool isSimilar(const string& str1, const string& str2);
/*Time: O(N^2 * M + N^2 * α(N)) ~ O(N^2 * M), where N <= 300 is the number of strings in strs, M <= 300 is length of each string.
Explanation: Using both path compression and union by size ensures that the amortized time per UnionFind operation is only α(n), which is optimal, where α(n) is the inverse Ackermann function. This function has a value α(n) < 5 for any value of n that can be written in this physical universe, so the disjoint-set operations take place in essentially constant time.
Reference: https://en.wikipedia.org/wiki/Disjoint-set_data_structure or https://www.slideshare.net/WeiLi73/time-complexity-of-union-find-55858534 for more information.
Space: O(N)
 *
 */
int numSimilarGroups(vector<string>& strs) {
	if(strs.empty()) return 0;
	int n = strs.size(), groups = n;
	UnionFindSimiStrGrp uf(n);

	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if( isSimilar(strs[i], strs[j]) &&  uf.Union(i,j))
				groups -= 1;
		}
	}
	return groups;
}

bool isSimilar(const string& str1, const string& str2) {
	int diff1 = -1, diff2 = -1;

	for(int i = 0; i < str1.size(); i++) {
		if(str1[i] != str2[i]) {
			if(diff1 == -1) diff1 = i;
			else if(diff2 == -1) diff2 = i;
			else return false;
		}
	}
	if(diff1 == -1) return true;
	if(diff2 == -1) return false;

	return str1[diff1] == str2[diff2] && str1[diff2] == str2[diff1];
}
/*
int main() {
	vector<string> strs = {"tars","rats","arts","star"};
	cout << numSimilarGroups(strs) << endl;

	return 0;
}*/
