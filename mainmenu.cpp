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
// FILE:                mainmenu.cpp
//
// DESCRIPTION:  This file contains the driver and the user-
//                  interface functions for the temperature
//                  conversion program converted of Homework 8
//
****************************************************************/

#include <iostream>
#include "llist.h"

void getaddress (char [ ], int);

/*****************************************************************
//
// Function name:       main
//
// DESCRIPTION:   A function that calls the function printf to
//                  print the sequence of characters and the
//                  function createTable for the temperature
//                  conversion program
//
// Parameters:          argc (int) : contains the number of
//                      arguments which will be processed
//                      argv (char[]) : contains an array of
//                      characters to be procesed
//
// Return values:       0 : successfully run the calls in the
//                      function
//
****************************************************************/

int main (int argc, char *argv [ ])
{
    int count, option, uaccountno, check, maxinput;
    char uname[25] = "";
    char uaddress[80] = "";

    using std::cin;
    using std::cout;
    using std::endl;
 
    /*Creates mylist object using default constructor*/

    llist mylist;

    /*Creates mylist object that holds the input file using constructor with 1 parameter*/

    //llist mylist( "proj2.txt" );

    /*Copies the contents of mylist to _______*/



    count = 1;
    option = 0;
    check = 1;
    maxinput = 80;

    /*Loop through options*/

    do 
    {
        cout << "\nMenu Options Displayed" << endl;
        cout << "1: Add a Record to Database" << endl;
        cout << "2: Modify a Record in Database" << endl; 
        cout << "3: Print a Record in Database" << endl;
        cout << "4: Print All Records in Database" << endl; 
        cout << "5: Delete a Record from Database" << endl;
        cout << "6: Reverses Records in Database" << endl; 
        cout << "7: Quit menu" << endl;

        cout << "\nPlease choose an option between 1 to 7 below:" << endl;
        cin >> option;

        if (option == 1)
        {
            cout << "\nYou chose option 1: Add a record.\n" << endl;

            /*User enters their account number*/
  
            cout << "Enter your account number below:" << endl;

            /*Checks if user did not enter an integer*/ 

            while (!(cin >> uaccountno))
            {
                cout << "\nERROR: Account number cannot be a string or character.\nPlease re-enter account number below" << endl;

                /*Clears bad input and trailing newline*/

                cin.clear();
                cin.ignore(10000, '\n');
            }

            /*Clears trailing newline in buffer*/

            std::cin.clear();
            std::cin.ignore(10000, '\n');

            /*User enters their name*/

            cout << "\nEnter your name below. Only 24 characters allowed.\nPress ENTER once when finished:" << endl;

            while (!cin.get(uname, 25))
            {
                /*Clears trailing newline in buffer*/

                std::cin.clear();
                std::cin.ignore(10000, '\n');

            }
   
            /*Clears trailing newline in buffer*/

            std::cin.clear();
            std::cin.ignore(10000, '\n');

            /*User enters their address*/
          
            cout << "\nEnter your address below. Only 79 characters allowed.\nWhen finished, press ENTER, then press '?' and ENTER two more times:" << endl;

            getaddress(uaddress, maxinput);

            /*Clears trailing newline in buffer*/

            std::cin.clear();
            //std::cin.ignore(10000, '\n');

            /*Calls addRecord to add a record to database*/

            mylist.addRecord(uaccountno, uname, uaddress);

            cout << "Your record was successfully added to database\n" << endl;
        }
        else if (option == 2)
        {
            cout << "\nYou chose option 2: Modify a record.\n" << endl;

            /*User enters their account number*/

            cout << "Enter your account number below:" << endl;

            /*Checks if user did not enter an integer*/ 

            while (!(cin >> uaccountno))
            {
                cout << "\nERROR: Account number cannot be a string or character.\nPlease re-enter account number below" << endl;

                /*Clears bad input and trailing newline*/

                cin.clear();
                cin.ignore(10000, '\n');
            }

            /*Clears trailing newline in buffer*/

            std::cin.clear();
            std::cin.ignore(10000, '\n');

            /*User enters their address*/
            /*
             cout << "\nEnter your address below. Press ENTER twice when finished:" << endl;

            //check here - counter

            getaddress(uaddress, maxinput);
 
            //check return value of modify 
            */

            if (mylist.modifyRecord(uaccountno, "") == 0)
            {
                /*User enters their address*/

                cout << "\nEnter your address below. Only 79 characters allowed.\nWhen finished, press ENTER, then press '?' and ENTER two more times:" << endl;

                getaddress(uaddress, maxinput);

                mylist.modifyRecord(uaccountno, uaddress);

                cout << "All records with this account number have been modified\n" << endl;
            }
            else
            {
                cout << "\nThis record does not exist\n" << endl;
            }
        }
        else if (option == 3)
        {
            cout << "\nYou chose option 3: Print a record.\n" << endl;

            /*User enters their account number*/
            cout << "Enter your account number below:" << endl;

            /*Checks if user did not enter an integer*/

            while (!(cin >> uaccountno))
            {
                cout << "\nERROR: Account number cannot be a string or character.\nPlease re-enter account number below" << endl;

                /*Clears bad input and trailing newline*/

                cin.clear();
                cin.ignore(10000, '\n');
            }

            if (mylist.printRecord(uaccountno) == 0)
            {
                cout << "\nAll records with this account number have been printed\n" << endl;
            }   
            else
            {
                cout << "\nThis record does not exist\n" << endl;
            }
        }
        else if (option == 4)
        {
            cout << "\nYou chose option 4: Print all records.\n" << endl;

            cout << mylist << endl;
        }
        else if (option == 5)
        {
            cout << "\nYou chose option 5: Delete a record.\n" << endl;

            /*User enters their account number*/

            cout << "Enter your account number below:" << endl;

            /*Checks if user did not enter an integer*/

            while (!(cin >> uaccountno))
            {
                cout << "\nERROR: Account number cannot be a string or character.\nPlease re-enter account number below" << endl;

                /*Clears bad input and trailing newline*/

                cin.clear();
                cin.ignore(10000, '\n');
            }

            //check return value of delete 

            if (mylist.deleteRecord(uaccountno) == 0)
            {
                cout << "\nAll records with this account number have been deleted\n" << endl;
            }   
            else
            {
                cout << "\nThis record does not exist\n" << endl;
            }

            //mylist.deleteRecord(uaccountno);

        }
        else if (option == 6)
        {
            cout << "\nYou chose option 6: Reverse the database.\n" << endl;

            /*Reverses list without printing it*/

            mylist.reverse();

            cout << "The records in the database have been reversed\n" << endl;
        }
        else if (option == 7)
        {
            cout << "You chose option 7: Quit the program.\n\nGoodbye\n" << endl;
            count = 0;
        }
        else
        {
            cout << "\nInvalid number option. Number option must be between 1 and 7. \n\nPlease re-enter numbered option below.\n" << endl;
             
            /*Clears trailing newline in buffer*/
            cin.clear();
            cin.ignore(10000, '\n');
        }
    } while (count != 0);

    count = 1;




    return 0;
}

/*
Used these for help:
http://minich.com/education/wyo/cplusplus/cplusplusch10/getfunction.htm
http://www.cplusplus.com/reference/istream/istream/get/
http://www.cplusplus.com/forum/beginner/26118/
https://stackoverflow.com/questions/22188867/using-cin-get-to-discard-unwanted-characters-from-the-input-stream-in-c

*/

