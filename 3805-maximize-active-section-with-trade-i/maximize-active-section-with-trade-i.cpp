class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int> contarr;
        int n=s.length();
        int cnt=0;
        int maxsum=0;
        int possum=0; 
        for(int i=0;i<n;i++)
        {
            if(i!=0 && s[i]!=s[i-1])
            {
                contarr.push_back(cnt);
                cnt=0;
            }
            cnt= s[i]=='0'?cnt-1:cnt+1;
        }
        contarr.push_back(cnt);
        for(int i:contarr) 
        {
            if(i>0)
            possum+=i;
        }
        maxsum=possum;
        int m = contarr.size();
        for(int i=1;i<m-1;i++)
        {
            if(i>0 && contarr[i-1]<0 && contarr[i+1]<0 && contarr[i]>0)
            {
                maxsum=max(maxsum,(possum+abs(contarr[i-1]+contarr[i+1]))); 
            }
        }
        return maxsum;
    }
};
