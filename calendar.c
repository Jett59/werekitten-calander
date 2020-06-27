#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomSeed(int*result) {
int seed = (time(0)*time(0))>>(time(0)+time(0)/time(0)+512);
if(result != 0){
*result = seed;
}
return seed;
}

int main() {
FILE* output;
output = fopen("output.log", "a+");
if(output == 0) {
output = fopen("output.log", "w+");
printf("openning in write mode because append was null\n");
}
if(output == 0) {
fprintf(stderr, "error while opening file");
return -1;
}
fprintf(output, "generating random numbers:\n\n");

int seed = 0;
randomSeed(&seed);
srand(seed);
for(int i = 0; i < 100; i++){
fprintf(output, "%d ", rand());
}
fprintf(output, "\n");
fclose(output);
}