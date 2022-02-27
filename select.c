int search(char *guess, short start, short end){
	FILE *fp =  fopen("allowed_words.txt", "r");
	if(start < 0|| end < 0 || start > size || end > size) return 0;
	char select[5];
	short mid = (start + end) / 2;
	fseek(fp, 6 * (mid - 1), SEEK_SET);
	fscanf(fp, "%s", select);
	if(end == start){ for(short i = 0; i < 5; i++) if(select[i] != guess[i]) return 0;}
	else{
		for(short i = 0; i < 5; i++){
			if(select[i] > guess[i]) return search(guess, start, mid - 1);
			if(select[i] < guess[i]) return search(guess, mid + 1, end);
		}
	}
	fclose(fp);
	return 1;
}
/*
int main() {
	fp = fopen("allowed_words.txt", "r");
	char guess[] = "cameo";
	printf("%d\n", search( guess, 1, size));
	printf("%d\n", count);
	return 0;
}
*/
