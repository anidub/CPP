#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/longest-duplicate-substring/
 * Given a string s, consider all duplicated substrings: (contiguous) substrings of s that occur 2 or more times. The occurrences may overlap.

Return any duplicated substring that has the longest possible length. If s does not have a duplicated substring, the answer is "".
Input: s = "banana"
Output: "ana"

https://leetcode.com/problems/longest-duplicate-substring/discuss/1548004/c-rkhash-and-binary-search/1287152

https://www.youtube.com/watch?v=FQ8hcOOzQMU : to understand

https://leetcode.com/problems/longest-duplicate-substring/discuss/291048/C%2B%2B-solution-using-Rabin-Karp-and-binary-search-with-detailed-explaination
 */
string lds_ans;
vector<int> power;
int prime = 1000007;// large prime number

string validate(int desire, string& str);
//TC:O(NlogN).LogN for binary search and N for for rabin karp SC :  O(N)
string longestDupSubstring(string s) {
	lds_ans = "";
	power = vector<int>(s.length(), 1);

	// precompute all the pow(26, k) 0 < k < S.length() modulus prime
	for(int i = 1; i < s.length(); i++)
		power[i] = (power[i-1] * 26) % prime;

	int low = 0, high = s.length();

	while(low <= high) {// code for the binary search, very trivial
		int mid = low + (high - low) / 2;
		string tmp = validate(mid, s);
		if(tmp.length() == 0)
			high = mid - 1;
		else {
			if(tmp.length() > lds_ans.length())
				lds_ans = tmp;
			low = mid + 1;
		}
	}
	return lds_ans;
}

string validate(int desire, string& str) {
	if(desire == 0) return "";
	unordered_map<int, vector<int>> hash;
	int i; long long current = 0;

	for(i = 0; i < desire; i++)// compute the hash value of the first "length" characters
		current = ((current * 26) % prime + (str[i] - 'a')) % prime;

	hash[current] = vector<int>(1, 0);// store the result in a hashmap that maps from hashvalue to starting index

	for(int i = desire; i < str.length(); i++) {
		// sliding window to maintain the current substr's hash value be aware of overflow
		current = ((current - (long long) power[desire - 1] * (str[i - desire] - 'a')) % prime + prime) % prime;
		current = (current * 26 + (str[i] - 'a')) % prime;

		if(hash.find(current) == hash.end())// if that hash value is not in our set we do nothing and add the value to our map
			hash[current] = vector<int>(1, i - desire + 1);
		else {
			for(auto it : hash[current]) {// otherwise, start a string by string comparason and see if there's a match
				if( strcmp(str.substr(it, desire).data(), str.substr(i - desire + 1, desire).data() ) == 0 )
					return str.substr(it, desire);
			}
			hash[current].push_back(i - desire + 1);
		}
	}
	return "";

}
/*
int main() {
	cout << longestDupSubstring("nnpxouomcofdjuujloanjimymadkuepightrfodmauhrsy") << endl;

	return 0;
}*/
