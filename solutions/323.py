class KthLargest(object):

    def __init__(self, k, nums):
        self.k = k
        self.pq = nums[:min(k, len(nums))]
        heapify(self.pq)
        for i in range(k, len(nums)):
            heappushpop(self.pq, nums[i])

    def add(self, val):
        heappush(self.pq, val)
        if len(self.pq) > self.k : heappop(self.pq)
        return self.pq[0]

# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)
