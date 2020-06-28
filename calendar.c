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
unsigned int fileLength = 0;
unsigned int wordCount = 1;
char currentChar = 0;
while((currentChar = getc(dictionary)) != -1) {
fileLength++;
if(currentChar == '\n') {
wordCount++;
}
}
rewind(dictionary);
char** words = malloc(wordCount*sizeof(char*));
void* wordsAnkor = (void*)words;
char* chars = malloc(fileLength*sizeof(char));
void* charsAnkor = (void*)chars;
*words = chars;
words++;
while((*chars = getc(dictionary)) != -1) {
if(*chars == '\n') {
*chars = '\0';
*words = chars+1;
words++;
}
chars++;
}
*chars = '\0';
chars = (char*)charsAnkor;
words = (char**)wordsAnkor;
for(int i = 0; i < wordCount; i++) {
printf("%s ", *words);
words++;
}
printf("\n");
words = (char**)wordsAnkor;
free(chars);
free(words);
return 0;
}