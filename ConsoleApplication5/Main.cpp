#include "TicTacToe.h"
#include<Windows.h>

#include<iostream>
using namespace std;

int main()
{
	TicTacToe tic;
	int place;
	cout << "TicTacToe 1.0" << endl;
	cout << endl;
	tic.print();
	int playtimes = 1;                                                                      // counter to check moves
	while (1)
	{

		cout << "enter the field where you want to play" << tic.getPlayer() << ":" << endl;
		cin >> place;
		bool isvalid = tic.move(place);
		system("cls");
		if (isvalid == true)                                                                 // if move is true allow player to play

			// checking fo winner
			bool iswon = tic.isWon(playtimes);
		if (iswon == true)                                                               //  when one player wins the restart memember will be called
		{
			cout << "Player" << tic.getPlayer() << " Wins!" << endl;
			Sleep(3000);                                                                 // sleep for 5s for the player to see if he has won
			tic.restart();
			playtimes = 0;                                                               // set playtimes back to zero
			cout << "New Game. Lets play!" << endl;

		}
		else if (iswon == false && playtimes == 9)
		{
			cout << "the game ended in a DRAW! Let's play the game again in 5" << endl;
			Sleep(5000);                                                                  // sleep for 5s for the player to see if it's a draw
			tic.restart();
			playtimes = 0;                                                                // set playtimes back to zero
			cout << "New Game. Lets play!" << endl;
		}
		else
		{
			cout << " We are still playing. Check! we have " << 9 - playtimes << "moves left" << endl;//tell how many moves have left

		}
		tic.changePlayer();                                                                     // change player if move is valid
		playtimes++;                                                                    // increase the number of play times after everyplay
	}
		else
		{
			cout << "illegal move! Try again" << endl;

			tic.print();
			continue;
		}

		tic.print();

}

cout << endl;
system("pause");
return 0;
}