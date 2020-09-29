/*! \file VisualFunctions.c
    \brief Visual Functions

    File contains functions managing visuals.
*/
#include "Functions.h"

/**
 * @brief Head message
 *
 * This function clears screen and displays a top graphic
 * @param message A message which should be displayed
 */
void headMessage(const char* message)
{
    system("cls");
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############      Library Management System Project in C       ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printMessageCenter(message);
    printf("\n\t\t\t----------------------------------------------------------------------------");
}

/**
 * @brief Welcome message
 *
 * This function displays a welcome message graphic
 */
void welcomeMessage()
{
    headMessage("www.OnlineLibrary.com");
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                 WELCOME                   =");
    printf("\n\t\t\t        =                   TO                      =");
    printf("\n\t\t\t        =                 LIBRARY                   =");
    printf("\n\t\t\t        =               MANAGEMENT                  =");
    printf("\n\t\t\t        =                 SYSTEM                    =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getch();
}

/**
 * @brief Center message
 *
 * This function allows to display message at the center
 * @param message A message which should be displayed
 */
void printMessageCenter(const char* message)
{
    int len = 0;
    int pos = 0;
    //calculate how many space need to print
    len = (78 - strlen(message)) / 2;
    printf("\t\t\t");
    for (pos = 0; pos < len; pos++)
    {
        //print space
        printf(" ");
    }
    //print message
    printf("%s", message);
}