def File_Create(name):
    mode=int(input("Do you want to append file (1) or create a clear file (0)? "))
    if mode==1: m='a'
    else: m='w'
    with open(name,m) as outfile1:
        print("Input text to the file. Press Ctrl+E to stop inputing\n")
        flag=True
        while flag:
            string=input()
            for i in range(len(string)):
                if string[i]==chr(5):
                    flag=False
                    string=string[:i:]
            if len(string)>0:
                outfile1.write(string+'\n')

def ReWrite(name1,name2):
    with open(name1) as infile1:
        with open(name2,'w') as file2:
            for line in infile1:
                string=line
                if len(string)>0:
                    if string[-2]==' ' or string[-2]=='.' or string[-2]==',':
                        file2.write(string)
                    else: file2.write('-\n')
        
def Output(name):
    with open(name) as filee:
        for line in filee:
            print(line, end = "")