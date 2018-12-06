#include <iostream>
#include <algorithm>
#include <vector>
#include "Date.h"

int Date::get_year() {
	return this->year;
}

int Date::get_day() {
	return this->day;
}

int Date::get_month() {
	return this->month;
}

Date Date::setDate(int d = 1, int m = 1, int y = 1901) {
	this->day = d;
	this->month = m;
	this->year = y;
	return *this;
}

void Date::print() {
	std::cout << this->day << "." << this->month << "." << this->year << std::endl;
}

bool Date::leap() {
	return (this->year % 400 == 0) ||
		(this->year % 100 != 0) &&
		(this->year % 4 == 0);
}

int Date::days_in_year() {
	return (this->leap() ? 366 : 365);
}

int Date::days_in_month() {
	if (this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11) {
		return 30;
	}else if (this->month == 2) {
		if (this->leap()) {
			return 29;
		}
		else {
			return 28;
		}
	}else {
		return 31;
	}
}

int Date::days_range(Date date) {
	int sum = 0;
	int days_sum1 = this->countDays();
	int days_sum2 = date.countDays();
	return (days_sum2 - days_sum1);
}

int Date::countDays() {
	int sum = 0;
	Date tmp;
	for (int y = 1901; y < this->year; y++) {
		sum += tmp.setDate(0, 0, y).days_in_year();	//put year in parameters
	}
	for (int m = 1; m < this->month; m++) {
		sum += tmp.setDate(0, m, 0).days_in_month();
	}
	sum += this->day;
	return sum;
}

bool Date::right_date() {
	return (this->year >= 1901 && this->month >= 1 && this->month <= 12 && this->day >= 1 && this->day <= this->days_in_month());
 }

void Date::next() {
	if (this->right_date()) {
		if (this->day < this->days_in_month()) {	//если не последний день мес€ца
			this->day++;
		}
		else {
			if (this->month < 12) {
				this->month++;
				this->day = 1;
			}
			else {
				this->year++;
				this->month = 1;
				this->day = 1;
			}
		}
	}else {
		throw("Wrong date");
	}
}

Date define_date(int days) {
	Date tmp;
	int y = 0;
	tmp.setDate(0,0,y);
	Date tmp2;
	while (days > tmp.setDate(0, 0, 1901 + y).days_in_year()) {
		days = days - tmp.days_in_year();									 
		y++;							
	}
	y = 1901 + y;
	int m = 1;
	while (days > tmp.setDate(0, m, y).days_in_month()) {
		days = days - tmp.days_in_month();
		m++;
	}
	tmp.setDate(days, m, y);
	return tmp;
}

Date Date::future_date(int d) {
	int days = this->countDays() + d;
	return define_date(days);
}

Date Date::past_date(int d) {
	int days = this->countDays() - d;
	return define_date(days);
}

int Date::days_to_exams() {
	Date exam;
	return this->days_range(exam.setDate(14, 1, 2019));
}