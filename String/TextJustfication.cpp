#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/text-justification/
 * Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left-justified and no extra space is inserted between words.
 * Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
Output:[
   "This    is    an",
   "example  of text",
   "justification.  "
]
https://leetcode.com/problems/text-justification/discuss/1243483/Intuitive-code-with-Explanation
 */
string spaceJustifier(string output, int maxWidth, int isLast);

vector<string> fullJustify(vector<string>& words, int maxWidth) {
	vector<string> result;
	string output = words[0];

	for(int i = 1; i < words.size(); i++) {
		if(output.length() + words[i].length() + 1 <= maxWidth)
			output += " " + words[i];//add space before adding word
		else {
			output = spaceJustifier(output, maxWidth, 0);//formatting space before adding it to result
			result.push_back(output);
			output = words[i];//add current word to output(start of new line)
		}
	}
	output = spaceJustifier(output, maxWidth, 1);
	result.push_back(output);//justifying spaces in last line
	return result;
}

string spaceJustifier(string str, int maxWidth, int isLast) {
	if(str.length() == maxWidth) return str;

	int spacesInString = 0;//count total spaces in the line
	for(int i = 0; i < str.length(); i++) {
		if(str[i] == ' ') spacesInString++;
	}

	int spacesToBeInserted = maxWidth - str.length();//spaces to be inserted will be maxWidth - line length

	if(spacesInString == 0 || isLast == 1) { //if line has only 1 word(number of spaces in one word is 0 ex "hi") || it's last line then left justify the line
		str.insert(str.length(), spacesToBeInserted, ' ');
		return str;
	}

	int eachSlot = spacesToBeInserted / spacesInString;
	int leftOverSpace = spacesToBeInserted % spacesInString;

	for(int i = 0; i < str.length(); i++) {
		if(str[i] == ' ' && (eachSlot > 0 || leftOverSpace > 0)) {
			int noOfSpaces = eachSlot + ( (leftOverSpace--) > 0 ? 1 : 0); //((leftOverSpace--) > 0 ? 1:0) will return 1 if leftoverspace>0.(leftOverSpace--) post decrement
			str.insert(i, noOfSpaces, ' ');
			i += noOfSpaces;//increament count with no of spaces inserted each time
		}
	}
	return str;
}
/*
int main() {
	vector<string> input = {"What","must","be","acknowledgment","shall","be"};
	vector<string> res = fullJustify(input, 16);
	for(auto s : res) {
		cout << s << endl;
	}
	return 0;
}
*/
