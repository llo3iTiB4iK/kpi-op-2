from classes import*

def Task1(arr):
    sum=0
    for i in range(1,len(arr)):
        if arr[0].Parallel(arr[i]):
            sum+=arr[i].Length()
    print("Sum of lengths of vectors', parallel to the first two-dimensional vector = "+str(sum))

def Task2(arr):
    sum_vec=R3_Vector(0,0,0)
    for i in range(1,len(arr)):
        if arr[0].Perpendicular(arr[i]):
            sum_vec+=arr[i]
    print("Sum of vectors, perpendicular to the first three-dimensional vector = ",end='')
    sum_vec.show()