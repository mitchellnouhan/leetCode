class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        cur = []
        numLen = len(nums)
        
        def dfs(ind):
            #base case
            if ind >= numLen:
                res.append(list(cur))
                return 
            
            #decision to add and forward track
            cur.append(nums[ind])
            dfs(ind + 1)

            #backtrack then make decision not to add
            cur.pop()
            dfs(ind + 1)
        
        #init/call depth first solution search function and then return
        dfs(0)    
        return res