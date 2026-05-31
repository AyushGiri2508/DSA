class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n=asteroids.size();
        long long newmass=mass;
        sort(asteroids.begin(),asteroids.end() );
        for(int i=0;i<n;i++){
            if(asteroids[i]<=newmass){
                newmass=asteroids[i]+newmass;
            }
            else{
                return false;
            }
        }
    return true;
    }
};