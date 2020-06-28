#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
FILE* dictionary;
if(argc > 1) {
dictionary = fopen(argv[1], "r");
}else {
dictionary = fopen("dictionary.txt", "r");
}
if(dictionary == 0) {
fprintf(stderr, "error: unable to open dictionary file\n");
return 1;
}
printf("reading: \n");
char str[] = "hello!\0";
while(fgets(str, 30, dictionary) != 0) {
printf("%s ", str);
}
return 0;
}