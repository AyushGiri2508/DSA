class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
       unordered_map<int,int> freq;
    for(int x : candyType) freq[x]++;
    int unique_types = freq.size();
    return min(unique_types, (int)candyType.size() / 2);

    }
};