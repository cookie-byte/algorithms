def linear_search(arr, key):
	count = 0
	for i in arr:
		if i == key and count == 0:
			count += 1
			print(str(key) + " is in the array")
	if count == 0:
		print(str(key) + " is not in the array")

#test code
arr = [0, 4, 2, 3]
linear_search(arr, 4)
linear_search(arr, 1)