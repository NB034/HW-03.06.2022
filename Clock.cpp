#include "Clock.h"
#include <iostream>

using namespace std;

Clock_::Clock_(int h, int m, int s) {
	setClock(h, m, s);
}

Clock_& Clock_::setHours(int h) {
	if (0 <= h && h < 24)
		hours = h;
	else
		hours = 0;
	return *this;
}
Clock_& Clock_::setMinutes(int m) {
	if (0 <= m && m < 60)
		minutes = m;
	else
		minutes = 0;
	return *this;
}
Clock_& Clock_::setSeconds(int s) {
	if (0 <= s && s < 60)
		seconds = s;
	else
		seconds = 0;
	return *this;
}
Clock_& Clock_::setClock(int h, int m, int s) {
	setHours(h);
	setMinutes(m);
	setSeconds(s);
	return *this;
}

int Clock_::getHours() const { return hours; }
int Clock_::getMinutes() const { return minutes; }
int Clock_::getSeconds() const { return seconds; }

void Clock_::printClock() const {
	if (hours < 10)
		cout << "0";
	cout << hours << ":";
	if (minutes < 10)
		cout << "0";
	cout << minutes << ":";
	if (seconds < 10)
		cout << "0";
	cout << seconds;
}
void Clock_::setClockWithSeconds(int sec) {
	this->seconds = sec % 60;
	this->hours = sec / 3600;
	this->minutes = (sec - this->seconds - this->hours * 3600) / 60;
	this->hours %= 24;
}

Clock_& Clock_::operator++() {
	seconds++;
	if (seconds == 60) {
		seconds = 0;
		minutes++;
		if (minutes == 60) {
			minutes = 0;
			hours++;
			if (hours == 24)
				hours = 0;
		}
	}
	return *this;
}
Clock_ Clock_::operator++(int) {
	Clock_ cl = *this;
	seconds++;
	if (seconds == 60) {
		seconds = 0;
		minutes++;
		if (minutes == 60) {
			minutes = 0;
			hours++;
			if (hours == 24)
				hours = 0;
		}
	}
	return cl;
}
Clock_& Clock_::operator--() {
	seconds--;
	if (seconds == -1) {
		seconds = 59;
		minutes--;
		if (minutes == -1) {
			minutes = 59;
			hours--;
			if (hours == -1)
				hours = 23;
		}
	}
	return *this;
}
Clock_ Clock_::operator--(int) {
	Clock_ cl = *this;
	seconds--;
	if (seconds == -1) {
		seconds = 59;
		minutes--;
		if (minutes == -1) {
			minutes = 59;
			hours--;
			if (hours == -1)
				hours = 23;
		}
	}
	return cl;
}

Clock_& Clock_::operator+=(const Clock_& right) {
	this->seconds += right.seconds;
	if (this->seconds >= 60) {
		this->seconds -= 60;
		this->minutes++;
	}
	this->minutes += right.minutes;
	if (this->minutes >= 60) {
		this->minutes -= 60;
		this->hours++;
	}
	this->hours += right.hours;
	if (hours >= 24)
		this->hours -= 24;
	return *this;
}
Clock_& Clock_::operator-=(const Clock_& right) {
	this->seconds -= right.seconds;
	if (this->seconds < 0) {
		this->seconds += 60;
		this->minutes--;
	}
	this->minutes -= right.minutes;
	if (this->minutes < 0) {
		this->minutes += 60;
		this->hours--;
	}
	this->hours -= right.hours;
	if (hours < 0)
		this->hours += 24;
	return *this;
}

Clock_ operator+(const Clock_& left, const Clock_& right) {
	Clock_ res = left;
	return res += right;
}
Clock_ operator-(const Clock_& left, const Clock_& right) {
	Clock_ res = left;
	return res -= right;
}

bool operator==(const Clock_& left, const Clock_& right) {
	if (left.hours == right.hours)
		if (left.minutes == right.minutes)
			return left.seconds == right.seconds;
	return false;
}
bool operator!=(const Clock_& left, const Clock_& right) {
	return !(left == right);
}
bool operator<(const Clock_& left, const Clock_& right) {
	if (left.hours < right.hours)
		return true;
	else if (left.hours > right.hours)
		return false;
	else {
		if (left.minutes < right.minutes)
			return true;
		else if (left.minutes > right.minutes)
			return false;
		else
			return left.seconds < right.seconds;
	}
}
bool operator>(const Clock_& left, const Clock_& right) {
	return !(left < right) && !(left == right);
}
bool operator<=(const Clock_& left, const Clock_& right) {
	return !(left > right);
}
bool operator>=(const Clock_& left, const Clock_& right) {
	return !(left < right);
}

ostream& operator<<(ostream& out, const Clock_& cl) {
	cl.printClock();
	return out;
}
istream& operator>>(istream& in, Clock_& cl) {
	int tmp;
	cout << "Hours: ";
	in >> tmp;
	cl.setHours(tmp);
	cout << "Minutes: ";
	in >> tmp;
	cl.setMinutes(tmp);
	cout << "Seconds: ";
	in >> tmp;
	cl.setSeconds(tmp);
	return in;
}