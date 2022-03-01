void status_render(WINDOW *status, int id){
	wclear(status);
	box(status, 0, 0);
	switch(id){
		case 1:
			mvwprintw(status, 2, 2, "TOO SHORT");
			break;
		case 2:
			mvwprintw(status, 2, 2, "NOT A WORD IN THE LIST");
			break;
		case 3:
			mvwprintw(status, 2, 2, "YOU WON");
			break;
		case 4:
			mvwprintw(status, 2, 2, "YOU LOOSE");
			break;
		case 5:
			mvwprintw(status, 2, 2, "RANGE IS a-z");
			break;
	}
}
