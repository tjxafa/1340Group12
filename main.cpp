#include <iostream>
#include <string>
#include <vector>
#include "Easy1.h"
#include "Easy2.h"
#include "Easy3.h"
#include "Easy4.h"
#include "Med1.h"

#include "Diff1.h"
#include "Diff2.h"

using namespace std;

enum Difficulty { EASY, MEDIUM, HARD };

struct MiniGame {
string name;
Difficulty difficulty;
bool completed;
string description;
int (*playGame)(); // Function pointer to play the mini-game
};

struct Player {
string name;
int score;
};

bool checkVictoryCondition(const vector<MiniGame>& games) {
for (const MiniGame& game : games) {
if (!game.completed) {
return false;
}
}
return true;
}

void displayRankingTable(const Player& player) {
// For now, we only have one player, so the ranking table only contains that player.
cout << "Ranking Table:\n";
cout << "1. " << player.name << " - " << player.score << " points\n";
}

int main() {
string playerName;
cout << "Enter your name: ";
cin >> playerName;
Player player = {playerName, 100};
bool game_over = false;

// Game background story
cout << "Welcome, " << playerName << "! The world has been devastated by an unknown force, and humanity is on the brink of extinction. You have been chosen to complete a series of tasks that could save us all.\n";
cout << "Each task will consume some of your energy. You start with 100 energy points, and if your energy is depleted, you will fail in your mission to save humanity.\n\n";

// Initialize mini-games
vector<MiniGame> games = {
{"Communication Interference", EASY, false, "Re-establish the communication network disrupted by the Mechs", playEasy1},
{"Energy Crisis", EASY, false, "Restart the nuclear power plants controlled by the Mechs to restore power supply", playEasy2},
{"Virus Invasion", EASY, false, "Eliminate the malware implanted by the Mechs to protect critical information systems", playEasy3},
{"Tactical Stealth", EASY, false, "Infiltrate the Mech base to gather intelligence on their plans", playEasy4},
{"Counterattack", MEDIUM, false, "Organize and execute a carefully planned counterattack to destroy the Mechs' strategic fortress", playMed1},

{"Mind War", HARD, false, "Delve deep into the Mechs' consciousness network to persuade some of them to join the human cause", playDiff1},
{"The Ultimate Battle", HARD, false, "Launch an unprecedented large-scale battle to completely destroy the Mechs' command center", playDiff2},
};

int size = games.size();
int choice;

while (!game_over) {
    cout << "\nTasks:\n";
    for (int i = 0; i < size; i++) {
        if (!games[i].completed) {
            cout << i + 1 << ". " << games[i].name << endl;
        }
    }
    cout << "0. Give up and let humanity perish\n";
    cout << "\nChoose a task to complete (0 to give up): ";
    cin >> choice;

    if (choice == 0) {
        game_over = true;
        cout << "You have given up. Humanity is lost.\n";
    } else {
        choice--;  // Adjust for 0-based index
        int result = games[choice].playGame();  // Call the mini-game function

        if (result == 1) {
            games[choice].completed = true;

            int points;
            if (games[choice].difficulty == EASY) points = 10;
            else if (games[choice].difficulty == MEDIUM) points = 20;
            else if (games[choice].difficulty == HARD) points = 30;

            player.score -= points;
            if (player.score <= 0) {
                cout << "Unfortunately, you failed to save humanity.\n";
                game_over = true;
            }
        } else {
            cout << "You did not pass the task. Try again or choose another task.\n";
        }
    }

    if (checkVictoryCondition(games)) {
        if (player.score > 0) {
            cout << "\nCongratulations, " << playerName << "! You have successfully completed all tasks and saved humanity!\n";
        } else {
            cout << "\nYou have completed all tasks, but you have exhausted your energy. Humanity's fate remains uncertain.\n";
        }
        displayRankingTable(player);
        game_over = true;
    }
}
}