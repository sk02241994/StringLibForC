#include <stdio.h>
#include <string.h>
#include "String.h"

int main(){
    String *str = init();
    str->strings = "Good buy moon man";
    printf("\nchar at \t-> %c\n", str->charAt(str, 3));
    printf("compare to \t-> %d\n", str->compareTo(str, "Good buy moon man"));
    printf("concat string to original string \t-> %s\n", str->concat(str, " Good buy moon man"));
    printf("contains \t-> %d\n", str->contains(str, "moon"));
    printf("ends with \t-> %d\n", str->endsWith(str, "man"));
    printf("hash code \t-> %l\n", str->hashCode(str->strings));
    printf("equals \t-> %d\n", str->equals(str, "Good buy moon man"));
    printf("equals ignore case \t-> %d\n", str->equalsIgnoreCase(str, "good buy moon man"));
    printf("to lower case \t-> %s\n", str->toLowerCase("GOOD BUY MOON MAN"));
    printf("to upper case \t-> %s\n", str->toUpperCase("good buy moon man"));
    printf("index of \t-> %d\n", str->indexOf(str, "buy"));
    printf("index of with start \t-> %d\n", str->indexOfWithStart(str, "buy", 2));
    printf("is empty \t-> %d\n", str->isEmpty(str));
    printf("last index of \t-> %d\n", str->lastIndexOf(str, "moon"));
    printf("last index of with start \t-> %d\n", str->lastIndexOfWithStart(str, "buy", 9));
    printf("replace characters \t-> %s\n", str->replaceChar(str->strings, 'o', '9'));
    printf("replace string \t-> %d\n", str->replaceString(str->strings, "moon", "goon"));

    printf("Split string : \n");
    Strings *splittedString = str->split(str->strings, " ");
    for(int i = 0; splittedString[i] != NULL; i++){
        printf("->\t %s\n", splittedString[i]);
    }
    printf("trimmed string \t-> %s\n", str->trim("         Hello world       "));
    printf("sub string \t -> %s\n", str->subString(str->strings, 2, 10));
    free(str);
    return 0;
}
