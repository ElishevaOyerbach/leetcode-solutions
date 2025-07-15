class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        min_heap = []
        max_sum = float('-inf')

        for i, lst in enumerate(nums):
            val = lst[0]
            heapq.heappush(min_heap, (val, i, 0))
            max_sum = max(max_sum, val)

        start, end = float('-inf'), float('inf')

        while len(min_heap) == len(nums):
            val, list_idx, ele_idx = heapq.heappop(min_heap)
        
            if max_sum - val < end - start or (max_sum - val == end - start and val < start):
                start, end = val, max_sum

            if ele_idx + 1 < len(nums[list_idx]):
                next_val = nums[list_idx][ele_idx + 1]
                heapq.heappush(min_heap, (next_val, list_idx, ele_idx + 1))
                max_sum = max(max_sum, next_val)

        return [start, end]
