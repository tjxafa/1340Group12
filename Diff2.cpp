#include <iostream>
#include <graphics.h>//easyX
#include <vector>

using namespace std;

//set the width and height of the screen
constexpr auto width = 1920;
constexpr auto height = 1080;

constexpr unsigned int SHP = 4;//blood

constexpr auto hurttime = 1000;//ms

unsigned long long his[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
unsigned long long ord = 0-1;

bool Mousetouch(int x, int y, RECT& r)
{
	return (r.left <= x && x <= r.right && r.top <= y && y <= r.bottom);
}

//invoid the enemy clip together
bool RectCrashRect(RECT& r1, RECT& r2) {
	RECT r;//the range of crush happen
	r.left = r1.left - (r2.right - r2.left);
	r.right = r1.right;
	r.top = r1.top - (r2.bottom - r2.top);
	r.bottom = r1.bottom;

	return (r.left < r2.left && r2.left <= r.right && r.top <= r2.top && r2.top <= r.bottom);

}

//a begin UI
void BeginUI() {
	//style of bg
	setbkcolor(WHITE);
	cleardevice();
	settextstyle(50, 0, _T("RM_B"));
	settextcolor(BLACK);
	//word on main UI
	LPCTSTR title = _T("War of Warplane");
	LPCTSTR play = _T("Touch to Begin");
	LPCTSTR LB = _T("History");
	LPCTSTR exit_b = _T("Exit");
	//print title
	outtextxy(width / 2 - textwidth(title) / 2 - 200, height / 5, title);
	//range of the button
	RECT play1, exit1, LB1;
	settextstyle(40, 0, _T("RM_B"));
	//range of play button
	play1.left = width / 2 - textwidth(play) / 2 - 200;
	play1.right = play1.left + textwidth(play);
	play1.top = height / 5 * 2;
	play1.bottom = play1.top + textheight(play);
	//range of LB button
	LB1.left = width / 2 - textwidth(LB) / 2 - 200;
	LB1.right = LB1.left + textwidth(LB);
	LB1.top = height / 5 * 2.5;
	LB1.bottom = LB1.top + textheight(LB);
	//range of exit button
	exit1.left = width / 2 - textwidth(exit_b) / 2 - 200;
	exit1.right = exit1.left + textwidth(exit_b);
	exit1.top = height / 5 * 3;
	exit1.bottom = exit1.top + textheight(exit_b);
	//print
	outtextxy(play1.left, play1.top, play);
	outtextxy(LB1.left, LB1.top, LB);
	outtextxy(exit1.left, exit1.top, exit_b);

	EndBatchDraw();

	//set function of button
	while (true)
	{
		ExMessage mess;
		getmessage(&mess, EM_MOUSE);
		if (mess.lbutton)
		{
			if (Mousetouch(mess.x, mess.y, play1)){
				return;
			}
			else if (Mousetouch(mess.x, mess.y, LB1)) {
				for (int i = 0; i < 10; i++) {
					TCHAR* str2 = new TCHAR[128];
					_stprintf_s(str2, 128, _T("Your score: %llu"), his[i]);
					outtextxy(width / 2 - textwidth(str2) / 2 + 200, height / 5 + i * 45, str2);
				}
				continue;
			}
			else if (Mousetouch(mess.x, mess.y, exit1)){
				exit(0);
			}
		}
	}

}

//an end UI
void OverUI(unsigned long long &kill) {
	unsigned long long score = kill / 10;
	his[ord] = score;
	TCHAR* str = new TCHAR[128];
	TCHAR* str1 = new TCHAR[128];
	_stprintf_s(str, 128, _T("Beat Enemy: %llu"), kill);//set string of number of kill
	_stprintf_s(str1, 128, _T("Cumulative Score: %llu"), score);//set string of number of score

	outtextxy(width / 2 - textwidth(str) / 2 - 200, height / 5, str);//print the kill number string
	outtextxy(width / 2 - textwidth(str1) / 2 - 200, height / 5 + 200, str1);//print the score string

	//control with keyboard(touch "Esc" button to escipe)
	LPCTSTR info = _T("Touch Esc to Return Home");
	settextstyle(20, 0, _T("RM_B"));
	settextcolor(RED);
	outtextxy(width/2 - textwidth(info) - 80, height / 5 + 400, info);
	//continues search if there is keyboard event
	while (true) {
		ExMessage km;
		getmessage(&km, EM_KEY);
		//judge if the touched button is "ESC"
		if (km.vkcode == 0x1B) {
			return;
		}
	}

}
//background when playing
class BK
{
public:
	BK(IMAGE& img)
		:img(img), x(0){

	}
	void Show(){
		if (x == -width) { 
			x = 0; 
		}
		x -= 8;
		putimage(x, 0, &img);
	}

private:
	IMAGE& img;
	int x;

};

//Hero
class Hero{
public:
	Hero(IMAGE& img)
		:img(img){
		//range of hero
		rect.left = 0;
		rect.top = height / 2 - img.getheight() / 2;
		rect.right = img.getwidth();
		rect.bottom = rect.top + img.getheight();
	}
	void Show(){
		//initial position
		putimage(rect.left, rect.top, &img);
	}
	//control the position of hero
	void Control(){
		ExMessage mess;
		if (peekmessage(&mess, EM_MOUSE)){
			//position of mouse
			rect.left = mess.x - img.getwidth() / 2;
			rect.top = mess.y - img.getheight() / 2;
			rect.right = rect.right = rect.left + img.getwidth();
			rect.bottom = rect.top + img.getheight();
		}
	}
	RECT& GetRect() { return rect; }

private:
	IMAGE& img;
	RECT rect;


};

//Enemy
class Enemy {
public:
	Enemy(IMAGE& img, int y)
		:img(img) {
		//position of enemy
		rect.top = y;
		rect.bottom = rect.top + img.getheight();
		rect.left = width;
		rect.right = width + img.getwidth();
	}
	bool Show() {

		//die if out of playground
		if (rect.right <= 0) {
			return false;
		}
		//move the enemy
		rect.right -= 15;
		rect.left -= 15;
		putimage(rect.left, rect.top, &img);

		return true;
	}
	RECT& GetRect() { return rect; }
private:
	IMAGE& img;
	RECT rect;
};

//add enemy
bool AddEnemy(vector<Enemy*> &se, IMAGE& gra_enemy){
	Enemy* e = new Enemy(gra_enemy, abs(rand()) % (height - gra_enemy.getheight()));
	for (auto& i : se) {
		//judge if enemy slip with each other
		if (RectCrashRect(i->GetRect(), e->GetRect())) {
			delete e;
			return false;
		}
	}
	se.push_back(e);
	return true;
}

//bullet of hero
class Bullet{
public:
	Bullet(IMAGE& img, RECT pr)
		:img(img){
		//size of bullet
		rect.left = pr.right;
		rect.right = rect.left + img.getwidth();
		rect.top = pr.bottom - (pr.bottom - pr.top) / 2 - img.getheight() / 2;
		rect.bottom = rect.top + img.getheight();
	}
	bool Show(){
		if (rect.left >= width)
		{
			return false;
		}
		rect.right += 10;
		rect.left += 10;
		putimage(rect.left, rect.top, &img);

		return true;
	}
	RECT& GetRect() { return rect; }

protected:
	IMAGE& img;
	RECT rect;
};

bool BeginPlay() {
	//style of playground
	setbkcolor(WHITE);
	cleardevice();
	bool begin_play = true;
	//import graph
	IMAGE gra_hero, gra_enemy, gra_background, gra_bullet;
	IMAGE eboom[3];

	loadimage(&gra_hero, _T("../image/hero.png"));
	loadimage(&gra_enemy, _T("../image/enemy.png"));
	loadimage(&gra_background, _T("../image/bk.png"), width*2, height);
	loadimage(&gra_bullet, _T("../image/bullet.png"));

	loadimage(&eboom[0], _T("../image/enemy1_down2.png"));
	loadimage(&eboom[1], _T("../image/enemy1_down3.png"));
	loadimage(&eboom[2], _T("../image/enemy1_down4.png"));
	
	BK bk = BK(gra_background);
	Hero hp = Hero(gra_hero);
	
	//store the enemy
	vector<Enemy*> se;
	vector<Bullet*> sb;
	int sbf = 0;//auto shoot by number of frame

	unsigned long long kill = 0;

	for (int i = 0; i < 10; i++) {
		AddEnemy(se, gra_enemy);
	}


	while (begin_play) {
		sbf++;
		if (sbf == 10) {
			sbf = 0;
			sb.push_back(new Bullet(gra_bullet, hp.GetRect()));
		}

		BeginBatchDraw();

		//show the playground and control
		bk.Show();
		Sleep(6);
	    flushmessage();
		Sleep(2);
		hp.Control();
		hp.Show();

		//draw the bullet
		for (auto& i : sb) {
			i->Show();
		}

		auto it = se.begin();
		while (it != se.end()) {
			if (RectCrashRect((*it)->GetRect(), hp.GetRect())) {
				begin_play = false;
			}
			auto bit = sb.begin();
			//if bullet crush enemy delete both of them
			while (bit != sb.end()) {
				if (RectCrashRect((*bit)->GetRect(), (*it)->GetRect())) {
					delete(*it);
					it = se.erase(it);
					it = se.begin();
					delete (*bit);
					sb.erase(bit);

					kill++;

					break;
				}
				bit++;
			}
			if (!(*it)->Show()) {
				delete(*it);
				it = se.erase(it);
				it = se.begin();
			}
			it++;
		}
		for (int i = 0; i < 5 - se.size(); i++) {
			AddEnemy(se, gra_enemy);
		}
		EndBatchDraw();
	}
	OverUI(kill);

	return true;
}

//judge if earn score in main game
bool playDiff2(){
	if (his[ord] > 5) {
		return true;
	}
	else {
		return false;
	}
}


int main() {
	initgraph(width,height, EW_NOMINIMIZE | EW_SHOWCONSOLE);//initialize easyX
	bool living = true;
	while (living) {
		BeginUI();//show the ui of beginning screen
		//begin to play
		ord++;
		//end during playing
		living = BeginPlay();
		

	}



	return 0;
}
