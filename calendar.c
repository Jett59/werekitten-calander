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
char* chars = malloc(1024*sizeof(char));
void* ankor = (void*)chars;
while((*chars = getc(dictionary)) != -1) {
chars++;
}
*chars = '\n';
chars = (char*) ankor;
printf("read: \n%s", chars);
free(ankor);
return 0;
}