"""
Binary Search Implementation using recursion
"""

def binary_search(arr, x, y, z):
    if y >= x:
        mid = 1 + (y-1)//2

        if arr[mid] == z:
            return mid
        elif arr[mid] > z:
            return binary_search(arr, x, mid-1, z)
        else:
            return binary_search(arr, mid+1, y, z)

    else:
        return -1


# tests

arr = [10, 20, 30, 100, 40, 200]
z = 100

ret = binary_search(arr, 0, len(arr)-1, z)
print(ret)

