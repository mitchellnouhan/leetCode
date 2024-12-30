class Solution {
public:
    int rot_num(vector<int> nums){
        int l = 0;
        int r = nums.size() - 1;
        while (l < r){
            int m = l + (r - l) / 2;
            if (nums[m] > nums[r])
                l = m + 1;
            else
                r = m;
        }
        return l;
    }

    //create mapping function using the number of rotations
    int map(int index, int rots, int arr_size){
        return (index + rots) % arr_size;
    }

    int search(vector<int>& nums, int target) {
        //find pivot point or number of rotations (find min in rotated sorted array)
        int rots = rot_num(nums);
        int arr_size = nums.size();

        //now, you can do a nominal regular binary search using a mapped m index nums vals to adjust l and r :) 
        //unmapped indexes 
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r){
            int m = l + (r - l) / 2;
            int m_m = map(m, rots, arr_size);
            if(target < nums[m_m])
                r = m - 1;
            else if(target > nums[m_m])
                l = m + 1;
            else
                return m_m;
        }
        return -1;
    }
};
