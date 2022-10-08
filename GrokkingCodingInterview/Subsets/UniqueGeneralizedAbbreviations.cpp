#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/NEOZDEg5PlN
 * Given a word, write a function to generate all of its unique generalized abbreviations.
 * A word's generalized abbreviation can be constructed by taking any number of non-overlapping and non-adjacent substrings and replacing them with their respective lengths.

For example, "abcde" can be abbreviated into:
"a3e" ("bcd" turned into "3")
"1bcd1" ("a" and "e" both turned into "1")
"5" ("abcde" turned into "5")
"abcde" (no substrings replaced)
However, these abbreviations are invalid:
"23" ("ab" turned into "2" and "cde" turned into "3") is invalid as the substrings chosen are adjacent.
"22de" ("ab" turned into "2" and "bc" turned into "2") is invalid as the substring chosen overlap.
Given a string word, return a list of all the possible generalized abbreviations of word. Return the answer in any order.
Input: "BAT"
Output: "BAT", "BA1", "B1T", "B2", "1AT", "1A1", "2T", "3"
https://leetcode.com/problems/generalized-abbreviation/discuss/77280/My-backtracking-C%2B%2B-solution

 O(n 2^n). For each call to backtrack, it either returns without branching, or it branches into two recursive calls.
 All these recursive calls form a complete binary recursion tree with 2^n leaves and 2^n - 1 inner nodes.
  For each leaf node, it needs O(n)time for converting builder to String; for each internal node, it needs only constant time. Thus, the total time complexity is dominated by the leaves. In total that is O(n2^n)O(n2
n
 ).
 */
class GeneralizedAbbreviation {
 public:
	//TC:O(N * 2^N), SC: O(N * 2^N) : with stack size else O(N)
  vector<string> generateGeneralizedAbbreviation(const string &word) {
      vector<string> result;
      generateGeneralizedAbbreviationHelper(word, "", 0, result, false);
      return result;
  }

  void generateGeneralizedAbbreviationHelper(const string &word, string abbr, int index, vector<string> &result, bool prevNum) {
	  if(index == word.length()) {
		  result.push_back(abbr);
		  return ;
	  }
	  generateGeneralizedAbbreviationHelper(word, abbr + word[index], index + 1, result, false);
	  if (!prevNum) { // Add number abbreviations only when we added a character instead of an abbreviation earlier
		  for(int len = 1; index + len <= word.length(); len++) {
			 generateGeneralizedAbbreviationHelper(word, abbr + to_string(len), index + len, result, true);
		  }
	  }
  }
};

/*
int main(int argc, char *argv[]) {
	GeneralizedAbbreviation ga;
  vector<string> result = ga.generateGeneralizedAbbreviation("BAT");
  cout << "Generalized abbreviation are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;

  result = ga.generateGeneralizedAbbreviation("code");
  cout << "Generalized abbreviation are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;
}*/
