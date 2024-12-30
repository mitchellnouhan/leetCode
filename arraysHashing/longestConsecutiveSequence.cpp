class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //the key is identifying/detecting a consecutive sequence
        // pass thru the nums input array 
        // create boolean hashMap representing which values are in nums
        // iterate thru nums again
        // you only want to start counting the length of the seq if you start a seq
        // well.. how do you know if you're at the start of a seq:
        // it has no left neighbor! (we will assume left to right traversal
        // accross the number line)
        // once you've detected the start of a sequence, start counting a current seq len
        // once you've reached the end of the sequence, update the max len var
        // return max 
        int longest_consec = 0;
        unordered_map<int, bool> present;
        for(int num: nums)
            present[num] = true;

        for(int num: nums){
            if(present.count(num - 1) == 0){
                //we have detected the start of a consec seq!
                int cur_consec = 1;
                while(present.count(num + cur_consec)){
                    cur_consec++;
                }
                if(cur_consec > longest_consec)
                    longest_consec = cur_consec;
            }
        }
        return longest_consec;
    }
};
//(not drawn to scale)
//   ......1.2.3.4.5.......10...........20....
