def binarysearch(arr, start, end, k):
    mid = (start + end) // 2
    
    if start > end: return -1

    if arr[mid] == k: return mid

    if arr[mid] > k: return binarysearch(arr, start, mid-1, k)

    if arr[mid] < k: return binarysearch(arr, mid+1, end, k)


arr = [12, 34, 37, 45, 57, 82, 99, 120, 134]
start = 0
end = len(arr) -1

print(binarysearch(arr, start, end, 34))