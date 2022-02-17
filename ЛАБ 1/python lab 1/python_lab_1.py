import module
name1="source file.txt"
name2="created file.txt"
module.File_Create(name1)
module.ReWrite(name1,name2)
print("File 1 content:")
module.Output(name1)
print("File 2 content:")
module.Output(name2)
