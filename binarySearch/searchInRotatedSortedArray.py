class Solution(object):
    def search(self, nums, target):
        #find the pivot point k by finding index of miniumum value
        numsLen = len(nums)
        l, r = 0, numsLen - 1
        while nums[l] > nums[r]:
            m = l + (r - l) / 2
            if nums[m] > nums[r]:
                l = m + 1
            else:
                r = m
        #you can modify the indexes with the pivot value k to do a classical binary search
        k = (numsLen - l)  % numsLen
        mapped = lambda x: (x + k) % numsLen
        unMapped = lambda x: (x - k + numsLen) if (x - k) < 0 else (x - k)
        r = unMapped(mapped(l) + numsLen - 1)
        while mapped(l) <= mapped(r):
            m = mapped(l) + (mapped(r) - mapped(l)) / 2
            if target < nums[unMapped(m)]:
                if m - 1 < 0:
                    break
                r = unMapped(m - 1)
            elif target > nums[unMapped(m)]:
                if m + 1 > numsLen - 1:
                    break
                l = unMapped(m + 1)
            else:
                return unMapped(m)
        return -1