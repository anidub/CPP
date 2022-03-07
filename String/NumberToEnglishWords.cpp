#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>

using namespace std;
/*https://leetcode.com/problems/integer-to-english-words/
 *Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

https://leetcode.com/problems/integer-to-english-words/discuss/70756/Short-clean-C%2B%2B-code-with-explanation : comments used
https://leetcode.com/problems/integer-to-english-words/discuss/70651/Fairly-Clear-4ms-C%2B%2B-solution
 *
 */
string ones[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen",
"Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

string tens[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
string numberToWordsHelper(int n);
//TC: O(log N)
string numberToWords(int n) {
	if(n == 0) return "Zero";
	return numberToWordsHelper(n).substr(1);
}

string numberToWordsHelper(int n) {
	if(n >= 1000000000) return numberToWordsHelper(n / 1000000000) + " Billion" + numberToWordsHelper(n % 1000000000);
	if(n >= 1000000) return numberToWordsHelper(n / 1000000) + " Million" + numberToWordsHelper(n % 1000000);
	if(n >= 1000) return numberToWordsHelper(n / 1000) + " Thousand" + numberToWordsHelper(n % 1000);
	if(n >= 100) return numberToWordsHelper(n / 100) + " Hundred" + numberToWordsHelper(n % 100);
	if(n >= 20) return " " + tens[(n/10) - 2] + numberToWordsHelper(n % 10);
	if(n >= 1) return " " + ones[n];
	return "";
}
/*
int main() {
	cout << numberToWords(1234567) << endl;

	return 0;
}*/
