#include <stdio.h>  // standard input output library
#include <iostream> 
#include <conio.h>  // console input output
#include <time.h>  
#include <stdlib.h> // standard library
#include <ctime>  
#include<dos.h>
#include <windows.h>
#include<string.h>

#define WRONGTRIES 5
#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70
#define MENU_WIDTH 20
#define GAP_SIZE 7
#define PIPE_DIF 45
#define dinoPos 2
#define hurdlePos 74
#define GAP_SIZE 7
#define Enemy_DIF 45


using namespace std;

class Game {     // parent class creation

    public:  // public access specifier
		string player1;
		string player2;
		Game(string p1) {   // constructor with one argument
			player1 = p1;
			player2 = string("");
		};
		Game(string p1, string p2) {   // constructor with two arguments
			player1 = p1;
			player2 = p2;
		};

		Game() {   // default constructor

		};

		virtual void instruction() {    // run time polymorphism
			// Print game instruction
			cout<< ("Game instructions")<<endl;
		}
		virtual void play() {          // rum time polymorphism
			//Code for playing the game
			cout << ("playing game")<<endl;
		}
};

class ticTac: public Game {          // sub class for game tick tak toe
	public:
		ticTac(string p1,string p2):Game(p1, p2) {};    //constructor


		char board[3][3] = {' ',' ',' ',
		                    ' ',' ',' ',
		                    ' ',' ',' '
		                   };                     // 3x3 matrix creation
		int turn = 1; //1-Player 1 | 0-Player 2
		char mark = 'O'; //O-Player 1 | X-Player 2
		int input;



        void instruction() {                           
			// Print game instruction
			cout<< ("According to the input matrix, enter number")<<endl;
		}

		void printInputMatrix() {           // this function prints the input matrix
			cout<<endl<<endl<<"INPUT MATRIX"<<endl;
			cout<<" 1 | 2 | 3 "<<endl;
			cout<<"------------"<<endl;
			cout<<" 4 | 5 | 6 "<<endl;
			cout<<"------------"<<endl;
			cout<<" 7 | 8 | 9 "<<endl;
		}

		void printBoard() {
			cout<<" "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<" "<<endl;
			cout<<"------------"<<endl;
			cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<" "<<endl;
			cout<<"------------"<<endl;
			cout<<" "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<" "<<endl;
		}

		int addMark() {
			for(int i=0,k=1; i<3; i++ ) {
				for(int j=0; j<3; j++,k++) {
					if( k==input )
						if(board[i][j] == ' ') {
							board[i][j] = mark;
							return 1;
						} else {
							cout<<"Invalid Input";
							getch();
							return 0;
						}
				}
			}
			return 0;
		}
		int check() {
			//checking rows
			if(board[0][0]==mark && board[0][1]==mark && board[0][2]==mark)
				return 1;
			if(board[1][0]==mark && board[1][1]==mark && board[1][2]==mark)
				return 1;
			if(board[2][0]==mark && board[2][1]==mark && board[2][2]==mark)
				return 1;
			//checking Columns
			if(board[0][0]==mark && board[1][0]==mark && board[2][0]==mark)
				return 1;
			if(board[0][1]==mark && board[1][1]==mark && board[2][1]==mark)
				return 1;
			if(board[0][2]==mark && board[1][2]==mark && board[2][2]==mark)
				return 1;

			//checking diagonals
			if(board[0][0]==mark && board[1][1]==mark && board[2][2]==mark)
				return 1;
			if(board[0][2]==mark && board[1][1]==mark && board[2][0]==mark)
				return 1;

			return 0;
		}


		void play() {
			int won = 0;
			int validInput = 0;

			for(int i=0; i<9; i++) {
				system("cls");
				printBoard();
				if(turn) cout << endl << player1 <<" Turn (Symbol: O)"<<endl;
				else cout << endl << player2 <<" Turn (Symbol: X)"<<endl;
				printInputMatrix();
				cout<<endl<<"Enter Input from Input Matrix: ";
				cin>>input;
				while(input<0 || input>9) {
					cout<<"Invalid Input. Please Re-Enter input: ";
					cin>>input;
				}
				if(turn) mark = 'O';
				else mark = 'X';

				validInput = addMark();
				if( !validInput ) {
					i--;
					continue;
				}
				won = check();
				if( won) {
					system("cls");
					printBoard();
					cout << endl << player1 <<" (Symbol: O)"<<endl;
					cout << endl << player2 <<" (Symbol: X)"<<endl;
					if(turn) cout << endl << "*** "<< player1 << " - You Won ***";
					else cout << endl << "*** " << player2 << " - You Won ***";

					cout << endl <<"Press any key to continue" <<endl;
					getch();
					break;
				}
				if(i==8) {
					system("cls");
					printBoard();
					cout<<endl<<"*** MATCH DRAW ***";
				}

				turn = !turn;
			}
		}

};

class mathsGame : public Game {            //sub class for maths game
	public:
		mathsGame(string p1):Game(p1) {};              // constructor with one aggument
 
		void play() {
			int level, limit;
			char option;

			system("cls");
			cout<<"-----------------------------------"<<endl;
			cout<<"           MATHS GAME			  "<<endl;
			cout<<"-----------------------------------"<<endl<<endl;
			cout<<"1. Level 1"<<endl;
			cout<<"2. Level 2"<<endl;
			cout<<"3. Level 3"<<endl;
			cout<<"4. Back to Menu"<<endl<<endl;
			cout<<"Choose Option (1-4):";
			cin>>option;

			switch(option) {
				case '1':
					limit = 10;
					break;
				case '2':
					limit = 20;
					break;
				case '3':
					limit = 100;
					break;
				case '4':
					break;
			}

			float q1, q2, ans, correctAns;
			int correctNo = 0, totalNo;
			char operation;
			totalNo = 5;

			if( option != '4' ) {
				for(int i=0; i<totalNo; i++) {
					q1 = rand()%limit;
					q2 = rand()%limit;

					int tmpOp = rand()%3;
					switch(tmpOp) {
						case 0:
							operation = '+';
							break;
						case 1:
							operation = '-';
							break;
						case 2:
							operation = '*';
							break;
					}

					cout<<"("<<(i+1)<<"). ";
					cout<<q1<<" "<<operation<<" "<<q2<<" = ";

					cin>> ans;

					switch(operation) {
						case '+':
							correctAns = q1 + q2;
							break;
						case '-':
							correctAns = q1 - q2;
							break;
						case '*':
							correctAns = q1 * q2;
							break;
					}

					if( correctAns == ans ) {
						correctNo++;
						cout<<"correct."<<endl<<endl;
					} else {
						cout<<"wrong"<<endl;
						cout<<q1<<" "<<operation<<" "<<q2<<" = ";
						cout<<correctAns<<endl<<endl;
					}
				}

				cout<<"Total: "<<totalNo<<endl;
				cout<<"Correct: "<<correctNo<<endl<<endl;

				cout<<"Press any key to continue..."<<endl;
				getch();
			}
		}

		void instruction() {             // prints instructions
			system("cls");
			cout<<"-----------------------------------"<<endl;
			cout<<"          Instructions			  "<<endl;
			cout<<"-----------------------------------"<<endl<<endl;
			cout<<"1. This game contains basic arithmetic problems"<<endl;
			cout<<"2. Each correct answer will yeild to 1 Point"<<endl;
			cout<<"3. Total questions will be 5 "<<endl;
			cout<<"4. To win, you need 3 or more correct answers"<<endl;
			cout<<endl;

			cout<<"Press any key to continue..."<<endl;
			getch();
		}

};


class CasinoGame : public Game {            // subclass for casino game
	public :         // creating data members
		string personName;
		int totalMoney;
		int betMoney;
		int guess;
		int dice;
		char option;

		CasinoGame(string p1):Game(p1) {};      // constructor with one argument


		void instruction() {           // prints instructions
			system("cls");
			cout << endl << endl;
			cout << " ----------------------------------------------------------------------------" << endl;
			cout << " RULES OF THE GAME" << endl;
			cout << " ----------------------------------------------------------------------------" << endl;
			cout << " 1. Choose any number between 1 to 5" << endl;
			cout << " 2. If you win you will get 10 times of money you bet" << endl;
			cout << " 3. If you bet on wrong number you will lose your betting totalMoney" << endl;
			cout << " ----------------------------------------------------------------------------" << endl;
			cout << "Press any key to start...";
			getch();
		}

		void play() {
			cout << " -------------------------------------" << endl;
			cout << "|           CASINO GAME             |" << endl;
			cout << " -------------------------------------" << endl << endl;

			cout << "Enter Your Name : ";
			getline(cin, personName);

			cout << endl << endl;
			cout << "Enter Deposit Money to start game : $";
			cin >> totalMoney;

			do {
				system("cls");

				cout << " -------------------------------------" << endl;
				cout << "|           CASINO GAME             |" << endl;
				cout << " -------------------------------------" << endl << endl<<endl;

				cout << "\nCurrent balance is $ " << totalMoney << endl;

				do {
					cout << personName << ", Please Enter amount to bet : $";
					cin >> betMoney;
					if (betMoney > totalMoney)
						cout << "Betting Amount is more than current balance" << endl << "Re-enter data" << endl;

				} while (betMoney > totalMoney);

				do {
					cout << "Enter Guess number to bet between 1 to 5 :";
					cin >> guess;
					if (guess < 1 || guess > 5)
						cout << "Number should be between 1 to 5" << endl << "Re-enter data " << endl;

				} while (guess < 1 || guess > 5);

				dice = rand() % 5 + 1;

				if (dice != guess) {
					totalMoney -= betMoney;
					cout << endl << endl << "You lost $ " << betMoney << endl;
				} else {
					totalMoney += (betMoney * 10);
					cout << endl << endl << "Congratulations!! You won Rs." << betMoney * 10;
				}

				cout << "\nThe winning number was : " << dice << endl;
				cout << "\n" << personName << ", You have $ " << totalMoney << endl;
				if (totalMoney == 0) {
					cout << "You have no money to play ";
					break;
				}
				cout << endl << endl << " Do you want to play again (y/n)? ";
				cin >> option;
			} while (option == 'Y' || option == 'y');

			cout << " ----------------------------------------------------------------------------" << endl;
			cout << " Thanks for playing. Your Current Money is $ " << totalMoney << endl;
			cout << " ----------------------------------------------------------------------------" << endl;
			getch();
		}
};




class Hangman : public Game {             // subclass for hangman game
		//Hangman(string p1):Game(p1) {};

		void DrawMan(int tries) {          // draws the hangman according to the number of tries used
			cout<<endl<<endl;
			cout<<"  -----"<<endl;
			cout<<"  |   |"<<endl;
			cout<<"  |";
			if(tries>=1) cout<<"   O    ";
			cout<<endl;
			cout<<"  |";
			if(tries>=3) cout<<"  /|\\   ";
			cout<<endl;
			cout<<"  |";
			if(tries>=5) cout<<"  / \\    ";
			cout<<endl;
			cout<<"  |"<<endl;
			cout<<"__|__"<<endl;
		}

		void play() {
			srand (time(NULL));
			string wordList[5] = {"apple","peach","banana","strawberry","mango"};
			string word;
			string guessed;

			word = wordList[rand()%5];

			int wordLength = word.length();
			string dispWord (wordLength, '_');

			int found = 0;
			char guess = ' ';
			int tries = 5; //No of wrong tries
			int flagFound = 0;

			while(tries>=0) {
				system("cls");
				cout<<"Guess Fruit Name: "<<endl<<endl;

				for(int i=0; i<wordLength; i++)
					cout<<" "<<dispWord[i]<<" ";
				cout<<endl<<endl<<endl;

				cout<<"Wrong Attempts: "<<tries<<" / "<<WRONGTRIES<<endl;
				cout<<"Guessed Letters: "<<guessed<<endl;

				DrawMan(tries);

				if( found == wordLength ) {
					cout<<endl;
					cout<<"*****************"<<endl;
					cout<<"*    You Win    *"<<endl;
					cout<<"*****************"<<endl;
					break;
				}

				if( tries == 0) break;

				cout<<"Pick a Letter:";
				guess = getche();

				guessed = guessed + " " + guess;

				if( dispWord.find(guess)!=string::npos ) tries++;

				flagFound = 0;
				for(int i=0; i<wordLength; i++) {
					if( word[i]==guess && dispWord[i]=='_' ) {
						dispWord[i] = guess;
						found++;
						flagFound = 1;
					}
				}

				if( !flagFound )
					tries--;
			}
			if( found != wordLength ) {
				cout<<endl;
				cout<<"******************"<<endl;
				cout<<"*    You Lose    *"<<endl;
				cout<<"******************"<<endl;
			}

			getch();
		}
};




class CarGame : public Game {             // subclass for car game

	public:   // creating data members with public accessibility
		CarGame(string p1):Game(p1) {};   // constructor with one argument

		int enemyY[3];
		int enemyX[3];
		int enemyFlag[3];
		char car[4][4] = { ' ','0','0',' ',
		                   '0','0','0','0',
		                   ' ','0','0',' ',
		                   '0','0','0','0'
		                 };

		int carPos = WIN_WIDTH/2;
		int score = 0;


		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD CursorPosition;

		void gotoxy(int x, int y) {
			CursorPosition.X = x;
			CursorPosition.Y = y;
			SetConsoleCursorPosition(console, CursorPosition);
		}
		void setcursor(bool visible, DWORD size) {
			if(size == 0)
				size = 20;

			CONSOLE_CURSOR_INFO lpCursor;
			lpCursor.bVisible = visible;
			lpCursor.dwSize = size;
			SetConsoleCursorInfo(console,&lpCursor);
		}
		void drawBorder() {
			for(int i=0; i<SCREEN_HEIGHT; i++) {
				for(int j=0; j<17; j++) {
					gotoxy(0+j,i);
					cout<<"±";
					gotoxy(WIN_WIDTH-j,i);
					cout<<"±";
				}
			}
			for(int i=0; i<SCREEN_HEIGHT; i++) {
				gotoxy(SCREEN_WIDTH,i);
				cout<<"±";
			}
		}
		void genEnemy(int ind) {
			enemyX[ind] = 17 + rand()%(33);
		}
		void drawEnemy(int ind) {
			if( enemyFlag[ind] == true ) {
				gotoxy(enemyX[ind], enemyY[ind]);
				cout<<"****";
				gotoxy(enemyX[ind], enemyY[ind]+1);
				cout<<" ** ";
				gotoxy(enemyX[ind], enemyY[ind]+2);
				cout<<"****";
				gotoxy(enemyX[ind], enemyY[ind]+3);
				cout<<" ** ";
			}
		}
		void eraseEnemy(int ind) {
			if( enemyFlag[ind] == true ) {
				gotoxy(enemyX[ind], enemyY[ind]);
				cout<<"    ";
				gotoxy(enemyX[ind], enemyY[ind]+1);
				cout<<"    ";
				gotoxy(enemyX[ind], enemyY[ind]+2);
				cout<<"    ";
				gotoxy(enemyX[ind], enemyY[ind]+3);
				cout<<"    ";
			}
		}
		void resetEnemy(int ind) {
			eraseEnemy(ind);
			enemyY[ind] = 1;
			genEnemy(ind);
		}

		void drawCar() {
			for(int i=0; i<4; i++) {
				for(int j=0; j<4; j++) {
					gotoxy(j+carPos, i+22);
					cout<<car[i][j];
				}
			}
		}
		void eraseCar() {
			for(int i=0; i<4; i++) {
				for(int j=0; j<4; j++) {
					gotoxy(j+carPos, i+22);
					cout<<" ";
				}
			}
		}

		int collision() {
			if( enemyY[0]+4 >= 23 ) {
				if( enemyX[0] + 4 - carPos >= 0 && enemyX[0] + 4 - carPos < 9  ) {
					return 1;
				}
			}
			return 0;
		}
		void gameover() {
			system("cls");
			cout<<endl;
			cout<<"\t\t--------------------------"<<endl;
			cout<<"\t\t-------- Game Over -------"<<endl;
			cout<<"\t\t--------------------------"<<endl<<endl;
			cout<<"\t\tPress any key to go back to menu.";
			getch();
		}
		void updateScore() {
			gotoxy(WIN_WIDTH + 7, 5);
			cout<<"Score: "<<score<<endl;
		}

		void instruction() {            // prints instructions

			system("cls");
			cout<<"Instructions";
			cout<<"\n----------------";
			cout<<"\n Avoid Cars by moving left or right. ";
			cout<<"\n\n Press 'a' to move left";
			cout<<"\n Press 'd' to move right";
			cout<<"\n Press 'escape' to exit";
			cout<<"\n\nPress any key to play";
			getch();
		}

		void play() {
			carPos = -1 + WIN_WIDTH/2;
			score = 0;
			enemyFlag[0] = 1;
			enemyFlag[1] = 0;
			enemyY[0] = enemyY[1] = 1;

			system("cls");
			drawBorder();
			updateScore();
			genEnemy(0);
			genEnemy(1);

			gotoxy(WIN_WIDTH + 7, 2);
			cout<<"Car Game";
			gotoxy(WIN_WIDTH + 6, 4);
			cout<<"----------";
			gotoxy(WIN_WIDTH + 6, 6);
			cout<<"----------";
			gotoxy(WIN_WIDTH + 7, 12);
			cout<<"Control ";
			gotoxy(WIN_WIDTH + 7, 13);
			cout<<"-------- ";
			gotoxy(WIN_WIDTH + 2, 14);
			cout<<" A Key - Left";
			gotoxy(WIN_WIDTH + 2, 15);
			cout<<" D Key - Right";

			gotoxy(18, 5);
			cout<<"Press any key to start";
			getch();
			gotoxy(18, 5);
			cout<<"                      ";

			while(1) {
				if(kbhit()) {
					char ch = getch();
					if( ch=='a' || ch=='A' ) {
						if( carPos > 18 )
							carPos -= 4;
					}
					if( ch=='d' || ch=='D' ) {
						if( carPos < 50 )
							carPos += 4;
					}
					if(ch==27) {
						break;
					}
				}

				drawCar();
				drawEnemy(0);
				drawEnemy(1);
				if( collision() == 1  ) {
					gameover();
					return;
				}
				Sleep(50);
				eraseCar();
				eraseEnemy(0);
				eraseEnemy(1);

				if( enemyY[0] == 10 )
					if( enemyFlag[1] == 0 )
						enemyFlag[1] = 1;

				if( enemyFlag[0] == 1 )
					enemyY[0] += 1;

				if( enemyFlag[1] == 1 )
					enemyY[1] += 1;

				if( enemyY[0] > SCREEN_HEIGHT-4 ) {
					resetEnemy(0);
					score++;
					updateScore();
				}
				if( enemyY[1] > SCREEN_HEIGHT-4 ) {
					resetEnemy(1);
					score++;
					updateScore();
				}
			}

			setcursor(0,0);
			srand( (unsigned)time(NULL));

			do {
				system("cls");
				gotoxy(10,5);
				cout<<" -------------------------- ";
				gotoxy(10,6);
				cout<<" |        Car Game        | ";
				gotoxy(10,7);
				cout<<" --------------------------";
				gotoxy(10,9);
				cout<<"1. Start Game";
				gotoxy(10,10);
				cout<<"2. Instructions";
				gotoxy(10,11);
				cout<<"3. Quit";
				gotoxy(10,13);
				cout<<"Select option: ";
				char op = getche();

				if( op=='1') play();
				else if( op=='2') instruction();
				else if( op=='3') exit(0);

			} while(1);
		}
};


class FlappyBird : public Game {             // subclass for flappy bird game
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);       
		COORD CursorPosition; 

	public :
		FlappyBird(string p1):Game(p1) {};             // constructor with one variable
		int pipePos[3];
		int gapPos[3];
		int pipeFlag[3];
		char bird[2][6] = { '/','-','-','o','\\',' ',
		                    '|','_','_','_',' ','>'
		                  };
		int birdPos = 6;
		int score = 0;




		void gotoxy(int x, int y) {
			CursorPosition.X = x;
			CursorPosition.Y = y;
			SetConsoleCursorPosition(console, CursorPosition);
		}

		void setcursor(bool visible, DWORD size) {
			if(size == 0)
				size = 20;

			CONSOLE_CURSOR_INFO lpCursor;
			lpCursor.bVisible = visible;
			lpCursor.dwSize = size;
			SetConsoleCursorInfo(console,&lpCursor);
		}

		void drawBorder() {

			for(int i=0; i<SCREEN_WIDTH; i++) {
				gotoxy(i,0);
				cout<<"±";
				gotoxy(i,SCREEN_HEIGHT);
				cout<<"±";
			}

			for(int i=0; i<SCREEN_HEIGHT; i++) {
				gotoxy(0,i);
				cout<<"±";
				gotoxy(SCREEN_WIDTH,i);
				cout<<"±";
			}
			for(int i=0; i<SCREEN_HEIGHT; i++) {
				gotoxy(WIN_WIDTH,i);
				cout<<"±";
			}
		}
		void genPipe(int ind) {
			gapPos[ind] = 3 + rand()%14;
		}
		void drawPipe(int ind) {
			if( pipeFlag[ind] == true ) {
				for(int i=0; i<gapPos[ind]; i++) {
					gotoxy(WIN_WIDTH-pipePos[ind],i+1);
					cout<<"***";
				}
				for(int i=gapPos[ind]+GAP_SIZE; i<SCREEN_HEIGHT-1; i++) {
					gotoxy(WIN_WIDTH-pipePos[ind],i+1);
					cout<<"***";
				}
			}
		}
		void erasePipe(int ind) {
			if( pipeFlag[ind] == true ) {
				for(int i=0; i<gapPos[ind]; i++) {
					gotoxy(WIN_WIDTH-pipePos[ind],i+1);
					cout<<"   ";
				}
				for(int i=gapPos[ind]+GAP_SIZE; i<SCREEN_HEIGHT-1; i++) {
					gotoxy(WIN_WIDTH-pipePos[ind],i+1);
					cout<<"   ";
				}
			}
		}

		void drawBird() {
			for(int i=0; i<2; i++) {
				for(int j=0; j<6; j++) {
					gotoxy(j+2,i+birdPos);
					cout<<bird[i][j];
				}
			}
		}
		void eraseBird() {
			for(int i=0; i<2; i++) {
				for(int j=0; j<6; j++) {
					gotoxy(j+2,i+birdPos);
					cout<<" ";
				}
			}
		}

		int collision() {
			if( pipePos[0] >= 61  ) {
				if( birdPos<gapPos[0] || birdPos >gapPos[0]+GAP_SIZE ) {
//			cout<< " HIT ";
//			getch();
					return 1;
				}
			}
			return 0;
		}
		void debug() {
//	gotoxy(SCREEN_WIDTH + 3, 4); cout<<"Pipe Pos: "<<pipePos[0];

		}
		void gameover() {
			system("cls");
			cout<<endl;
			cout<<"\t\t--------------------------"<<endl;
			cout<<"\t\t-------- Game Over -------"<<endl;
			cout<<"\t\t--------------------------"<<endl<<endl;
			cout<<"\t\tPress any key to go back to menu.";
			getch();
		}
		void updateScore() {
			gotoxy(WIN_WIDTH + 7, 5);
			cout<<"Score: "<<score<<endl;
		}

		void instruction() {           //prints instructions

			system("cls");
			cout<<"Instructions";
			cout<<"\n----------------";
			cout<<"\n Press spacebar to make bird fly";
			cout<<"\n\nPress any key to play";
			getch();
		}

		void play() {

			birdPos = 6;
			score = 0;
			pipeFlag[0] = 1;
			pipeFlag[1] = 0;
			pipePos[0] = pipePos[1] = 4;

			system("cls");
			drawBorder();
			genPipe(0);
			updateScore();

			gotoxy(WIN_WIDTH + 5, 2);
			cout<<"FLAPPY BIRD";
			gotoxy(WIN_WIDTH + 6, 4);
			cout<<"----------";
			gotoxy(WIN_WIDTH + 6, 6);
			cout<<"----------";
			gotoxy(WIN_WIDTH + 7, 12);
			cout<<"Control ";
			gotoxy(WIN_WIDTH + 7, 13);
			cout<<"-------- ";
			gotoxy(WIN_WIDTH + 2, 14);
			cout<<" Spacebar = jump";

			gotoxy(10, 5);
			cout<<"Press any key to start";
			getch();
			gotoxy(10, 5);
			cout<<"                      ";

			while(1) {

				if(kbhit()) {
					char ch = getch();
					if(ch==32) {
						if( birdPos > 3 )
							birdPos-=3;
					}
					if(ch==27) {
						break;
					}
				}

				drawBird();
				drawPipe(0);
				drawPipe(1);
				debug();
				if( collision() == 1 ) {
					gameover();
					return;
				}
				Sleep(100);
				eraseBird();
				erasePipe(0);
				erasePipe(1);
				birdPos += 1;

				if( birdPos > SCREEN_HEIGHT - 2 ) {
					gameover();
					return;
				}

				if( pipeFlag[0] == 1 )
					pipePos[0] += 2;

				if( pipeFlag[1] == 1 )
					pipePos[1] += 2;

				if( pipePos[0] >= 40 && pipePos[0] < 42 ) {
					pipeFlag[1] = 1;
					pipePos[1] = 4;
					genPipe(1);
				}
				if( pipePos[0] > 68 ) {
					score++;
					updateScore();
					pipeFlag[1] = 0;
					pipePos[0] = pipePos[1];
					gapPos[0] = gapPos[1];
				}

			}

			setcursor(0,0);
			srand( (unsigned)time(NULL));

//	play();

			do {
				system("cls");
				gotoxy(10,5);
				cout<<" -------------------------- ";
				gotoxy(10,6);
				cout<<" |      Flappy Bird       | ";
				gotoxy(10,7);
				cout<<" --------------------------";
				gotoxy(10,9);
				cout<<"1. Start Game";
				gotoxy(10,10);
				cout<<"2. Instructions";
				gotoxy(10,11);
				cout<<"3. Quit";
				gotoxy(10,13);
				cout<<"Select option: ";
				char op = getche();

				if( op=='1') play();
				else if( op=='2') instruction();
				else if( op=='3') exit(0);

			} while(1);

		}
};


class DinoRun : public Game {          // subclass for dino run game
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD CursorPosition;

	public : // creating data members
		DinoRun(string p1):Game(p1) {};      // constructor with one argument
		int dinoY;
		int speed = 40;
		int gameover = 0;

		void gotoxy(int x, int y) {
			COORD coord;
			coord.X = x;
			coord.Y = y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		}

		void setcursor(bool visible, DWORD size) {
			if (size == 0) {
				size = 20; // default cursor size Changing to numbers from 1 to 20, decreases cursor width
			}
			CONSOLE_CURSOR_INFO lpCursor;
			lpCursor.bVisible = visible;
			lpCursor.dwSize = size;
			SetConsoleCursorInfo(console, & lpCursor);
		}

		void init() {
			system("cls");
			gameover = 0;
			gotoxy(3, 2);
			cout<<"SCORE : ";
			for (int i = 0; i < 79; i++) {
				gotoxy(1+i, 1);
				cout<<"ß";
				gotoxy(1+i, 25);
				cout<<"ß";
			}
		}

		void moveDino(int jump = 0) {
			static int foot = 0;

			if (jump == 0)
				dinoY = 0;
			else if (jump == 2)
				dinoY--;
			else dinoY++;

			gotoxy(dinoPos, 15 - dinoY);
			cout<<"                 ";
			gotoxy(dinoPos, 16 - dinoY);
			cout<<"         ÜÛßÛÛÛÛÜ";
			gotoxy(dinoPos, 17 - dinoY);
			cout<<"         ÛÛÛÛÛÛÛÛ";
			gotoxy(dinoPos, 18 - dinoY);
			cout<<"         ÛÛÛÛÛßßß";
			gotoxy(dinoPos, 19 - dinoY);
			cout<<" Û      ÜÛÛÛÛßßß ";
			gotoxy(dinoPos, 20 - dinoY);
			cout<<" ÛÛÜ  ÜÛÛÛÛÛÛÜÜÜ ";
			gotoxy(dinoPos, 21 - dinoY);
			cout<<" ßÛÛÛÛÛÛÛÛÛÛÛ  ß ";
			gotoxy(dinoPos, 22 - dinoY);
			cout<<"   ßÛÛÛÛÛÛÛß     ";
			gotoxy(dinoPos, 23 - dinoY);

			if (jump == 1 || jump == 2) {
				cout<<"    ÛÛß ßÛ       ";
				gotoxy(2, 24 - dinoY);
				cout<<"    ÛÜ   ÛÜ      ";
			} else if (foot == 0) {
				cout<<"    ßÛÛß  ßßß    ";
				gotoxy(2, 24 - dinoY);
				cout<<"      ÛÜ         ";
				foot = !foot;
			} else if (foot == 1) {
				cout<<"     ßÛÜ ßÛ      ";
				gotoxy(2, 24 - dinoY);
				cout<<"          ÛÜ     ";
				foot = !foot;
			}

			gotoxy(2, 25 - dinoY);
			if (jump == 0) {
				cout<<"ßßßßßßßßßßßßßßßßß";
			} else {
				cout<<"                ";
			}
			Sleep(speed);
		}
		void drawHurdle() {
			static int plantX = 0;
			static int score = 0;
			if (plantX == 56 && dinoY < 4) {
				score = 0;
				speed = 40;
				gotoxy(36, 8);
				cout<<"Game Over";
				getch();
				gameover = 1;
			}

			gotoxy(hurdlePos - plantX, 20);
			cout<<"| | ";
			gotoxy(hurdlePos - plantX, 21);
			cout<<"| | ";
			gotoxy(hurdlePos - plantX, 22);
			cout<<"|_| ";
			gotoxy(hurdlePos - plantX, 23);
			cout<<" |  ";
			gotoxy(hurdlePos - plantX, 24);
			cout<<" |  ";

			plantX++;

			if (plantX == 73) {
				plantX = 0;
				score++;
				gotoxy(11, 2);
				cout<<"     ";
				gotoxy(11, 2);
				cout<<score;
				if (speed > 20)
					speed--;
			}
		}

		void instruction() {        // prints instructions
			system("cls");
			cout<<"Instructions";
			cout<<"\n----------------";
			cout<<"\n1. Avoid hurdles by jumping";
			cout<<"\n2. Press 'Spacebar' to jump ";
			cout<<"\n3. Press 'p' to pause game ";
			cout<<"\n4. Press 'Escape' to exit from game";
			cout<<"\n\nPress any key to play";
			getch();
		}

		void play() {
			system("cls");
			char ch;
			int i;
			init();
			while (true) {
				while (!kbhit()) {
					if( gameover==1 ) {
						return;
					}
					moveDino();
					drawHurdle();
				}
				ch = getch();
				if (ch == 32) {
					i = 0;
					while( i < 12) {
						moveDino(1);
						drawHurdle();
						i++;
					}
					while(i > 0) {
						moveDino(2);
						drawHurdle();
						i--;
					}
				} else if (ch == 'p'||ch=='P')
					getch();
				else if (ch == 27)
					break;
			}

			setcursor(0, 0);

			do {
				system("cls");
				gotoxy(10,5);
				cout<<" -------------------------- ";
				gotoxy(10,6);
				cout<<" |        DINO RUN        | ";
				gotoxy(10,7);
				cout<<" -------------------------- ";
				gotoxy(10,9);
				cout<<"1. Start Game";
				gotoxy(10,10);
				cout<<"2. Instructions";
				gotoxy(10,11);
				cout<<"3. Quit";
				gotoxy(10,13);
				cout<<"Select option: ";
				char op = getche();

				if( op=='1') play();
				else if( op=='2') instruction();
				else if( op=='3') exit(0);

			} while(1);
		}
};




class SpaceShooter : public Game {         // subclass for space shooter game
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD CursorPosition;

	public :
		SpaceShooter(string p1):Game(p1) {};  // constructor with one argument
		int enemyY[3];
		int enemyX[3];
		int enemyFlag[3];
		char bird[3][5] = { ' ',' ','0',' ',' ',
		                    '|','0','0','0','|',
		                    '0','0','0','0','0'
		                  };
		int birdPos = WIN_WIDTH/2;
		int score = 0;
		int bullets[20][4];
		int bulletsLife[20];
		int bIndex = 0;




		void gotoxy(int x, int y) {
			CursorPosition.X = x;
			CursorPosition.Y = y;
			SetConsoleCursorPosition(console, CursorPosition);
		}
		void setcursor(bool visible, DWORD size) {
			if(size == 0)
				size = 20;

			CONSOLE_CURSOR_INFO lpCursor;
			lpCursor.bVisible = visible;
			lpCursor.dwSize = size;
			SetConsoleCursorInfo(console,&lpCursor);
		}
		void drawBorder() {

			for(int i=0; i<SCREEN_WIDTH; i++) {
				gotoxy(i,SCREEN_HEIGHT);
				cout<<"±";
			}

			for(int i=0; i<SCREEN_HEIGHT; i++) {
				gotoxy(0,i);
				cout<<"±";
				gotoxy(SCREEN_WIDTH,i);
				cout<<"±";
			}
			for(int i=0; i<SCREEN_HEIGHT; i++) {
				gotoxy(WIN_WIDTH,i);
				cout<<"±";
			}
		}
		void genEnemy(int ind) {
			enemyX[ind] = 3 + rand()%(WIN_WIDTH-10);
		}
		void drawEnemy(int ind) {
			if( enemyFlag[ind] == true ) {
				gotoxy(enemyX[ind], enemyY[ind]);
				cout<<".**.";
				gotoxy(enemyX[ind], enemyY[ind]+1);
				cout<<"****";
				gotoxy(enemyX[ind], enemyY[ind]+2);
				cout<<"****";
				gotoxy(enemyX[ind], enemyY[ind]+3);
				cout<<".**.";

			}
		}
		void eraseEnemy(int ind) {
			if( enemyFlag[ind] == true ) {
				gotoxy(enemyX[ind], enemyY[ind]);
				cout<<"    ";
				gotoxy(enemyX[ind], enemyY[ind]+1);
				cout<<"    ";
				gotoxy(enemyX[ind], enemyY[ind]+2);
				cout<<"    ";
				gotoxy(enemyX[ind], enemyY[ind]+3);
				cout<<"    ";
			}
		}
		void resetEnemy(int ind) {
			eraseEnemy(ind);
			enemyY[ind] = 4;
			genEnemy(ind);
		}
		void genBullet() {
			bullets[bIndex][0] = 22;
			bullets[bIndex][1] = birdPos;
			bullets[bIndex][2] = 22;
			bullets[bIndex][3] = birdPos+4;
			bIndex++;
			if( bIndex == 20)
				bIndex = 0;
		}
		void moveBullet() {
			for(int i=0; i<20; i++) {
				if( bullets[i][0] > 2 )
					bullets[i][0]--;
				else
					bullets[i][0] = 0;

				if( bullets[i][2] > 2 )
					bullets[i][2]--;
				else
					bullets[i][2] = 0;
			}
		}
		void drawBullets() {
			for(int i=0; i<20; i++) {
				if( bullets[i][0] > 1) {
					gotoxy(bullets[i][1],bullets[i][0]);
					cout<<".";
					gotoxy(bullets[i][3],bullets[i][2]);
					cout<<".";
				}
			}
		}
		void eraseBullets() {
			for(int i=0; i<20; i++) {
				if( bullets[i][0] >= 1 ) {
					gotoxy(bullets[i][1],bullets[i][0]);
					cout<<" ";
					gotoxy(bullets[i][3],bullets[i][2]);
					cout<<" ";
				}
			}
		}
		void eraseBullet(int i) {
			gotoxy(bullets[i][1],bullets[i][0]);
			cout<<" ";
			gotoxy(bullets[i][3],bullets[i][2]);
			cout<<" ";
		}
		void drawBird() {
			for(int i=0; i<3; i++) {
				for(int j=0; j<5; j++) {
					gotoxy(j+birdPos, i+22);
					cout<<bird[i][j];
				}
			}
		}
		void eraseBird() {
			for(int i=0; i<3; i++) {
				for(int j=0; j<5; j++) {
					gotoxy(j+birdPos, i+22);
					cout<<" ";
				}
			}
		}

		int collision() {
			if( enemyY[0]+4 >= 23 ) {
				if( enemyX[0] + 4 - birdPos >= 0 && enemyX[0] + 4 - birdPos < 8  ) {
					return 1;
				}
			}
			return 0;
		}
		int bulletHit() {
			for(int i=0; i<20; i++) {
				for(int j=0; j<4; j+=2) {
					if( bullets[i][j] != 0 ) {
						if( bullets[i][j] >= enemyY[0] && bullets[i][j] <= enemyY[0]+4 ) {
							if( bullets[i][j+1] >= enemyX[0] && bullets[i][j+1] <= enemyX[0]+4 ) {
								eraseBullet(i);
								bullets[i][j] = 0;
								resetEnemy(0);
								return 1;
							}
						}
						if( bullets[i][j] >= enemyY[1] && bullets[i][j] <= enemyY[1]+4 ) {
							if( bullets[i][j+1] >= enemyX[1] && bullets[i][j+1] <= enemyX[1]+4 ) {
								eraseBullet(i);
								resetEnemy(1);
								bullets[i][j] = 0;
								return 1;
							}
						}
					}
				}
			}
			return 0;
		}
		void gameover() {
			system("cls");
			cout<<endl;
			cout<<"\t\t--------------------------"<<endl;
			cout<<"\t\t-------- Game Over -------"<<endl;
			cout<<"\t\t--------------------------"<<endl<<endl;
			cout<<"\t\tPress any key to go back to menu.";
			getch();
		}
		void updateScore() {
			gotoxy(WIN_WIDTH + 7, 5);
			cout<<"Score: "<<score<<endl;
		}

		void instruction() {       //prints instructions

			system("cls");
			cout<<"Instructions";
			cout<<"\n----------------";
			cout<<"\n Press spacebar to make bird fly";
			cout<<"\n\nPress any key to play";
			getch();
		}


		void play() {

			birdPos = -1 + WIN_WIDTH/2;
			score = 0;
			enemyFlag[0] = 1;
			enemyFlag[1] = 1;
			enemyY[0] = enemyY[1] = 4;

			for(int i=0; i<20; i++) {
				bullets[i][0] = bullets[i][1] = 0;
			}

			system("cls");
			drawBorder();
			genEnemy(0);
			genEnemy(1);
			updateScore();

			gotoxy(WIN_WIDTH + 5, 2);
			cout<<"Space Shooter";
			gotoxy(WIN_WIDTH + 6, 4);
			cout<<"----------";
			gotoxy(WIN_WIDTH + 6, 6);
			cout<<"----------";
			gotoxy(WIN_WIDTH + 7, 12);
			cout<<"Control ";
			gotoxy(WIN_WIDTH + 7, 13);
			cout<<"-------- ";
			gotoxy(WIN_WIDTH + 2, 14);
			cout<<" A Key - Left";
			gotoxy(WIN_WIDTH + 2, 15);
			cout<<" D Key - Right";
			gotoxy(WIN_WIDTH + 2, 16);
			cout<<" Spacebar = Shoot";

			gotoxy(10, 5);
			cout<<"Press any key to start";
			getch();
			gotoxy(10, 5);
			cout<<"                      ";

			while(1) {
				if(kbhit()) {
					char ch = getch();
					if( ch=='a' || ch=='A' ) {
						if( birdPos > 2 )
							birdPos -= 2;
					}
					if( ch=='d' || ch=='D' ) {
						if( birdPos < WIN_WIDTH-7 )
							birdPos += 2;
					}
					if(ch==32) {
						genBullet();
					}
					if(ch==27) {
						break;
					}
				}

				drawBird();
				drawEnemy(0);
				drawEnemy(1);
				drawBullets();
				if( collision() == 1  ) {
					gameover();
					return;
				}
				if(  bulletHit() == 1 ) {
					score++;
					updateScore();
				}
				Sleep(200);
				eraseBird();
				eraseEnemy(0);
				eraseEnemy(1);
				eraseBullets();
				moveBullet();

				if( enemyFlag[0] == 1 )
					enemyY[0] += 1;

				if( enemyFlag[1] == 1 )
					enemyY[1] += 1;

				if( enemyY[0] > SCREEN_HEIGHT-5 ) {
					resetEnemy(0);
				}
				if( enemyY[1] > SCREEN_HEIGHT-5 ) {
					resetEnemy(1);
				}
			}

			setcursor(0,0);
			srand( (unsigned)time(NULL));

			do {
				system("cls");
				gotoxy(10,5);
				cout<<" -------------------------- ";
				gotoxy(10,6);
				cout<<" |     Space Shooter      | ";
				gotoxy(10,7);
				cout<<" --------------------------";
				gotoxy(10,9);
				cout<<"1. Start Game";
				gotoxy(10,10);
				cout<<"2. Instructions";
				gotoxy(10,11);
				cout<<"3. Quit";
				gotoxy(10,13);
				cout<<"Select option: ";
				char op = getche();

				if( op=='1') play();
				else if( op=='2') instruction();
				else if( op=='3') exit(0);

			} while(1);
		}


};




int main() {
	Game *obj1  ;     // pointer to hold child game class object
	int input;
	string player1, player2;

	while (1) {         //works in a loop, loop works everytime the user enters anything other than "N"

	
       cout<<" -------------------------- "<<endl;
	   cout<<" |        MULTIGAMES      | "<<endl;
	   cout<<" --------------------------"<<endl;
	   cout<<"-----------------------------------";
		cout << endl <<"| 1.Tic Tac Toe                   |"<<endl;
		cout <<"| 2.Maths game                    |"<<endl;
		cout <<"| 3.Casino game                   | "<<endl;
		cout <<"| 4.Hangman game                  |"<<endl;
		cout<<"| 5.Car game                      |"<<endl;
		cout<<"| 6.Flappy bird game              |"<<endl;
		cout<<"| 7.Dino run                      |"<<endl;
		cout<<"| 8.Space shooter                 | "<<endl;
		cout<<"----------------------------------"<<endl;

		cout<<endl;
        cout<<"Enter 1-8 to play the game ";
		cout <<"or press any other key to exit: "<<endl;

		cin >> input;    // taking choice input to run switch case
		
		
	    cout << endl <<"Input Player name : ";
		cin >> player1;      // inputs player name
		 
		
		switch (input) {
			case 1:
				cout << "Input second Player's name : ";
				cin >> player2;   // inputs second player name for tick tak tow
				obj1 = new ticTac(player1, player2);      // initializing a new child class object, assigning to base class pointer
				break;
			case 2:
				obj1 = new mathsGame(player1);
				break;
			case 3:
				obj1 = new CasinoGame(player1);
				break;
			case 4:
				obj1 = new Hangman();
				break;
			case 5:
				obj1 = new CarGame(player1);
				break;
			case 6:
				obj1 = new FlappyBird(player1);
				break;
			case 7:
				obj1 = new DinoRun(player1);
				break;
			case 8:
				obj1 = new SpaceShooter(player1);
				break;
			default:
				return 0;
		}
		obj1->instruction();  // calling the function, run time polymorphism, invokes function
		obj1->play();

		cout << endl << "Do you want to play again? Press N to exit, any other key to continue : ";
		if (getch()=='N') break;
		system("cls");
	}
	return 0;
}