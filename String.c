#include "String.h"

/*
    Method to concat strings if the size is found to be 0, it will return -1.
*/
Strings concatString (String *self, Strings string){
    int i = strlen(string);
    Strings charArr = (Strings)malloc(sizeof(char)*(strlen(self->strings) + i + 1));
    if((NULL == charArr) || (0 == i)){
        return -1;
    }
    strcpy(charArr, self->strings);
    strcat(charArr, string);
    return charArr;

}

/*
    Method to compare two strings lexicographically
    If  both strings are equal, 0 is returned else it returns
    positive or negative values.
*/
int getCompareTo(String *self, Strings str){
    int i = strlen(self->strings);
    int j = strlen(str);
    char arr1[i];
    char arr2[j];
    strcpy(arr1, self->strings);
    strcpy(arr2, str);
    int k = (int) fmin(i,j);
    for(int m = 0; m < k; m++){
        int n = arr1[m];
        int o = arr2[m];
        if(n != o){
            return n - o;
        }
    }
    return i - j;
}

/*
    Method to get character at specified index
    if the index is lower or equals than 0, there it will return 0
    if the index is out of bound it will return 0
    if there is no string is NULL, it will return 0.
*/
char getCharAt(String *self, int index){
    if(self->strings != NULL && (index > 0 && index <= strlen(self->strings))){
        return self->strings[index - 1];
    }
    return -1;
}

/*
    Method to initialize the default values for String struct.
*/
String *init(){
    String *s = (String *) malloc(sizeof(String));
    s->strings = NULL;
    s->charAt = &getCharAt;
    s->compareTo = &getCompareTo;
    s->concat = &concatString;
    return s;
}

