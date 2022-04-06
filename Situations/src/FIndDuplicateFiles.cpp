#include <iostream>
#include <string>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>
#include <sstream>
#include <unordered_map>
using namespace std;
/*https://leetcode.com/problems/find-duplicate-file-in-system/
 *Given a list paths of directory info, including the directory path, and all the files with contents in this directory, return all the duplicate files in the file system in terms of their paths. You may return the answer in any order.

A group of duplicate files consists of at least two files that have the same content.

A single directory info string in the input list has the following format:

"root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ... fn.txt(fn_content)"
It means there are n files (f1.txt, f2.txt ... fn.txt) with content (f1_content, f2_content ... fn_content) respectively in the directory "root/d1/d2/.../dm". Note that n >= 1 and m >= 0. If m = 0, it means the directory is just the root directory.

The output is a list of groups of duplicate file paths. For each group, it contains all the file paths of the files that have the same content. A file path is a string that has the following format:

"directory_path/file_name.txt"

 *Input: paths = ["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"]
Output: [["root/a/2.txt","root/c/d/4.txt","root/4.txt"],["root/a/1.txt","root/c/3.txt"]]

https://leetcode.com/problems/find-duplicate-file-in-system/discuss/104123/C%2B%2B-clean-solution-answers-to-follow-up
 *Follow up questions:

1. Imagine you are given a real file system, how will you search files? DFS or BFS ?
In general, BFS will use more memory then DFS. However BFS can take advantage of the locality of files in inside directories, and therefore will probably be faster
Just for a file system, it's more common the case you have 100 files stored in one folder, instead of 100 level of directories. In general, DFS takes the same space as BFS, both of which are O(n), regardless the n is height or width.
In a file system, BFS is like scan all the files under one directory, then go to the 1st child directory, 2nd child directory etc.
DFS instead, is visiting 1st child directory, 1st child directory's child (grandchild directory).. etc all the way down to the bottom, then go back to 2nd child directory of the root. So it adds a lot of overhead of "cd" (change directory) operations.

2. If the file content is very large (GB level), how will you modify your solution?
In a real life solution we will not hash the entire file content, since it's not practical. Instead we will first map all the files according to size. Files with different sizes are guaranteed to be different. We will than hash a small part of the files with equal sizes (using MD5 for example). Only if the md5 is the same, we will compare the files byte by byte

3. If you can only read the file by 1kb each time, how will you modify your solution?
This won't change the solution. We can create the hash from the 1kb chunks, and then read the entire file if a full byte by byte comparison is required.

What is the time complexity of your modified solution? What is the most time consuming part and memory consuming part of it? How to optimize?
Time complexity is O(n^2 * k) since in worse case we might need to compare every file to all others. k is the file size
What is the most time consuming part and memory consuming part of it? How to optimize? part:
Comparing the file (by size, by hash and eventually byte by byte) is the most time consuming part.
Generating hash for every file will be the most memory consuming part.
We follow the above procedure will optimize it, since we compare files by size first, only when sizes differ, we'll generate and compare hashes, and only when hashes are the same, we'll compare byte by byte.
Also, using better hashing algorithm will also reduce memory/time.
https://stackoverflow.com/questions/2722943/is-calculating-an-md5-hash-less-cpu-intensive-than-sha-family-functions


How to make sure the duplicated files you find are not false positive?
We will use several filters to compare: File size, Hash and byte by byte comparisons.
 */
//TC:O(N), SC: O(N)
vector<vector<string>> findDuplicate(vector<string>& paths) {
	unordered_map<string, vector<string>> files;
	vector<vector<string>> result;

	for(auto path : paths) {
		stringstream ss(path);
		string root;
		string s;
		getline(ss, root, ' ');
		while(getline(ss, s, ' ')) {
			string fileName = root + '/' + s.substr(0, s.find('('));
			string fileContent = s.substr(s.find('(') + 1, s.find(')') - s.find('(') - 1);
			files[fileContent].push_back(fileName);
		}
	}

	for(auto file : files) {
		if(file.second.size() > 1)
			result.push_back(file.second);
	}
	return result;
}
/*
int main() {
	vector<string> paths {"root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"};
	findDuplicate(paths);

	return 0;
}*/
