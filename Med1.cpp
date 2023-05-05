#include "med1.h"
#include <graphics.h>
#include <conio.h>
#include <thread>
#include <chrono>
#include <vector>
#include <cstdlib>
#include <ctime>


const int unitSize = 100;
const int borderWidth = 5;

enum Player { NONE, PLAYER1, PLAYER2 };

Player board[3][3] = { {NONE, NONE, NONE}, {NONE, NONE, NONE}, {NONE, NONE, NONE} };

void drawBoard();
void drawX(int x, int y);
void drawO(int x, int y);
bool isWin(Player player);

void aiMove(Player aiPlayer) {
    // Find available moves
    std::vector<std::pair<int, int>> availableMoves;
    for (int x = 0; x < 3; ++x) {
        for (int y = 0; y < 3; ++y) {
            if (board[x][y] == NONE) {
                availableMoves.push_back({ x, y });
            }
        }
    }

    Player opponent = (aiPlayer == PLAYER1) ? PLAYER2 : PLAYER1;
    int x, y;
    bool aiFoundWinningMove = false;

    // Check if AI can win
    for (const auto& move : availableMoves) {
        // Temporarily make the move on the board
        board[move.first][move.second] = aiPlayer;

        // If the AI would win with this move, make the move
        if (isWin(aiPlayer)) {
            x = move.first;
            y = move.second;
            aiFoundWinningMove = true;
            break;
        }

        // Undo the temporary move
        board[move.first][move.second] = NONE;
    }

    // If AI did not find a winning move, check if the player is about to win and block them
    if (!aiFoundWinningMove) {
        bool blockedOpponent = false;
        for (const auto& move : availableMoves) {
            // Temporarily make the move on the board
            board[move.first][move.second] = opponent;

            // If the opponent would win with this move, block them
            if (isWin(opponent)) {
                x = move.first;
                y = move.second;
                board[x][y] = aiPlayer;
                blockedOpponent = true;
                break;
            }

            // Undo the temporary move
            board[move.first][move.second] = NONE;
        }

        // If the AI didn't block the opponent, make a random move
        if (!blockedOpponent) {
            srand(static_cast<unsigned>(time(0)));
            int randomIndex = rand() % availableMoves.size();
            x = availableMoves[randomIndex].first;
            y = availableMoves[randomIndex].second;

            board[x][y] = aiPlayer;
        }
    }

    // Draw the AI's move on the board
    if (aiPlayer == PLAYER1) {
        drawX(x, y);
    }
    else {
        drawO(x, y);
    }
}

// Function to check if the board is full
bool isBoardFull() {
    for (int x = 0; x < 3; ++x) {
        for (int y = 0; y < 3; ++y) {
            if (board[x][y] == NONE) {
                return false;
            }
        }
    }
    return true;
}

// Function to reset the board
void resetBoard() {
    for (int x = 0; x < 3; ++x) {
        for (int y = 0; y < 3; ++y) {
            board[x][y] = NONE;
        }
    }
    cleardevice();
    drawBoard();
}

bool playMed1() {
    initgraph(3 * unitSize, 3 * unitSize);

    setbkcolor(WHITE);
    cleardevice();

    drawBoard();

    Player currentPlayer = PLAYER1;
    bool wasLButtonDown = false;
    while (true) {
        while (_kbhit()) _getch(); // Clear keyboard buffer

        // Exit the game if ESC is pressed
        if (GetAsyncKeyState(VK_ESCAPE)) {
            break;
        }

        // Check for mouse clicks
        if (GetAsyncKeyState(VK_LBUTTON)) {
            // Get the current mouse position
            POINT mouse;
            GetCursorPos(&mouse);
            ScreenToClient(GetHWnd(), &mouse); // Convert screen coordinates to client coordinates

            int x = (mouse.x - borderWidth) / unitSize;
            int y = (mouse.y - borderWidth) / unitSize;

            // Make a move
            if (x >= 0 && x < 3 && y >= 0 && y < 3 && board[x][y] == NONE) {
                board[x][y] = currentPlayer;

                if (currentPlayer == PLAYER1) {
                    drawX(x, y);
                }
                else {
                    drawO(x, y);
                }
                if (isWin(PLAYER1)) {
                    MessageBox(NULL, _T("Player wins!"), _T("Tic-Tac-Toe"), MB_OK);
                    resetBoard();
                }
                else if (isWin(PLAYER2)) {
                    MessageBox(NULL, _T("Player wins!"), _T("Tic-Tac-Toe"), MB_OK);
                    resetBoard();
                }
                else {
                    // AI makes a move if the board is not full
                    if (!isBoardFull()) {
                        Player aiplayer;
                        if (currentPlayer == PLAYER1) {
                            aiplayer = PLAYER2;
                        }
                        else {
                            aiplayer = PLAYER1;
                        }
                        aiMove(aiplayer);

                        if (isWin(aiplayer)) {
                            MessageBox(NULL, _T("AI wins!"), _T("Tic-Tac-Toe"), MB_OK);
                            resetBoard();
                        }
                        else if (isBoardFull()) {
                            MessageBox(NULL, _T("It's a draw!"), _T("Tic-Tac-Toe"), MB_OK);
                            resetBoard();
                        }
                    }
                    else {
                        MessageBox(NULL, _T("It's a draw!"), _T("Tic-Tac-Toe"), MB_OK);
                        resetBoard();
                    }
                }
            
            }
        }

        // Sleep to avoid high CPU usage
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    closegraph();
    return false;
}


void drawBoard() {
    setcolor(BLACK);

    // Vertical lines
    for (int i = 1; i < 3; i++) {
        line(i * unitSize, 0, i * unitSize, 3 * unitSize);
    }

    // Horizontal lines
    for (int i = 1; i < 3; i++) {
        line(0, i * unitSize, 3 * unitSize, i * unitSize);
    }
}

void drawX(int x, int y) {
    setcolor(RED);
    line(x * unitSize + borderWidth, y * unitSize + borderWidth, (x + 1) * unitSize - borderWidth, (y + 1) * unitSize - borderWidth);
    line(x * unitSize + borderWidth, (y + 1) * unitSize - borderWidth, (x + 1) * unitSize - borderWidth, y * unitSize + borderWidth);
}

void drawO(int x, int y) {
    setcolor(BLUE);
    circle(x * unitSize + unitSize / 2, y * unitSize + unitSize / 2, unitSize / 2 - borderWidth);
}

bool isWin(Player player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}
