#ifndef	___MIME_H__
#define ___MIME_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Loads MIME-Types mappings from a mime.types-style file
 * @param file The mime.types file
 * @return 0, if successful, else value describing the error
 */
int mime_load(FILE * file);

/**
 * Get the MIME-Type typically associated with the file extention.
 * @param extention The file extention from which the MIME-Type shall be derived.
 * @return The associated MIME-Type
 */
const char * mime_get(const char * extention);

/**
 * Frees the loaded mappings
 */
void mime_unload();

#endif//___MIME_H__

