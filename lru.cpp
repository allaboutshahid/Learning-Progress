#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
private:
    int capacity;

    list<pair<int, int> > cache;
    unordered_map<int, list<pair<int, int> >::iterator> lookup;

public:
    explicit LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        unordered_map<int, list<pair<int, int> >::iterator>::iterator it;

        it = lookup.find(key);

        if (it == lookup.end())
            return -1;

        // Move accessed item to the front.
        cache.splice(cache.begin(), cache, it->second);

        return it->second->second;
    }

    void put(int key, int value) {
        unordered_map<int, list<pair<int, int> >::iterator>::iterator it;

        it = lookup.find(key);

        // Key already exists.
        if (it != lookup.end()) {
            it->second->second = value;

            // Mark as recently used.
            cache.splice(cache.begin(), cache, it->second);

            return;
        }

        // Insert new item at the front.
        cache.push_front(make_pair(key, value));

        lookup[key] = cache.begin();

        // Remove least recently used item.
        if (cache.size() > static_cast<size_t>(capacity)) {
            int oldKey = cache.back().first;

            lookup.erase(oldKey);
            cache.pop_back();
        }
    }

    void display() const {
        list<pair<int, int> >::const_iterator it;

        cout << "Cache: ";

        for (it = cache.begin(); it != cache.end(); ++it) {
            cout << "("
                 << it->first
                 << ": "
                 << it->second
                 << ") ";
        }

        cout << endl;
    }
};

int main() {
    LRUCache cache(3);

    cout << "Adding items..." << endl;

    cache.put(1, 100);
    cache.put(2, 200);
    cache.put(3, 300);

    cache.display();

    cout << "\nAccessing key 1..." << endl;
    cout << "Value: " << cache.get(1) << endl;

    cache.display();

    cout << "\nAdding key 4..." << endl;
    cache.put(4, 400);

    cache.display();

    cout << "\nTrying to access key 2..." << endl;

    int result = cache.get(2);

    if (result == -1)
        cout << "Key 2 was evicted." << endl;
    else
        cout << "Value: " << result << endl;

    return 0;
}
