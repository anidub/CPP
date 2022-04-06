#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <stack>
#include <utility>
#include <list>
#include <iterator>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/
 * Given a file and assume that you can only read the file using a given method read4, implement a method read to read n characters. Your method read may be called multiple times.

Method read4:

The API read4 reads four consecutive characters from file, then writes those characters into the buffer array buf4.

The return value is the number of actual characters read.

Note that read4() has its own file pointer, much like FILE *fp in C.


https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/discuss/49618/Simple-short-Java-C%2B%2B : comments
 */
int i4 = 0, n4 = 0; // Interval buffer pointer,  // Interval buffer size
char buf4[4]; // Interval buffer to store data between calls
int read4(char *buf);

// Populating data to external buffer form interval buffer.
// If interval buffer runs out of data, then populate it first.
int read(char *buf, int n) {
	int i = 0;// Pointer to external buffer
	while(i < n) {
		if(i4 == n4) { // Interval buffer runs out of data, so trigger a new read4 call
			i4 = 0;// Reset interval buffer's pointer to the beginning
			//n4 = read4(buf4); //WORKS
			if(!n4) break;// No more data, break
		}

		buf[i++] = buf4[i++];
	}
	return i;
}
//https://leetcode.com/problems/read-n-characters-given-read4/
//https://leetcode.com/problems/read-n-characters-given-read4/discuss/49509/C%2B%2B-concise-solution. : comments
int read158(char* buf, int n) {
    //Need to initialize the buf4
    char buf4[4] = {0};
    int times = n/4;
    int index = 0;
    for (int i = 0; i < times; i++) {
        int size = 0;
        //size = read4(buf4); //WORKS!
        for (int j = 0; j < size; j++)
            buf[index++] = buf4[j];
    }
    int leftOver = n%4;
    if (leftOver != 0) {
        int size = 0;//read4(buf4);
        //size = read4(buf4);
        int minSize = min(leftOver, size);
        for (int j = 0; j < minSize; j++)
            buf[index++] = buf4[j];
    }
    return index;
}
/*
int main() {


	return 0;
}*/
