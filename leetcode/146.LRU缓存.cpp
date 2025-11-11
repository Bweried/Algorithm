#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

/**
 * method 1
 * 标准库
 */
class LRUCache {
private:
    int cap;
    // pair中存储的是 key - value
    list<pair<int, int>> cache;
    // key -> 链表节点迭代器
    unordered_map<int, list<pair<int, int>>::iterator> map;

public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }
    
    int get(int key) {
        // 未找到
        if(!map.count(key)) return -1;
        // 找到元素  删除链表中的结点  重新添加到链尾
        auto it = map[key];
        int val = it->second;
        cache.erase(it);
        cache.push_back({key, val});
        // 迭代器改变   重新添加到 map 中
        map[key] = --cache.end();
        return val;
    }
    
    void put(int key, int value) {
        if(map.count(key))
            cache.erase(map[key]);
        // 容量满了   删除链首元素
        else if(cache.size() == cap) {
            auto old = cache.front();
            cache.pop_front();
            map.erase(old.first);
        }
        // 将新元素插到链尾
        cache.push_back({key, value});
        map[key] = --cache.end();
    }
};


/**
 * method 2
 * 手撕
 */



 int main() {
    return 0;
}