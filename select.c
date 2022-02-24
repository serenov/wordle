#include <stdio.h>
#define size 12973
char guess[] = "cameo";
char select[5];
short count = 0;

int search(FILE *fp, short start, short end){
	count++;
	if(start < 0|| end < 0 || start > size || end > size) return 0;
	short mid = (start + end) / 2;
	fseek(fp, 6 * (mid - 1), SEEK_SET);
	fscanf(fp, "%s", select);
	if(end == start){ for(short i = 0; i < 5; i++) if(select[i] != guess[i]) return 0;}
	else{
		for(short i = 0; i < 5; i++){
			if(select[i] > guess[i]) return search(fp, start, mid - 1);
			if(select[i] < guess[i]) return search(fp, mid + 1, end);
		}
	}

	return 1;

}
int main() {
	FILE *fp = fopen("allowed_words.txt", "r");
	printf("%d\n", search(fp, 1, size));
	printf("%d\n", count);
	return 0;
}
