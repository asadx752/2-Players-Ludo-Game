//#include<iostream>
//#include<windows.h>
//#include<conio.h>
//#include<cstdlib>
//#include<ctime>
//#include<cstdio>
//#include<fstream>
//#define RED_PLAYER 0
//#define YELLOW_PLAYER 1
//using namespace std;
//
////Variable to store player's name
//char playername[2][30];
//
////Token positions
//int tokenPos[2][4];
//int score[2] = { 0,0 };
//
////Path creation
//int path[52][2];
//
////Functions Prototypes
//void soundWin();
//int select_token(int current_player, int dice);
//void soundTokenMove();
//void soundCapture();
//void soundRolledSix();
//void initboard(char board[][15]);
//void displayboard(const char board[][15]);
//void drawtokens();
//
////Initializing the path for tokens
//void initpath() {
//	int index = 0;
//		// LEFT TO TOP
//		for (int col = 0; col <= 5; col++) {
//			path[index][0] = 6;
//			path[index][1] = col;
//			index++;
//		}
//
//		for (int row = 5; row >= 0; row--) {
//			path[index][0] = row;
//			path[index][1] = 6;
//			index++;
//		}
//
//		// TOP TO RIGHT
//		path[index][0] = 0;
//		path[index][1] = 7;
//		index++;
//
//		for (int row = 0; row <= 5; row++) {
//			path[index][0] = row;
//			path[index][1] = 8;
//			index++;
//		}
//
//		for (int col = 9; col <= 14; col++) {
//			path[index][0] = 6;
//			path[index][1] = col;
//			index++;
//		}
//
//		// RIGHT TO BOTTOM
//		path[index][0] = 7;
//		path[index][1] = 14;
//		index++;
//
//		for (int col = 14; col >= 9; col--) {
//			path[index][0] = 8;
//			path[index][1] = col;
//			index++;
//		}
//
//		for (int row = 9; row <= 14; row++) {
//			path[index][0] = row;
//			path[index][1] = 8;
//			index++;
//		}
//
//		// BOTTOM TO LEFT
//		path[index][0] = 14;
//		path[index][1] = 7;
//		index++;
//
//		for (int row = 14; row >= 9; row--) {
//			path[index][0] = row;
//			path[index][1] = 6;
//			index++;
//		}
//
//		for (int col = 5; col >= 0; col--) {
//			path[index][0] = 8;
//			path[index][1] = col;
//			index++;
//		}
//
//		// FINAL CELL
//		path[index][0] = 7;
//		path[index][1] = 0;
//}
//
////Setting color
//void color(int text_color,int bg_color) {
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text_color+bg_color);
//}
//
////Animation of token
//void gotoxy(int x, int y) {
//	COORD coord;
//	coord.X = x;
//	coord.Y = y;
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
//}
//
////Initializing the tokens
//void initializetokens() {
//	for (int player = 0;player < 2;player++) {
//		for (int token = 0;token < 4;token++) {
//			tokenPos [player][token] = -1;
//		}
//	}
//}
//
////Moving Token
//void movetoken(int player, int token, int dice, char board[15][15]) {
//	// Cannot move a token that is already finished
//	if (tokenPos[player][token] == 57) return;
//
//	if (tokenPos[player][token] == -1) {
//		if (dice == 6) {
//			tokenPos[player][token] = 1; // Both players now start at Step 1!
//			system("cls");
//			initboard(board);
//			displayboard(board); // Make sure you changed displayboard to drawBoard!
//			drawtokens();
//			gotoxy(0, 16);
//		}
//	}
//	else {
//		if (tokenPos[player][token] + dice > 57) {
//			cout << "\nNeeds exact roll to reach home!" << endl;
//			Sleep(1500);
//			return;
//		}
//
//		for (int step = 0; step < dice; step++) {
//			tokenPos[player][token]++;
//
//			if (tokenPos[player][token] == 57) {
//				score[player]++;       // Increments score
//				gotoxy(0, 16);
//				if (player == 0) {
//					color(12, 0); cout << playername[0]; color(7, 0);
//				}
//				else {
//					color(14, 0); cout << playername[1]; color(7, 0);
//				}
//				cout << "'s token reached home! Score: " << score[player] << "/4          "<< endl;
//				soundWin();
//				Sleep(2000);
//				break;  // stop moving this token further
//			}
//			system("cls");
//			initboard(board);
//			displayboard(board);
//			drawtokens();
//			soundTokenMove();
//			Sleep(300);
//		}
//	}
//}
//
////Rolling the dice
//int rolldice() {
//	return (rand() % 6 + 1);
//}
//
////Selecting the token which is to be moved after rolling the dice
//int select_token(int current_player, int dice) {
//	char choice;
//	while (true) {
//		cout << "Select Token (1-4): ";
//		if (current_player == 0)
//			cout << "(R1=1, R2=2, R3=3, R4=4): ";
//		else
//			cout << "(Y1=1, Y2=2, Y3=3, Y4=4): ";
//		while (true) {
//			if (_kbhit()) {
//				choice = _getch();
//				if (choice >= '1' && choice <= '4') {
//					cout << choice << endl;
//					int t = choice - '1';
//					int pos = tokenPos[current_player][t];
//
//					if (pos == 57) {
//						cout << "That token already finished! Choose another." << endl;
//						break;
//					}
//					if (pos == -1 && dice!=6) {
//						cout << "That token is still at home! Choose another." << endl;
//						break;
//					}
//					return t;
//				}
//			}
//		}
//	}
//}
//
////Checking safe cell
//bool is_safecell(int pos) {
//	int safeCells[8] = { 1,8,13,21,27,34,39,47 };
//
//	for (int i = 0; i < 8; i++) {
//		if (pos == safeCells[i]) {
//			return true;
//		}
//	}
//	return false;
//}
//
////Checking cut of tokens
//void checkCapture(int current_player, int current_token) {
//	int currentSteps = tokenPos[current_player][current_token];
//
//	// If token is at base (-1), or in the safe home stretch (>51), no collisions possible
//	if (currentSteps == -1 || currentSteps > 51) {
//		return;
//	}
//
//	// Convert steps back to path array index for checking safe cells
//	int currentIndex = (current_player == 0) ? currentSteps : (26 + currentSteps) % 52;
//
//	if (is_safecell(currentIndex)) {
//		return;
//	}
//
//	// Check all opponent tokens
//	for (int player = 0; player < 2; player++) {
//		if (player == current_player) continue;
//
//		for (int token = 0; token < 4; token++) {
//			int enemySteps = tokenPos[player][token];
//
//			// Only check enemies that are out of base and NOT in their home stretch
//			if (enemySteps != -1 && enemySteps <= 51) {
//				int enemyIndex = (player == 0) ? enemySteps : (26 + enemySteps) % 52;
//
//				// If enemy token is on same path index
//				if (enemyIndex == currentIndex) {
//					tokenPos[player][token] = -1; // Send back to base
//					soundCapture();
//					gotoxy(0, 17);
//					if (player == 0)
//						cout << "RED token R" << (token + 1) << " was sent home!" << endl;
//					else
//						cout << "YELLOW token Y" << (token + 1) << " was sent home!" << endl;
//					Sleep(1500);
//				}
//			}
//		}
//	}
//}
//
////Checking the winner
//bool check_win(int player) {
//	return score[player] == 4;  // All 4 tokens finished = WIN
//}
//
////Initializing the board
//void initboard(char board[][15]) {
//	for (int rows = 0; rows < 15; ++rows) {
//		for (int cols = 0; cols < 15; ++cols) {
//			board[rows][cols] = ' ';
//		}
//	}
//	for (int rows = 0;rows < 15;++rows) {
//		for (int cols = 0;cols < 15;++cols) {
//			if ((rows == 2 && cols >= 2 && cols <= 3) || (rows == 3 && cols >= 2 && cols <= 3)) {
//				board[rows][cols] = 'R';
//			}
//			else if ((rows == 2 && cols >=11  && cols <= 12) || (rows == 3 && cols >= 11 && cols <= 12)) {
//				board[rows][cols] = 'B';
//			}
//			else if ((rows == 11 && cols >= 2 && cols <= 3) || (rows == 12 && cols >= 2 && cols <= 3)) {
//				board[rows][cols] = 'G';
//			}
//			else if ((rows == 11 && cols >= 11 && cols <= 12) || (rows == 12 && cols >= 11 && cols <= 12)) {
//				board[rows][cols] = 'Y';
//			}
//		}
//	}
//}
//
////Displaying the board & initializing it with colors
//void displayboard(const char board[][15]) {
//	for (int rows = 0;rows < 15;++rows) {
//		gotoxy(0, rows);
//		for (int cols = 0;cols < 15;++cols) {
//			if ((rows == 0 && cols <= 5) || (cols == 0 && rows <= 5) || (cols == 5 && rows <= 5) || (rows == 5 && cols <= 5)) {
//				color(0, 64);
//				cout << board[rows][cols];
//			}
//			else if ((rows == 0 && cols <= 14 && cols > 8) || (cols == 9 && rows <= 5) || (cols == 14 && rows <= 5) || (rows == 5 && cols <= 14 && cols > 8)) {
//				color(0, 16);
//				cout << board[rows][cols];
//			}
//			else if ((rows == 9 && cols <= 5) || (cols == 0 && rows <= 14 && rows > 8) || (cols == 5 && rows <= 14 && rows > 8) || (rows == 14 && cols <= 5)) {
//				color(0, 32);
//				cout << board[rows][cols];
//			}
//			else if ((rows == 9 && cols <= 14 && cols > 8) || (cols == 9 && rows <= 14 && rows > 8) || (cols == 14 && rows > 8 && rows <= 14) || (rows == 14 && cols <= 14 && cols > 8)) {
//				color(0, 96);
//				cout << board[rows][cols];
//			}
//			else if ((rows >= 1 && cols ==7 && rows <= 5)) {
//				color(0,144);
//				cout<<board[rows][cols];
//			}
//			else if (cols == 8 && rows == 1) {
//				color(0, 144);
//				cout << board[rows][cols];
//			}
//			else if (cols == 6 && rows == 2) {
//				color(0, 192);
//				cout << board[rows][cols];
//			}
//			else if (cols == 6 && rows == 13) {
//				color(0, 160);
//				cout << board[rows][cols];
//			}
//			else if ((rows >=9 && cols == 7 && rows <=13 )) {
//				color(0, 160);
//				cout << board[rows][cols];
//			}
//			else if (cols == 8 && rows == 12) {
//				color(0, 224);
//				cout << board[rows][cols];
//			}
//			else if ((rows >= 6 && rows <= 8 && cols >= 6 && cols <= 8)) {
//				color(0, 128);
//				cout << board[rows][cols];
//			}
//			else if ((rows == 7 && cols >= 1 && cols <= 5)) {
//				color(0, 192);
//				cout << board[rows][cols];
//			}
//			else if (cols == 2 && rows == 8) {
//				color(0, 160);
//				cout << board[rows][cols];
//			}
//			else if (cols == 1 && rows == 6) {
//				color(0, 192);
//				cout << board[rows][cols];
//			}
//			else if ((rows == 7 && cols >= 9 && cols <= 13)) {
//				color(0, 224);
//				cout << board[rows][cols];
//			}
//			else if (cols == 12 && rows == 6) {
//				color(0, 144);
//				cout << board[rows][cols];
//			}
//			else if (cols == 13 && rows == 8) {
//				color(0, 224);
//				cout << board[rows][cols];
//			}
//			else {
//				color(0, 240);
//				cout << board[rows][cols];
//			}
//		}
//		cout << endl;
//		color(7, 0);
//	}
//}
//
////Function to calculate board coordinates based on steps taken
//void getCoords(int player, int steps, int& row, int& col) {
//	if (steps <= 51) {
//		// Perimeter path
//		int index = (player == 0) ? steps : (26 + steps) % 52;
//		row = path[index][0];
//		col = path[index][1];
//	}
//	else {
//		// Home stretch columns (steps 52 to 56)
//		row = 7;
//		if (player == 0) {
//			col = steps - 51;           // Red moves right (col 1 to 5)a
//		}
//		else {
//			col = 14 - (steps - 51);    // Yellow moves left (col 13 to 9)
//		}
//	}
//}
//
////Drawing tokens on the board
//void drawtokens() {
//	for (int player = 0; player < 2; player++) {
//		for (int token = 0; token < 4; token++) {
//			int steps = tokenPos[player][token];
//			// Ignore tokens at home (-1) or fully finished (57)
//			if (steps == -1 || steps == 57) continue;
//
//			int row, col;
//			getCoords(player, steps, row, col);
//			gotoxy(col, row);
//
//			if (player == 0) {
//				color(15, 64);
//				cout << "R" << (token + 1);
//			}
//			else {
//				color(15, 96);
//				cout << "Y" << (token + 1);
//			}
//			color(7, 0);
//		}
//	}
//}
//
////Sound functions
//
//// Sound when dice is rolled
//void soundDiceRoll() {
//		Beep(300, 60);
//		Beep(400, 60);
//		Beep(500, 60);
//		Beep(600, 60);
//		Beep(700, 60);
//}
//
//// Sound when token moves one step
//void soundTokenMove() {
//	Beep(800, 100);
//}
//
//// Sound when token is captured
//void soundCapture() {
//	Beep(200, 400);
//}
//
//// Sound when player rolls 6
//void soundRolledSix() {
//	Beep(1000, 150);
//	Beep(1200, 150);
//}
//
//// Sound when player wins
//void soundWin() {
//	Beep(523, 300);   // C5
//	Beep(659, 300);   // E5
//	Beep(784, 300);   // G5
//	Beep(1047, 500);  // C6
//}
//
//// Save Game Function
//void saveGame(int current_player) {
//	// Opens a file called savegame.dat in normal text mode
//	ofstream outfile("savegame.dat");
//	if (!outfile) {
//		cout << "Error: Could not save the game!" << endl;
//		return;
//	}
//
//	//Save player names (one per line)
//	outfile << playername[0] << endl;
//	outfile << playername[1] << endl;
//
//	//Save all 8 token positions
//	for (int player = 0; player < 2; player++) {
//		for (int token = 0; token < 4; token++) {
//			outfile << tokenPos[player][token] << " ";
//		}
//		outfile << endl;
//	}
//
//	//Save both scores
//	outfile << score[0] << " " << score[1] << endl;
//
//	//Save current player
//	outfile << current_player << endl;
//	outfile.close();
//	gotoxy(0, 18);
//	color(10, 0);
//	cout << "Game Saved Successfully!" << endl;
//	color(7, 0);
//	Sleep(1500);
//}
//
////Load Game Function
//int loadGame() {
//	int loaded_player = 1;
//	// Opens the file to read the data back
//	ifstream infile("savegame.dat");
//	if (!infile) {
//		return loaded_player; // If no file, just return player 1
//	}
//
//	// 1. Read player names
//	infile >> playername[0];
//	infile >> playername[1];
//
//	// 2. Read all 8 token positions
//	for (int player = 0; player < 2; player++) {
//		for (int token = 0; token < 4; token++) {
//			infile >> tokenPos[player][token];
//		}
//	}
//
//	// 3. Read both scores
//	infile >> score[0];
//	infile >> score[1];
//
//	// 4. Read current player
//	infile >> loaded_player;
//	infile.close(); // Close the file
//	return loaded_player;
//}
//
////Getting players names
//void getPlayerNames() {
//	system("cls");
//	gotoxy(0, 0);
//	cout << "========== ENTER PLAYER NAMES ==========" << endl << endl;
//	cout << "Enter Name for Player 1 (RED): ";
//	cin >> playername[0];
//	cout << "Enter Name for Player 2 (YELLOW): ";
//	cin >> playername[1];
//	cout << endl << "Welcome, ";
//	color(12, 0);  // red color
//	cout << playername[0];
//	color(7, 0);
//	cout << " & ";
//	color(14, 0);  // yellow color
//	cout << playername[1];
//	color(7, 0);
//	cout << "! Get ready to play!" << endl;
//	Sleep(3000);   // show welcome message for 3 seconds
//}
//
//
////Showing the winner
//void showWinner(int player) {
//	system("cls");
//	cout << "========================================" << endl;
//	cout << "           GAME OVER!                   " << endl;
//	cout << "========================================" << endl << endl;
//	cout << "         CONGRATULATIONS!               " << endl << endl;
//	cout << "          ";
//	if (player == 0) {
//		color(12, 0);   // red color
//		cout << playername[0];
//		color(7, 0);
//		cout << " (RED) WINS THE GAME!" << endl;
//	}
//	else {
//		color(14, 0);   // yellow color
//		cout << playername[1];
//		color(7, 0);
//		cout << " (YELLOW) WINS THE GAME!" << endl;
//	}
//
//	// Victory beeps
//	soundWin();
//	cout << endl << "Press any key to return to main menu...";
//	(void)_getch();
//}
//
////Main Menu function
//char showMenu() {
//	system("cls");
//	cout << "========== LUDO GAME ==========";
//	gotoxy(0, 2);
//	cout << "[1] Start New Game" << endl;
//
//	bool has_save_file = false;
//
//	// Check if the save file exists
//	ifstream checkfile("savegame.dat");
//	if (checkfile) {
//		has_save_file = true;
//		gotoxy(0, 3);
//		cout << "[2] Resume Saved Game" << endl;
//		cout << "[3] Exit" << endl;
//	}
//	else {
//		gotoxy(0, 3);
//		cout << "[2] Exit" << endl;
//	}
//	checkfile.close();
//	gotoxy(0, 5);
//	cout<< "Enter Your Choice: ";
//	char choice;
//	while (true) {
//		if (_kbhit()) {
//			choice = _getch();
//			if (has_save_file && choice >= '1' && choice <= '3') {
//				return choice;
//			}
//			else if (!has_save_file && choice >= '1' && choice <= '2') {
//				if (choice == '2') 
//					return '3'; // Map 2 to 3 for Exit logic
//				return choice;
//			}
//		}
//	}
//}
//
//// Starts new game or resumes saved game
//void startnewgame(bool resume = false) {
//	char board[15][15];
//	int current_player = 1;
//	initpath();
//
//	if (resume) {
//		current_player = loadGame();
//		initboard(board);
//	}
//	else {
//		score[0] = 0;
//		score[1] = 0;
//		getPlayerNames();
//		initializetokens();
//		initboard(board);
//	}
//
//	int dicevalue = 0;
//	while (true) {                          // ← main game loop opens
//		system("cls");
//		initboard(board);
//		displayboard(board);
//		drawtokens();
//		gotoxy(0, 16);                      // ← was wrongly closed HERE before
//
//		cout << "============ BOARD DETAILS =============" << endl << endl;
//		if (current_player == 1) {
//			color(12, 0);
//			cout << playername[0];
//			color(7, 0);
//			cout << "'s Turn (RED)" << endl;
//		}
//		else {
//			color(14, 0);
//			cout << playername[1];
//			color(7, 0);
//			cout << "'s Turn (YELLOW)" << endl;
//		}
//		cout << "Score  -->  ";
//		color(12, 0); cout << playername[0]; color(7, 0);
//		cout << ": " << score[0] << "/4  |  ";
//		color(14, 0); cout << playername[1]; color(7, 0);
//		cout << ": " << score[1] << "/4" << endl;
//
//		cout << "Press SPACE to roll dice, or 'S' to Save Game... ";
//		char key;
//		while (true) {                      // ← key-waiting loop opens
//			if (_kbhit()) {
//				key = _getch();
//				if (key == ' ') break;
//				if (key == 's' || key == 'S') {
//					saveGame(current_player);
//					gotoxy(0, 18); cout << "                               ";
//					gotoxy(0, 16);
//				}
//			}
//		}                                   // ← key-waiting loop closes
//
//		dicevalue = rolldice();
//		soundDiceRoll();
//		cout << "\nYou rolled: " << dicevalue << endl;
//		bool canMove = false;
//		bool needs_exact = false;
//		for (int token = 0; token < 4; token++) {
//			int pos = tokenPos[current_player - 1][token];
//			if (pos != -1 && pos != 57) {
//				if (pos + dicevalue <= 57)
//					canMove = true;
//				else {
//					needs_exact = true;
//				}
//			}
//		}
//
//		if (!canMove && dicevalue != 6) {
//			if (needs_exact)
//				cout << "All tokens need exact roll to finish! Turn skipped." << endl;
//			else {
//				cout << "No token can move!" << endl;
//			}
//			(void)_getch();
//		}
//		else {
//			int selectedToken = select_token(current_player - 1, dicevalue);
//			movetoken(current_player - 1, selectedToken, dicevalue, board);
//			checkCapture(current_player - 1, selectedToken);
//			gotoxy(0, 16);
//		}
//
//		if (check_win(current_player - 1)) {
//			remove("savegame.dat");
//			showWinner(current_player - 1);
//			break;
//		}
//
//		cout << "Press any key for next turn...";
//		(void)_getch();
//
//		if (dicevalue == 6) {
//			soundRolledSix();
//			gotoxy(0, 16);
//			cout << "You rolled 6! You get an extra turn!" << endl;
//			Sleep(2000);
//		}
//		else {
//			current_player = (current_player % 2) + 1;
//		}
//	}                                       // ← main game loop closes
//}                                           // ← startnewgame closes
//
////Calling functions
//void callfunctions(char choice) {
//	switch (choice) {
//	case '1':
//		startnewgame(false); // Start new
//		break;
//	case '2':
//		startnewgame(true);  // Resume
//		break;
//	case '3':
//		cout << "YOU EXITED THE GAME!";
//		break;
//	}
//}
//
////Main function
//int main() {
//	char choice;
//	srand(time(0));
//	do {
//		choice = showMenu();
//		callfunctions(choice);
//	} while (choice != '3'); // Loop stops at 3
//	color(7, 0);
//	return 0;
//}