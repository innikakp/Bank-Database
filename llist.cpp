/*****************************************************************
//
// NAME:        Innika Pang
//
// PROJECT:	2
//
// CLASS:       ICS 212
//
// INSTRUCTOR:  Ravi Narayan
//
// DATE:        July 20, 2017
//
// FILE:                llist.cpp
//
// DESCRIPTION:  This file contains the function definitions for 
//		    all the class member functions, including
//		    the constructor and destructor for Project 2 
//
****************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "llist.h"
//#define DEBUGMODE

/*****************************************************************
//
// Function name:       llist
//
// DESCRIPTION:   A default constructor that initializes the class variables 
//		    start to NULL and filename to "database.txt" 
//
// Parameters:          none 
//
// Return values:       none 
//
****************************************************************/

llist::llist()
{
    int readval;
    this->start = NULL;
    strcpy(this->filename, "inputfile.txt");

    #ifdef DEBUGMODE
        using std::cout;
        using std::endl;
        cout << "\nllist::llist() default constructor called\n" << endl;
    #endif 

    /*Call read function to read from default file*/

    readval = llist::readfile();
}


/*****************************************************************
//
// Function name:       llist(char file [ ])
//
// DESCRIPTION:   A constructor that initializes the class variables 
//		    start to NULL and filename to the file the 
//		    user wants to intput 
//
// Parameters:          file (char [ ]) : file user wants to input 
//
// Return values:       none 
//
****************************************************************/

llist::llist(char file[ ])
{
    int readval;
    this->start = NULL;
    strcpy(this->filename, file);

    #ifdef DEBUGMODE
        using std::cout;
        using std::endl;
        cout << "\nllist::llist(char file[ ]) constructor with parameter called" << endl;
        cout << "File parameter passed: " << file << "\n" << endl;
    #endif 

    /*Call read function to read from file*/

    readval = llist::readfile();

    std:: cout << "Allocating memory. llist object with file parameter created" << std::endl; 
}


/*****************************************************************
//
// Function name:       ~llist
//
// DESCRIPTION:   A function that deallocates the entire linked
//		    list by calling the cleanup member function
//
// Parameters:          none 
//
// Return values:       none 
//
****************************************************************/

llist::~llist()
{
    int writeval;

    #ifdef DEBUGMODE
        using std::cout;
        using std::endl;
        cout << "llist::~llist() destructor called\n" << endl;
    #endif 

    /*Call write function to write to default file*/

    writeval = llist::writefile();

    /*Calls cleanup member function*/

    llist::cleanup();
}


/*****************************************************************
//
// Function name:       readfile
//
// DESCRIPTION:   A function that reads data from a text file 
//
// Parameters:          none  
//
// Return values:       0 : successfully reads the data from a 
//                      file
//                      -1 : file not found     
//
****************************************************************/

int llist::readfile()
{
    int returnval, uaccountno, recordval, count; 
    //char buffer[100] = "";
    char accountno[50] = "";
    char uname[25] = "";
    char uaddress[80] = ""; 
    //char copyuaddress[80] = "";
    using std::ifstream;
    using std::ios;
    using std::cout;
    using std::endl;
    ifstream inputfp;

    returnval = 0;
    recordval = 0;
    count = 1;

    /*Opens the file stream to read a file*/

    inputfp.open(filename, ios::in);

    #ifdef DEBUGMODE
        using std::cout;
        using std::endl;
        cout << "readfile function called\n" << endl;
    #endif 

    /*Checks if current file is associated with file stream*/
 
    if (inputfp.is_open())
    {
        while (!inputfp.getline(accountno, 50).eof())
        {
            /*Checks for newline on first line of file and '?' indicating end of file input*/

            if (strcmp(accountno, "") != 0 && strcmp(accountno, "?") != 0)
            {
                /*Retrieves first string from file, copies it to accountno (temporary array), and converts to an integer to store in uaccountno*/

                uaccountno = atoi(accountno); 
            
                /*Retrieves the second string from file and copies it to uname*/

                inputfp.getline(uname, 25);

                /*Retrieves the third string from file. Loops through file input to copy third string*/

                do
                {
                    /*Checks if thre is a newline in file input and stops getting file input*/

                    if (strcmp(uaddress, "") == 0)
                    {
                        count = 0;
                    }

                } while (!inputfp.getline(uaddress, 80, '?') && count != 0);

                //cout << "ADDRESS: " << uaddress << endl;
 
                count = 1; 
           
                /*Adds information from file stream to list*/
 
                recordval = llist::addRecord(uaccountno, uname, uaddress);
            }
        }        

        /*If file stream is associated to the file, then file exists. Return success*/ 

        returnval = 0;
        inputfp.close();
    }
    else
    {
        /*If file stream is not associated to the file, then the file does not exist. Return failure*/

        returnval = -1;
    }

    return returnval;
}

/*****************************************************************
//
// Function name:       writefile
//
// DESCRIPTION:   A function that writes to a text file  
//
// Parameters:          none 
//
// Return values:       0 : successfully writes the data to a 
//                      file
//                      -1 : cannot write to file 
//
****************************************************************/

int llist::writefile()
{
    int returnval;
    //char buffer[100] = "";
    using std::ofstream;
    using std::ios;
    using std::cout;
    using std::endl;
    ofstream outputfp;

    returnval = 0;
    returnval = 0;

    /*Opens the file stream to write a file*/

    outputfp.open(filename, ios::out); 
    
    #ifdef DEBUGMODE
        using std::cout;
        using std::endl;
        cout << "llist::writefile function called\n" << endl;
    #endif 

    /*Checks if current file is associated with file stream*/

    if (outputfp.is_open()) 
    {
        /*Checks if list is not empty*/

        if (start != NULL)
        {
            struct record *temp;
   
            temp = start;

            /*Checks if there is one record in the database and writes that record to a file*/

            if (start->next == NULL)
            {
                outputfp << temp->accountno << endl;
                outputfp << temp->name << endl;
                outputfp << temp->address << "\?\n" << endl;
                //outputfp << "\n"; 
            }
            else
            {
                /*Writes the first record to the list (temp is currently pointing to the first record to a file*/

                outputfp << temp->accountno << endl;
                outputfp << temp->name << endl;
                outputfp << temp->address << "\?\n" << endl;

                /*Writes the rest of the list to file until the end is reached*/
            
                while (temp->next != NULL)
                {
                    temp = temp->next;
 
                    outputfp << temp->accountno << endl;
                    outputfp << temp->name << endl;
                    outputfp << temp->address << "\?\n" << endl;
                }
            }
        } 

        /*If file stream is associated to the file, then file exists. Return success*/ 

        returnval = 0;
        outputfp.close();
    }
    else
    {
        /*If file stream is not associated to the file, then the file does not exist. Return failure*/

        returnval = -1;
    }
    
    return returnval;
}


/*****************************************************************
//
// Function name:       reverse
//
// DESCRIPTION:   A function that uses recursion to reverse the
//		    list without printing it 
//
// Parameters:          start (record *) : contains a pointer to 
//			the head/starting node of the list 
//
// Return values:       start (record *) : the pointer to the head/
//			starting node of the reversed list 
//
****************************************************************/

record * llist::reverse(record * start )
{
    /*Define a pointer to record called temp*/

    record * temp;

    #ifdef DEBUGMODE
        using std::cout;
        using std::endl;
        cout << "llist::reverse(record *start) function called\n" << endl;
        cout << "Record pointer passed: " << start << endl;
    #endif 

    /*Check if list is empty or address in next of temp points to the last node in the list*/

    if (start == NULL || start->next == NULL)
    {
        /*Copy from the address in temp to address in start, making the last node the head node*/
      
        //start = temp;
        temp = start;
    }
    else
    {
        /*Recursively call the reverse function on the next node - traverse bsckwards - and copy from address in next in temp (last node to be reversed) to prev (next node to be reversed)*/

        temp = reverse(start->next);

        start->next->next = start;

        start->next = NULL;
    }

    return temp;
}


/*****************************************************************
//
// Function name:       cleanup
//
// DESCRIPTION:   A function that cleans up any remaining pointers 
//		    left in the database 
//
// Parameters:          none 
//
// Return values:       none 
//
****************************************************************/

void llist::cleanup()
{
    record * temp;

    temp = start;

    #ifdef DEBUGMODE
        using std::cout;
        using std::endl;
        cout << "llist::cleanup() function called\n" << endl;
    #endif 

    /*Loop until reach end of list*/

    while (temp != NULL)
    {
        /*Checks if contents of next in the record whose address is in start is null*/
        
        if (start->next == NULL)
        {
            /*Copy null to start*/

            start = NULL;

            /*Release the space in temp*/

            delete(temp);

            /*Copy null to temp*/

            temp = NULL;
        }
        else
        {
            /*Copy contents of next in the record whose address is in temp to start*/

            start = temp->next;

            /*Checks if contetns of next in the record whose address is in start is not null*/

            if (temp->next != NULL)
            {
                /*Release the space in temp*/

                delete(temp);

                /*Copy contents of start to temp*/

                temp = start;
            }
        }
    }
}


/*****************************************************************
//
// Function name:       addRecord
//
// DESCRIPTION:   A function that adds a new record in the
//                  database
//
// Parameters:          uaccountno (int) : contains the user's
//                      account number
//                      uname (char [ ]) : contains the name of
//                      the user
//                      uaddress (char [ ]) : contains the
//                      address of the user
//
// Return values:       0 : successfully added record
//
****************************************************************/

int llist::addRecord (int uaccountno, char uname [ ], char uaddress [ ])
{
    record * ptr;

    /*Allocates space on heap and store address into ptr*/

    /*
    ptr = (struct record *) malloc (sizeof(struct record));
    */

    ptr = new record;

    ptr->accountno = uaccountno;
    strcpy(ptr->name, uname);
    strcpy(ptr->address, uaddress);
    ptr->next = NULL;

    #ifdef DEBUGMODE
        using std::cout;
        using std::endl;
        cout << "\nllist::addRecord function called" << endl;
        cout << "Account number passed: " << uaccountno << endl;
        cout << "Name passed: " << uname << endl;
        cout << "Address passed: " << "\n" << uaddress << "\n" << endl;
    #endif

    /*Check if list is empty. If is, add a record to list. If not, add a record to end of list*/

    if (start == NULL)
    {
        start = ptr;
    }
    else
    {
        record * temp;

        /*Copy contents of start to temp*/

        temp = start;

        if (start->next == NULL)
        {
            /*Copy contents of ptr to temp*/

            temp = ptr;

            /*Copy contents of temp to next in the record whose address is in start*/

            start->next = temp;
        }
        else
        {

            /*Loop until next in the record whose address is in temp is null*/

            while (temp->next != NULL)
            {
                /*Copy contents of next in the record whose address is in temp to temp*/

                temp = temp->next;
            }

            /*Copy contents of ptr to next in the record whose address is in temp*/

            temp->next = ptr;
        }
    }

    return 0; 
}


/*****************************************************************
//
// Function name:       printRecord
//
// DESCRIPTION:   A function that prints information about a
//                  record using the accountno as the key
//
// Parameters:          uaccountno (int) : contains the user's
//                      account number
//
// Return values:       0 : successfully printed record(s)
//			-1 : record does not exist
//
****************************************************************/

int llist::printRecord (int uaccountno)
{
    record * temp;
    int returnval;

    temp = start;
    returnval = 0; 
    
    using std::cout;
    using std::endl;

    #ifdef DEBUGMODE
        cout << "\n\nllist::printRecord function called" << endl;
        cout << "Account number passed: " << uaccountno << "\n" << endl;
    #endif

    /*Check if list is empty. Return failure if list is empty or account does not exist. Return success if account exists*/

    if (start == NULL)
    {
        /*List is empty. Return failure as records do not exist*/

        returnval = -1;
    } 
    else
    {

        /*Loop until end of list for existing accounts*/

        while (temp != NULL)
        {
            /*Prints information if the account number is the same as the user's account number. If it is not, continue going through the list*/

            if (temp->accountno == uaccountno)
            {
                cout << "\nAccount number is " << temp->accountno << endl;
                cout << "User's name is " << temp->name << endl;
                cout << "User's address is " << "\n" << temp->address << endl;

                temp = temp->next;

                /*Return success if existing account is printed*/

                returnval = 0;
            }
            else
            {
                temp = temp->next;

                /*Return failure if ccount number does not match*/

                //returnval = -1;
            }
        }
    }

    return returnval;
    //return 0;
}

/*****************************************************************
//
// Function name:       modifyRecord
//
// DESCRIPTION:   A function that modifies a record in the
//                  database using the accountno as the key
//
// Parameters:          uaccountno (int) : contains the user's
//                      account number
//                      uaddress (char [ ]) : contains the
//                      address of the user
//
// Return values:       0 : successfully modified record(s)
//			-1 : record does not exist 
// 
****************************************************************/

int llist::modifyRecord ( int uaccountno, char uaddress [ ])
{
    int maxinput;
    int returnval;
    record * temp;

    temp = start;
    maxinput = 80;
    returnval = 0;

    /*Check if list is empty. Return failure if list is empty or account does not exist. Return success if account exists*/

    if (start == NULL)
    {
        /*List is empty. Return failure as records do not exist*/

        returnval = -1;
    }
    else
    {
        /*Loop until end of list for existing accounts*/

        while (temp != NULL)
        {
            /*Checks if account number matches account number in the record whose address is in temp. If not, keep going through the list*/

            if (temp->accountno == uaccountno)
            {
                /*Copy contents of uaddress to the address in record whose address is in temp*/

                strcpy(temp->address, uaddress);

                temp = temp->next;

                /*Returns success if existing account is modified*/

                returnval = 0;
            }
            else
            {
                temp = temp->next;
            }
        }
    }

    #ifdef DEBUGMODE
        using std::cout;
        using std::endl;
        cout << "\n\nllist::modifyRecord function called" << endl;
        cout << "Account number passed: " << uaccountno << endl;
        cout << "Address passed: " << "\n" << uaddress << "\n" << endl;
    #endif

    return returnval;
    //return 0;
}

/*****************************************************************
//
// Function name:       operator<<
//
// DESCRIPTION:   A function that prints all the information in the
//                  database
//
// Parameters:          outputlist (ostream&) : contains the
//			output operations such as cout
//			mylist (const llist&) : contains a 
//			reference to the list object
//
// Return values:	outputlist (ostream&) : contains the
//			overloaded output using cout 
// 
****************************************************************/

std::ostream& operator<< (std::ostream& outputlist, const llist& mylist)
{
    using std::cout;
    using std::endl;

    #ifdef DEBUGMODE
        cout << "\nOverloaded operator << called\n\n" << endl;
    #endif

    /*Checks if list/database is empty and print message saying it is. If not, print everything in the list*/

    if (mylist.start == NULL)
    {
        /*Print error message if database is empty*/

        cout << "Database is empty. There are no records in the database" << endl;
    }
    else 
    {
        record * temp;

        temp = mylist.start;

        cout << "All accounts will be printed.\n" << endl;

        /*Checks if there is one record in list*/

        if (mylist.start->next == NULL)
        {
            /*Prints the first record in list*/

            outputlist << "Account number: " << (mylist.start)->accountno << endl;
            outputlist << "Name: " << (mylist.start)->name << endl;
            outputlist << "Address: " << "\n" << (mylist.start)->address << "\n" << endl; 
        }
        else 
        {
            /*Prints the first record in list (temp is currently pointing to first record)*/

            outputlist << "Account number: " << temp->accountno << endl;
            outputlist << "Name: " << temp->name << endl;
            outputlist << "Address: " << "\n" << temp->address << "\n" << endl; 

            /*Loops and prints the rest of the list until the end is reached*/

            while (temp->next != NULL)
            {
                temp = temp->next;
               
                outputlist << "Account number: " << temp->accountno << endl;
                outputlist << "Name: " << temp->name << endl;
                outputlist << "Address: " << "\n" << temp->address << "\n" << endl; 
            }
        } 
    }

    return outputlist;
}


/*****************************************************************
//
// Function name:       deleteRecord
//
// DESCRIPTION:   A function that deletes an existing record from
//                  the database using the accountno as a key
//
// Parameters:          uaccountno (int) : contains the user's
//                      account number
//
// Return values:       0 : sucessfully deleted record(s)
//			-1 : record does not exist
// 
****************************************************************/

int llist::deleteRecord(int uaccountno)
{
    record * temp;
    record * prev;
    int returnval;

    temp = start;
    returnval = 0;

    #ifdef DEBUGMODE
        using std::cout;
        using std::endl;
        cout << "\n\nllist::deleteRecord function called" << endl;
        cout << "Account number passed: " << uaccountno << "\n" << endl;
    #endif

    /*Checks if list is empty. Returns failure if empty or account does not exist. Returns success if account exists*/

    if (start == NULL)
    {
        /*List is empty. Return failure as records do not exist*/

        returnval = -1;
    }
    else
    {
        /*Loop until end of list*/

        while (temp != NULL)
        {
            /*Check if uaccountno matches the accountno in the record whose address is in start*/

            if (start->accountno == uaccountno)
            {
                /*Checks if the contents of next in the record whose address is in start is not null*/

                if (start->next != NULL)
                {
                    /*Copy contents of next in the record whose address is in temp to start*/

                    start = temp->next;
                }
                else
                {
                    /*Copy null to start*/

                    start = NULL;
                }

                /*Release the space whose address is in temp*/
			
                delete(temp);

                /*Copy contents of start to temp*/

                temp = start;

                /*Returns success if existing account is deleted*/

                returnval = 0;
            }
            else
            {
                /*Checks if uaccountno doesn't match the accountno in the record whose address is in temp*/

                if (temp->accountno != uaccountno)
                {

                    /*Copy contents of temp to prev*/

                    prev = temp;

                    /*Copy contents of next in the record whose address is in temp to temp*/

                    temp = temp->next;

                    /*Returns failure if account number does not match*/

                    //returnval = -1;
                }
                else
                {
                    /*Copy contents of next in the record whose addresss is in temp to next in the record whose address is in prev*/

                    prev->next = temp->next;

                    /*Release the space whose address is in temp*/

                    delete(temp);

                    /*Copy contents of next in the record whose address is in prev to temp*/

                    temp = prev->next;

                    /*Returns success if existing account is deleted*/

                    returnval = 0;
                }
            }
        }
    
    }

    return returnval;
    //return 0;
}


/*****************************************************************
//
// Function name:       reverse
//
// DESCRIPTION:   A function that calls the reverse(record *)
//		    function to reverse the list
//
// Parameters:          none  
//
// Return values:       none 
//
****************************************************************/

void llist::reverse()
{
    #ifdef DEBUGMODE
        using std::cout;
        using std::endl;
        cout << "\n\nllist::reverse function called\n" << endl;
    #endif

    /*Reverses list from start*/

    start = llist::reverse(start);
}



/*
https://www.programiz.com/cpp-programming/constructors
https://www.tutorialspoint.com/cplusplus/cpp_constructor_destructor.htm
https://stackoverflow.com/questions/5507545/c-how-to-write-a-constructor
https://www.tutorialspoint.com/cplusplus/cpp_constructor_destructor.htm
https://msdn.microsoft.com/en-us/library/1z2f6c2k.aspx
https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm
https://www.youtube.com/watch?v=TwW2Nl45FvE
http://www.cplusplus.com/forum/general/1796/
https://www.youtube.com/watch?v=hAluLUqaB0s
https://www.tutorialspoint.com/cplusplus/cpp_files_streams.htm
http://www.cprogramming.com/fod/atoi.html
https://www.experts-exchange.com/questions/25060948/error-ISO-C-forbids-declaration-of-ostream-with-no-type.html
https://stackoverflow.com/questions/15734020/error-declaration-of-operator-as-non-function
https://stackoverflow.com/questions/7921621/c-error-private-data-member-was-not-declared-in-this-scope
http://augustcouncil.com/~tgibson/tutorial/iotips.html
http://www.cplusplus.com/doc/tutorial/files/
http://www.cplusplus.com/reference/fstream/ifstream/is_open/
http://www.cplusplus.com/reference/fstream/ofstream/is_open/
http://www.linuxquestions.org/questions/programming-9/reading-multiple-lines-into-a-string-c-4175505240/
http://www.cplusplus.com/reference/ostream/ostream/
http://algorithms.tutorialhorizon.com/reverse-a-linked-list-part-2/

*/
