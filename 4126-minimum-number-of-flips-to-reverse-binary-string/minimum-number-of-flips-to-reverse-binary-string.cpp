class Solution {
public:
    int minimumFlips(int n) {
        string s = bitset<64>(n).to_string(); 
         s = s.substr(s.find('1'));
    int flips = 0;
    int len = s.size();
    
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - 1 - i]) {
            flips += 2;  
        }
    }
    return flips;
    }
};