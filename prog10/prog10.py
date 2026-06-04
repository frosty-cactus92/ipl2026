## Hoare's partition algorithm swaps an array's elements in place , based on a chosen pivot. This pivot is the first element within your array
## All elements that are than the pivot stay on the left side of the array , whereas all elements that are greater , are pushed to the right.
## Unlike Lomuto's partition , the pivot may or may not end up in the correct final position for sorting.
arr = [5,3,8,4,2,7,1,10]
i = -1 ## we pick out of bounds first , since after every iteration/swap , we need to verify if the elements on either side still satisfy
        ## the condition for hoare's partition , that is , everythin to the left is lesser than pivot , and everything to the right greater.
j = len(arr)
piv = arr[0] ## Choosing a pivot
while(True):
    i += 1 
    while(arr[i]<piv):
        i+=1
    j-=1
    while(arr[j]>piv):
        j-=1
    if i>=j:
        break
    arr[i],arr[j] = arr[j],arr[i] ## swapping in place
    
    
print(arr) ## Output : [1,3,2,4,8,7,5,10] , note 5 is not in the correct position for final sorting , but it does not matter

## Using this , we can implement sorting , by recursively performing hoare's partition , on the smaller portions of the array
#  now created at ,  the left and right , of your right pointer ,  to  obtain a fully sorted array

arr1 = [5,3,8,4,2,7,1,10]
def hoare_part(arr , low , high):
    piv = arr[low]
    i = low - 1
    j = high+1
    while(True):
        i += 1
        while(arr[i]<piv):
            i+=1
        j-=1
        while(arr[j]>piv):
            j-=1
        if i>=j:
            break
        arr[i],arr[j] = arr[j],arr[i]
    
    return j
    

def qsort(arr , low , high):
    if low<high:
        p = hoare_part(arr , low , high)
        print(arr)
        qsort(arr , low ,p) # Performing the partition recursively , on the two smaller parts of the array , post partitioning
        qsort(arr , p+1 , high) # <Same note as above>
        
qsort(arr1 , 0  , len(arr1)-1)
print(arr1) ## Output: [1 , 2 , 3 , 4 , 5 , 7 , 8 , 10]