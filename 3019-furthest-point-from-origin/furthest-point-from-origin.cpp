class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left=0;
        int right=0;
        int cnt=0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='L')left++;
            else if(moves[i]=='R') right++;
            else cnt++;
        }
        return abs(left-right)+cnt;
    }
};