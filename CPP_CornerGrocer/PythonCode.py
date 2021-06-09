import re
import string


def ReadFile():
    filepath = 'CS210_Project_Three_Input_File.txt'
    with open(filepath, encoding='utf-16-sig') as fp:
        #, 
        line = fp.readline()
        cnt = 1
        while line:
            print(line.strip())
            #print("Item {}: {}".format(cnt, line.strip()))
            line = fp.readline()
            
            cnt += 1
    return 0;

def SingleItem(s):
    text = open("CS210_Project_Three_Input_File.txt", "r", encoding='utf-8-sig')
    d = dict()
    s = s.lower()
    print("You are searching for " + str(s))
    for line in text:
        line = line.strip()
        line = line.lower()
        words = line.split(" ")
        for word in words:
            if word in d:
                d[word] = d[word] + 1
            else:
                d[word] = 1

    
    for key in sorted(d.keys()):
        #print(key, ":", d[key])
        if str(key) == s:
           #print(str(key) + " " + str(d[key]))
           return int(d[key]);

    #print("No such item exists, try again.")
    return 0;
        

      
def WriteItems():
    # Open the file in read mode
    text = open("CS210_Project_Three_Input_File.txt", "r", encoding='utf-8-sig')
    f = open("frequency.dat", "w")
    d = dict()
  
    for line in text:
        line = line.strip()
        line = line.lower()
  
        words = line.split(" ")
          
        for word in words:
            if word in d:
                d[word] = d[word] + 1
            else:
                d[word] = 1
    for key in sorted(d.keys()):
        s = str(key) + " " + str(d[key]) + "\n"
        f.write(s)
    f.write("end")

def ListItems():
    # Open the file in read mode
    text = open("CS210_Project_Three_Input_File.txt", "r", encoding='utf-8-sig')
    # Code found online!
    # Create an empty dictionary
    d = dict()
  
    # Loop through each line of the file
    for line in text:
        # Remove the leading spaces and newline character
        line = line.strip()
  
        # Convert the characters in line to 
        # lowercase to avoid case mismatch
        line = line.lower()
  
        # Split the line into words
        words = line.split(" ")
          
        # Iterate over each word in line
        for word in words:
            # Check if the word is already in dictionary
            if word in d:
                # Increment count of word by 1
                d[word] = d[word] + 1
            else:
                # Add the word to dictionary with count 1
                d[word] = 1
    # Code written by me!   
    # Print the contents of dictionary
    print(" ALL ITEMS PURCHASED TODAY\n")
    for key in sorted(d.keys()):
        print("|", key, ":", d[key])
        

    #sorts by least to most purchased
    #print('\n')
    #for key, value in sorted(d.items(), key=lambda item: item[1]):
    #    print(key, ":", d[key])
   

