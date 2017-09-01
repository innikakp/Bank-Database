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
// DATE:        July 25, 2017
//
// FILE:                record.h
//
// DESCRIPTION:  This header file contains the structure for
//                  making a record for Project 2
//
****************************************************************/

#ifndef RECORD_H
#define RECORD_H

struct record
{
    int                accountno;
    char               name[25];
    char               address[80];
    struct record*     next;
};

#endif


