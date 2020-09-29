/*! \file Functions.h
    \brief Functions

    File contains all functions used in program.
*/


#pragma once
#include "Structs.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

//visual functions
void headMessage(const char* message);
void welcomeMessage();
void printMessageCenter(const char* message);

//book managment
void borrowBookFromLibrary();
void searchBooks();
void viewBooks();
void deleteBooks();
void addBookToLibrary();

//validation functions
int isNameValid(const char* name);
int isLeapYear(int year);
int isValidDate(Date* validDate);
int isFileExists(const char* path);
int is_empty(const char* s);


//user functions
void updateCredential(void);
void login();
void menu();