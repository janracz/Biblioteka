/*! \file BookManagment.c
    \brief Book Managment Functions

    File contains functions used to manage books.
*/
#include "Functions.h"



/**
 * @brief Borrow books
 *
 * This function lets user to borrow books from library.
 */
void borrowBookFromLibrary()
{
    int days;
    s_BooksInfo searchForBookInLibrary = { 0 };
    s_BorrowedBookInfo addBookInfoInDataBase = { 0 };
    FILE* fp = NULL;
    int status = 0;
    int bookID = 0;
    int found = 0;
    char bufor[50] = "";
    fp = fopen(FILE_NAME, "ab+");
    if (fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    FILE* fpLibrary = NULL;
    fpLibrary = fopen(FILE_NAME_LIBRARY_BASE, "r");
    if (fpLibrary == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }

    headMessage("ADD NEW BOOKS");
    printf("\n\n\t\t\tENTER YOUR DETAILS BELOW:");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("\n\t\t\tBook ID NO  = ");
    fflush(stdin);
    //scanf("%u", &bookID);
    fgets(bufor, 50, stdin);
    bookID = atoi(bufor);

    while (fread(&searchForBookInLibrary, sizeof(searchForBookInLibrary), 1, fpLibrary))
    {
        if (searchForBookInLibrary.books_id == bookID)
        {
            addBookInfoInDataBase.bookInfo.books_id = searchForBookInLibrary.books_id;
            strcpy(addBookInfoInDataBase.bookInfo.authorName, searchForBookInLibrary.authorName);
            strcpy(addBookInfoInDataBase.bookInfo.bookName, searchForBookInLibrary.bookName);
            found = 1;
        }
    }
    if (found == 0)
    {
        printf("\n\t\t\tBook ID not found!");
        exit(1);
    }
    do
    {
        printf("\n\t\t\tStudent Name  = ");
        fflush(stdin);
        fgets(addBookInfoInDataBase.studentName, MAX_STUDENT_NAME, stdin);
        status = isNameValid(addBookInfoInDataBase.studentName);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    } while (!status);
    do
    {
        //get date year,month and day from user
        printf("\n\t\t\tEnter date in format (day/month/year): ");
        fflush(stdin);
        scanf("%d/%d/%d", &addBookInfoInDataBase.bookIssueDate.dd, &addBookInfoInDataBase.bookIssueDate.mm, &addBookInfoInDataBase.bookIssueDate.yyyy);
        //check date validity
        status = isValidDate(&addBookInfoInDataBase.bookIssueDate);
        if (!status)
        {
            printf("\n\t\t\tPlease enter a valid date.\n");
        }
    } while (!status);
    fwrite(&addBookInfoInDataBase, sizeof(addBookInfoInDataBase), 1, fp);
    fclose(fp);
}


/**
 * @brief Search books
 *
 * This function lets user to search a book from his borrowed books.
 */void searchBooks()
{
    int found = 0;
    char bookName[MAX_BOOK_NAME] = { 0 };
    s_BorrowedBookInfo addBookInfoInDataBase = { 0 };
    FILE* fp = NULL;
    int status = 0;
    fp = fopen(FILE_NAME, "rb");
    if (fp == NULL)
    {
        printf("\n\t\t\tFile is not opened\n");
        exit(1);
    }
    headMessage("SEARCH BOOKS");
    //put the control on books detail
    if (fseek(fp, FILE_HEADER_SIZE, SEEK_SET) != 0)
    {
        fclose(fp);
        printf("\n\t\t\tFacing issue while reading file\n");
        exit(1);
    }
    printf("\n\n\t\t\tEnter Book Name to search:");
    fflush(stdin);
    fgets(bookName, MAX_BOOK_NAME, stdin);
    while (fread(&addBookInfoInDataBase, sizeof(addBookInfoInDataBase), 1, fp))
    {
        if (!strcmp(addBookInfoInDataBase.bookInfo.bookName, bookName))
        {
            found = 1;
            break;
        }
    }
    if (found)
    {
        printf("\n\t\t\tBook id = %u\n", addBookInfoInDataBase.bookInfo.books_id);
        printf("\t\t\tBook name = %s", addBookInfoInDataBase.bookInfo.bookName);
        printf("\t\t\tBook authorName = %s", addBookInfoInDataBase.bookInfo.authorName);
        printf("\t\t\tBook issue date(day/month/year) =  (%d/%d/%d)", addBookInfoInDataBase.bookIssueDate.dd,
            addBookInfoInDataBase.bookIssueDate.mm, addBookInfoInDataBase.bookIssueDate.yyyy);
    }
    else
    {
        printf("\n\t\t\tNo Record");
    }
    fclose(fp);
    printf("\n\n\n\t\t\tPress any key to go to main menu.....");
    getchar();
}

 /**
  * @brief View books
  *
  * This function lets user to show his borrowed books.
  */
void viewBooks()
{
    int found = 0;
    char bookName[MAX_BOOK_NAME] = { 0 };
    s_BorrowedBookInfo addBookInfoInDataBase = { 0 };
    FILE* fp = NULL;
    int status = 0;
    unsigned int countBook = 1;
    headMessage("VIEW BOOKS DETAILS");
    fp = fopen(FILE_NAME, "rb");
    if (fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    if (fseek(fp, FILE_HEADER_SIZE, SEEK_SET) != 0)
    {
        fclose(fp);
        printf("Facing issue while reading file\n");
        exit(1);
    }
    while (fread(&addBookInfoInDataBase, sizeof(addBookInfoInDataBase), 1, fp))
    {
        printf("\n\t\t\tBook Count = %d\n\n", countBook);
        printf("\t\t\tBook id = %u", addBookInfoInDataBase.bookInfo.books_id);
        printf("\n\t\t\tBook name = %s", addBookInfoInDataBase.bookInfo.bookName);
        printf("\t\t\tBook authorName = %s", addBookInfoInDataBase.bookInfo.authorName);
        printf("\t\t\tBook issue date(day/month/year) =  (%d/%d/%d)\n\n", addBookInfoInDataBase.bookIssueDate.dd,
            addBookInfoInDataBase.bookIssueDate.mm, addBookInfoInDataBase.bookIssueDate.yyyy);
        found = 1;
        ++countBook;
    }
    fclose(fp);
    if (!found)
    {
        printf("\n\t\t\tNo Record");
    }
    printf("\n\n\t\t\tPress any key to go to main menu.....");
    fflush(stdin);
    getchar();
}

/**
 * @brief Add book
 *
 * This function lets you to add a book to library.
 */
void addBookToLibrary()
{
    int days;
    s_BooksInfo addBookInfoInDataBase = { 0 };
    char bufor[50] = "";
    FILE* fp = NULL;
    int status = 0;
    fp = fopen(FILE_NAME_LIBRARY_BASE, "ab+");
    if (fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    headMessage("ADD NEW BOOKS");
    printf("\n\n\t\t\tENTER DETAILS BELOW:");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("\n\t\t\tBook ID NO  = ");
    fflush(stdin);
    //scanf("%u", &addBookInfoInDataBase.books_id);
    fgets(bufor, 50, stdin);
    addBookInfoInDataBase.books_id = atoi(bufor);
    do
    {
        printf("\n\t\t\tBook Name  = ");
        fflush(stdin);
        fgets(addBookInfoInDataBase.bookName, MAX_BOOK_NAME, stdin);
        status = isNameValid(addBookInfoInDataBase.bookName);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    } while (!status);
    do
    {
        printf("\n\t\t\tAuthor Name  = ");
        fflush(stdin);
        fgets(addBookInfoInDataBase.authorName, MAX_AUTHOR_NAME, stdin);
        status = isNameValid(addBookInfoInDataBase.authorName);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    } while (!status);
    fwrite(&addBookInfoInDataBase, sizeof(addBookInfoInDataBase), 1, fp);
    fclose(fp);
}


/**
 * @brief Return book
 *
 * This function lets user to return a book to library.
 */
void deleteBooks()
{
    int found = 0;
    int bookDelete = 0;
    sFileHeader fileHeaderInfo = { 0 };
    char bookName[MAX_BOOK_NAME] = { 0 };
    s_BorrowedBookInfo addBookInfoInDataBase = { 0 };
    FILE* fp = NULL;
    FILE* tmpFp = NULL;
    int status = 0;
    char bufor[50] = "";
    headMessage("Delete Books Details");
    fp = fopen(FILE_NAME, "rb");
    if (fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    tmpFp = fopen("tmp.bin", "wb");
    if (tmpFp == NULL)
    {
        fclose(fp);
        printf("File is not opened\n");
        exit(1);
    }
    fread(&fileHeaderInfo, FILE_HEADER_SIZE, 1, fp);
    fwrite(&fileHeaderInfo, FILE_HEADER_SIZE, 1, tmpFp);
    printf("\n\t\t\tEnter Book ID NO. for delete:");
    //scanf("%d", &bookDelete);
    fgets(bufor, 50, stdin);
    bookDelete = atoi(bufor);
    while (fread(&addBookInfoInDataBase, sizeof(addBookInfoInDataBase), 1, fp))
    {
        if (addBookInfoInDataBase.bookInfo.books_id != bookDelete)
        {
            fwrite(&addBookInfoInDataBase, sizeof(addBookInfoInDataBase), 1, tmpFp);
        }
        else
        {
            found = 1;
        }
    }
    (found) ? printf("\n\t\t\tRecord deleted successfully.....") : printf("\n\t\t\tRecord not found");
    fclose(fp);
    fclose(tmpFp);
    remove(FILE_NAME);
    rename("tmp.bin", FILE_NAME);

    printf("\n\n\t\t\tPress any key to go to main menu.....");
    fflush(stdin);
    getchar();
}