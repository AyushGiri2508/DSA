class Solution {
public:
    string reorganizeString(string s) {
        string ans(s.size(), ' ');
        int hash[256] = {0};
        for (int i = 0; i < s.size(); i++) {
            hash[s[i]]++;
        }
        int maxFreq = 0;
        char maxChar;

        for (int i = 0; i < 256; i++) {
            if (hash[i] > maxFreq) {
                maxFreq = hash[i];
                maxChar = (char)i;
            }
        }
        if(maxFreq > (s.size() + 1) / 2)
              return "";
              int index = 0;

while(hash[maxChar] > 0) {
    ans[index] = maxChar;
    hash[maxChar]--;
    index += 2;
}
for(int i = 0; i < 256; i++) {
    while(hash[i] > 0) {

        if(index >= s.size()) {
            index = 1;
        }

        ans[index] = (char)i;
        hash[i]--;
        index += 2;
    }
}
     return ans;
    }
};