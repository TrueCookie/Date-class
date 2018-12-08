#include <iostream>
#include <algorithm>
#include <vector>
#include "Date.h"

std::vector<int> Date::months = { 31, 30, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date Date::set_date(int d = 1, int m = 1, int y = 1901) {
	this->day_ = d;
	this->month_ = m;
	this->year_ = y;
	return *this;
}

void Date::print() {
	std::cout << this->day_ << "." << this->month_ << "." << this->year_ << std::endl;
}

bool Date::leap() {
	return (this->year_ % 400 == 0) ||
		(this->year_ % 100 != 0) &&
		(this->year_ % 4 == 0);
}

int Date::days_in_year() {
	return (this->leap() ? 366 : 365);
}

int Date::days_in_month() {
	if (this->month_ == 4 || this->month_ == 6 || this->month_ == 9 || this->month_ == 11) {
		return 30;
	}else if (this->month_ == 2) {
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
	int days_sum1 = this->count_days();
	int days_sum2 = date.count_days();
	return (days_sum2 - days_sum1);
}

int Date::count_days() {
	int sum = 0;
	Date tmp;
	for (int y = 1901; y < this->year_; y++) {
		sum += tmp.set_date(0, 0, y).days_in_year();	//put year in parameters
	}
	for (int m = 1; m < this->month_; m++) {
		sum += tmp.set_date(0, m, 0).days_in_month();
	}
	sum += this->day_;
	return sum;
}

bool Date::right_date() {
	return (this->year >= 1901 && this->month >= 1 && this->month <= 12 && this->day >= 1 && this->day <= this->days_in_month());
 }

void Date::next() {
	if (this->right_date()) {
		if (this->day_ < this->days_in_month()) {
			this->day_++;
		}
		else {
			if (this->month_ < 12) {
				this->month_++;
				this->day_ = 1;
			}
			else {
				this->year_++;
				this->month_ = 1;
				this->day_ = 1;
			}
		}
	}else {
		throw("Wrong date");
	}
}

Date define_date(int days) {
	Date tmp;
	int y = 0;
	tmp.set_date(0,0,y);
	Date tmp2;
	while (days > tmp.set_date(0, 0, 1901 + y).days_in_year()) {
		days = days - tmp.days_in_year();									 
		y++;							
	}
	y = 1901 + y;
	int m = 1;
	while (days > tmp.set_date(0, m, y).days_in_month()) {
		days = days - tmp.days_in_month();
		m++;
	}
	tmp.set_date(days, m, y);
	return tmp;
}

Date Date::future_date(int d) {
	int days = this->count_days() + d;
	return define_date(days);
}

Date Date::past_date(int d) {
	int days = this->count_days() - d;
	return define_date(days);
}
