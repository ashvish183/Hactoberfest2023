def search(target: int , nums: list) -> int:
    left = 0
    right = len(nums) - 1
    while left <= right:
        mid = (right + left) // 2
        if nums[mid] == target:
            return mid
        elif nums[mid] < target:
            left = mid + 1
        elif nums[mid] > target:
            right = mid - 1
    return -1

if __name__ == '__main__':
    nums = [1, 2, 3, 4, 5, 6]
    target = 5
    print(search(target, nums))