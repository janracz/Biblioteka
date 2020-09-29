/*! \file UserFunctions.c
    \brief User Functions

    File contains functions used by user.
*/

#include "Functions.h"


/**
 * @brief Update password
 *
 * This function lets a user to update his password.
 */
void updateCredential(void)
{
    sFileHeader fileHeaderInfo = { 0 };
    FILE* fp = NULL;
    unsigned char userName[MAX_SIZE_USER_NAME] = { 0 };
    unsigned char password[MAX_SIZE_PASSWORD] = { 0 };
    headMessage("Update Credential");
    fp = fopen(FILE_NAME_LOGIN, "rb+");
    if (fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    fread(&fileHeaderInfo, FILE_HEADER_SIZE, 1, fp);
    if (fseek(fp, 0, SEEK_SET) != 0)
    {
        fclose(fp);
        printf("\n\t\t\tFacing issue while updating password\n");
        exit(1);
    }
    printf("\n\n\t\t\tNew Password:");
    fflush(stdin);
    fgets(password, MAX_SIZE_PASSWORD, stdin);
    strncpy(fileHeaderInfo.password, password, sizeof(password));
    fwrite(&fileHeaderInfo, FILE_HEADER_SIZE, 1, fp);
    fclose(fp);
    printf("\n\t\t\tYour Password has been changed successfully");
    printf("\n\t\t\tLogin Again:");
    fflush(stdin);
    getchar();
    exit(1);
}


/**
 * @brief Login
 *
 * This function lets a user to login to his account.
 */
void login()
{
    unsigned char userName[MAX_SIZE_USER_NAME] = { 0 };
    unsigned char password[MAX_SIZE_PASSWORD] = { 0 };
    int L = 0;
    sFileHeader fileHeaderInfo = { 0 };
    FILE* fp = NULL;
    headMessage("Login");
    fp = fopen(FILE_NAME_LOGIN, "rb");
    if (fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    fread(&fileHeaderInfo, FILE_HEADER_SIZE, 1, fp);
    fclose(fp);
    do
    {
        printf("\n\n\n\t\t\t\tUsername:");
        fgets(userName, MAX_SIZE_USER_NAME, stdin);
        printf("\n\t\t\t\tPassword:");
        fgets(password, MAX_SIZE_PASSWORD, stdin);
        if ((!strcmp(userName, fileHeaderInfo.username)) && (!strcmp(password, fileHeaderInfo.password)))
        {
            menu();
        }
        else
        {
            printf("\t\t\t\tLogin Failed Enter Again Username & Password\n\n");
            L++;
        }
    } while (L <= 3);
    if (L > 3)
    {
        headMessage("Login Failed");
        printf("\t\t\t\tSorry,Unknown User.");
        getch();
        system("cls");
    }
}


/**
 * @brief Menu
 *
 * This function shows and lets a user chose menu of choices a user have.
 */
void menu()
{
    int choice = 0;
    char bufor[50] = "";
    do
    {
        strcpy(bufor, "");
        headMessage("MAIN MENU");
        printf("\n\n\n\t\t\t1.Borrow Books");
        printf("\n\t\t\t2.Search Books");
        printf("\n\t\t\t3.View Books");
        printf("\n\t\t\t4.Delete Book");
        printf("\n\t\t\t5.Update Password");
        printf("\n\t\t\t0.Exit");
        printf("\n\n\n\t\t\tEnter choice => ");
        //scanf("%d", &choice);
        fgets(bufor, 50, stdin);
        if (!is_empty(bufor))
        {
            choice = atoi(bufor);
        }
        else
        {
            choice = 10;
        }
        choice = atoi(bufor);
        switch (choice)
        {
        case 1:
            borrowBookFromLibrary();
            break;
        case 2:
            searchBooks();
            break;
        case 3:
            viewBooks();
            break;
        case 4:
            deleteBooks();
            break;
        case 5:
            updateCredential();
            break;
        case 0:
            printf("\n\n\n\t\t\t\tThank you!!!\n\n\n\n\n");
            exit(1);
            break;
        default:
            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");
        }                                            //Switch Ended
    } while (choice != 0);                                        //Loop Ended
}