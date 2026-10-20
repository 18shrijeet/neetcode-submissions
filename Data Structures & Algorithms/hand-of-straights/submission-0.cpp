class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize)return false;
        sort(hand.begin(), hand.end());
        unordered_map<int,int>mp;
        for(auto i: hand)mp[i]++;

        for(int i=0;i<n;i++){
            if(mp[hand[i]] > 0){
                for(int j=hand[i];j< hand[i]+groupSize; j++){
                    if(mp[j] > 0){
                        mp[j]--;
                    }
                    else return false;
                }
            }
        }
        return true;
    }
};
