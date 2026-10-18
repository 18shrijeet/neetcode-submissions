class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Treat this like a linked list 
        // from an index i , next index is nums[i]
        // so repeated number case means , those multiple indices will point to same next index 
        // we can use fast-slow floyd cycle algo and cycle will be detected 
        // once cycle detected , move both slow and a new slow pointers from 0 , they will meet at intersection
        // thats duplicate

        int slow = 0, fast = 0;
        int n = nums.size();
        while(true){
            fast = nums[nums[fast]];
            slow = nums[slow];
            if(fast == slow)break;
        } 
        int sloww = 0;
        while(slow!=sloww){
            sloww=nums[sloww];
            slow = nums[slow];
        }
        return sloww;
    }
};
