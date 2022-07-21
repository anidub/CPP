#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/encode-and-decode-strings/
 *Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is
 *Design decoded back to the original list of strings.
 Input: dummy_input = ["Hello","World"]
Output: ["Hello","World"]
Explanation:
Machine 1:
Codec encoder = new Codec();
String msg = encoder.encode(strs);
Machine 1 ---msg---> Machine 2

Machine 2:
Codec decoder = new Codec();
String[] strs = decoder.decode(msg);
https://leetcode.com/problems/encode-and-decode-strings/discuss/70443/Accepted-simple-C%2B%2B-solution : comments
 */
class EncodeDecode {
public:
    // Encodes a list of strings to a single string.
	//TC:O(N), SC:O(1)
    string encode(vector<string>& strs) {
        string res;
        for(auto i : strs) {
        	res = res + to_string(i.size()) + '#' + i;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    //TC:O(N), SC:O(1)
    vector<string> decode(string s) {
        vector<string> res;

        while(!s.empty()) {
        	int pos = s.find_first_of('#');
        	int len = stoi(s.substr(0, pos));
        	res.push_back(s.substr(pos + 1, len));
        	s = s.substr(len + pos + 1);
        }
        return res;
    }
};
/*
int main() {
	EncodeDecode ed;
	vector<string> strs = {"Hello", "World"};
	ed.decode(ed.encode(strs));

}*/
