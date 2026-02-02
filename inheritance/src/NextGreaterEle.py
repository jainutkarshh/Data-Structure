from typing import List

class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        res = []

        for target in nums1:
            ng = -1
            target_found = False

            for num in nums2:
                if num == target:
                    target_found = True
                elif target_found:
                    if num > target:
                        ng = num
                        break
            
            res.append(ng)
        
        return res


# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Test case 1
    nums1 = [4, 1, 2]
    nums2 = [1, 3, 4, 2]
    result = solution.nextGreaterElement(nums1, nums2)
    print(f"Input: nums1 = {nums1}, nums2 = {nums2}")
    print(f"Output: {result}")
    print(f"Expected: [-1, 3, -1]\n")
    
    # Test case 2
    nums1 = [2, 4]
    nums2 = [1, 2, 3, 4]
    result = solution.nextGreaterElement(nums1, nums2)
    print(f"Input: nums1 = {nums1}, nums2 = {nums2}")
    print(f"Output: {result}")
    print(f"Expected: [3, -1]")
