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
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/design-browser-history/
 * You have a browser of one tab where you start on the homepage and you can visit another url, get back in the history number of steps or move forward in the history number of steps.

Implement the BrowserHistory class:

BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
void visit(string url) Visits url from the current page. It clears up all the forward history.
string back(int steps) Move steps back in history. If you can only return x steps in the history and steps > x, you will return only x steps. Return the current url after moving back in history at most steps.
string forward(int steps) Move steps forward in history. If you can only forward x steps in the history and steps > x, you will forward only x steps. Return the current url after forwarding in history at most steps.

https://leetcode.com/problems/design-browser-history/discuss/674605/C%2B%2B-unordered_map-100-faster : used
https://leetcode.com/problems/design-browser-history/discuss/675481/Clean-code-using-Doubly-List-in-C%2B%2B : using DLL
 */

class BrowserHistory {
int curPg; int size;
unordered_map<int, string> urlMap;

public:
	BrowserHistory(string homepage) {
		urlMap[0] = homepage;
		curPg = 0;
		size = 1;
	}

	void visit(string url) {
		curPg++;
		urlMap[curPg] = url;
		size = curPg + 1;
	}

	string back(int steps) {
		if(steps > curPg) curPg = 0;
		else curPg = curPg - steps;
		return urlMap[curPg];
	}

	string forward(int steps) {
		if(curPg + steps < size) curPg += steps;
		else curPg = size - 1;
		return urlMap[curPg];
	}
};
/*
int main() {
	BrowserHistory browserHistory("leetcode.com");
	browserHistory.visit("google.com");       // You are in "leetcode.com". Visit "google.com"
	browserHistory.visit("facebook.com");     // You are in "google.com". Visit "facebook.com"
	browserHistory.visit("youtube.com");      // You are in "facebook.com". Visit "youtube.com"
	browserHistory.back(1);                   // You are in "youtube.com", move back to "facebook.com" return "facebook.com"
	browserHistory.back(1);                   // You are in "facebook.com", move back to "google.com" return "google.com"
	browserHistory.forward(1);                // You are in "google.com", move forward to "facebook.com" return "facebook.com"
	browserHistory.visit("linkedin.com");     // You are in "facebook.com". Visit "linkedin.com"
	browserHistory.forward(2);                // You are in "linkedin.com", you cannot move forward any steps.
	browserHistory.back(2);                   // You are in "linkedin.com", move back two steps to "facebook.com" then to "google.com". return "google.com"
	cout << browserHistory.back(7) << endl;   // You are in "google.com", you can move back only one step to "leetcode.com". return "leetcode.com"

	//delete(browserHistory);
}*/
