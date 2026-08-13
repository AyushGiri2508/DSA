class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s="";
        int n1=word1.size();
        int n2=word2.size();
        int i=0;
        while(i<min(n1,n2)){
            s+=word1[i];
            s+=word2[i];
            i++;
        }
        if(n1>n2){
        for(int i=n2;i<n1;i++){
            s+=word1[i];
        }
        }
        else{
            for(int i=n1;i<n2;i++){
            s+=word2[i];
        } 
        
        }
        return s;
    }
};