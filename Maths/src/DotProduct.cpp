#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/dot-product-of-two-sparse-vectors/
 * Given two sparse vectors, compute their dot product.

Implement class SparseVector:

SparseVector(nums) Initializes the object with the vector nums
dotProduct(vec) Compute the dot product between the instance of SparseVector and vec
A sparse vector is a vector that has mostly zero values, you should store the sparse vector efficiently and compute the dot product between two SparseVector.

Follow up: What if only one of the vectors is sparse?

https://leetcode.com/problems/dot-product-of-two-sparse-vectors/discuss/1697337/C%2B%2B-or-Brute-greater-Optimal-or-HashMap-and-Pair-Indexing
 *
 */

//TC: O(n) for creating the Hash Map, O(L)O(L) for calculating the dot product.
// SC :  O(L) for creating the Hash Map, as we only store elements that are non-zero. O(1) for calculating the dot product.
class SparseVector {
	unordered_map<int, int> m;
public:
	SparseVector(vector<int>& nums) {
		for(int i = 0; i < nums.size(); i++) {
			if(nums[i] != 0)// Unordered Map to hash non zero elements of vector since anything multiply with 0 is 0
				m[i] = nums[i];
		}
 	}

	int dotProduct(SparseVector& vec) {
		int dotProd = 0;

		for(auto i : this->m) {
			if(vec.m.find(i.first) != vec.m.end())
				dotProd += this->m[i.first] * vec.m[i.first];
		}
		return dotProd;
	}
};
/*FB interview asked not to use to map
 * Time complexity: O(n)for creating the <index, value> pair for non-zero values; O(L + L2) for calculating the dot product.
 * Space complexity: O(L)
 *
 * follow up:
 * what would you do if one of the vectors werent fully "sparse" -> hint use binary search
 * If the sizes of the two index-pair vectors are n and m then you iterate the smaller vector
 *  and binary search the larger one. So the effective runtime is O(min(n, m) * log(max(n, m))).
 *
 */
class SparseVectorIdxPair {
	vector<pair<int, int>> pairs;

public:
	SparseVectorIdxPair(vector<int>&  nums) {
		for(int i = 0; i < nums.size(); i++) {
			if(nums[i] != 0)
				pairs.push_back({i, nums[i]});
		}
	}

	int dotProduct(SparseVectorIdxPair& vec) {
		int res = 0, p = 0, q = 0;

		while(p < pairs.size() && q < vec.pairs.size()) {
			if(pairs[p].first == vec.pairs[q].first){
				res += pairs[p].second * vec.pairs[p].second;
				p++;
				q++;
			} else if(pairs[p].first > vec.pairs[q].first)
				q++;
			else
				p++;
		}
		return res;
	}
};
/*https://leetcode.com/problems/dot-product-of-two-sparse-vectors/discuss/1342228/C%2B%2B-Binary-Search
 * Using binary search
 */
class SparseVectorBinarySearch{
public:
	SparseVectorBinarySearch(vector<int> &nums) {
        const int SIZE = nums.size();

        for(int index =0; index < SIZE; ++index)  {
            if(nums[index] != 0) {
                m_sparse_vector.emplace_back(index, nums[index]);
            }
        }
    }

    // Time: O(nlogm)
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVectorBinarySearch& vec) {
        long dot_product = 0;

        const int SIZE = this->m_sparse_vector.size();

        // Time:  O(n)
        for(int index = 0; index < SIZE; ++index) {
            const int target_position = this->m_sparse_vector[index].first;
            const int target_value    = this->m_sparse_vector[index].second;

            // Time: O(logm)
            int target_pos = get_first_position_binary_search(vec, target_position);

            if(target_pos != -1) {
                dot_product += (target_value * vec.m_sparse_vector[target_pos].second);
            }
        }
        if(dot_product >INT_MAX) {
            return INT_MAX;
        }
        else if(dot_product < INT_MIN)  {
            return INT_MIN;
        }
        return dot_product;
    }

private:
    vector<pair<int,int>> m_sparse_vector;
    // Time: O(logm)
    int get_first_position_binary_search(SparseVectorBinarySearch& vec, const int target_position)  {
        int left_index =0;
        int right_index = vec.m_sparse_vector.size();

        while(left_index < right_index) {
            int mid_index = (left_index + (right_index - left_index)/2);

            if(vec.m_sparse_vector[mid_index].first < target_position) {
                left_index = mid_index + 1;
            }
            else {
                right_index = mid_index;
            }
        }

        if(left_index == vec.m_sparse_vector.size() || vec.m_sparse_vector[left_index].first != target_position)  {
            return -1;
        }
        return left_index;
    }
};

/*
int main() {
	vector<int> v1 = {1, 0, 0, 2, 3};
	vector<int> v2 = {0, 3, 0, 4, 0};

	SparseVectorBinarySearch sv1 (v1);
	SparseVectorBinarySearch sv2 (v2);

	int ans = sv1.dotProduct(sv2);

	cout << ans << endl;
	return 0;
}
*/
