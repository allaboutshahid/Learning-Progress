#include <iostream>
#include <unordered_map>
#include <list>

class LRUCache {
    int capacity;
    std::list<std::pair<int, int>> items; // {key, value}
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> lookup;

public:
    LRUCache(int cap) : capacity(cap) {}

    int get(int key) {
        if (lookup.find(key) == lookup.end()) return -1;
        items.splice(items.begin(), items, lookup[key]);
        return lookup[key]->second;
    }

    void put(int key, int value) {
        if (lookup.find(key) != lookup.end()) {
            items.erase(lookup[key]);
        } else if ((int)items.size() >= capacity) {
            auto last = items.back();
            lookup.erase(last.first);
            items.pop_back();
        }
        items.push_front({key, value});
        lookup[key] = items.begin();
    }
};

int main() {
    LRUCache cache(2);
    cache.put(1, 10);
    cache.put(2, 20);
    std::cout << cache.get(1) << std::endl; // 10
    cache.put(3, 30); // evicts key 2
    std::cout << cache.get(2) << std::endl; // -1
    return 0;
}