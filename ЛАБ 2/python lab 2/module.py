import string
def File_Create(name):
    mode=int(input("Do you want to append file (1) or create a clear file (0)? ")) # �������� �����������, �� ��������� ���� � ����� ���������� �� ��������
    if mode==1: m='ab'
    else: m='wb'
    with open(name,m) as outfile1:
        number=int(input("Input the number of cars you want to add: ")) # �������� ����������� ������ ���������  �� ���� ������ � ����
        for i in range(number):
            Model=str(input("Input car model: ")) # ��� ������� ��������� ������� ������ ������, ���� ������� � ���� ����������� � ������ (���� � ������ �����.��, �� �������� ����������� ��� ���������)
            ReleaseDate=str(input("Input release date (MM.YYYY): "))
            DateofSale=str(input("Input date of sale (MM.YYYY): ")) 
            Automobile=Model+', '+ReleaseDate+', '+DateofSale+'\n' # �������� �� ��� ������ � ���� ����� ����� ���� � �����
            if len(Automobile)>0:
                outfile1.write(Automobile.encode()) # �������� ��������� ����� � ������ ��� ��������� ������ (��������� ������� ���� � bytes)
   
def Output(name):
    with open(name, 'rb') as file:
        for Automobile in file:
            print(Automobile.decode()) # ������� �� ����� �� �����, ������������ �� bytes � �������� �� �����

def NewAutosListCreate(name1, name2):
    with open(name1,'rb') as file1:
        with open(name2,'wb') as file2:
            for Auto in file1:
                Auto=Auto.decode() # �� ����� ������� � �����������
                Automobile=Auto.split(', ') # ��������� �� ��� � ������ ����� �� list, �� ������(�������� ������) ��������� ���� ������ ������, � ���������� �������� ������ ���� ������� � ���� ����������� � ������
                releaseYear=int(Automobile[1][3:7]) # �� ������� �� ����������� � ������ ��� ������ ������ ������ ���� ����������� � ����������-������� �� ������� ��������� �����
                releaseMonth=int(Automobile[1][:2]) # ����� ������� �� ����������� � ������ ��� ������ ������ ������ ���� ����������� � �������-������� ��������� �����
                saleYear=int(Automobile[2][3:7])
                saleMonth=int(Automobile[2][:2])
                if (12*(saleYear-releaseYear)+saleMonth-releaseMonth)<=2: # ��� �������� ������ � ������ �� ������ ������� � ����������� � ������, ����� �� ������� ���� �� ������� ��������� �� 12 (������� ������ � ����) ������ ����� ������� � ������ ����� �������
                    file2.write(Auto.encode());
                        
def AutosReleasedAfter(name):
    X_year=int(input("Input the year to output autos released not earlier than: ")) # �������� �����������, �� ����� ���� �������� ��������
    with open(name,'rb') as file:
        print("Autos released in or after " + str(X_year) + ':')
        for auto in file:
            auto=auto.decode()
            Automobile=auto.split(', ')
            releaseYear=int(Automobile[1][3:7]) # ����� �� �����, �� � � ��������� �������, ������ �� ����� ���� ������� ���������
            if (releaseYear >= X_year):
                print(auto) # ���� �� ��������� �� ���������� ����� ��� ��������� � ��������� ���� ��� �� ������, ������� ��� �����