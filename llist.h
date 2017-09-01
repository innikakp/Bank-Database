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
// FILE:                llist.h
//
// DESCRIPTION:  This file contains the class definition and 
//		    necessary variable declarations and member
//		    functions for Project 2 
//
****************************************************************/

#ifndef LLIST_H
#define LLIST_H
#include "record.h"

class llist
{
  private:
    record *    start;
    char        filename[16];
    int         readfile();
    int         writefile();
    record *    reverse(record * );
    void        cleanup();

  public:
    llist();
    llist(char[]);
    ~llist();
    int addRecord (int, char [ ],char [ ]);
    int printRecord (int);
    int modifyRecord ( int, char [ ]);
    friend std::ostream& operator<< (std::ostream&, const llist&);
    int deleteRecord(int);
    void reverse();
};

#endif

/*
https://stackoverflow.com/questions/3246803/why-use-ifndef-class-h-and-define-class-h-in-h-file-but-not-in-cpp
https://stackoverflow.com/questions/15734020/error-declaration-of-operator-as-non-function
https://www.experts-exchange.com/questions/25060948/error-ISO-C-forbids-declaration-of-ostream-with-no-type.html
https://stackoverflow.com/questions/8020113/c-include-guards

*/
