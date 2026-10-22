class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>s;
        while(true){
            int sum = 0;
            int tot = 0;
            if(n==1)return true;
            while(n){
                sum = n%10;
                n/=10;
                tot+= (sum*sum);
            }
            if(s.count(tot)) return false;
            s.insert(tot);
            n = tot;
            tot = 0;
        }
        return true;
    }
};
