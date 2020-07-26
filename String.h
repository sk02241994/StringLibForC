#ifndef STRING_H
    #include <string.h>
#endif
#ifndef STDLIB_H
    #include <stdlib.h>
#endif
#ifndef MATH_H
    #include<math.h>
#endif



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
struct strStruct{
    Strings strings;
    char (*charAt)(String *self, int);
    int (*compareTo) (String *self, Strings);
    Strings (*concat) (String *self, Strings);
    int (*contains)(String *self, Strings);
    int (*endsWith)(String *self, Strings);
    long (*hashCode) (Strings);
    int (*equals) (String *self, Strings);
    int (*equalsIgnoreCase) (String *self, Strings);
    Strings (*toLowerCase) (Strings);
};

/*
    Method to initialize the default settings for struct.
*/
String *init();
