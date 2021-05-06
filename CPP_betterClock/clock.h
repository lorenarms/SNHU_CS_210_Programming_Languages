#pragma once

using namespace std;

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string>


class clockk
{
	
public:
	int h, m, s, mh;
	string tod = "";
	clockk(int h, int m, int s, int mh) {
		this->h = h;
		this->m = m;
		this->s = s;
		this->mh = mh;

	}

public:
	int getHours() {
		return h;
	}
	int getMHours() {
		return mh;
	}
	void setHours(int h) {
		if (h > 23) {
			this->h = 0;
		}
		else {
			this->h = h;
		}
		
		
		
	}
	void setMHours(int h) {
		if (h > 12) {
			mh = h - 12;
			tod = "PM";
		}
		else if (h == 0) {
			mh = 12;
			tod = "AM";
		}
		else {
			mh = h;
			tod = "AM";
		}
		
		
	}

	int getMinutes() {
		return m;
	}
	void setMinutes(int m) {
		if (m > 59) {
			this->m = 0;
		}
		else {
			this->m = m;
		}
		
	}

	int getSeconds() {
		return s;
	}
	void setSeconds(int s) {
		if (s > 59) {
			this->s = 0;
		}
		else {
			this->s = s;
		}
		
	}

	string getTOD() {
		return tod;
	}

	int runMinutes() {

		return m;
	}
	void runClock() {

		s++;
		if (s > 59) {
			m++;
			s = 0;
			if (m > 59) {
				h++;
				mh++;
				m = 0;
			}
		}



	}
public: 
		void timeStamp() {
		cout << "TIME STAMP" << endl;
		return;
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

