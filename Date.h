#pragma once
#include <vector>
class Date {
private:
	int day, month, year;
	
	bool right_date();
	bool leap();
public:
	Date(int d = 1, int m = 1, int y = 1901) {
		day = d;
		month = m;
		year = y;
	}
	std::vector<int> months = { 31, 30, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	Date setDate(int, int, int);	//set date
	void print();	//print date
	int days_range(Date); //count days in range between two dates
	int days_in_year(); //count days in year
	int days_in_month(); //count days in mounth
	void next();	// swith date to next day
	Date past_date(int);	//return date at n days ago
	Date future_date(int);	//return date for days
	int countDays();	// days since the begin of the time

	int days_to_exams();
};
