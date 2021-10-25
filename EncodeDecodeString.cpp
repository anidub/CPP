#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>

using namespace std;
/*271: Encode and Decode Strings
 * esign an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings. Machine 1 (sender) has the function:

string encode(vector<string> strs) {
  // ... your code
  return encoded_string;
}
Machine 2 (receiver) has the function:

vector<string> decode(string s) {
  //... your code
  return strs;
}
So Machine 1 does:

string encoded_string = encode(strs);
and Machine 2 does:

vector<string> strs2 = decode(encoded_string);
 * cnblogs.com/grandyang/p/5265628.html
 */
string encode(vector<string>& strs) {
	if(strs.empty()) return "";

	string result = "";
	for(string& s : strs) {
		result.append(to_string(s.size())).append("/").append(s);
	}
	return result;
}

vector<string> decode(string s) {
	if(s.size() == 0) return {};
	vector<string> result;

	while(!s.empty()) {
		int found = s.find("/");
		int len = stoi(s.substr(0, found));

		s = s.substr(found+1);
		result.push_back(s.substr(0, len));
		s = s.substr(len);
	}
	return result;
}
/*
int main() {

	return 0;
}*/
