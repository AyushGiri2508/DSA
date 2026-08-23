class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int firstSum = 0, lastSum = 0;
        int leftq = 0, rightq = 0;
        for (int i = 0; i < n / 2; i++)
            if (num[i] == '?')
                leftq++;
            else
                firstSum += num[i] - '0';
        for (int i = n / 2; i < n; i++)
            if (num[i] == '?')
                rightq++;
            else
                lastSum += num[i] - '0';

        if ((leftq + rightq) % 2 == 1) {
            return true;
        }
        // return firstSum-lastSum =(leftq-rightq)/2*9;
        return firstSum - lastSum != (rightq - leftq) / 2 * 9;
    }
};