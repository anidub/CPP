#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/NEXBg8YA5A2
 * For a given number ‘N’, write a function to generate all combination of ‘N’ pairs of balanced parentheses.
 * Input: N=3
Output: ((())), (()()), (())(), ()(()), ()()()
 */

class ParenthesisString {
public:
	string str;
	int openCount = 0;
	int closeCount = 0;

	ParenthesisString(string str, int openCount, int closeCount) {
		this->str = str;
		this->openCount = openCount;
		this->closeCount = closeCount;
	}
};

class GenerateParenthesis {
public:
	//TC:(N * 2^N), SC: O(N * 2^N)
	vector<string> generateNStrings(int num) {
		vector<string> result;
		if(num == 0) return result;
		queue<ParenthesisString> q;
		q.push({"", 0, 0});

		while(!q.empty()) {
			ParenthesisString ps = q.front(); q.pop();

			if(ps.openCount == num && ps.closeCount == num) {
				result.push_back(ps.str);
			} else {
				if(ps.openCount < num)
					q.push({ps.str + '(', ps.openCount + 1, ps.closeCount});
				if(ps.closeCount < ps.openCount)
					q.push({ps.str + ')', ps.openCount, ps.closeCount + 1});
			}
		}
		return result;
 	}
};

/*
int main(int argc, char *argv[]) {
	GenerateParenthesis gp;
  vector<string> result = gp.generateNStrings(2);
  cout << "All combinations of balanced parentheses are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;

  result = gp.generateNStrings(3);
  cout << "All combinations of balanced parentheses are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;
}
*/
