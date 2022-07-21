#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <utility>
#include <iterator>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/design-twitter/
 *Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the 10 most recent tweets in the user's news feed.

Implement the Twitter class:

Twitter() Initializes your twitter object.
void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. Each call to this function will be made with a unique tweetId.
List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be ordered from most recent to least recent.
void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.
void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId.

["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
[[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
Output
[null, null, [5], null, null, [6, 5], null, [5]]

Explanation
Twitter twitter = new Twitter();
twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
twitter.follow(1, 2);    // User 1 follows user 2.
twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2 tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.unfollow(1, 2);  // User 1 unfollows user 2.
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5], since user 1 is no longer following user 2.

https://leetcode.com/problems/design-twitter/discuss/82916/C%2B%2B-solution-with-max-heap

O(1) post/follow/unfollow,
O(n + k log n) newsfeed for getting k tweets from n followed users,
with the O(n) part coming from constructing the heap of followed users
 */

class Twitter {
unordered_map<int, unordered_set<int>> fo;
unordered_map<int, vector<pair<int, int>>> t;
long long time;

public:
	Twitter() {
		time = 0;
	}

	vector<int> getNewsFeed(int userId) {
		priority_queue<pair<int, int>> maxHeap;
		for(auto it = t[userId].begin(); it != t[userId].end(); it++)
			maxHeap.push(*it);


		for(auto it1 = fo[userId].begin(); it1 != fo[userId].end(); it1++) {
			int user = *it1;
			for(auto it2 = t[user].begin(); it2 != t[user].end(); it2++) {
				maxHeap.push(*it2);
			}
		}
		vector<int> result;
		while(maxHeap.size() > 0) {
			result.push_back(maxHeap.top().second);
			if(result.size() == 10) break;
			maxHeap.pop();
		}
		return result;
	}


	void postTweet(int userId, int tweetId) {
		t[userId].push_back({time++, tweetId});
	}

	void follow(int followerId, int followeeId) {
		if(followerId != followeeId)
			fo[followerId].insert(followeeId);
	}

	void unfollow(int followerId, int followeeId) {
		fo[followerId].erase(followeeId);
	}

};
/*
int main() {
	Twitter *twitter = new Twitter();
	twitter->postTweet(1, 5); // User 1 posts a new tweet (id = 5).
	twitter->getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
	twitter->follow(1, 2);    // User 1 follows user 2.
	twitter->postTweet(2, 6); // User 2 posts a new tweet (id = 6).
	twitter->getNewsFeed(1);  // User 1's news feed should return a list with 2 tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
	twitter->unfollow(1, 2);  // User 1 unfollows user 2.
	vector<int> param_2 = twitter->getNewsFeed(1);
	cout << param_2[0] << endl;  // User 1's news feed should return a list with 1 tweet id -> [5], since user 1 is no longer following user 2.

	delete twitter;
	return 0;
}
*/
