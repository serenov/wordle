int constraints(char temp, char guessw[], int *x){
	FILE *fp = fopen("allowed_words.txt", "r");
	if(temp == 10){  
		if((*x) > 4){ 
			if(search(fp, guessw, 1, size))return 0;  
			return 2;
		} 
		else return 1;
	}
	else if(temp == 127 || temp == 8)*x = ((*x) == 0)? 0: (*x) - 1;
	else if((*x) > 4 || temp < 97 || temp > 123) return 5;
	else{ 
		guessw[*x] = temp; 
		(*x)++;
	}
	fclose(fp);
	return 6;
}
void drawboxes(WINDOW *cell[]){
        for(int i = 0; i < 5; i++){
                box(cell[i], 0, 0);
                wrefresh(cell[i]);
        }
        wmove(cell[0], 1, 2);
        wrefresh(cell[0]);
}
void clear_cells(WINDOW *cell[]){
        for(int i = 0; i < 5; i++) wclear(cell[i]);
}
void render_cells_colors(WINDOW *cell[], char c[], short statusw[]){
        clear_cells(cell);
        //drawboxes(cell);
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_GREEN);
	init_pair(2, COLOR_WHITE, COLOR_YELLOW);
	init_pair(3, COLOR_WHITE, COLOR_BLACK);
	move(1, 49);
	for(int i = 0; i < 5; i++){
		//wattron(cell[i], COLOR_PAIR(statusw[i]));
		printw("%d ", statusw[i]);
		wbkgd(cell[i], COLOR_PAIR(statusw[i] + 1));
		mvwprintw(cell[i], 1, 2, "%c", c[i]); wrefresh(cell[i]);
	}
}
void render_cells(WINDOW *cell[], WINDOW *status, char c[], int a){
        clear_cells(cell);
        drawboxes(cell);
	wrefresh(status);
        for(int i = 0; i < a; i++){mvwprintw(cell[i], 1, 2, "%c", c[i]); wrefresh(cell[i]);} 
}
void input(char guessw[], WINDOW *cell[], WINDOW *status){
	char temp;
	for(int i = 0;;){ 
		temp = getch(); 
		temp = constraints(temp, guessw, &i);
		status_render(status, temp);
		render_cells(cell, status, guessw, i);
		if(temp == 0) break;
	}
}
