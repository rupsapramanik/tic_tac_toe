#include <stdio.h>

char square[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int choice, player;
int checkForWin();
void displayBoard();
void markBoard(char mark);

int main()
{
    int gameStatus;
    char mark;
    player = 1;

    do
    {
        displayBoard();
        //change turn
        player = (player % 2) ? 1 : 2;

        //get input
        printf("Player%d, Enter a Number: ", player);
        scanf("%d", &choice);

        //set the correct character
        mark = (player == 1) ? 'X' : 'O';

        //set the board based on choice
        markBoard(mark);
        gameStatus = checkForWin();
        player++;
    } while (gameStatus == -1);

    if (gameStatus == 1)
    {
        printf("--> Player%d WIN <-- \n \n", --player);
    }
    else
    {
        printf("--> Game Draw <-- \n\n");
    }

    return 0;
}

/*function return game status
  1 for game is over with result
  -1 game is in progress
  0 game is over with no result*/
int checkForWin()
{
    int returnValue = 0;

    //horizontal
    if (square[1] == square[2] && square[2] == square[3])
    {
        returnValue = 1;
    }
    else if (square[4] == square[5] && square[5] == square[6])
    {
        returnValue = 1;
    }
    else if (square[7] == square[8] && square[8] == square[9])
    {
        returnValue = 1;
    }

    //diagonal
    else if (square[1] == square[5] && square[5] == square[9])
    {
        returnValue = 1;
    }
    else if (square[3] == square[5] && square[5] == square[7])
    {
        returnValue = 1;
    }

    //vertical
    else if (square[1] == square[4] && square[4] == square[7])
    {
        returnValue = 1;
    }
    else if (square[2] == square[5] && square[5] == square[8])
    {
        returnValue = 1;
    }
    else if (square[3] == square[6] && square[6] == square[9])
    {
        returnValue = 1;
    }

    //gave over with no result
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
    {
        returnValue = 0;
    }

    else
    {
        returnValue = -1;
    }

    return returnValue;
}

//function to draw game board
void displayBoard()
{
    printf("\n\n     Tic Tac Toe   \n\n");
    printf("Player1 (X) -- Player2 (O)\n\n");
    printf("  ____ ____ ____\n");
    printf(" |    |    |    |\n");
    printf(" | %c  | %c  | %c  |\n", square[1], square[2], square[3]);
    printf(" |____|____|____|\n");
    printf(" |    |    |    |\n");
    printf(" | %c  | %c  | %c  |\n", square[4], square[5], square[6]);
    printf(" |____|____|____|\n");
    printf(" |    |    |    |\n");
    printf(" | %c  | %c  | %c  |\n", square[7], square[8], square[9]);
    printf(" |____|____|____|\n");
}

//Set the board with the correct character
// X or O in the correct spot
void markBoard(char mark)
{
    if (choice == 1 && square[1] == '1')
    {
        square[1] = mark;
    }
    else if (choice == 2 && square[2] == '2')
    {
        square[2] = mark;
    }
    else if (choice == 3 && square[3] == '3')
    {
        square[3] = mark;
    }
    else if (choice == 4 && square[4] == '4')
    {
        square[4] = mark;
    }
    else if (choice == 5 && square[5] == '5')
    {
        square[5] = mark;
    }
    else if (choice == 6 && square[6] == '6')
    {
        square[6] = mark;
    }
    else if (choice == 7 && square[7] == '7')
    {
        square[7] = mark;
    }
    else if (choice == 8 && square[8] == '8')
    {
        square[8] = mark;
    }
    else if (choice == 9 && square[9] == '9')
    {
        square[9] = mark;
    }
    else
    {
        printf("Invalid Move");

        player--;
    }
}