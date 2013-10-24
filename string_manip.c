/** 
 *  Author: A. Daouzli - Copyright 2013
 *  Licence: GPL v3
 *
 */
#include <ctype.h>
#include <string.h>

void strip(char *s); /** removes external spaces and newline characters from a string */


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

