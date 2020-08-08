#include <stdio.h>
#include <string.h>
#include "String.h"

int main(){
    String *str = init();
    Strings ss = "Good buy moon man";
    printf("\nchar at \t-> %c\n", str->charAt(ss, 3));
    printf("compare to \t-> %d\n", str->compareTo(ss, "Good buy moon man"));
    printf("concat string to original string \t-> %s\n", str->concat(ss, " Good buy moon man"));
    printf("contains \t-> %d\n", str->contains(ss, "moon"));
    printf("ends with \t-> %d\n", str->endsWith(ss, "man"));
    printf("hash code \t-> %ld\n", str->hashCode(ss));
    printf("equals \t-> %d\n", str->equals(ss, "Good buy moon man"));
    printf("equals ignore case \t-> %d\n", str->equalsIgnoreCase(ss, "good buy moon man"));
    printf("to lower case \t-> %s\n", str->toLowerCase("GOOD BUY MOON MAN"));
    printf("to upper case \t-> %s\n", str->toUpperCase("good buy moon man"));
    printf("index of \t-> %d\n", str->indexOf(ss, "buy"));
    printf("index of with start \t-> %d\n", str->indexOfWithStart(ss, "buy", 2));
    printf("is empty \t-> %d\n", str->isEmpty(ss));
    printf("last index of \t-> %d\n", str->lastIndexOf(ss, "moon"));
    printf("last index of with start \t-> %d\n", str->lastIndexOfWithStart(ss, "buy", 9));
    printf("replace characters \t-> %s\n", str->replaceChar(ss, 'o', '9'));
    printf("replace string \t-> %d\n", str->replaceString(ss, "moon", "goon"));

    printf("Split string : \n");
    Strings *splittedString = str->split(ss, " ");
    for(int i = 0; splittedString[i] != NULL; i++){
        printf("->\t %s\n", splittedString[i]);
    }
    printf("trimmed string \t->%s\n", str->trim("         Hello world       "));
    printf("sub string \t -> %s\n", str->subString(ss, 2, 10));
    free(str);
    return 0;
}
