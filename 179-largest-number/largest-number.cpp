class Solution {
public:
static bool comp(string &x,string &y){
    if(x+y>y+x){
        return true;
    }
    else{
        return false;
    }
}
    string largestNumber(vector<int>& nums) {
        vector<string>ans;
        for(int i=0;i<nums.size();i++){
            string ch=to_string(nums[i]);
            ans.push_back(ch);
        }
        sort(ans.begin(),ans.end(),comp);
        if(ans[0]=="0"){
            return "0";
        }
        string res="";
        for(int i=0;i<ans.size();i++){
            res+=ans[i];
        }
        return res;
    }
};