#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>
#include <sstream>

using namespace std;
/*https://leetcode.com/problems/simplify-path/
 * Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path.

In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level, and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'. For this problem, any other format of periods such as '...' are treated as file/directory names.

The canonical path should have the following format:

The path starts with a single slash '/'.
Any two directories are separated by a single slash '/'.
The path does not end with a trailing '/'.
The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
Input: path = "/home//foo/"
Output: "/home/foo"
https://leetcode.com/problems/simplify-path/discuss/1050697/C%2B%2B-Simple-and-Easy-Solution-Faster-than-94
 */

//TC: O(N). SC : O(N)
string simplifyPath(string path) {
	if(path.empty()) return "";
	vector<string> stack;

	string res, temp;
	stringstream p(path);

	while(getline(p, temp, '/')) {
		if(temp == "" || temp == ".") continue;
		else if(!stack.empty() && temp == "..")
			stack.pop_back();
		else if(temp != "..")
			stack.push_back(temp);
	}
	for(auto s : stack)
		res += "/" + s;

	return stack.empty() ? "/" : res;
}
/*
int main() {
	cout << simplifyPath("/home//foo/");
	return 0;
}
*/
