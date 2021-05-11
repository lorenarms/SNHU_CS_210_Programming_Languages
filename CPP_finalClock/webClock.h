#pragma once

#include <stdio.h>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include "time.h"
#include <string>
#include "webClock.h"
#include <iomanip>
#include <iostream>
#include "clockMenus.h"
#include "cursorSet.h"

using namespace std;

class webClock 
{

public:
	int h, m, s, mh;
	string tod = "";
	webClock(int h, int m, int s, int mh) {
		this->h = h;
		this->m = m;
		this->s = s;
		this->mh = mh;


	}
	
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

	
	webClock changeTime(webClock newTimer, cursorSet newCursorLoc);
	
	
};

