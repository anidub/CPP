#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/
 *You are given a binary array nums and an integer k.
A k-bit flip is choosing a subarray of length k from nums and simultaneously changing every 0 in the subarray to 1, and every 1 in the subarray to 0.
Return the minimum number of k-bit flips required so that there is no 0 in the array. If it is not possible, return -1.
A subarray is a contiguous part of an array.
https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/discuss/239284/C%2B%2B-greedy-stack-and-O(1)-memory :: coumments
 */
//TC: O(N) and SC: O(K) as our queue can at max grow to K only

//https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/discuss/1131369/C%2B%2B-O(N)-time-O(1)-space for more optimalSoln
int minKBitFlips(vector<int>& A,int K) {
    int n = A.size();
   /*Keeps track of the last index of a k-window flip
    The size of the queue at anytime gives us the total number of flips that
    have happened within any k-interval*/
    queue<int> isflipped; //Space is O(K) max
    int count = 0; //min k-bit flips

    for(int i = 0; i < n; i++){ //O(N)
      //If current index is 0, then we need to process it/do sth about it
      if(A[i] == 0){

        /*If our queue is empty or queue is even size
        (i.e our current index has been flipped even # of times , thus ending back at state 0),
        then we need to flip this 0 to a 1*/
        if(isflipped.empty() || isflipped.size() % 2 == 0){
          count++; //Flip it
          /*Populate the queue with the index of the end of this k interval that was flipped*/
          isflipped.push(i + K - 1);
        }
        /*Lets say we are here, that means our original element is a zero and the queu size is
        odd sized which means that this 0 has been flipped odd # of times, giving us the result 1.
        So we do nothing since we know the element has been flipped to 1 already*/
      }else{ //A[i] == 1
        /*If A[i] == 1, we need to process it only in one case*/
        if(isflipped.size() % 2 != 0){
          /*this means a '1' has been flipped odd # of times , thus ending at state '0',
          we need to flip this then*/
          count++;

          /*Populate the queue with the index of the end of this k interval that was flipped*/
          isflipped.push(i + K - 1);
        }
      }

      //Anytime we are done with a interval, we pop the index out of the queue
      //MISTAKE: Make sure to check the q is emoty or not before popping off the value
      if(!isflipped.empty() && i >= isflipped.front()) isflipped.pop();
    }

    /*Return the minimum number of K-bit flips required so that there is no 0 in the array.  If it is not possible, return -1*/
    return isflipped.empty() ? count : -1;
}
/*

/*
int main() {
	vector<int> A;
	A.push_back(0);A.push_back(0);A.push_back(0);A.push_back(1);
	A.push_back(0);A.push_back(1);A.push_back(1);A.push_back(0);

	cout << minKBitFlips(A, 3) << endl;

	return 0;
}*/
