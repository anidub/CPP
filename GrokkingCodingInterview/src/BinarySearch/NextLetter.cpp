#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/R1B78K9oBEz
 * Given an array of lowercase letters sorted in ascending order, find the smallest letter in the given array greater than a given ‘key’.

Assume the given array is a circular list, which means that the last letter is assumed to be connected with the first letter.
This also means that the smallest letter in the given array is greater than the last letter of the array and is also the first letter of the array.

Write a function to return the next letter of the given ‘key’.
Input: ['a', 'c', 'f', 'h'], key = 'f'
Output: 'h'
Explanation: The smallest letter greater than 'f' is 'h' in the given array.

Trick for this questions and ceiling/floor:
If asked smaller number greater than equal then key then arr[start]
if asked bigger number less than equal than key then arr[end]
 */
class NextLetter {
public:
	char searchNextLetter(const vector<char>& letters, char key) {
		if(letters.empty()) return ' ';
		int n = letters.size();
		int start = 0, end = n - 1;

		while(start <= end) {
			int mid = start + (end - start) / 2;
			if(key >= letters[mid]) // the questions asks only greater than not equal to hence mid == key condition ignored
				start = mid + 1;
			else
				end = mid - 1;
		}
		return letters[start % n]; // % n since circular
	}
};
/*
int main(int argc, char* argv[]) {
  NextLetter nl;
  cut << nl.searchNextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'f') << endl;
  cout << nl.searchNextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'b') << endl;
  cout << nl.searchNextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'm') << endl;
  cout << nl.searchNextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'h') << endl;
}
*/
