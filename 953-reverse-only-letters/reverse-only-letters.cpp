class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {

            // If left is not a letter, move i
            if (!((s[i] >= 'a' && s[i] <= 'z') ||
                  (s[i] >= 'A' && s[i] <= 'Z'))) {
                i++;
            }

            // If right is not a letter, move j
            else if (!((s[j] >= 'a' && s[j] <= 'z') ||
                       (s[j] >= 'A' && s[j] <= 'Z'))) {
                j--;
            }
            else {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }

        return s;
    }
};
