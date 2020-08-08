#include "String.h"

/*
    Method to find the substring of given string.
*/
static Strings sub_string(Strings str, int start, int end){
    Strings result = (Strings)malloc(sizeof(char) * (end - start));
    if(result == NULL) {
        return result;
    }
    int j = 0;
    for(int i = start; i < end; i++){
        result[j++] = str[i];
    }
    result[j] = '\0';
    return result;
}

/*
    Method to remove extra white space that is before or after the entered string.
*/
static Strings trim_string(Strings str) {
  int i = strlen(str);
  int j = 0;
  while((j < i) && str[j] <= ' '){
    j++;
  }
  while((j < i) && str[i-1] <= ' '){
    i--;
  }
  return j > 0 || i < strlen(str) ? sub_string(str, j, i) : str;
}

/*
    Method to find the number of words present after splitting.
*/
static int char_split_number(Strings str, Strings token) {
  int count = 0;
  Strings bufferArray = strdup(str);
  Strings tokenStr = strtok(bufferArray, token);
  while(tokenStr != NULL) {
    count++;
    tokenStr = strtok(NULL, token);
  }
  free(bufferArray);
  return count;
}

/*
    Method to split a string according to delimiters/tokes present and return array
    of strings this uses strtok to split the string.
*/
static Strings* split_string(Strings str, Strings token) {
  Strings *resultStrings = NULL;
  Strings bufferString = strdup(str);
  Strings tokenBuffer;
  int count = 0;

  resultStrings = (Strings *)malloc(sizeof(Strings) * (char_split_number(str, token) + 1));
  if(resultStrings == NULL){
    return resultStrings;
  }

  for(tokenBuffer = strtok(bufferString, token); tokenBuffer != NULL; count++) {
    resultStrings[count] = strdup(tokenBuffer);
    tokenBuffer = strtok(NULL, token);
  }
  free(bufferString);
  resultStrings[count] = NULL;
  return resultStrings;
}

/*
    Method to replace substring with provided string.
*/
static Strings replace_string(Strings str, Strings replaceFromString, Strings stringToReplace) {
  Strings result = NULL;
  int i, count = 0;
  int newStringLen = strlen(stringToReplace);
  int oldStringLen = strlen(replaceFromString);
  for(i = 0; str[i] != '\0'; i++) {
    if(strstr(&str[i], replaceFromString) == &str[i]) {
      count++;
      i += oldStringLen - 1;
    }
  }
  result = (Strings)malloc(i + count * (newStringLen - oldStringLen) + 1);
  if(result == NULL){
    return result;
  }
  i = 0;
  while(*str) {
    if(strstr(str, replaceFromString) == str) {
      strcpy(&result[i], stringToReplace);
      i += newStringLen;
      str += oldStringLen;
    } else {
      result[i++] = *str++;
    }
  }
  result[i] = '\0';
  return result;
}

/*
    Method to replace characters in a string.
*/
static Strings replace_char(Strings str, char replaceFromChar, char charToReplace) {
  Strings resultString = strdup(str);
  for(int i = 0; resultString[i] != '\0'; i++) {
    if(resultString[i] == replaceFromChar) {
      resultString[i] = charToReplace;
    }
  }
  return resultString;
}

/*
    Method to check if the string is empty ie has no characters in it.
*/
static int is_empty(Strings str) {
  return str[0] == '\0' ? 1 : 0;
}

/*
    Method to find the index of the occurrence of string from last.
*/
static int last_index_of_string(Strings str, Strings stringToFind, int startPosition) {
  int count = strlen(stringToFind);
  int i = startPosition == 0 ? strlen(str) : startPosition;
  for(; i >= 0; i--) {
    if(str[i] == stringToFind[count-1]) {
      count --;
    }
    if(count == 0) {
      break;
    }
  }
  return i;
}

/*
    Method to find the last index of the string given the start position.
*/
static int last_index_of_with_start(Strings str, Strings stringToFind, int startPosition) {
  return last_index_of_string(str, stringToFind, startPosition);
}

/*
    Method to find the last index string mentioned.
*/
static int last_index_of(Strings str, Strings stringToFind) {
  return last_index_of_string(str, stringToFind, 0);
}

/*
    Method to find the index of the substring
*/
static int index_of_string(Strings stringToFindFrom, Strings stringToFind, int startPosition) {
  int count = 0;
  int i = 0;
  int stringToFindLen = strlen(stringToFind);
  for(i = startPosition; stringToFindFrom[i] != '\0'; i++) {
    if(stringToFindFrom[i] == stringToFind[count]) {
      count++;
    }
    if(count == stringToFindLen) {
      break;
    }
  }

  if(count != stringToFindLen) {
    return -1;
  }
  return (i - stringToFindLen + 1);
}

/*
    Method to find the index of the substring starting from the desired position.
*/
static int index_of_with_start(Strings stringToFindFrom, Strings stringToFind, int startPosition) {
  return index_of_string(stringToFindFrom, stringToFind, startPosition);
}

/*
    Method to find the index of the substring starting from initial position.
*/
static int index_of(Strings stringToFindFrom, Strings stringToFind) {
  return index_of_string(stringToFindFrom, stringToFind, 0);
}

/*
    Method to generate hash code for the given string.
*/
static long hash_code(const Strings string) {
  long hash = 0;
  int stringLength = strlen(string);
  if((hash == 0) &&  stringLength > 0) {
    char arr[stringLength];
    strcpy(arr, string);
    for(int i = 0; i < stringLength + 1; i++) {
      hash = 31 * hash + arr[i];
    }
  }
  return hash;
}

/*
    Method to convert string to upper case.
*/
static Strings to_upper(Strings string) {
  int stringLength = strlen(string);
  if(stringLength == 0) {
    return (Strings)-1;
  }
  Strings s = (Strings) malloc(sizeof(char) * stringLength + 1);
  strcpy(s, string);
  for(int i = 0; i < stringLength + 1; i++) {
    if(s[i] >= 'a' && s[i] <= 'z') {
      s[i] = s[i] - 32;
    }
  }
  return s;
}

/*
    Method to convert string to lower case.
*/
static Strings to_lower(Strings string) {
  int stringLength = strlen(string);
  if(stringLength == 0) {
    return (Strings)-1;
  }
  Strings s = (Strings) malloc(sizeof(char) * stringLength + 1);
  strcpy(s, string);
  for(int i = 0; i < stringLength + 1; i++) {
    if(s[i] >= 'A' && s[i] <= 'Z') {
      s[i] = s[i] + 32;
    }
  }
  return s;
}

/*
    Method to compare strings ignoring the case of string.
*/
static int equals_ignore_case(Strings str, Strings string) {
  return hash_code(to_lower(str)) - hash_code(to_lower(string));
}

/*
    Method to check if the entered string are equal.
*/
static int is_equal(Strings str, Strings string) {
  return hash_code(str) - hash_code(string);
}

/*
    Method to check if the given string ends with
    given sub-string.
*/
static int end_with(Strings str, Strings string) {
  int m = strlen(str);
  int n = strlen(string);
  int flag = -1;
  int count = n;
  for(int i = m; i >=0; i--) {
    if(str[i] == string[count]) {
      count--;
    } else {
      count = n;
    }
    if(count == 0) {
      flag = 1;
      break;
    }
  }
  return (flag == 1) ? 1 : 0;
}

/*
    Method to check if the string contains certain sub-string
*/
static int does_contains(Strings str, Strings string) {
  int m = strlen(str);
  int n = strlen(string);
  int flag = -1;
  int count = 0;
  for(int i = 0; i < m; i++) {
    if(str[i] == string[count]) {
      count++;
    } else {
      count = 0;
    }
    if(count == n) {
      flag = 1;
      break;
    }
  }
  return (flag == 1) ? 1 : 0;
}

/*
    Method to concat strings if the size is found to be 0, it will return -1.
*/
static Strings concat_string(Strings str, Strings string) {
  int i = strlen(string);
  Strings charArr = (Strings)malloc(sizeof(char)*(strlen(str) + i + 1));
  if((NULL == charArr) || (0 == i)) {
    return (Strings)-1;
  }
  strcpy(charArr, str);
  strcat(charArr, string);
  return charArr;

}

/*
    Method to compare two strings lexicographically
    If  both strings are equal, 0 is returned else it returns
    positive or negative values.
*/
static int get_compare_to(Strings str, Strings string) {
  int i = strlen(str);
  int j = strlen(string);
  char arr1[i];
  char arr2[j];
  strcpy(arr1, str);
  strcpy(arr2, string);
  int k = (int) fmin(i,j);
  for(int m = 0; m < k; m++) {
    int n = arr1[m];
    int o = arr2[m];
    if(n != o) {
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
static char get_char_at(Strings str, int index) {
  if(str != NULL && (index > 0 && index <= strlen(str))) {
    return str[index - 1];
  }
  return -1;
}

/*
    Method to initialize the default values for String struct.
*/
String *init() {
  String *s = (String *) malloc(sizeof(String));
  s->charAt = &get_char_at;
  s->compareTo = &get_compare_to;
  s->concat = &concat_string;
  s->contains = &does_contains;
  s->endsWith = &end_with;
  s->hashCode = &hash_code;
  s->equals = &is_equal;
  s->equalsIgnoreCase = &equals_ignore_case;
  s->toLowerCase = &to_lower;
  s->toUpperCase = &to_upper;
  s->indexOf = &index_of;
  s->indexOfWithStart = &index_of_with_start;
  s->isEmpty = &is_empty;
  s->lastIndexOf = &last_index_of;
  s->lastIndexOfWithStart = &last_index_of_with_start;
  s->replaceChar = &replace_char;
  s->replaceString = &replace_string;
  s->split = &split_string;
  s->trim = &trim_string;
  s->subString = &sub_string;
  return s == NULL ? NULL : s;
}

