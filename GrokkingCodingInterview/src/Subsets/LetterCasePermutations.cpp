#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/xVlKmyX542P
 * Given a string, find all of its permutations preserving the character sequence but changing case.
 * Input: "ad52"
Output: "ad52", "Ad52", "aD52", "AD52"
https://leetcode.com/problems/letter-case-permutation/
 */

class LetterCaseStringPermutation {
 public:
	//TC:O(N*2^N), SC:O(N*2^N)
  vector<string> findLetterCaseStringPermutations(const string& str) {
    vector<string> permutations;
    permutations.push_back(str);

    for(int i = 0; i < str.length(); i++) {
      if(isalpha(str[i])) {
        int n = permutations.size();
        for(int j = 0; j < n; j++) {
          vector<char> chs(permutations[j].begin(), permutations[j].end());
          if(islower(chs[i])) {
            chs[i] = toupper(chs[i]);
          } else {
            chs[i] = tolower(chs[i]);
          }
          permutations.push_back(string(chs.begin(), chs.end()));
        }
      }
    }
    return permutations;
  }
};

/*
int main(int argc, char* argv[]) {
	LetterCaseStringPermutation lc;
  vector<string> result = lc.findLetterCaseStringPermutations("ad52");
  cout << "String permutations are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;

  result = lc.findLetterCaseStringPermutations("ab7c");
  cout << "String permutations are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;
}*/
