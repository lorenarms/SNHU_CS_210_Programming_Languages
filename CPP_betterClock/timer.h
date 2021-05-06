#pragma once

using namespace std;

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

class timer
{
public:
	int h, m, s;
	timer(int h, int m, int s) {
		this->h = h;
		this->m = m;
		this->s = s;
	}
	

public:
	int getHours() {
		return h;
	}
	void setHours(int h) {
		this->h = h;
	}


	int getMinutes() {
		return m;
	}
	void setMinutes(int m) {
		this->m = m;
	}

	int getSeconds() {
		return s;
	}
	void setSeconds(int s) {
		this->s = s;
	}

	int runMinutes() {
		
		return m;
	}
	void runTimer() {
		
		s--;
		if (s < 0) {
			m--;
			s = 59;
			if (m < 0) {
				h--;
				m = 59;
			}
		}
		
		

	}

	int checkTime() {
		if (h + m + s == 0) {
			return 2;
		}
		else {
			return 1;
		}
	}

	void timeIsUp() {
		for (int i = 0; i < 5; i++) {
			system("cls");
			Sleep(250);
			cout << "Time is up!" << endl;
			Sleep(250);
		}
		cout << "Time is up!" << endl;
	}



};

