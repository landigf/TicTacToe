#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 *  ITA: Tris usando un'array bidimensionale
 *  EN: Tic Tac Toe using an 2D array
 */

void CreateGame(char [][3]); // Initializes the game board
void CreateGame2(int [][3]); // Initializes a board for the computer
void PlayerChoice(char [][3]); // Handles player's choice of square
void PC_Choice(char [][3], int [][3]); // Handles computer's choice of square
void Win_Lose(char [][3], char, int [][3], bool *); // Check for a possible Win or Lose for the computer
void BestChoice(char [][3], int [][3]); // Chooses the best square for the computer
void Board(char [][3], int, int);
void Board2(int [][3]);
void Increase(int [][3], int, int);
char Check(char [][3]); // Checks if there is a winner
void Tris();
void cls();

int main()
{
    bool player = true;

    int plays = 9; // mosse possibili durante la partita

    char game[3][3]; // declare an 2D array of tic tac toe
    int computerBoard[3][3];
    
    CreateGame(game); // initialize the board
    CreateGame2(computerBoard);
    
    do // play the game
    {
        if (player) PlayerChoice(game);
        else PC_Choice(game, computerBoard);
        player = !player;
        plays--;
    } while (Check(game) == ' ' && plays > 0);
    
    Board(game, 0, 0);
    
    switch (Check(game))
    {
        case 'X':
            printf("Player 1 Wins");
            break;
        case 'O':
            printf("Computer Wins");
            break;
        default:
            printf("Pareggio");
    }

    printf("\n\n\n\n");
    getch();
    return 0;
}

void CreateGame(char game[][3])
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            game[i][j] = ' ';
        }
    }
}

void CreateGame2(int computerBoard[][3])
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            computerBoard[i][j] = 0;
        }
    }
}

void PlayerChoice(char game[][3])
{
    int posX = 1;
    int posY = 1;
    if (game[posY][posX] == ' ') game[posY][posX] = '_';
    Board(game, posX, posY);
    printf("Player 1: ");
    if (game[posY][posX] == '_') game[posY][posX] = ' ';
    char ch;
    bool flag = false;
    do
    {
        ch = getch();
        // ITA: segli la casella con i numeri
        // EN: moving aroung using numbers
        switch(ch)
        {
            case '7':
                posX = 0;
                posY = 0;
                break;
            case '8':
                posX = 1;
                posY = 0;
                break;
            case '9':
                posX = 2;
                posY = 0;
                break;
            case '4':
                posX = 0;
                posY = 1;
                break;
            case '5':
                posX = 1;
                posY = 1;
                break;
            case '6':
                posX = 2;
                posY = 1;
                break;
            case '1':
                posX = 0;
                posY = 2;
                break;
            case '2':
                posX = 1;
                posY = 2;
                break;
            case '3':
                posX = 2;
                posY = 2;
                break;
            case 13:
                flag = !flag;
                break;
            default:
                break;
        }
        if (flag && game[posY][posX] == ' ') break;
        if (game[posY][posX] == ' ') game[posY][posX] = '_';
        
        Board(game, posX, posY);
        printf("Player 1: ");
        
        if (game[posY][posX] == '_') game[posY][posX] = ' ';
        
    } while (!(flag && game[posY][posX] == ' '));
    game[posY][posX] = 'X';
    
    Board(game, posX, posY);
}

void PC_Choice(char game[][3], int computerBoard[][3])
{
    bool flag = true;
    Win_Lose(game, 'O', computerBoard, &flag);
    if (flag) Win_Lose(game, 'X', computerBoard, &flag);
    if (flag) BestChoice(game, computerBoard);
}

void Win_Lose (char game[][3], char ch, int computerBoard[][3], bool *flag)
{
    int i, j, posX, posY, count = 0;
    for (i = 0; i < 3; i++)for (j = 0; j < 3; j++)
        {
            if (game[i][j] == ch)
            {
                count++;
                Increase(computerBoard, i, j);
            }
            else (posX = j);
        }
    {
        for (j = 0; j < 3; j++)
        {
            if (game[i][j] == ch)
            {
                count++;
                Increase(computerBoard, i, j);
            }
            else (posX = j);
        }
        if (count == 2 && game[i][posX] == ' ')
        {
            game[i][posX] = 'O';
            *flag = false;
            return;
        }
        count = 0;
    }

    for (j = 0; j < 3; j++)
    {
        for (i = 0; i < 3; i++)
        {
            if (game[i][j] == ch)
            {
                count++;
                Increase(computerBoard, i, j);
            }
            else (posY = i);
        }
        if (count == 2 && game[posY][j] == ' ')
        {
            game[posY][j] = 'O';
            *flag = false;
            return;
        }
        count = 0;
    }

    j = 0;
    for (i = 0; i < 3; i++)
    {
        if (game[i][j] == ch)
        {
            count++;
            Increase(computerBoard, i, j);
        }
        else
        {
            (posX = j);
            (posY = i);
        }
        j++;
    }
    if (count == 2 && game[posY][posX] == ' ')
    {
        game[posY][posX] = 'O';
        *flag = false;
        return;
    }
    count = 0;

    j = 2;
    for (i = 0; i < 3; i++)
    {
        if (game[i][j] == ch)
        {
            count++;
            Increase(computerBoard, i, j);
        }
        else
        {
            (posX = j);
            (posY = i);
        }
        j--;
    }
    if (count == 2 && game[posY][posX] == ' ')
    {
        game[posY][posX] = 'O';
        *flag = false;
        return;
    }
    count = 0;
}

void BestChoice(char game[][3], int computerBoard[][3])
{
    int i, j, posX, posY, oldX, oldY, max = -1;
    do
    {
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (game[i][j] != ' ') computerBoard[i][j] = 0;
                if (max < computerBoard[i][j] && (i != oldY || j != oldX))
                {
                    max = computerBoard[i][j];
                    posX = j;
                    posY = i;
                }
            }
        }
        oldY = posY;
        oldX = posX;
        max = -1;
    } while (game[posY][posX] != ' ');
    game[posY][posX] = 'O';
}

void Increase(int computerBoard[][3], int posY, int posX)
{
    int i, j;
    for (i = posY-1; i <= posY+1; i++)
    {
        for (j = posX-1; j <= posY+1; j++)
        {
            if (i >= 0 && i < 3 && j >= 0 && j < 3 && !(i == posY && j == posX)) computerBoard[i][j]++;
        }
    }
}

void Board(char game[][3], int posX, int posY)
{
    cls();
    int i, j;
    // crea la board per inserire i valori
    printf("\t\t\t Tic Tac Toe \n\n");
    printf("\t\tPlayer 1 (X) - Computer (O) \n\n\n");
    printf("Seleziona la casella libera usando il tastiero numerico, partendo sempre dal centro [1][1]\n");
    if(game[1][1] == '_') Tris();
    printf("\n");
    printf("\tPer selezionare la casella scelta premere 'INVIO'\n\n");
    printf("\tCasella attualmente selezionata: [%d][%d]", posX, posY);
    printf("\n\n");
    for(i = 0; i < 11; i++)
    {
        printf("\t\t  ");
        if (i == 1) printf("   %c   |   %c   |   %c   ", game[0][0], game[0][1], game[0][2]);
        else if (i == 5) printf("   %c   |   %c   |   %c   ", game[1][0], game[1][1], game[1][2]);
        else if (i == 9) printf("   %c   |   %c   |   %c   ", game[2][0], game[2][1], game[2][2]);
        else if (i == 3 || i == 7) printf("-----------------------");
        else
        {
            for(j = 0; j < 23; j++)
            {
                if (j == 7 || j == 15) printf("|");
                else printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void Board2(int computerBoard[][3])
{
    int i, j;
    // crea la board per inserire i valori
    printf("\t\t\t Computer Board \n\n");
    for(i = 0; i < 11; i++)
    {
        printf("\t\t  ");
        if (i == 1) printf("   %d   |   %d   |   %d   ", computerBoard[0][0], computerBoard[0][1], computerBoard[0][2]);
        else if (i == 5) printf("   %d   |   %d   |   %d   ", computerBoard[1][0], computerBoard[1][1], computerBoard[1][2]);
        else if (i == 9) printf("   %d   |   %d   |   %d   ", computerBoard[2][0], computerBoard[2][1], computerBoard[2][2]);
        else if (i == 3 || i == 7) printf("-----------------------");
        else
        {
            for(j = 0; j < 23; j++)
            {
                if (j == 7 || j == 15) printf("|");
                else printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

char Check(char game[][3])
{
    int i;
    for (i = 0; i < 3; i++)
    {
        if (game[i][0] == game [i][1] && game[i][0] == game[i][2])
        {
            if (game[i][0] != ' ') return game[i][0];
        }
    }
    
    for (i = 0; i < 3; i++)
    {
        if (game[0][i] == game [1][i] && game[0][i] == game[2][i])
        {
            if (game[0][i] != ' ') return game[0][i];
        }
    }
    
    if (game[0][0] == game [1][1] && game[0][0] == game[2][2])
    {
        if (game[0][0] != ' ') return game[0][0];
    }
    
    if (game[0][2] == game [1][1] && game[0][2] == game[2][0])
    {
        if (game[0][2] != ' ') return game[0][2];
    }
    
    return ' ';
}

void Tris()
{
    int i, j;
    for(i = 0; i < 11; i++)
    {
        printf("\t\t  ");
        if (i == 1) printf("   7   |   8   |   9   ");
        else if (i == 5) printf("   4   |   5   |   6   ");
        else if (i == 9) printf("   1   |   2   |   3   ");
        else if (i == 3 || i == 7) printf("-----------------------");
        else
        {
            for(j = 0; j < 23; j++)
            {
                if (j == 7 || j == 15) printf("|");
                else printf(" ");
            }
        }
        printf("\n");
    }
}

void cls()
{
    system("cls||clear");
}
