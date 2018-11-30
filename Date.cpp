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

int Date::days_in_year(Date y) {
	return (y.leap() ? 366 : 365);
}

int Date::days_in_month(Date m) {
	if (m.month == 4 || m.month == 6 || m.month == 9 || m.month == 11) {
		return 30;
	}else if (m.month == 2) {
		if (m.leap()) {
			return 29;
		}
		else {
			return 28;
		}
	}else {
		return 31;
	}
}

int Date::countDaysBetweenTwoDates(Date date) {
	int sum = 0;
	int days_sum1 = this->countDays();
	int days_sum2 = date.countDays();
	return (days_sum2 - days_sum1);
}

int Date::countDays() {
	int sum = 0;
	for (int y = 1901; y < this->year; y++) {
		sum += this->days_in_year(y);	//put year in parameters
	}
	for (int m = 1; m < this->month; m++) {
		sum += days_in_month(m);
	}
	sum += this->day;
	return sum;
}

bool Date::right_date() {
	return (this->year >= 1901 && this->month >= 1 && this->month <= 12 && this->day >= 1 && this->day <= this->days_in_month(*this));
 }

void Date::next() {
	if (this->right_date()) {
		if (this->day < this->days_in_month(*this)) {	//если не последний день мес€ца
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
	while (days > (tmp.setDate(0, 0, 1901 + tmp.get_year())).days_in_year(tmp.setDate(0, 0, 1901 + tmp.get_year()))) { //is it run in while()?
		days = days - tmp.days_in_year(tmp);									 //	
		tmp.setDate(0, 0, tmp.get_year() - 1900);							//	
	}
	tmp.setDate(0, 1, tmp.get_year() + 1901);
	while (days > tmp.days_in_month(tmp)) {
		days = days - tmp.days_in_month(tmp);
		tmp.setDate(0, tmp.get_month() + 1, tmp.get_year());
	}
	tmp.setDate(days, tmp.get_month(), tmp.get_year());
	return tmp;
}

void Date::future_date(int d) {
	int days = this->countDays() + d;
	*this = define_date(days);
}

Date Date::past_date(int d) {
	int days = this->countDays() - d;
	return define_date(days);
}