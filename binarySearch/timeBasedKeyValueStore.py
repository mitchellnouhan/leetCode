class TimeMap(object):
    def __init__(self):
        self.timeMap = defaultdict(list)

    def set(self, key, value, timestamp):
        timeMapValue = (timestamp, value)
        self.timeMap[key].append(timeMapValue)     

    def get(self, key, timestamp):
        arr = self.timeMap[key]
        arrLen = len(arr)
        if arrLen < 1:
            return ""
        elif arrLen == 1:
            return arr[0][1]
        
        l, r = 0, arrLen - 1
        while arr[r][0] > timestamp and l <= r:
            m = l + (r - l) / 2
            #edge case
            if l == m and timestamp > arr[m][0]:
                if timestamp < arr[r][0]:
                    return arr[m][1]
                else:
                    return arr[r][1]

            if timestamp < arr[m][0]:
                r = m - 1
            elif timestamp > arr[m][0]:
                l = m
            else:
                return arr[m][1]

        if l > r:
            return ""
        return arr[r][1]

# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)