#include <stdio.h>
#include <stdlib.h>

typedef struct String {
char* chars;
int length;
} String;

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
String* words = malloc(wordCount*sizeof(String));
void* wordsAnkor = (void*)words;
char* chars = malloc(fileLength*sizeof(char));
void* charsAnkor = (void*)chars;
words->chars = chars;
int wordLength = 0;
while((*chars = getc(dictionary)) != -1) {
if(*chars == '\n') {
*chars = '\0';
words->length = wordLength;
words++;
words->chars = chars+1;
wordLength = 0;
}else {
wordLength++;
}
chars++;
}
*chars = '\0';
words->length = wordLength;
chars = (char*)charsAnkor;
words = (String*)wordsAnkor;
for(int i = 0; i < wordCount; i++) {
printf("%s %d ", words->chars, words->length);
words++;
}
printf("\n");
words = (String*)wordsAnkor;
free(chars);
free(words);
return 0;
}