#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <unordered_set>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/goat-latin/
 * You are given a string sentence that consist of words separated by spaces. Each word consists of lowercase and uppercase letters only.

We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.) The rules of Goat Latin are as follows:

If a word begins with a vowel ('a', 'e', 'i', 'o', or 'u'), append "ma" to the end of the word.
For example, the word "apple" becomes "applema".
If a word begins with a consonant (i.e., not a vowel), remove the first letter and append it to the end, then add "ma".
For example, the word "goat" becomes "oatgma".
Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
For example, the first word gets "a" added to the end, the second word gets "aa" added to the end, and so on.
Return the final sentence representing the conversion from sentence to Goat Latin.
Input: sentence = "I speak Goat Latin"
Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"

https://leetcode.com/problems/goat-latin/discuss/379245/C%2B%2B-Soolution-0ms-9MB(less-than-100)
 */
//TC: O(N)
string toGoatLatin(string S) {
	if(S.empty()) return "";
	int front = 0;
	int count = 1, n = S.size();
	unordered_set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
	string res;

	for(int i = 0; i <= n; i++) {
		if(i == n || S[i] == ' ') {
			string word(S.begin() + front, S.begin() + i);
			char c = word[0];
			if(st.find(c) != st.end())
				res += word + "ma";
			else
				res += word.substr(1) + word[0] + "ma";

			for(int k = 0; k < count; k++)
				res += "a";
			if(i != n)
				res += " ";

			front = i + 1;
			count++;
		}
	}
	return res;
}
/*
int main() {
	string s = "I speak Goat Latin";
	cout << toGoatLatin(s) << endl;

	return 0;
}*/
