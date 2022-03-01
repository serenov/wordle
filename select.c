/*#include<stdio.h>
#define size 12974
int count = 0;*/
int search(FILE *fp, char *guess, short start, short end){
	if(start < 0|| end < 0 || start > size || end > size) return 0;
	char select[6];
	short mid = (start + end) / 2;
	fseek(fp, 6 * (mid - 1), SEEK_SET);
	//printf("%d\n", end);
	fscanf(fp, "%s", select);
	//printf("start: %d, end: %d, mid: %d, string: %s\n", start, end, mid, select);
	if(end <= start){ for(short i = 0; i < 5; i++) if(select[i] != *(guess + i)) return 0;}
	else{
		for(short i = 0; i < 5; i++){
			if(select[i] > *(guess + i)) return search(fp, guess, start, mid - 1);
			if(select[i] < *(guess + i)) return search(fp, guess, mid + 1, end);
		}
	}
	return 1;
}
/*
int main() {
	char guess[] = "lands";
	FILE *fp =  fopen("allowed_words.txt", "r");
	printf("%d\n", search(fp, guess, 1, size));
	guess[0] = 'l';
	guess[1] = 'a';
	guess[2] = 'n';
	guess[3] = 'd';
	guess[4] = 's';
	printf("%d\n", search(fp, guess, 1, size));
	//printf("%d\n", count);
	return 0;
}
*/
