class TVector:
    def __init__(self,k,arr):
        self.n=int(k)
        self.coordinates=arr
    def show(self):
        print('('+str(self.coordinates[0]),end='')
        for i in range(1,self.n):
            print(';'+str(self.coordinates[i]),end='')
        print(')')
    def Parallel(self,vec):
        if self.n!=vec.n:
           print("Vectors of different size...\n")
           return False
        else:
            flag=True
            for i in range(1,len(self.coordinates)):
                if self.coordinates[0]/vec.coordinates[0]!=self.coordinates[i]/vec.coordinates:
                    flag=False
            return flag
    def Perpendicular(self,vec):
        if self.n!=vec.n:
            print("Vectors of different size...\n")
            return False
        else:
            scalar=0
            for i in range(len(self.coordinates)):
                scalar+=self.coordinates[i]*vec.coordinates[i]
            if scalar==0:
                return True
            else:
                return False
    def Length(self):
        len_square=0
        for i in len(self.coordinates):
            len_square+=pow(self.coordinates[i],2)
        return pow(len_square,0.5)

class R2_Vector(TVector):
    def __init__(self,a=0,b=0):
        self.x=a
        self.y=b
        arr=[a,b]
        super().__init__(2,arr)
    def input(self,s):
        print("Input coordinates for vector "+s+" :")
        self.x=float(input("х="))
        self.y=float(input("y="))
        self.coordinates=[self.x,self.y]
    def Length(self):
        return pow(pow(self.x,2)+pow(self.y,2),0.5)
    def Parallel(self,vec):
        if vec.x==0:
            X_Relation=float('inf')
        else:
            X_Relation=self.x/vec.x
        if vec.y==0:
            Y_Relation=float('inf')
        else:
            Y_Relation=self.y/vec.y
        if X_Relation==Y_Relation:
           return True
        else:
            return False
    def Perpendicular(self, vec):
        if self.x*vec.x+self.y*vec.y==0:
            return True
        else:
            return False

class R3_Vector(TVector):
    def __init__(self,a=0,b=0,c=0):
        self.x=a
        self.y=b
        self.z=c
        arr=[a,b,c]
        super().__init__(3,arr)
    def input(self,s):
        print("Input coordinates for vector "+str(s)+" :")
        self.x=float(input("х="))
        self.y=float(input("y="))
        self.z=float(input("z="))
        self.coordinates=[self.x,self.y,self.z]
    def Length(self):
        return pow(pow(self.x,2)+pow(self.y,2)+pow(self.z,2),0.5)
    def Parallel(self,vec):
        if vec.x==0:
            X_Relation=float('inf')
        else:
            X_Relation=self.x/vec.x
        if vec.y==0:
            Y_Relation=float('inf')
        else:
            Y_Relation=self.y/vec.y
        if vec.z==0:
            Z_Relation=float('inf')
        else:
            Z_Relation=self.z/vec.z
        if X_Relation==Y_Relation==Z_Relation:
           return True
        else:
            return False
    def Perpendicular(self, vec):
        if self.x*vec.x+self.y*vec.y+self.z*vec.z==0:
            return True
        else:
            return False
    def __iadd__(self, vec):
        self.x+=vec.x
        self.y+=vec.y
        self.z+=vec.z
        self.coordinates[0]+=vec.x
        self.coordinates[1]+=vec.y
        self.coordinates[2]+=vec.z
        return self