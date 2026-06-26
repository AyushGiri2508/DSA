class LFUCache {
public:
    struct Node {
        int key, value, freq;
        Node(int k, int v) {
            key = k;
            value = v;
            freq = 1;
        }
    };
    int capacity;
    int minFreq;
    unordered_map<int, list<Node>> freqList;
    unordered_map<int, list<Node>::iterator> keyNode;
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }
    void updateFreq(list<Node>::iterator it) {
        int key = it->key;
        int value = it->value;
        int freq = it->freq;

        // Remove from old frequency list
        freqList[freq].erase(it);

        if (freqList[freq].empty()) {
            freqList.erase(freq);
            if (minFreq == freq)
                minFreq++;
        }

        // Insert into new frequency list
        freqList[freq + 1].push_front(Node(key, value));
        freqList[freq + 1].front().freq = freq + 1;
        keyNode[key] = freqList[freq + 1].begin();
    }

    int get(int key) {
        if (keyNode.find(key) == keyNode.end())
            return -1;

        int value = keyNode[key]->value;
        updateFreq(keyNode[key]);
        return value;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        if (keyNode.find(key) != keyNode.end()) {
            keyNode[key]->value = value;
            updateFreq(keyNode[key]);
            return;
        }

        if (keyNode.size() == capacity) {
            auto &lst = freqList[minFreq];
            int delKey = lst.back().key;
            keyNode.erase(delKey);
            lst.pop_back();

            if (lst.empty())
                freqList.erase(minFreq);
        }

        minFreq = 1;
        freqList[1].push_front(Node(key, value));
        keyNode[key] = freqList[1].begin();
    }
};