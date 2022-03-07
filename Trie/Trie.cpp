#include <iostream>
using namespace std;
/*https://www.techiedelight.com/cpp-implementation-trie-data-structure/
 * https://www.techiedelight.com/memory-efficient-trie-implementation-using-map-insert-search-delete/
 */
#define CHAR_SIZE 128

class Trie {
public:
    bool endOfWord;
    Trie* character[CHAR_SIZE];

    Trie() {
        this->endOfWord = false;
        for(int i = 0; i < CHAR_SIZE; i++) {
            this->character[i] = nullptr;
        }
    }
    void insert(string);
    bool search(string);
    bool deletion(Trie*&, string);
    bool haveChildren(Trie const*);
};

void Trie::insert(string key) {
    Trie* cur = this;
    for(int i = 0; i < key.length(); i++) {
        if(cur->character[key[i]] == nullptr)
            cur->character[key[i]] = new Trie();

        cur = cur->character[key[i]];
    }
    cur->endOfWord = true;
}

bool Trie::search(string key) {
    if(this == nullptr)
        return false;
    Trie* cur = this;
    for(int i = 0; i < key.length(); i++) {
        cur = cur->character[key[i]];
        if(cur == nullptr)
            return false;
    }
    //cout << cur->endOfWord << endl;
    return cur->endOfWord;
}

bool Trie::haveChildren(Trie const* cur) {
    for(int i = 0; i < CHAR_SIZE; i++) {
        if(cur->character[i])
            return true;
    }
    return false;
}

bool Trie::deletion(Trie*& cur, string key){
    if(cur == nullptr) return false;

    if(key.length()) {
        if(cur != nullptr && cur->character[key[0]] != nullptr
        && deletion(cur->character[key[0]], key.substr(1)) && cur->endOfWord == false) {
            if(!haveChildren(cur)) {
                delete cur;
                cur = nullptr;
                return true;
            } else {
                return false;
            }
        }
    }
    if(key.length() == 0 && cur->endOfWord) {
        if(!haveChildren(cur)) {
            delete cur;
            cur = nullptr;
            return true;
        } else {
            cur->endOfWord = false;
            return false;
        }
    }
    return false;
}
/*
int main() {
    Trie* head = new Trie();
    head->insert("Hello");
    cout << head->search("Hello") << " ";
    head->deletion(head, "Hello");
    cout << head->search("Hello") << " ";
}*/
