// BouncingBall.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
using namespace std;
struct Position {
	int x = 0;
	int y = 0;
};
struct Velocity
{
	int x = 0;
	int y = 0;
};
vector<bool>row(80, 0);
vector<vector<bool>> screen;
Position p;
Velocity v;

void inertia();
void gravity();
void makeScreen();
void showPath();
void display();
int main() {
	v.y = 2;
	p.x = 10;
	makeScreen();
	showPath();
	display();

	this_thread::sleep_for(2000ms);

	system("CLS");
	while (true)
	{
		inertia();
		gravity();
		showPath();
		display();
		this_thread::sleep_for(100ms);
		system("CLS");
	}

}
void makeScreen() {
	for (size_t i = 0; i < 40; i++)
	{
		screen.push_back(row);
	}

}
void inertia()
{
	int ground = screen.size() - 1;

	if (p.x + v.x >= ground) {
		v.x = -v.x + 2;

	}

	p.x += v.x;


	p.y += v.y;

}
void gravity()
{
	v.x += 2;
}
void showPath()
{
	for (size_t i = 0; i < screen.size(); i++)
	{
		for (size_t j = 0; j < row.size(); j++)
		{
			if (p.x == i && p.y == j)
			{
				screen[i][j] = true;
			}
		}
	}
}
void display()
{
	for (size_t i = 0; i < screen.size(); i++)
	{
		for (size_t j = 0; j < row.size(); j++)
		{
			if (screen[i][j])
			{
				cout << "0";
			}
			else if (i == screen.size() - 1) {
				cout << "_";
			}
			else
			{

				cout << " ";

			}

		}
		cout << endl;
	}
}