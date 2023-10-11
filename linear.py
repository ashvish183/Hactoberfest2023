def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1

my_list = [10, 23, 45, 6, 2, 8, 12]

target_value = 6

result = linear_search(my_list, target_value)

if result != -1:
    print(f"Element {target_value} found at index {result}")
else:
    print(f"Element {target_value} not found in the list")

