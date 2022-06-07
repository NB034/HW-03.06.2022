#pragma once
#include <iostream>

using namespace std;

class String112 {
	char* str = nullptr;
	int len = 0;
public:
	String112();
	String112(const char* str);
	String112(int cnt, char s);
	String112(const char* str, int index);
	String112(const String112& str);
	~String112();

	void setString(const char* str);
	String112& setString(const String112& right);

	int lenght() const;

	char& operator[](int index);
	const char& operator[](int index) const;

	String112& operator+=(const String112& right);
	String112& operator=(const String112& right);

	void printStr() const;
	void clear();
	void addString(const String112& right);
	void reverse();
	bool empty() const;
	void replace(char from, char to);
	void remove(char a);
	int find(char a) const;
	void erase(int index);
	void insert(int index, const char* str);

	friend String112 operator+(const String112& a, const String112& b);

	friend bool operator==(const String112& a, const String112& b);
	friend bool operator!=(const String112& a, const String112& b);
	friend bool operator<(const String112& a, const String112& b);
	friend bool operator>(const String112& a, const String112& b);
	friend bool operator<=(const String112& a, const String112& b);
	friend bool operator>=(const String112& a, const String112& b);

	friend ostream& operator<<(ostream& out, const String112& str);
	friend istream& operator>>(istream& in, String112& str);
};