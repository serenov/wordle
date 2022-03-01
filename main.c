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

void del_box(WINDOW *cell[][5]){
	for(int i = 0; i < 6; i++)for(int j = 0; j < 5; j++)delwin(cell[i][j]);
}

int gameOn(short statusw[], WINDOW *status){
	for(int i = 0; i < 5; i++){
		if(statusw[i] > 0) return 1; 
	}
	status_render(status, 3);
	return 0;
}

int main(){
	init();
	start_color();
	char selectw[6];
	char guessw[][6] = {"     \0", "     \0", "     \0", "     \0", "     \0"};
	
	randoms(selectw);
	short statusw[5] = {2};
	WINDOW *cell[6][5];
	
//	mvprintw(0, 40, "%s\n", selectw);
	
	for(int j = 0; j < 6; j++)for(int i = 0; i < 5; i++){
		cell[j][i] = newwin(3, 5, 3 * j + 1 , i * 5 + 1);
	}

	for(int j = 5; j > -1; j--)drawboxes(cell[j]);

	WINDOW *status = newwin(5, 90, 20, 0);
	box(status, 0, 0);	
	wrefresh(status);

	for(int j = 0; (gameOn(statusw, status)) && j < 6;){
		if(j > 0)render_cells_colors(cell[j - 1], guessw[j - 1], statusw);
		input(guessw[j], cell[j], status);
		check_the_word(guessw[j], selectw, statusw);
		j++;
	}
		
	getch();	
	

	del_box(cell);
	
	dest();
	
	return 0;
}
