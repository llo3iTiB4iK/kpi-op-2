from functions import*

n1=3
n2=4
Arr1=[]
Arr2=[]
for i in range(n1):
    vector=R2_Vector()
    vector.input(str("Arr1["+str(i+1)+"]"))
    Arr1+=[vector]
for i in range(n2):
    vector=R3_Vector()
    vector.input(str("Arr2["+str(i+1)+']'))
    Arr2+=[vector]
print("Array 1:")
for i in range(len(Arr1)):
    Arr1[i].show()
print("Array 2:")
for i in range(len(Arr2)):
    Arr2[i].show()
Task1(Arr1)
Task2(Arr2)