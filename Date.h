#pragma once
#include <vector>
class Date {
private:
	int day_, month_, year_;
	static std::vector<int> months;
	bool right_date();
	bool leap();

public:
	Date(int d = 1, int m = 1, int y = 1901) {
		day_ = d;
		month_ = m;
		year_ = y;
	}
	
	Date(const Date& date) {
		day_ = date.day_;
		month_ = date.month_;
		year_ = date.year_;
	}

	Date set_date(int, int, int);	//set date
	void print();	//print date
	int days_range(Date); //count days in range between two dates
	int days_in_year(); //count days in year
	int days_in_month(); //count days in mounth
	void next();	// swith date to next day
	Date past_date(int);	//return date at n days ago
	Date future_date(int);	//return date for days
	int count_days();	// days since the begin of the time
	
};
