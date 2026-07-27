class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lowspeed = 1;
        int highspeed = *max_element(piles.begin(), piles.end());

        while(lowspeed < highspeed)
        {
            int midspeed = lowspeed + (highspeed-lowspeed)/2;
            long long tot= 0;
            for(int pile: piles)
            {
                tot += (pile + midspeed -1)/midspeed;
            }
            if(tot <= h)
            {
                highspeed = midspeed;
            }
            else if(tot>h)
            {
                lowspeed= midspeed+1;
            }
        }
        return lowspeed;
    }
};
