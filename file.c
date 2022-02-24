#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define upper 2314
void randoms(FILE *fp, char *buff){
	srand(time(0));	
	for(int i = 0; i < 6; i++){
		fseek( fp, 6 * (rand() % (upper + 1)), SEEK_SET );
		fscanf(fp, "%s", buff);
	}
}
int main() {

	FILE *fp = fopen("possible_words.txt", "r");
	char buff[5];
	randoms(fp, buff);
	printf("%s\n", buff);
	return 0;
}
