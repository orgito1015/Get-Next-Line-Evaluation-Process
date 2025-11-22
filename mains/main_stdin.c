#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
int main(void){char*l;while((l=get_next_line(0))){printf("STDIN: %s",l);free(l);}}
