void randoms(char *buff){
	FILE *fp = fopen("possible_words.txt", "r");
	srand(time(0));	
	fseek( fp, 6 * (rand() % (upper + 1)), SEEK_SET );
	fscanf(fp, "%s", buff);
	*(buff + 5) = '\0';
	fclose(fp);
}
/*
int main() {

	char buff[5];
	randoms(buff);
	printf("%s\n", buff);
	return 0;
}
*/
