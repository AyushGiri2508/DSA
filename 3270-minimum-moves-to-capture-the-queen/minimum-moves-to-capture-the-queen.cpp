class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {

        // Check if bishop blocks rook
        if (a == e) {
            // Same row
            if (!(c == a && d > min(b, f) && d < max(b, f)))
                return 1;
        }

        if (b == f) {
            // Same column
            if (!(d == b && c > min(a, e) && c < max(a, e)))
                return 1;
        }

        // Check if rook blocks bishop
        if (abs(c - e) == abs(d - f)) {
            // Rook lies on the same diagonal
            if (!(abs(a - e) == abs(b - f) &&
                  a > min(c, e) && a < max(c, e) &&
                  b > min(d, f) && b < max(d, f)))
                return 1;
        }

        return 2;
    }
};