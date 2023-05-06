#ifndef DIFF2_H
#define DIFF2_H

#include <iostream>
#include <graphics.h>//easyX
#include <vector>

bool Mousetouch(int x, int y, RECT& r);
bool RectCrashRect(RECT& r1, RECT& r2);
void BeginUI();
void OverUI(unsigned long long &kill);
class BK;
class Hero;
class Enemy;
bool AddEnemy(vector<Enemy*> &se, IMAGE& gra_enemy);
class Bullet;
bool BeginPlay();

#endif
