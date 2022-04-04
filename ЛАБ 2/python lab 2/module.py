import string
def File_Create(name):
    mode=int(input("Do you want to append file (1) or create a clear file (0)? ")) # запитати користувача, чи в≥дкривати файл у режим≥ перезапису чи дозапису
    if mode==1: m='ab'
    else: m='wb'
    with open(name,m) as outfile1:
        number=int(input("Input the number of cars you want to add: ")) # запитати користувача ск≥льки автомоб≥л≥в  в≥н хоче додати у файл
        for i in range(number):
            Model=str(input("Input car model: ")) # дл€ кожного автомоб≥л€ просимо ввести модель, дату випуску ≥ дату надходженн€ у продаж (дати у формат≥ м≥с€ць.р≥к, €к зазвичай зазначаЇтьс€ дл€ автомоб≥л≥в)
            ReleaseDate=str(input("Input release date (MM.YYYY): "))
            DateofSale=str(input("Input date of sale (MM.YYYY): ")) 
            Automobile=Model+', '+ReleaseDate+', '+DateofSale+'\n' # записуЇмо ц≥ три критер≥њ в один р€док через кому ≥ проб≥л
            if len(Automobile)>0:
                outfile1.write(Automobile.encode()) # записуЇмо в≥дпов≥дний р€док у список вс≥х автомоб≥л≥в салону (одночасно кодуючи його в bytes)
   
def Output(name):
    with open(name, 'rb') as file:
        for Automobile in file:
            print(Automobile.decode()) # зчитуЇмо по р€дку ≥з файла, розшифровуЇмо ≥з bytes ≥ виводимо на екран

def NewAutosListCreate(name1, name2):
    with open(name1,'rb') as file1:
        with open(name2,'wb') as file2:
            for Auto in file1:
                Auto=Auto.decode() # по р€дку зчитуЇмо ≥ розкодовуЇмо
                Automobile=Auto.split(', ') # розбиваЇмо по ком≥ ≥ проб≥лу р€док на list, де першим(нульовий ≥ндекс) елементом буде модель машини, а наступними в≥дпов≥дно будуть дата випуску ≥ дата надходженн€ у продаж
                releaseYear=int(Automobile[1][3:7]) # р≥к випуску чи надходженн€ у продаж при такому формат≥ запису буде зазначатись у четвертому-сьомому по пор€дку елементах р€дка
                releaseMonth=int(Automobile[1][:2]) # м≥с€ць випуску чи надходженн€ у продаж при такому формат≥ запису буде зазначатись у першому-другому елементах р€дка
                saleYear=int(Automobile[2][3:7])
                saleMonth=int(Automobile[2][:2])
                if (12*(saleYear-releaseYear)+saleMonth-releaseMonth)<=2: # щоб рахувати р≥зницю у м≥с€ц€х м≥ж датами випуску ≥ надходженн€ у продаж, треба р≥к другого м≥нус р≥к першого помножити на 12 (к≥льк≥сть м≥с€ц≥в у роц≥) додати м≥с€ць другого ≥ в≥дн€ти м≥с€ць першого
                    file2.write(Auto.encode());
                        
def AutosReleasedAfter(name):
    X_year=int(input("Input the year to output autos released not earlier than: ")) # запитати користувача, в≥д €кого року автомоб≥л≥ показати
    with open(name,'rb') as file:
        print("Autos released in or after " + str(X_year) + ':')
        for auto in file:
            auto=auto.decode()
            Automobile=auto.split(', ')
            releaseYear=int(Automobile[1][3:7]) # таким же чином, €к ≥ в попередн≥й функц≥њ, д≥стаЇмо ≥з р€дка дату випуску автомоб≥л€
            if (releaseYear >= X_year):
                print(auto) # €кщо р≥к автомоб≥ль ≥з в≥дпов≥дного р€дка був випущений у вказаному роц≥ або ще нов≥ший, вивести цей р€док