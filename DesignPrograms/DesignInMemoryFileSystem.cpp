#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <map>
#include <vector>
#include <stack>
#include <utility>
#include <list>
#include <iterator>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/design-in-memory-file-system/
 * Design a data structure that simulates an in-memory file system.

Implement the FileSystem class:

FileSystem() Initializes the object of the system.
List<String> ls(String path)
If path is a file path, returns a list that only contains this file's name.
If path is a directory path, returns the list of file and directory names in this directory.
The answer should in lexicographic order.
void mkdir(String path) Makes a new directory according to the given path. The given directory path does not exist. If the middle directories in the path do not exist, you should create them as well.
void addContentToFile(String filePath, String content)
If filePath does not exist, creates that file containing given content.
If filePath already exists, appends the given content to original content.
String readContentFromFile(String filePath) Returns the content in the file at filePath.
https://leetcode.com/problems/design-in-memory-file-system/discuss/879721/C%2B%2B-short-and-very-easy-understand-solution-20-ms
 */
struct fileNode {
	unordered_map<string, fileNode*> next;
	bool isFile;
	string content;

	fileNode() : isFile(false), content("") {}
};

class FileSystem {
	fileNode *root;

public:
	FileSystem() {
		root = new fileNode();
	}

	fileNode* goToPathFolder(string path) {
		fileNode *cur = root;
		stringstream s(path);
		string folder;
		while(getline(s, folder, '/')) {
			if(folder.size()) {
				if(cur->next[folder] == NULL)
					cur->next[folder] = new fileNode();
				cur = cur->next[folder];
			}
		}
		return cur;
	}

	vector<string> ls(string path) {
		fileNode *cur = goToPathFolder(path);

		if(cur->isFile)
			return {path.substr(path.find_last_of('/') + 1)};

		vector<string> res;
		for(auto &p : cur->next) {
			res.push_back(p.first);
		}
		sort(res.begin(), res.end());
		return res;
	}

	void mkdir(string path) {
		fileNode *cur = goToPathFolder(path);
	}

	void addContentToFile(string path, string content) {
		fileNode *cur = goToPathFolder(path);
		cur->content  += content;
		cur->isFile = true;
	}

	string readContentFromFile(string filePath) {
		fileNode *cur = goToPathFolder(filePath);
		return cur->content;
	}
};

/*

int main() {
	 FileSystem* obj = new FileSystem();
	 vector<string> param_1 = obj->ls("/");
	 obj->mkdir("/a/b/c");
	 obj->addContentToFile("/a/b/c/d", "hello");
	 string param_4 = obj->readContentFromFile("/a/b/c/d");
	 cout << param_4 << endl;
	return 0;
}*/
