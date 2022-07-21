#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_set>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/longest-consecutive-sequence/
 * Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

https://leetcode.com/problems/longest-consecutive-sequence/discuss/41060/A-simple-C%2B%2Bsolution-using-unordered_set.And-simple-consideration-about-this-problemhttps://leetcode.com/problems/longest-consecutive-sequence/discuss/41060/A-simple-C%2B%2Bsolution-using-unordered_set.And-simple-consideration-about-this-problem
 */
class LongestConsecutiveSequence {
public:
	//TC:O(N), SC:O(N)
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 1;

        for(int &n : nums) {
        	if(s.find(n) == s.end()) continue;
        	s.erase(n);
        	int prev = n - 1, next = n + 1;

        	while(s.find(prev) != s.end())
        		s.erase(prev--);

        	while(s.find(next) != s.end())
        		s.erase(next++);

        	longest = max(longest, next - prev - 1);
        }
        return longest;
    }

    //https://leetcode.com/problems/longest-consecutive-sequence/discuss/1254638/Short-and-Easy-Solution-w-Explanation-or-O(N)-Solution-with-comments-using-hashset
    //TC:O(N), SC:O(N)
    int longestConsecutiveOptimal(vector<int> &nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 1;

        for(int &num : nums) {
        	if(s.count(num - 1)) continue;
        	int j = 1;

        	while(s.count(num + j))
        		j++;
        	longest = max(longest, j);
        }
        return longest;
    }
};

/*
int main() {
	LongestConsecutiveSequence lcs;
	vector<int> nums = {100,4,200,1,3,2};
	cout << lcs.longestConsecutive(nums) << endl;
	cout << lcs.longestConsecutiveOptimal(nums) << endl;
}
*/
