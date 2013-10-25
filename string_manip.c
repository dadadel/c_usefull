/** 
 *  Author: A. Daouzli - Copyright 2013
 *  Licence: GPL v3
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void lowercase(char *s); /** changes a string to lower case */
void uppercase(char *s); /** changes a string to upper case */
void strip(char *s); /** removes external spaces and newline characters from a string */
int search_pattern(const char *s, const char *pattern); /** searchs a pattern in a string */

/** Convert a string to lower case
 *
 * \param [in|out] s The string to convert
 */
void lowercase(char *s)
{
    int i;
    for(i=0 ; i < strlen(s) ; i++)
    {
        s[i]=tolower(s[i]);
    }
}

/** Convert a string to upper case
 *
 * \param [in|out] s The string to convert
 */
void uppercase(char *s)
{
    int i;
    for(i=0 ; i < strlen(s) ; i++)
    {
        s[i]=toupper(s[i]);
    }
}



/** Removes starting and ending spaces.
 *
 * \param [in|out]s The string to strip.
 *
 */
void strip(char *s)
{
    int i;
    int start = -1, end = -1;
    int slen = strlen(s);

    /* Find the first non space character */

    for (i = 0; i < slen; i++)
    {
        if ( !isspace(s[i]) )
        {
            start = i;
            break;
        }
    }

    /* Find the last non space character */

    for (i = slen - 1 ; i >= 0 ; i--)
    {
        if ( !isspace(s[i]) )
        {
            end = i;
            break;
        }
    }
    if ( end != -1 )
    {
        s[end + 1] = '\0';
    }
    else
    {
        /* only space characters */
        if (start == -1)
        {
            s[0] = '\0';
        }
        else
        {
            end = slen - 1;
        }
    }
    
    /* Move the characters to the left in place of spaces */

    if ( start > 0 )
    {
        for ( i = 0 ; i <= (end-start) + 1 ; i++ )
        {
            s[i] = s[i + start];
        }
    }
}

/** Search a pattern in a string.
 *
 * \param [in] s The string where to search the pattern.
 * \param [in] pattern The pattern to search
 *
 * \return The index (starting at 0) of the starting of the pattern into the string.
 * \retval -1 The pattern was not found.
 */
int search_pattern(const char *s, const char *pattern)
{
    char *srch;
    srch = strstr(s, pattern);
    if ( srch == NULL)
        return -1;
    else
        return (int)(srch - s);
}

