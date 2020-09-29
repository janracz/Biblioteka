/*! \file ValidationFunction.c
    \brief Validation Functions

    File contains functions used to validate.
*/
#include "Functions.h"

/**
 * @brief Check name
 *
 * This function checks if name is valid.
 * @param name A name to check
 */
int isNameValid(const char* name)
{
    int validName = 1;
    int len = 0;
    int index = 0;
    len = strlen(name);
    for (index = 0; index < len; ++index)
    {
        if (!(isalpha(name[index])) && (name[index] != '\n') && (name[index] != ' '))
        {
            validName = 0;
            break;
        }
    }
    return validName;
}


/**
 * @brief Check year
 *
 * This function checks if year is a leap year.
 * @param year A year to check
 */
int  isLeapYear(int year)
{
    return (((year % 4 == 0) &&
        (year % 100 != 0)) ||
        (year % 400 == 0));
}


/**
 * @brief Check date
 *
 * This function checks if date is valid.
 * @param validDate A date to check
 */
int isValidDate(Date* validDate)
{
    //check range of year,month and day
    if (validDate->yyyy > MAX_YR ||
        validDate->yyyy < MIN_YR)
        return 0;
    if (validDate->mm < 1 || validDate->mm > 12)
        return 0;
    if (validDate->dd < 1 || validDate->dd > 31)
        return 0;
    //handle feb days in leap year
    if (validDate->mm == 2)
    {
        if (isLeapYear(validDate->yyyy))
            return (validDate->dd <= 29);
        else
            return (validDate->dd <= 28);
    }
    //handle months which has only 30 days
    if (validDate->mm == 4 || validDate->mm == 6 ||
        validDate->mm == 9 || validDate->mm == 11)
        return (validDate->dd <= 30);
    return 1;
}

/**
 * @brief Check file
 *
 * This function checks if file exist.
 * @param path A path where file should be
 */
int isFileExists(const char* path)
{
    // Try to open file
    FILE* fp = fopen(path, "rb");
    int status = 0;
    // If file does not exists
    if (fp != NULL)
    {
        status = 1;
        // File exists hence close file
        fclose(fp);
    }
    return status;
}


/**
 * @brief Check if empty
 *
 * This function checks if string consist of empty signs.
 * @param s A string to check
 */
int is_empty(const char* s) 
{
    if (*s == '\n')
    {
        return 1;
    }
    while (*s != '\n') {
        if (!isspace((unsigned char)*s))
            return 0;
        s++;
    }
    return 1;
}