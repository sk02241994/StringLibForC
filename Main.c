#include <stdio.h>
#include "String.h"


int main(){
    String *str = init();
    str->strings = "Hello world";
    printf("%d", str->compareTo(str, "Hello World"));
    return 0;
}
