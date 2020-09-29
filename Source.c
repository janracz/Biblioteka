/*! \file Source.c
    \brief Main

    File contains main function.
*/

#include "Functions.h"

/**
 * @brief Initialize
 *
 * This function Initialize allfiles that have to exist
 */
void init()
{
    FILE* fp = NULL;
    int status = 0;
    const char defaultUsername[] = "janracz\n";
    const char defaultPassword[] = "janracz\n";
    sFileHeader fileHeaderInfo = { 0 };
    status = isFileExists(FILE_NAME);
    if (!status)
    {
        //create the binary file
        fp = fopen(FILE_NAME, "wb");
        if (fp != NULL)
        {
            //Copy default password
            strncpy(fileHeaderInfo.password, defaultPassword, sizeof(defaultPassword));
            strncpy(fileHeaderInfo.username, defaultUsername, sizeof(defaultUsername));
            fwrite(&fileHeaderInfo, FILE_HEADER_SIZE, 1, fp);
            fclose(fp);
        }
    }

    status = isFileExists(FILE_NAME_LOGIN);
    if (!status)
    {
        //create the binary file
        fp = fopen(FILE_NAME_LOGIN, "wb");
        if (fp != NULL)
        {
            //Copy default password
            strncpy(fileHeaderInfo.password, defaultPassword, sizeof(defaultPassword));
            strncpy(fileHeaderInfo.username, defaultUsername, sizeof(defaultUsername));
            fwrite(&fileHeaderInfo, FILE_HEADER_SIZE, 1, fp);
            fclose(fp);
        }
    }

    status = isFileExists(FILE_NAME_LIBRARY_BASE);
    if (!status)
    {
        //create the binary file
        addBookToLibrary();
    }
}

/**
 * @brief Start
 *
 * This function This function lets you choose if you want to ;ogin or add book to library
 */
void loginOrAddBook()
{
    int choice = 0;
    char bufor[50] = "";
    do
    {
        headMessage("MENU");
        printf("\n\n\n\t\t\t1.Add Books To Library");
        printf("\n\t\t\t2.Login To Account");
        printf("\n\t\t\t0.Exit");
        printf("\n\n\n\t\t\tEnter choice => ");
        //scanf("%d", &choice);
        fflush(stdin);
        fgets(bufor, 50, stdin);
        if (!is_empty(bufor))
        {
            choice = atoi(bufor);
        }
        else
        {
            choice = 10;
        }

        switch (choice)
        {
        case 1:
            addBookToLibrary();
            break;
        case 2:
            login();
            break;
        case 0:
            printf("\n\n\n\t\t\t\tThank you!!!\n\n\n\n\n");
            exit(1);
            break;
        default:
            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");
        }                                            //Switch Ended
    } while (choice != 0);
}

/**
 * @brief Main
 *
 * This function is a main function of a program
 */
int main()
{
    init();
    welcomeMessage();
    loginOrAddBook();
    return 0;
}