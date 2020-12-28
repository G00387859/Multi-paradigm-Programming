import csv
from csv import reader
import traceback
import math
import shutil

def readCsv(name):
    # read csv file as a list of lists
    with open(name, 'r') as read_obj:
        # pass the file object to reader() to get the reader object
        csv_reader = reader(read_obj)
        # Pass reader object to list() to get a list of lists
        list_of_rows = list(csv_reader)
        return list_of_rows#
# used in the bulk order to write out to the csv 
def writeCSV(uPdrows):
    recList = uPdrows
    # field names  
    rows = recList
    # name of csv file  
    filename = 'stock.csv'   
    # writing to csv file  
    with open(filename, 'w',newline='') as csvfile:  
        # creating a csv writer object   ##newline=''
        csvwriter = csv.writer(csvfile)    
        csv.DictReader
        # writing the data rows  
        csvwriter.writerows(rows)
        #fileOverWrite(rows)
        
# attememt to update the stock csv but only the rows where the customer order. 
#not completed
#this funcion will read the CSV abd convert to a dictionary
def fileOverWrite(uPdrows):
    u1 = str(uPdrows[0][0])
    u2 = str(uPdrows[0][1])
    u3 = str(uPdrows[0][2])
    u4 = u1,u2,u3
    u5 = list(u4)
    #print("34", u5)
    recList = []
    uPdrowsList =[]
    retList = []
    for x in range(len(uPdrows)):
        listRet = uPdrows.pop(x)
        #retList.append(listRet)
    rowcount=0
    with open('stock.csv') as csvfile:
        reader = csv.reader(csvfile)
        for row in reader:
            rowcount +=1
            recList.append(row)
    i = len(retList)
    j = len(retList)
    #print("46",uPdrows[0][0])
    #print("47",recList[0][0])
    
    retList.append(recList)
    #retList.insert(int(recList[0][2]),u5[2])
    #retList = [j for i in zip(recList, u5) for j in i]
   # while i != 0:
    #    if(retList[i][0] == retList[j][0]):
    #        retList.pop(i)
    #    i-=1
    #    j-=1
    #while a < i or p < j:
    #    if str(recList[0][0]).strip == str(uPdrows[0][0]).strip:
    #        retList.append(uPdrows[0])
    #        a+=1
    #        p+=1
    #    else:
    #        #retList.append(recList[0])
    #        print("43", "true")
    #        a+=1
    #        p+=1
    print("")

            
# read the customers csv
def readCustomerCSV():
    try:
         filenameSelection = int(input("Please enter 1 for bulk customer, 2 bulk customer where the shop does not have enough stock ")) 
    except:
        print("invalid input ", filenameSelection)
    if filenameSelection == 1:
        # read csv file as a list of lists
        with open('customer.csv', 'r') as read_obj:
        # pass the file object to reader() to get the reader object
            csv_reader = reader(read_obj)
        # Pass reader object to list() to get a list of lists
            list_of_rows = list(csv_reader)
    if filenameSelection  == 2:
        print("90",filenameSelection)
    if filenameSelection == 3:
        print("92", filenameSelection)
    return list_of_rows

#this funcion will read the CSV abd convert to a dictionary
def convertToDict(x):
    listOfRows = x
    dic = {}
    i = 0
    while i < len(listOfRows):
        dic[listOfRows[i][0]]=listOfRows[i][1],listOfRows[i][2]
        i=i+1
    return dic
#this funcion will read the CSV add convert to a dictionary
def convertToDict1(x):
    listOfRows = x
    dic = {}
    i = 0
    while i < len(listOfRows):
        dic[listOfRows[i][0]]=listOfRows[i][1]
        i=i+1
    return dic

def displayShop(dict):
    i =0
    for x in dict:
        print(x,"Costs ",dict[str(x)][0])
        +i
def displayShopAndQuanity(dict):
    #quan =0
    i =0
    for x in dict:
        print(x,", Cost:" ,dict[str(x)][0],", Quanity:",dict[str(x)][1])
        
        +i
def buildDict(dict,quan):
    dictKeys = dict.keys()
    dictList = list(dictKeys)
    dictListLen = len(dictList)
    for i  in  range(len(dictList)):
        newDict[i] = dict[dictKeys[i]] + dict[dictKeys[i]][0] + int(dict[dictKeys[i]][0]) - quan
    print(newDict)
# call this function for walking customers
def getCustomerOrder(dict,shopCash):
    try:
        selection = 6
        cost =[]
        items = {}
        testCode = dict.keys()
        testCode = list(testCode)
        # ask the customer what they want to purhase
        # if they press 1 = coke, 2 = bin bags, 3 = ??, 4 ??.
        print("welcome to the shop")
        print("Current shop cash ", shopCash)
        #newDict = buildDict(dict,)
        displayShop(dict)
        budget = float(input("Enter you budget: "))
        print("Please make a selection. ")
       
        i =1
        while selection != 0:
            for x in testCode:
                print(i,"for" ,x," or 0 to exit")
                i = i +1
            
            selection = int(input("Enter you choice: "))
            i =1
            #count the elements in testCode
            counter = len(testCode)
            if selection >  counter:
                print("Error ", selection , "is out of range")
            elif selection == 0:
                selection = 0
            else:
                quan = 0
                productName = testCode[selection -1]
                productCost = float(dict[testCode[selection-1]][0])
                productQuantity = float(dict[testCode[selection-1]][1]) - quan
                #print("The cost of ",testCode[selection-1], "is  €",dict[testCode[selection-1]][0],"and the Quanity is ",dict[testCode[selection-1]][1])
                print("The cost of ",productName, 'is €',"{:.2f}".format(productCost),"and the Quanity is",math.trunc(productQuantity))
                items[testCode[selection -1]] = str(dict[testCode[selection-1]][0])
                quan += int(input("Please enter the quanitiy: "))
                itemCost = str(dict[testCode[selection-1]][0])
                # check the quanitiy
                stockQuanity = str(dict[testCode[selection-1]][1])
                stockQuan = float(stockQuanity) - quan
                # python considers dict[testCode[selection-1]][1] to be a tuple and is mutable. 
                # so i covert to a list update the element and covert back to a tuple
                stock = list(dict[testCode[selection-1]])
                stock[1] = stockQuan
                dict[testCode[selection-1]] = tuple(stock)
                #check the shop quanitiy
                stockQuanity = float(stockQuanity)
                if(quan > stockQuanity):
                    print("******** NOT ENOUGH STOCK *********")
                    print("******** CURRENT STOCK AND QUANITIYS *********")
                    displayShop(dict)
                    items[testCode[selection -1]] =0
                # python considers dict[testCode[selection-1]][1] to be a tuple and is mutable. 
                # so i covert to a list update the element and covert back to a tuple. 
                # the customer has choosen an amount that is greater than the shops stock so I have to re-assign the amount that is the last
                # amount before the customer asks for the quanity that is greater than the shop stock 
                    stockError = list(dict[testCode[selection-1]])
                    stockError[1] = stockQuanity
                    dict[testCode[selection-1]] = tuple(stockError)
                    print()
                else:
                    #writeCSV
                    #print("123",items)
                    #items[testCode[selection -1]] = str(dict[testCode[selection-1]][0]),float(dict[testCode[selection-1]][1]) - quan
                    items[testCode[selection -1]] = str(dict[testCode[selection-1]][0]),quan
                    print("")
                    sum = float(itemCost) * quan
                    sum = round(sum,3)
                    cost.append(sum)
        cash = receipt(items,sumUp(cost),shopCash,budget)
        ##cal function to updatae the stock. 
    except:
        print("An exception occurred")
        traceback.print_exc()
    return cash

#create the receipt for the bulkOrder
def searchStock(dic,custItem):
    # dic = stock
    stocKeys = dic.keys()
    stockOrder = list(stocKeys)
    keysList = []
    itemsList = dic.items()
    for item in itemsList:
        if item[0]==custItem:
            #print("SearchStock:", item[0],",",item[1])
            keysList.append(item[0])
            # need to add cost here from the stock 
            keysList.append(item[1])
            keysList.append(dic[custItem])
            #print("144",dic[custItem])
    #print("166 ",keysList)
    return keysList 
def custBulkOrder(dic,dic1):
    retStock = []
    customerOrderKeys = dic.keys()
    i = 0
    customerOrder = list(customerOrderKeys)
    for i in range(len(customerOrder)):
        retStock.append(searchStock(dic1,customerOrder[i]))
    writeCSV(retStock)
    return retStock


def searchKeysByVal(dict, byVal):
    keysList = []
    itemsList = dict.items()
    for item in itemsList:
        if item[1] == byVal:
            keysList.append(item[0])
    return keysList

def stockUpdate(d):
    return dict
# sum up the cast and format it.   
def sumUp(a):
    return round(sum(a),3)
#create a recipt function for walkin customers 
def receipt(dict,cost,cash,budget):
    receiptList = []
    shopcash = cash
    print("********************")
    print("Receipt")
   # for key,value in dict.items():
    #for x in range(len(dict)):
       #print("Product:",dict[x][1],': €',dict[x][1])
    i = 0
    if(budget > cost):
        for x in dict:
            #print(x,", Cost:" ,dict[str(x)][0],", Quanity:",dict[str(x)][1])
            print(x,", Cost:" ,'€',"{:.2f}".format(dict[str(x)][0]),", Quanity:",math.trunc(dict[str(x)][1]))
            #print(x,dict[str(x)][0],dict[str(x)][1])
            rec = x,dict[str(x)][0],dict[str(x)][1]
            receiptList.append(rec)
            shopcash = cash + cost
            +i
        print("Total cost €",cost)
        print("*********************")
    else:
        print("*********************")
        print("The cost:",cost," is greater than your budget")
    #writeCSV(receiptList)
    return shopcash

        ## how many 
        ## cost of the item 
        # contiune or checkout
        #if checkout the print out the order and update the stock
        ## no return
# calculate the remaining stock 
def calRemainingStock(n,stockDic,custOrderedQuan):
    #get the current order
    currentStock = stockDic[n][1]
    print("280", currentStock)
    #get the stock 
    updatedStock = float(currentStock) - float(custOrderedQuan)
    if updatedStock <= 0:
        print("Sorry not enough stock!")
    else:
        updatedStock = float(currentStock) - float(custOrderedQuan)
    # return the remaining stock
    return updatedStock

# this function used to print the customers receipt for bulk orders
# returns the calculated cash of the products
def receiptl(l,dic,stockDic,cash):
    print("********************")
    print("Receipt")
    # create a  list of keys
    recDicKeys = dic.keys()
    rDL = list(recDicKeys)
    tcost = 0
    recpList1 = []
    #loop over to print the passed dictionary 
    for x in range(len(l)):
        tcost += float(l[x][1][0]) * float(dic[rDL[x]])
        print("Product:",l[x][0],", Cost: ",l[x][1][0], "Quanitiy:",dic[rDL[x]])
        prod = l[x][0]
        #call to get the stock - customers order
        remainingStockQ = calRemainingStock(prod,stockDic,dic[rDL[x]])
        retPrd=(l[x][0],l[x][1][0],remainingStockQ)# remainingStockQ
        #get the remaining stock and add to a list
        recpList1.append(retPrd)
    # get the cost 
    cash += tcost
    print("Total cost €",tcost)
    print("*********************")
    # write the remaining stock to the stock.csv
    writeCSV(recpList1)
    return cash

def copyFile():
    # copy a file using shutil.copyfile() method  
    # # path where original file is located
    sourcePath = "stock_bkp.csv"
    #print("317",sourcePath)
    
    # path were a copy of file is needed
    destinationPath = "stock.csv"
    # call copyfile() method
    shutil.copyfile(sourcePath, destinationPath)
    
def main():
    dic = {}
    shopcash =100
    # set up the shop read the csv create a dict 
    #sudo: 2 parts, 
    # 1 create a program that allows the user to  ask for items in a shop = walkin-- done 
    # 2 create a program that takes in  a CSV and process it  -- pending 
    #  2 create a while loop in main as for input if input == 1 then customer is walkin id 2 is CVS customer
    # read the stock csv and customer csv, then loop over 
    run = True
    programCounter = 0
    while(run):
        if programCounter == 0:
            dic = convertToDict(readCsv('stock.csv'))
            programCounter = 1
        else:
            dic = convertToDict(readCsv('stock.csv'))
            #print("2")
        customerType = int(input("Please enter 1 for walkin customer 2 for bulk order customer or 3 to exit"))
        try:
            if customerType == 1:
                shopcash =  getCustomerOrder(dic,shopcash)
                print("The shop cash is", round(shopcash, 2))
        except:
            print("customerType invalid input")
           
            #dic = stockUpdate(dic)
            #programCounter +=1
        if customerType == 2:
            displayShopAndQuanity(dic)
            retStock = []
            custDic = convertToDict1(readCustomerCSV())
            retStock = custBulkOrder(custDic,dic)
            shopcash= receiptl(retStock,custDic,dic,shopcash)
            print("The shop cash is ", shopcash)
            #print(retStock)
            #programCounter +=1
        elif customerType == 3:
            #programCounter +=1
            copyFile()
            break

    
if __name__ == '__main__':
    main()