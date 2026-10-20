class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        unordered_map<int, int> count;
        for (int num : hand) count[num]++;

        for (int num : hand) {
            int start = num;
            while (count[start - 1] > 0) start--;
            while (start <= num) {
                while (count[start] > 0) {
                    for (int i = start; i < start + groupSize; i++) {
                        if (count[i] == 0) return false;
                        count[i]--;
                    }
                }
                start++;
            }
        }
        return true;
    }
};

/*
Hash Map
Intuition
We need to split the hand into groups of size groupSize, where each group is made of consecutive numbers and every card is used exactly once.
This approach uses only a frequency map and a simple rule:
Any valid group must start at the beginning of a consecutive run
So for a given number num, we first walk left to find the earliest possible start of its run
(we keep moving left while start - 1 still exists in the hand)
Once we know a possible start, we try to repeatedly form consecutive groups starting from that start:
while there are still cards at start, we build a group:
start, start+1, ..., start+groupSize-1
decrement counts as we use cards
By always forming groups from the earliest start in a run, we avoid skipping needed smaller cards and ensure groups remain consecutive.
Algorithm
If len(hand) is not divisible by groupSize, return false.
Build a frequency map count for all card values.
For each card value num in the hand:
Find the earliest start of the consecutive run containing num:
set start = num
while count[start - 1] > 0, decrement start
For every possible start up to num:
While count[start] > 0:
Try to create one full group starting at start
For each i from start to start + groupSize - 1:
If count[i] == 0, return false (missing a needed card)
Otherwise decrement count[i]
Move start forward by 1 and continue
If all groups are formed successfully, return true.



O(n) , O(n)
*/