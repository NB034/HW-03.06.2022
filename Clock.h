#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

class Clock_ {
	int hours;
	int minutes;
	int seconds;
public:
	Clock_(int h = 0, int m = 0, int s = 0);

	Clock_& setHours(int h);
	Clock_& setMinutes(int m);
	Clock_& setSeconds(int s);
	Clock_& setClock(int h, int m, int s);

	int getHours() const;
	int getMinutes() const;
	int getSeconds() const;

	void printClock() const;
	void setClockWithSeconds(int sec);

	Clock_& operator++();
	Clock_ operator++(int);
	Clock_& operator--();
	Clock_ operator--(int);

	Clock_& operator+=(const Clock_& right);
	Clock_& operator-=(const Clock_& right);

	friend Clock_ operator+(const Clock_& left, const Clock_& right);
	friend Clock_ operator-(const Clock_& left, const Clock_& right);

	friend bool operator==(const Clock_& left, const Clock_& right);
	friend bool operator!=(const Clock_& left, const Clock_& right);
	friend bool operator<(const Clock_& left, const Clock_& right);
	friend bool operator>(const Clock_& left, const Clock_& right);
	friend bool operator<=(const Clock_& left, const Clock_& right);
	friend bool operator>=(const Clock_& left, const Clock_& right);

	friend ostream& operator<<(ostream& out, const Clock_& cl);
	friend istream& operator>>(istream& in, Clock_& cl);
};