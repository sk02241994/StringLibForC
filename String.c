#include "String.h"

/*
    Method to replace characters in a string.
*/
Strings replace_char(Strings str, char replaceFromChar, char charToReplace ){
    Strings resultString = (Strings)malloc(sizeof(char) * strlen(str));
    strcpy(resultString, str);
    for(int i = 0; resultString[i] != '\0'; i++){
        if(resultString[i] == replaceFromChar){
            resultString[i] = charToReplace;
        }
    }
    return resultString;
}

/*
    Method to check if the string is empty ie has no characters in it.
*/
int is_empty(String *self){
    return strlen(self->strings) == 0 ? 1 : 0;
}

/*
    Method to find the last index of the string.
*/
int last_index_of_string(String *self, Strings stringToFind, int startPosition){
    int count = strlen(stringToFind);
    int i = startPosition == 0 ? strlen(self->strings) : startPosition;
    for(; i >= 0; i--){
        if(self->strings[i] == stringToFind[count-1]){
            count --;
        }
        if(count == 0){
            break;
        }
    }
    return i;
}

/*
    Method to find the last index of the string given the start position.
*/
int last_index_of_with_start(String *self, Strings stringToFind, int startPosition){
    return last_index_of_string(self, stringToFind, startPosition);
}

/*
    Method to find the last index string mentioned.
*/
int last_index_of(String *self, Strings stringToFind){
    return last_index_of_string(self, stringToFind, 0);
}

/*
    Method to find the index of the substring
*/
int index_of_string(String *self, Strings stringToFind, int startPosition){
    int count = 0;
    int i = 0;
    int stringToFindLen = strlen(stringToFind);
    for(i = startPosition; self->strings[i] != '\0'; i++){
        if(self->strings[i] == stringToFind[count]){
            count++;
        }
        if(count == stringToFindLen){
            break;
        }
    }

    if(count != stringToFindLen){
        return -1;
    }
    return (i - stringToFindLen + 1);
}

/*
    Method to find the index of the substring starting from the desired position.
*/
int index_of_with_start(String *self, Strings stringToFind, int startPosition){
    return index_of_string(self, stringToFind, startPosition);
}

/*
    Method to find the index of the substring starting from initial position.
*/
int index_of(String *self, Strings stringToFind){
    return index_of_string(self, stringToFind, 0);
}

/*
    Method to generate hash code for the given string.
*/
long hash_code(const Strings string){
    long hash = 0;
    int stringLength = strlen(string);
    if((hash == 0) &&  stringLength > 0){
        char arr[stringLength];
        strcpy(arr, string);
        for(int i = 0; i < stringLength + 1; i++){
            hash = 31 * hash + arr[i];
        }
    }
    return hash;
}

/*
    Method to convert string to lower case.
*/
Strings to_lower(Strings string){
    int stringLength = strlen(string);
    if(stringLength == 0){
        return (Strings)-1;
    }
    Strings s = (Strings) malloc(sizeof(char) * stringLength + 1);
    strcpy(s, string);
    for(int i = 0; i < stringLength + 1; i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = s[i] + 32;
        }
    }
    return s;
}

/*
    Method to compare strings ignoring the case of string.
*/
int equals_ignore_case(String *self, Strings string){
    return hash_code(to_lower(self->strings)) - hash_code(to_lower(string));
}

/*
    Method to check if the entered string are equal.
*/
int is_equal(String *self, Strings string){
    return hash_code(self->strings) - hash_code(string);
}

/*
    Method to check if the given string ends with
    given sub-string.
*/
int end_with(String *self, Strings string){
    int m = strlen(self->strings);
    int n = strlen(string);
    int flag = -1;
    int count = n;
    for(int i = m; i >=0; i--){
        if(self->strings[i] == string[count]){
            count--;
        }else{
            count = n;
        }
        if(count == 0){
            flag = 1;
            break;
        }
    }
    return (flag == 1) ? 1 : 0;
}

/*
    Method to check if the string contains certain sub-string
*/
int does_contains(String *self, Strings string){
    int m = strlen(self->strings);
    int n = strlen(string);
    int flag = -1;
    int count = 0;
    for(int i = 0; i < m; i++){
        if(self->strings[i] == string[count]){
            count++;
        }else{
            count = 0;
        }
        if(count == n){
            flag = 1;
            break;
        }
    }
    return (flag == 1) ? 1 : 0;
}

/*
    Method to concat strings if the size is found to be 0, it will return -1.
*/
Strings concat_string (String *self, Strings string){
    int i = strlen(string);
    Strings charArr = (Strings)malloc(sizeof(char)*(strlen(self->strings) + i + 1));
    if((NULL == charArr) || (0 == i)){
        return (Strings)-1;
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
int get_compare_to(String *self, Strings string){
    int i = strlen(self->strings);
    int j = strlen(string);
    char arr1[i];
    char arr2[j];
    strcpy(arr1, self->strings);
    strcpy(arr2, string);
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
char get_char_at(String *self, int index){
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
    s->charAt = &get_char_at;
    s->compareTo = &get_compare_to;
    s->concat = &concat_string;
    s->contains = &does_contains;
    s->endsWith = &end_with;
    s->hashCode = &hash_code;
    s->equals = &is_equal;
    s->equalsIgnoreCase = &equals_ignore_case;
    s->toLowerCase = &to_lower;
    s->indexOf = &index_of;
    s->indexOfWithStart = &index_of_with_start;
    s->isEmpty = &is_empty;
    s->lastIndexOf = &last_index_of;
    s->lastIndexOfWithStart = &last_index_of_with_start;
    s->replaceChar = &replace_char;
    return s == NULL ? NULL : s;
}

