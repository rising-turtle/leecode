
#include <iostream>
#include <string.h>
#include "str_two_way.h"

using namespace std; 

#ifndef _LIBC
// # include <config.h>
#endif
/* Specification of strstr.  */
#include <string.h>
#include <stdbool.h>

// #define RETURN_TYPE char *


char* str_str(const char *haystack, const char *needle);
extern size_t __strnlen (const char *str, size_t maxlen);

int main(int argc, char* argv[])
{

	const char* haystack = "ccdefabbbcdabbcdabbbbbbbb";
	const char* needle = "abcdeabcdeabcde";//"abcababc"; 
	str_str(haystack, needle); 

	return 0; 
}

char* str_str(const char *haystack, const char *needle){

	size_t needle_len; /* Length of NEEDLE.  */
	size_t haystack_len; /* Known minimum length of HAYSTACK.  */
	/* Handle empty NEEDLE special case.  */
	if (needle[0] == '\0')
	return (char *) haystack;
	/* Skip until we find the first matching char from NEEDLE.  */
	haystack = strchr (haystack, needle[0]);
	if (haystack == NULL || needle[1] == '\0')
	return (char *) haystack;

	cout<< "haystack = "<<haystack<<" needle = "<<needle<<endl; 
	/* Ensure HAYSTACK length is at least as long as NEEDLE length.
	 Since a match may occur early on in a huge HAYSTACK, use strnlen
	 and read ahead a few cachelines for improved performance.  */
	needle_len = strlen (needle);
	haystack_len = __strnlen (haystack, needle_len + 256);
	if (haystack_len < needle_len)
	return NULL;
	cout<<" needle_len = "<<needle_len<<" haystack_len = "<<haystack_len<<endl; 
	/* Check whether we have a match.  This improves performance since we avoid
	 the initialization overhead of the two-way algorithm.  */
	if (memcmp (haystack, needle, needle_len) == 0)
	return (char *) haystack;
	/* Perform the search.  Abstract memory is considered to be an array
	 of 'unsigned char' values, not an array of 'char' values.  See
	 ISO C 99 section 6.2.6.1.  */
	if (needle_len < LONG_NEEDLE_THRESHOLD)
	return two_way_short_needle ((const unsigned char *) haystack,
	                             haystack_len,
	                             (const unsigned char *) needle, needle_len);
	return two_way_long_needle ((const unsigned char *) haystack, haystack_len,
	                          (const unsigned char *) needle, needle_len);	

}