'''
###pseudocode###
while not Sorted(list) do
    shuffle (list)
done
'''
import random
def bogoSort(lst):
    while(is_sorted(lst) != True):
        shuffle(lst)

def shuffle(lst):
    for i in range(0, len(lst)):
        r = random.randint(0, len(lst) - 1)
        #shuffle
        lst[i], lst[r] = lst[r], lst[i]

#check if array is sorted or not
def is_sorted(lst):
    for i in range(0, len(lst)):
        if(lst[i] > lst[i + 1]):
            return False
    return True

