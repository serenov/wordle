//#include<stdio.h>
//short select_a_word();
void check_the_word(char *gword, char *sword, short *status){
	for(int i = 0; i < 5; i++){
		*(status + i) = (*(gword + i) == *(sword + i))? 0: 2;
	}
	short is_mapped[5] = {0};
	for(int i = 0; i < 5; i++){
		if(*(status + i)){ 
			for(int j = 0; j < 5; j++){
				if(*(status + j) && !is_mapped[j]){
					if(*(sword + j) == *(gword + i)){
						*(status + i) = 1;
						is_mapped[j] = 1;
						break;
					}
				}
			}
		}
	}
}
/*
int main(){
	char sword[] = "bloke";
	char gword[] = "slope";
	short status[5] = {0};
	check_the_word(gword, sword, status);
	for(int i = 0; i < 5; i++)printf("%d\n", status[i]);
	return 0;
}
*/
