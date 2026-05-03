class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()){
            return false;
        }
       string val=s+s;

        return val.find(goal)!=-1;

    }
};