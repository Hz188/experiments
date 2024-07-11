/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Trie {
private:
    bool is_end;
    vector<Trie*> next{};
public:
    Trie() {
        is_end = false;
        next.resize(26);
    }
    
    void insert(string word) {
        Trie* node = this;
        for(char c: word) {
            if(!node->next[c-'a']){
                node->next[c-'a'] = new Trie();
            }
            node = node->next[c-'a'];
        }
        node->is_end = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for(char c: word) {
            node = node->next[c-'a'];
            if(!node) return false;
        }
        return node->is_end;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for(char c: prefix) {
            node = node->next[c-'a'];
            if(!node) return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

