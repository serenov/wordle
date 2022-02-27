#include"include.h"
void init(){
	initscr();
	refresh();
	cbreak();
	noecho();
}
void dest(){
	endwin();
}
void del_box(WINDOW *status[]){
	for(int i = 0; i < 5; i++)delwin(status[i]);
}
void drawboxes(WINDOW *cell[]){
	for(int i = 0; i < 5; i++){ 
		box(cell[i], 0, 0);
		wrefresh(cell[i]);
	}
	wmove(cell[0], 1, 2);
	wrefresh(cell[0]);
}
void clearbox(WINDOW *cell[]){
	for(int i = 0; i < 5; i++) wclear(cell[i]);
}
void render(WINDOW *cell[], char c[], int a){
	clearbox(cell);
	drawboxes(cell);
	for(int i = 0; i < a; i++){mvwprintw(cell[i], 1, 2, "%c", c[i]); wrefresh(cell[i]);} 
}
int main(){
	init();
	
	char selectw[6], guessw[] = "     ", temp;
	randoms(selectw);
	FILE *fp = fopen("allowed_words.txt", "r");
	short statusw[5] = {0}, game = 1;

	WINDOW *cell[5];
	for(int i = 0; i < 5; i++)cell[i] = newwin(3, 5, 0, i * 5 + 1);
	
	WINDOW *status = newwin(4, 90, 18, 0);
	box(status, 0, 0);	
	wrefresh(status);

	drawboxes(cell);
	while(game){
		game = 0;
		for(int i = 0;;){
			temp = getch();
			if(temp == 10){ 
				if(i > 4){
					if(search(fp, guessw, 1, size))break; 
					wprintw(status, "NOT A WORD IN LIST!");
					wrefresh(status);
				}
				else{
					mvwaddstr(status, 1, 2, "TOO SHORT!!"); wrefresh(status);
				}
			}
			else if(temp == 127 || temp == 8)i = (i == 0)? 0: i - 1;
			else if(i > 4 || temp < 97 || temp > 123);
			else{ 
				guessw[i] = temp; 
				i++;
			}
			render(cell, guessw, i);
		}
		check_the_word(guessw, selectw, statusw);
		
		for(int i = 0; i < 5; i++){
			if(statusw[i] > 0) game = 1;
			wprintw(status, "%d ", statusw[i]); 
			wrefresh(status);
		}
	}
		
	wprintw(status, "%s\n", selectw);
	wrefresh(status);
	
	getch();
	
	del_box(cell);
	fclose(fp);
	
	dest();
	
	return 0;
}
