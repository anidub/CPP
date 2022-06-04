#include <iostream>
#include <vector>
#include <queue>
#include <mutex>
#include <unordered_set>

using namespace std;
/*https://leetcode.com/problems/web-crawler-multithreaded/
 * Given a URL startUrl and an interface HtmlParser, implement a Multi-threaded web crawler to crawl all links that are under the same hostname as startUrl.

Return all URLs obtained by your web crawler in any order.

Your crawler should:

Start from the page: startUrl
Call HtmlParser.getUrls(url) to get all URLs from a webpage of a given URL.
Do not crawl the same link twice.
Explore only the links that are under the same hostname as startUrl.
As shown in the example URL above, the hostname is example.org. For simplicity's sake, you may assume all URLs use HTTP protocol without any port specified. For example, the URLs http://leetcode.com/problems and http://leetcode.com/contest are under the same hostname, while URLs http://example.org/test and http://example.com/abc are not under the same hostname.

The HtmlParser interface is defined as such:

interface HtmlParser {
  // Return a list of all urls from a webpage of given url.
  // This is a blocking call, that means it will do HTTP request and return when this request is finished.
  public List<String> getUrls(String url);
}
Note that getUrls(String url) simulates performing an HTTP request. You can treat it as a blocking function call that waits for an HTTP request to finish. It is guaranteed that getUrls(String url) will return the URLs within 15ms. Single-threaded solutions will exceed the time limit so, can your multi-threaded web crawler do better?

Below are two examples explaining the functionality of the problem. For custom testing purposes, you'll have three variables urls, edges and startUrl. Notice that you will only have access to startUrl in your code, while urls and edges are not directly accessible to you in code.

Input:
urls = [
  "http://news.yahoo.com",
  "http://news.yahoo.com/news",
  "http://news.yahoo.com/news/topics/",
  "http://news.google.com",
  "http://news.yahoo.com/us"
]
edges = [[2,0],[2,1],[3,2],[3,1],[0,4]]
startUrl = "http://news.yahoo.com/news/topics/"
Output: [
  "http://news.yahoo.com",
  "http://news.yahoo.com/news",
  "http://news.yahoo.com/news/topics/",
  "http://news.yahoo.com/us"
]
https://leetcode.com/problems/web-crawler-multithreaded/discuss/719974/Efficient-C%2B%2B-with-mutex-and-condition-variable-97
 */
/*
class WebCrawler {
    int thread_num;
    string hostname;
    queue<string> q;
    unordered_set<string> seen;
    int working = 0;
    bool done;
    mutex m;
    condition_variable cv;
    vector<thread> workers;

    string extractHostName(string& url){
        int start = url.find('/') + 2;
        int end =  url.find('/', start);
        if(end == string::npos)
            return url.substr(start);
        return url.substr(start, end - start);
    }


    // this a worker thread that will be doing tasks.
	void startWorker(HtmlParser *parser) {
        while(true){
            unique_lock<mutex> ul(m);
            // wait until there are some tasks OR
            // we are done executing
            cv.wait(ul, [&](){
                return q.size() > 0 || done;
            });
            // if done, return.
            if(done)
                return;
            // indicate that this thread is in progress
            working++;
            string item = q.front(); q.pop();
            ul.unlock();
            // since getUrls can take a lot of time, release the lock.
            auto accessible = parser->getUrls(item);

            // acquire the lock and add tasks.
            ul.lock();
            for(auto& url : accessible){
                // if it has been seen already or the host name doesn't match, ignore it.
                if(seen.count(url) || extractHostName(url) != hostname)
                    continue;
                seen.insert(url);
                q.push(url);
            }
            working--;

            // IF
            //   1) no thread is processing
            //   2) no tasks are available even after executing this task
            // THEN we are done.
            if(working == 0 && q.empty()){
                done = true;
            }
            // notify all the threads either about finishing or about availability of tasks.
            cv.notify_all();
        }
	}

	vector<string> crawl(string startUrl, HtmlParser htmlParse) {
        // get the hostname for this url.
        // mark it as seen.
        hostname = extractHostName(startUrl);
        seen.insert(startUrl);
        done = false;
        // get number of supported threads
        thread_num = thread::hardware_concurrency();
        // push the first task to do.
        q.push(startUrl);

        // start bunch of worker threads.
        for(int i = 0; i < thread_num; i++){
            workers.emplace_back(&WebCrawler::startWorker, this, &htmlParser);
        }

        // join those threads so that crawl is a blocking call
        for(auto &t : workers){
            t.join();
        }
        // return every unique processed string
        return vector<string>(seen.begin(), seen.end());
	}

};*/
