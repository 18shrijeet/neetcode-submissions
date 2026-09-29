class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int ans = 0;
        vector<int>lcandies(n,1);
        vector<int>rcandies(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i] > ratings[i-1])lcandies[i]=lcandies[i-1]+1;
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i] > ratings[i+1])rcandies[i]=rcandies[i+1]+1;
        }
        for(int i=0;i<n;i++){
            ans+=max(lcandies[i],rcandies[i]);
        }
        return ans;
    }
};