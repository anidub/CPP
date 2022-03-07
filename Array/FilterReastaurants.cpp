#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <utility>

using namespace std;

/*
 * https://leetcode.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance/
 * Given the array restaurants where  restaurants[i] = [idi, ratingi, veganFriendlyi, pricei, distancei]. You have to filter the restaurants using three filters.
The veganFriendly filter will be either true (meaning you should only include restaurants with veganFriendlyi set to true) or false (meaning you can include any restaurant).
 In addition, you have the filters maxPrice and maxDistance which are the maximum value for price and distance of restaurants you should consider respectively.
Return the array of restaurant IDs after filtering, ordered by rating from highest to lowest.
 For restaurants with the same rating, order them by id from highest to lowest. For simplicity veganFriendlyi and veganFriendly take value 1 when it is true, and 0 when it is false.
Example 1:

Input: restaurants = [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]], veganFriendly = 1, maxPrice = 50, maxDistance = 10
Output: [3,1,5]
Explanation:
The restaurants are:
Restaurant 1 [id=1, rating=4, veganFriendly=1, price=40, distance=10]
Restaurant 2 [id=2, rating=8, veganFriendly=0, price=50, distance=5]
Restaurant 3 [id=3, rating=8, veganFriendly=1, price=30, distance=4]
Restaurant 4 [id=4, rating=10, veganFriendly=0, price=10, distance=3]
Restaurant 5 [id=5, rating=1, veganFriendly=1, price=15, distance=1]
After filter restaurants with veganFriendly = 1, maxPrice = 50 and maxDistance = 10 we have restaurant 3, restaurant 1 and restaurant 5 (ordered by rating from highest to lowest).
 * https://leetcode.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance/discuss/572061/C%2B%2B-Priority-Queue
 */
struct compare {
	bool operator()(vector<int> v1, vector<int> v2) {
		return v1[1] < v2[1] || (v1[1] == v1[1] &&  v1[0] < v2[0]);
	}
};

 vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
     if(restaurants.empty()) return {};

     vector<vector<int>> filter;
     for(int i = 0; i < restaurants.size(); i++) {
    	 if((!veganFriendly || veganFriendly == restaurants[i][2]) && restaurants[i][3] <= maxPrice &&  restaurants[i][4] <= maxDistance) {
    		 filter.push_back(restaurants[i]);
    	 }
     }

     priority_queue<vector<int>, vector<vector<int>>, compare> pq(filter.begin(), filter.end());
     vector<int> result;
     while(!pq.empty()) {
    	 vector<int> temp = pq.top();
    	 result.push_back(temp[0]);
    	 pq.pop();
     }
     return result;

 }
/*
 int main() {

	 return 0;
 }*/
