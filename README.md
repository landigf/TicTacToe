# TicTacToe
The game consists of a 3x3 grid in which two players (the first player is the human player, the second is the computer) compete in turn to fill the boxes with their symbols ("X" or "O").

The code defines various functions to manage the various phases of the game, such as the creation of the grid, the choice of squares by the players, the control of victory or defeat. The game runs in a "do-while" loop, which continues until one of the players wins or the grid is filled completely. At the end of the game, a victory or a tie message is displayed depending on the result.

The Choice_Player() function asks the user to enter the desired position for his move using numpad numbers. The PC_Choice() function uses logic to decide the best position for the AI to move. Both functions use the Board() function to print the current game board to the screen.
