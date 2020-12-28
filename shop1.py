import csv
from csv import reader
import traceback


def readCsv(name):
    # read csv file as a list of lists 'stock.csv'
    with open('name', 'r') as read_obj:
        # pass the file object to reader() to get the reader object
        csv_reader = reader(read_obj)
        # Pass reader object to list() to get a list of lists
        list_of_rows = list(csv_reader)
        return list_of_rows
def writeCSV():
    # field names  
    fields = ['Name', 'Branch', 'Year', 'CGPA']  
    
    # data rows of csv file  
    rows = [ ['Nikhil', 'COE', '2', '9.0'],  
            ['Sanchit', 'COE', '2', '9.1'],  
            ['Aditya', 'IT', '2', '9.3'],  
            ['Sagar', 'SE', '1', '9.5'],  
            ['Prateek', 'MCE', '3', '7.8'],  
            ['Sahil', 'EP', '2', '9.1']]  
    
    # name of csv file  
    filename = "university_records.csv"
    
    # writing to csv file  
    with open(filename, 'w') as csvfile:  
        # creating a csv writer object  
        csvwriter = csv.writer(csvfile)  
        
        # writing the fields  
        csvwriter.writerow(fields)  
        
        # writing the data rows  
        csvwriter.writerows(rows)
#this funcion will read the CSV abd convert to a dictionary
def convertToDict(x):
    listOfRows = x
    dic = {}
    i = 0
    while i < len(listOfRows):
        dic[listOfRows[i][0]]=listOfRows[i][1],listOfRows[i][2]
        i=i+1
    return dic

def getCustomerOrder(dict,dict2,select):
    try:
        cost =[]
        items = {}
        #stock
        testCode = dict.keys()
        #convert to list
        testCode = list(testCode)
        #bulk orders 
        customerBulkDicKeys = dict2.keys()
        customerBulk = list(customerBulkDicKeys)

        # ask the customer what they want to purhase
        # if they press 1 = coke, 2 = bin bags, 3 = ??, 4 ??.
        #print("welcome to the shop")
            
        selection = int(input("Enter you choice: "))
        i =1
                #count the elements in testCode
        counter = len(testCode)
        if selection >  counter:
            print("Error ", selection , "is out of range")
        elif selection == 0:
            selection = 0
        else:
            print("The cost of",testCode[selection-1], "is ",dict[testCode[selection-1]][0],"and the Quanity is ",dict[testCode[selection-1]][1])
            items[testCode[selection -1]] = str(dict[testCode[selection-1]][0])
            quan = int(input("Please enter the quanitiy: "))
            itemCost = str(dict[testCode[selection-1]][0])
            # check the quanitiy
            stockQuanity = str(dict[testCode[selection-1]][1])
            stockQuan = int(stockQuanity) - quan
            # python considers dict[testCode[selection-1]][1] to be a tuple and is mutable. 
            # so i covert to a list update the element and covert back to a tuple
            stock = list(dict[testCode[selection-1]])
            stock[1] = stockQuan
            dict[testCode[selection-1]] = tuple(stock)
            #check the shop quanitiy
            checkStock(dict,selection,quan,items)
                    
        receipt(items,sumUp(cost))
    except:
        print("An exception occurred")
        traceback.print_exc()

        ##cal function to updatae the stock.
def sumUp(a):
    return round(sum(a),3)
    #create a recipt function
def receipt(dict,cost):
    print("********************")
    print("Receipt")
    for key,value in dict.items():
        print("Product:",key,': €',value)
    print("Total cost €",cost)
    print("*********************")

# create a function that will search the stock for a value

def checkStock(dict,num,quan,items):
    name = num
    name = name -1
    testCode = dict.keys()
    testCode = list(testCode)
    stockQuanity = str(dict[testCode[name]][1])
    stockQuan = int(stockQuanity) - quan
    # python considers dict[testCode[selection-1]][1] to be a tuple and is mutable. 
    # so i covert to a list update the element and covert back to a tuple
    stock = list(dict[testCode[name]])
    stock[1] = stockQuan
    dict[testCode[name]] = tuple(stock)
    cost = []
    if(quan > int(stockQuanity)):
        print("******** NOT ENOUGH STOCK *********")
        print("******** CURRENT STOCK AND QUANITIYS *********")
        displayShopAndQuanity(dict)
        items[testCode[name]] =0
        # python considers dict[testCode[selection-1]][1] to be a tuple and is mutable. 
        # so i covert to a list update the element and covert back to a tuple. 
        # the customer has choosen an amount that is greater than the shops stock so I have to re-assign the amount that is the last
        # amount before the customer asks for the quanity that is greater than the shop stock 
        stockError = list(dict[testCode[name]])
        stockError[1] = stockQuanity
        dict[testCode[name]] = tuple(stockError)
        print()
    else:
        sum = float(itemCost) * quan
        sum = round(sum,3)
        cost.append(sum)
    receipt(items,sumUp(cost))    
    return cost
def displayShopAndQuanity(dict):
     print("debug1")
     i =0
     for x in dict:
        print(x,", Cost:" ,dict[str(x)][0],", Quanity:",dict[str(x)][1])
        +i
def main():
    # set up the shop read the csv create a dict 
    #sudo: 2 parts, 
    # 1 create a program that allows the user to  ask for items in a shop = walkin-- done 
    # 2 create a program that takes in  a CSV and process it  -- pending 
    #  2 create a while loop in main as for input if input == 1 then customer is walkin id 2 is CVS customer
    # read the stock csv and customer csv, then loop over 
    
    run = True
    # read stock csv one
    
    while(run):
        dic = convertToDict(readCsv('stock.csv'))
        # write out the stock to update stock
        print("welcome to the shop")
        displayShopAndQuanity(dict)
        print("What you want. ")
        customerType = int(input("Please enter 1 for walkin customer 2 for bulk order customer or 3 to exit"))
        if customerType == 1:
            dic = convertToDict(readCsv('stock.csv'))
            getCustomerOrder(dic)
        if customerType == 2:
            print("2")
            customerOrders = []
            dic = convertToDict(readCsv())
            custDic = convertToDict1(readCustomerCSV())
            print(custDic)
            #customerOrders.insert(0,custBulkOrder(dic,custDic))
            receiptl(custBulkOrder(custDic,dic),dic)
            #print(customerOrders)
            #print(searchStock(dic,"Milk"))
        elif customerType == 3:
            break

    
if __name__ == '__main__':
    main()