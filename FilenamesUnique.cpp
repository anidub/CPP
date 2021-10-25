#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>
#include <unordered_map>

using namespace std;
/*
 * https://leetcode.com/problems/making-file-names-unique/
 * Given an array of strings names of size n. You will create n folders in your file system such that, at the ith minute, you will create a folder with the name names[i].

Since two files cannot have the same name, if you enter a folder name which is previously used, the system will have a suffix addition to its name in the form of (k), where, k is the smallest positive integer such that the obtained name remains unique.

Return an array of strings of length n where ans[i] is the actual name the system will assign to the ith folder when you create it.
Input: names = ["gta","gta(1)","gta","avalon"]
Output: ["gta","gta(1)","gta(2)","avalon"]
Explanation: Let's see how the file system creates folder names:
"gta" --> not assigned before, remains "gta"
"gta(1)" --> not assigned before, remains "gta(1)"
"gta" --> the name is reserved, system adds (k), since "gta(1)" is also reserved, systems put k = 2. it becomes "gta(2)"
"avalon" --> not assigned before, remains "avalon"

https://leetcode.com/problems/making-file-names-unique/discuss/697788/C%2B%2B-or-Hashmap
 */
// O(n)
vector<string> getFolderNames(vector<string>& names) {
	if(names.size() == 0) return {};
	vector<string> result;
	unordered_map<string, int> hm;

	for(int i = 0; i < names.size(); i++) {
		if(hm.find(names[i]) != hm.end()) {
			int j = hm[names[i]] + 1;
			string p = '(' + to_string(j) + ')';
			while(hm.find(names[i] + p) != hm.end()) {
				j++;
				p = '(' + to_string(j) + ')';
			}
			hm[names[i]] = j;
			hm[names[i] + p] = 0;
			result.push_back(names[i] + p);

		} else {
			hm[names[i]] = 0;
			result.push_back(names[i]);
		}
	}
	return result;
}
/*
int main() {
	vector<string> names;
	names.push_back("gta");names.push_back("gta(1)");names.push_back("gta");names.push_back("avalon");
	vector<string> result = getFolderNames(names);
	for(string& s : result)
		cout << s << endl;
	return 0;
}*/
