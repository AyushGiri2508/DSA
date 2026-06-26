class LRUCache {
public:
    int cap;
    // {key, value}
    list<pair<int, int>> dll;
    // key -> iterator in list
    unordered_map<int, list<pair<int, int>>::iterator> mp;

    LRUCache(int capacity) {
        cap = capacity;
    }
    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        auto it = mp[key];
        int value = it->second;

        // Move to front (Most Recently Used)
        dll.erase(it);
        dll.push_front({key, value});
        mp[key] = dll.begin();

        return value;
    }

    void put(int key, int value) {

        // Key already exists
        if (mp.find(key) != mp.end()) {
            dll.erase(mp[key]);
        }
        // Cache full
        else if (dll.size() == cap) {
            auto last = dll.back();
            mp.erase(last.first);
            dll.pop_back();
        }

        // Insert at front
        dll.push_front({key, value});
        mp[key] = dll.begin();
    }
};