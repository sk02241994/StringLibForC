#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


/*
    Type defs for char pointer
*/
typedef char * Strings;

/*
    Type def for structs
*/
typedef struct strStruct String;

/*
    Struct setup includes string and methods associated with it
    1. charAt -> to get character at specified index
*/
struct strStruct {
  char (*charAt)(Strings, int);
  int (*compareTo)(Strings, Strings);
  Strings(*concat)(Strings, Strings);
  int (*contains)(Strings, Strings);
  int (*endsWith)(Strings, Strings);
  long (*hashCode)(Strings);
  int (*equals)(Strings, Strings);
  int (*equalsIgnoreCase)(Strings, Strings);
  Strings(*toLowerCase)(Strings);
  Strings(*toUpperCase)(Strings);
  int (*indexOf)(Strings, Strings);
  int (*indexOfWithStart)(Strings, Strings, int);
  int (*isEmpty)(Strings);
  int (*lastIndexOf)(Strings, Strings);
  int (*lastIndexOfWithStart)(Strings, Strings, int);
  Strings(*replaceChar)(Strings, char, char);
  Strings(*replaceString)(Strings, Strings, Strings);
  Strings *(*split)(Strings, Strings);
  Strings (*trim) (Strings);
  Strings (*subString) (Strings, int, int);
};

/*
    Method to initialize the default settings for struct.
*/
String *init();
