#include "String112.h"
#include <iostream>

using namespace std;

String112::String112() {}
String112::String112(const char* str) {
	this->len = strlen(str);
	this->str = new char[this->len + 1];
	strcpy_s(this->str, this->len + 1, str);
}
String112::String112(int cnt, char s) {
	this->len = cnt;
	this->str = new char[len + 1];
	for (int i = 0; i < len; i++) {
		this->str[i] = s;
	}
	this->str[len] = '\0';
}
String112::String112(const char* str, int index) {
	this->len = index;
	this->str = new char[this->len + 1];
	for (int i = 0; i < this->len; i++) {
		this->str[i] = str[i];
	}
}
String112::String112(const String112& str) {
	if (str.str != nullptr) {
		this->len = str.len;
		this->str = new char[this->len + 1];
		strcpy_s(this->str, this->len + 1, str.str);
	}
}
String112::~String112() {
	if (this->str != nullptr) {
		delete[] this->str;
		this->str = nullptr;
		this->len = 0;
	}
}

void String112::setString(const char* str) {
	this->clear();
	if (str != nullptr) {
		this->len = strlen(str);
		char* n_str = new char[this->len + 1];
		strcpy_s(n_str, this->len + 1, str);
		this->str = n_str;
	}
}
String112& String112::setString(const String112& right) {
	this->clear();
	if (right.str != nullptr) {
		this->len = right.len;
		this->str = new char[this->len + 1];
		strcpy_s(this->str, this->len + 1, right.str);
	}
	return *this;
}

int String112::lenght() const {
	return this->len;
}

char& String112::operator[](int index) {
	return this->str[index];
}
const char& String112::operator[](int index) const {
	return this->str[index];
}

String112& String112::operator+=(const String112& right) {
	this->addString(right);
	return *this;
}
String112& String112::operator=(const String112& right) {
	if (this == &right)
		return *this;
	this->~String112();
	if (right.str != nullptr) {
		this->len = right.len;
		this->str = new char[this->len + 1];
		strcpy_s(this->str, this->len + 1, right.str);
	}
	return *this;
}

void String112::printStr() const {
	if (this->str != nullptr)
		cout << this->str;
}
void String112::clear() {
	if (this->str != nullptr) {
		delete[] this->str;
		this->str = nullptr;
		this->len = 0;
	}
}
void String112::addString(const String112& right) {
	if (right.str == nullptr)
		return;
	if (this->str == nullptr) {
		this->setString(right);
		return;
	}
	this->len += right.len;
	char* n_str = new char[this->len + 1];
	strcpy_s(n_str, this->len + 1, this->str);
	strcat_s(n_str, this->len + 1, right.str);
	delete[] this->str;
	this->str = n_str;
}
void String112::reverse() {
	for (int i = 0; i < this->len / 2; i++) {
		swap(this->str[i], this->str[this->len - i - 1]);
	}
}
bool String112::empty() const {
	return this->str == nullptr;
}
void String112::replace(char from, char to) {
	for (int i = 0; i < this->len; i++) {
		if (this->str[i] == from)
			this->str[i] = to;
	}
}
void String112::remove(char a) {
	int count = 0;
	for (int i = 0; i < this->len; i++) {
		if (this->str[i] == a)
			count++;
	}
	char* n_str = new char[this->len - count + 1];
	for (int i = 0, k = 0; i < this->len + 1; i++) {
		if (this->str[i] != a) {
			n_str[k] = this->str[i];
			k++;
		}
	}
	this->len -= count;
	delete[] this->str;
	this->str = n_str;
}
int String112::find(char a) const {
	if (this->empty())
		return NULL;
	for (int i = 0; i < this->len; i++) {
		if (this->str[i] == a)
			return i;
	}
	return NULL;
}
void String112::erase(int index) {
	if (index < 0 || len - 1 < index || this->empty())
		return;
	if (len == 1) {
		this->clear();
		return;
	}
	char* n_str = new char[len];
	for (int i = 0, j = 0; i < len + 1; i++) {
		if (i != index) {
			n_str[j] = this->str[i];
			j++;
		}
	}
	delete[] this->str;
	this->str = n_str;
}
void String112::insert(int index, const char* str) {
	if (index < 0 || len < index)
		return;
	if (this->empty()) {
		this->len = strlen(str) + 1;
		strcpy_s((this->str = new char[this->len]), strlen(str) + 1, str);
		return;
	}
	char* n_str = new char[len + strlen(str) + 1];
	for (int i = 0, j = 0; i < this->len + 1; i++, j++) {
		if (i != index)
			n_str[j] = this->str[i];
		else {
			n_str[j] = '\0';
			strcat_s(n_str, len + strlen(str) + 1, str);
			j += strlen(str);
			n_str[j] = this->str[i];
		}
	}
	this->len = len + strlen(str) + 1;
	delete[] this->str;
	this->str = n_str;
}

String112 operator+(const String112& a, const String112& b) {
	String112 tmp = a;
	tmp += b;
	return tmp;
}

bool operator==(const String112& a, const String112& b) {
	if (a.len != b.len)
		return false;
	for (int i = 0; i < a.len; i++) {
		if (a.str[i] != b.str[i])
			return false;
	}
	return true;
}
bool operator!=(const String112& a, const String112& b) {
	return !(a == b);
}
bool operator<(const String112& a, const String112& b) {
	if (a.len < b.len)
		return true;
	if (a.len > b.len)
		return false;
	for (int i = 0; i < a.len; i++) {
		if (a.str[i] < b.str[i])
			return true;
		if (a.str[i] > b.str[i])
			return false;
	}
	return false;
}
bool operator>(const String112& a, const String112& b) {
	if (a.len > b.len)
		return true;
	if (a.len < b.len)
		return false;
	for (int i = 0; i < a.len; i++) {
		if (a.str[i] > b.str[i])
			return true;
		if (a.str[i] < b.str[i])
			return false;
	}
	return false;
}
bool operator<=(const String112& a, const String112& b) {
	if (a.len > b.len)
		return false;
	for (int i = 0; i < a.len; i++) {
		if (a.str[i] > b.str[i])
			return false;
	}
	return true;
}
bool operator>=(const String112& a, const String112& b) {
	if (a.len < b.len)
		return false;
	for (int i = 0; i < a.len; i++) {
		if (a.str[i] < b.str[i])
			return false;
	}
	return true;
}

ostream& operator<<(ostream& out, const String112& str) {
	out << str.str;
	return out;
}
istream& operator>>(istream& in, String112& str) {
	char* tmp = new char[10000];
	in >> tmp;
	str.setString(tmp);
	delete[] tmp;
	return in;
}