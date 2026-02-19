class Solution:
    def validMountainArray(self, arr: List[int]) -> bool:
        if len(arr) < 3:
            return False
        
        peak_idx1 = 0
        for i in range(1, len(arr)):
            if arr[i] > arr[i-1] and peak_idx1 >= 0:
                peak_idx1 = i
            elif arr[i] == arr[i-1]:
                peak_idx1 = -1

        if peak_idx1 <= 0:
            return False

        peak_idx2 = 0
        for i in range(len(arr)-2, -1, -1):
            if arr[i] > arr[i+1] and peak_idx2 >= 0:
                peak_idx2 = i
            elif arr[i] == arr[i+1]:
                peak_idx2 = -1
        
        if peak_idx2 <= 0:
            return False

        return peak_idx1 == peak_idx2
