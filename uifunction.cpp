/*****************************************************************
//
// NAME:        Innika Pang
//
// PROJECT:     2
//
// CLASS:       ICS 212
//
// INSTRUCTOR:  Ravi Narayan
//
// DATE:        July 27, 2017
//
// FILE:                uifunction.cpp
//
// DESCRIPTION:  This file contains the getaddress function to 
//		    get the user's address input  for Project 2
//
****************************************************************/

#include <iostream>
#include <cstring>
//#define DEBUGMODE

void getaddress(char [ ], int);

/*****************************************************************
//
// Function name:       getaddress
//
// DESCRIPTION:   A function that obtains the address information 
//		     of the user
//
// Parameters:          uaddress (char [ ]) : contains the user's
//			address
//                      maxinput (int) : maximum amount of input 
//			user can put in (i.e. size of array)
//
// Return values:       none
//
****************************************************************/

void getaddress (char uaddress[ ], int maxinput)
{
    char copyaddress[80] = "";
    //char *replace;
    int count, length;
    //int i = 0;
    using std::cin;
    using std::cout;
    using std::endl;

    count = 1;
    length = 0;

    do
    {
       //std::cin.clear();
       //std::cin.ignore(10000, '\n');

       cin.get(uaddress, 80);

       /*Clears trailing newline in buffer*/ 

       std::cin.clear();
       std::cin.ignore(10000, '\n');

       /*Checks if user did not enter input*/ 

       //if (strcmp(uaddress, "\n\n") == 0)
       if (strcmp(uaddress, "\?") == 0)
       {
           count = 0;
       }

       /*Checks if user entered multiple lines of input and concatenates them together. Stops loop if user enters an empty string (AKA enters newline)*/ 

       if (strcmp(uaddress, "\?") != 0 && count != 0)
       {
           strcat(uaddress, "\n");
           strcat(copyaddress, uaddress);
       }
       else
       {
           count = 0;
       }       

       length = strlen(copyaddress);

       if (length >= maxinput)
       {
           //copyaddress[maxinput - 2] = '\n';
           copyaddress[maxinput - 1] = '\0';
       } 

    } while (count != 0);
   

    std::cin.clear();
    std::cin.ignore(10000, '\n');

    strcpy(uaddress, copyaddress);

    count = 1;

    #ifdef DEBUGMODE
        using std::cout;
        using std::endl;
        cout << "\ngetaddress function called" << endl;
        cout << "Amount of maximum input passed: " << maxinput << endl;
        cout << "Address passed: " << "\n" << uaddress << endl;
    #endif
}
