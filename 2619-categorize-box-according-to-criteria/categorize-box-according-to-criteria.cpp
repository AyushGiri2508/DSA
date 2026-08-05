class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        long long vol = 1LL * length * width * height;
        int lim = 10000;
        bool bulky = (length >= lim || width >= lim || height >= lim ||
                      vol >= 1000000000LL);
        bool heavy = (mass >= 100);
        if (bulky && heavy)
            return "Both";
        else if (bulky)
            return "Bulky";
        else if (heavy)
            return "Heavy";
        else
            return "Neither";
    }
};