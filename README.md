# 1340-G12

## Our group members:
- Fu Jing (GitHub: Horace564)
- Sun Yisheng(GitHub: sys040628)
- Tang Jiaxuan (Github: tjxafa)
- Wang Jianan(GitHub: Jasper713)
- Zhu Tianming(GitHub: Arendt-Zhu)


## Background settings:
In 2057, AI has evolved the ability to think for itself and has become a threat to humanity. People will band together to fight the AI!
You, as reprentative of humanity, must pass multilple levles to beat the AI.

## Game Description:
The game is divided into three difficulties, **four** games for the easy level, **one** game for the medium level, and **two** games for advanced level.  
All the games are single player games.
You may start from the esay level, then medium level, and finnally advanced level.

## List of coding requirements:
1. Random elements in 4 easy level games
2. Data structures and dynamic memory for storing the ranking
3. File input in Sudoku game
4. Multiple files for different games
5. Proper indentation and naming styles

## List of non-standard C/C++ libraries:
1. graphics.h
2. Windows.h (for windows environment)
3. unistd.h (for linux environment)
4. conio.h

## Compilation and execution instructions
Since our files Med1.cpp and Diff2.cpp depend on external library EasyX which only supports windows, we recommend to use Visual Studio, or add -leasyx when compile the main.cpp.

However, our files Easy1.cpp, Easy2.cpp, Easy3.cpp, Easy4.cpp, and Diff1.cpp do not depends EasyX and thus can be compiled by linux. 


## Four Easy level games
  The detailed info and rules about these 4 games will be shown at the beginning of games.
  
## Medium level game
### Tic-tac-toc
This is an implementation of the classic Tic-Tac-Toe game using C++. It uses the EasyX and c++ standard library. The game features a graphical user interface and an AI opponent for the player to compete against.

Players must win AI 3 times to pass this checkpoint, and if the board is full(draw) more than or equal to 10 times, or AI wins three games first, the player loses and AI wins
## Two Difficult level games
### Sudoku
The borad would be provided, and fill in the blank in the board to let every row and collumn have number 1-9. The time taken to fininsh the game would be recorded and save to the leaderboard.
### Plane war
Use the mouse to control the plane to destroy as many enemy planes as possible. Scores earned will be recorded in the “History”
