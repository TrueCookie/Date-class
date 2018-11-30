#pragma once
#include <vector>
class Date {
private:
	int day, month, year;
public:
	Date(int d = 1, int m = 1, int y = 1901) {
		day = d;
		month = m;
		year = y;
	}

	int get_year();
	int get_month();
	int get_day();
	std::vector<int> months = { 31, 30, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	Date setDate(int, int, int);
	void print();
	int countDaysBetweenTwoDates(Date);
	bool leap();
	int days_in_year(Date);
	int days_in_month(Date);
	int countDays();
	bool right_date();
	void next();
	Date past_date(int);
	void future_date(int);
};
