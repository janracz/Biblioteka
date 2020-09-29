/*! \file Structs.h
    \brief Macros and structs

    File contains all macros and structures used in program.
*/

/*! \def MAX_YR
    \brief Returns a maximum of year.
*/

/*! \def MIN_YR
    \brief Returns a minimum of year.
*/

/*! \def MAX_SIZE_USER_NAME
    \brief Returns a maximum of user name.
*/

/*! \def MAX_SIZE_PASSWORD
    \brief Returns a maximum of password.
*/

/*! \def FILE_NAME
    \brief Returns name of borrow book file.

    Returns a name of a file where borrowed books are saved.
*/

/*! \def FILE_NAME_LOGIN
    \brief Returns name of log/pass file.

    Returns a name of a file where logins and passwords are saved.
*/

/*! \def FILE_NAME_LIBRARY_BASE
    \brief Returns name of library file.

    Returns a name of a file where books in library are saved.
*/

/*! \def MAX_BOOK_NAME
    \brief Returns a maximum of book name.
*/

/*! \def MAX_AUTHOR_NAME
    \brief Returns a maximum of author name.
*/

/*! \def MAX_STUDENT_NAME
    \brief Returns a maximum of student name.
*/

/*! \def MAX_STUDENT_ADDRESS
    \brief Returns a maximum of address.
*/

/*! \def FILE_HEADER_SIZE
    \brief Returns a size of a file header.
*/

#pragma once

#define MAX_YR  9999
#define MIN_YR  1900
#define MAX_SIZE_USER_NAME 30
#define MAX_SIZE_PASSWORD  20
#define FILE_NAME  "BorrowedBookBase.bin"
#define FILE_NAME_LOGIN "LoginBase.bin"
#define FILE_NAME_LIBRARY_BASE "LibraryBase.bin"
// Macro related to the books info
#define MAX_BOOK_NAME   50
#define MAX_AUTHOR_NAME 50
#define MAX_STUDENT_NAME 50
#define MAX_STUDENT_ADDRESS 300
#define FILE_HEADER_SIZE  sizeof(sFileHeader)

/**
 * @brief Used for storing date
 *
 * This structure storese a date when book was borrowed.
 */
typedef struct
{
    int yyyy;   /**< Year. */
    int mm;     /**< Month. */ 
    int dd;     /**< Day. */
} Date;

/**
 * @brief Used for storing login/pass
 *
 * This structure storese login and password of a user.
 */
typedef struct
{
    char username[MAX_SIZE_USER_NAME];  /**< Username. */
    char password[MAX_SIZE_PASSWORD];   /**< Password. */
} sFileHeader;

/**
 * @brief Used for storing book info
 *
 * This structure storese a information about a book.
 */
typedef struct
{
    unsigned int books_id;              /**< Id of book. */
    char bookName[MAX_BOOK_NAME];       /**< Title of book. */
    char authorName[MAX_AUTHOR_NAME];   /**< Author of book. */
} s_BooksInfo;

/**
 * @brief Used for storing borrowed book info
 *
 * This structure storese a information about a borrowed book.
 */
typedef struct
{
    s_BooksInfo bookInfo;                   /**< Info about book. */
    char studentName[MAX_STUDENT_NAME];     /**< Student name. */
    char studentAddr[MAX_STUDENT_ADDRESS];  /**< Student adress. */
    Date bookIssueDate;                     /**< Date of borrowing. */
} s_BorrowedBookInfo;