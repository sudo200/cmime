# CMIME

A simple library for converting file extentions to their MIME-type, based on the mappings from a mime.types-file

## Usage

1. Load a mime.types-file from a `FILE *` using `mime_load()`.
2. Convert file extentions like *.html* or *html* to their MIME-type (*text/html*).
3. Call `mime_unload()` to free all allocated memory.

## Example

See [test/main.c](test/main.c).

