#ifndef _HTML__H_
#define _HTML__H_

// FILE: html.h
//
// Functions to grab the next URL and parse HTML
//
// HTML parser utility implementation
// see html.h for detail usage

// This is a html parser to retrieve URLs from a html page.
//
// html:           The html data to be parsed,
// urlofthispage:  The current absolute URL path of the HTML page passed in by html. 
//                 Since many websites use relative paths in their webpages,  
//                 we need the absolute URL as output. Thus, we require the current url.
//                 to be able to fix those relative path'ed URL's.
// result:         The result URL will be written in this buffer. 
//                 Users should allocate it and set it to zero before calling this function.
// pos:            The position in the HTML where we should begin parsing.
//
// returns:        1 + the pos of the new founded URL in HTML, -1 if end of doc is reached.
// warning:        Sometimes return an empty result which means a URL path we cannot understand 
//                 For example:  "../../a.html".

// Usage Example  (retrieve all URL in a page)
// int pos = 0;
// char result[1000];
// BZERO(result, 1000);
// while ((pos = GetNextURL(html, urlofthispage, result, pos)) > 0) {
//     /* DO SOMETHING WITH THE RESULT URL */
//     BZERO(result, 1000);
// }
//
// Here you retrieve all the URLs from the documents. One URL in each loop.
// warning:  Make sure that every time you call this, you've BZEROed the result buffer.
// warning:  Make sure result buffer is big enough to hold any URL up to our max length.
int GetNextURL(char* html, char* urlofthispage, char* result, int pos);

//  normalize URL 
// 
// URL:    url to be normalized
// return: 1 if this url is pure text format (html/php/jsp), 0 if it is of other type (pdf/jpg........)
//
int NormalizeURL(char* URL);

//Description: Removes the white space characters from the input
//string buffer that contains the html content. This function
//basically scans through the entire html buffer content character
//by character, and abandons any white space character it encounters.
//The ASCII code of the characters are used to determine whether
//a character is a white space or not; Characters with ASCII code
//values below 32 are considered white space characters, and are
//thus removed.
void removeWhiteSpace(char *html);

#if 0  // This should be isalpha() from the standard <ctype.h> library!
       // So, we'll reimplement IS_ALPHA(c) as isalpha() so as not to disturb anything.
#define IS_ALPHA(c) ((('a'<=(c))&&((c)<='z'))||(('A'<=(c))&&((c)<='Z'))) 
#else
#include <ctype.h>
#define IS_ALPHA(c)  isalpha(c)
#endif
#endif
