#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <utility>
#include <unordered_set>

using namespace std;
/*
 * Given a list of folders, remove all sub-folders in those folders and return in any order the folders after removing.
If a folder[i] is located within another folder[j], it is called a sub-folder of it.
The format of a path is one or more concatenated strings of the form: / followed by one or more lowercase English letters. For example, /leetcode and /leetcode/problems are valid paths while an empty string and / are not.
Example 1:
Input: folder = ["/a","/a/b","/c/d","/c/d/e","/c/f"]
Output: ["/a","/c/d","/c/f"]
Explanation: Folders "/a/b/" is a subfolder of "/a" and "/c/d/e" is inside of folder "/c/d" in our filesystem.

https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/discuss/410087/C%2B%2B-200-ms-sort-then-compare-to-previous-clean-and-short-code
 */

//O NLOGN
vector<string> removeSubFolders(vector<string>& folder) {
	if(folder.empty()) return {};
	sort(folder.begin(), folder.end());
	vector<string> result {folder[0]};

	for(int i = 1; i < folder.size(); i++) {
		auto& first = folder[i];
		auto& last = result.back();

		if(first.size() > last.size() &&
				first[last.size()] == '/' &&
				first.compare(0, last.size(), last) == 0)
			continue;
		result.push_back(first);
	}

	for(auto& s : result)
		cout << s << " " << endl;
	return result;
}
//O(MN) where M is average legnth of string and N is number of strings.
//https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/discuss/824496/Without-sorting-O(MN)-C%2B%2B-solution
//https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/discuss/824496/Without-sorting-O(MN)-C%2B%2B-solution
vector<string> removeSubFoldersMN(vector<string>& folder) {
	vector<string> result;
	unordered_set<string> uset;
	for(string s: folder)
		uset.insert(s);

	for(string& f : folder) {
		int n = f.size();
		bool present = false;

		for(int i = 1; i < n; i++) {
			if(f[i] == '/') {
				string dir = f.substr(0, i);
				if(uset.find(dir) != uset.end()){
					present = true;
					break;
				}
			}
		}
		if(!present)
			result.push_back(f);
	}
	return result;
}
/*
int main() {
	vector<string> s;
	s.push_back("/a");s.push_back("/a/b");s.push_back("/c/d");
	s.push_back("/c/d/e");s.push_back("/c/f");
	removeSubFolders(s);
	return 0;
}
*/
