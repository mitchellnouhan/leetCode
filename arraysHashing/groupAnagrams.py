#Had to peek at neetcode's solution, this implementation uses a hash map where the index is a tuple char freq arr and the values is a list of strings
class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        #we are going to tackle this problem with a hashmap
        #key,value <=> char arr,list of strings
        charToStrHash = defaultdict(list)
        for string in strs:
            charArr = [0] * 26
            for char in string:
                index = ord(char) - ord("a")
                charArr[index] += 1
            charToStrHash[tuple(charArr)].append(string)
        return charToStrHash.values()