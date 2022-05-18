def solution(nums):
    answer = int(len(nums) / 2)
    nums = set(nums)
    
    if len(nums) < answer:
        return len(nums)
    else: return answer