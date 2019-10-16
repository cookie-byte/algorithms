#Code to return first index of occurrence of element x if it is present in array arr, -1 if not present
def search(arr, x): 

	for i in range(len(arr)): 

		if arr[i] == x: 
			return i 

	return -1
