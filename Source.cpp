#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <conio.h>
#include "Date.h"
#include "cmp.h"

void print_vector(std::vector<Date>);
int days_to_exams(Date);

int main() {

	Date d1, d2, d3, d4;
	d1.set_date(1, 1, 1999);
	d2.set_date(21, 1, 1999);
	d3.set_date(26, 7, 2019);
	d4.set_date(8, 12, 2018);
	
	Date datesArray[4] = {d1, d2, d3, d4};
	
	std::vector<Date> dates;
	dates.push_back(d1);
	dates.push_back(d2);
	dates.push_back(d3);
	dates.push_back(d4);
		
	std::cout << "Today: "; d1.print();

	std::cout << "After 10 days: "; d1.future_date(10).print();
	std::cout << "Tomorrow: "; d1.next(); d1.print();
	std::cout << "5 days ago: "; d1.past_date(5).print();

	std::cout << "Between "; d1.print(); std::cout << "and "; d2.print();
	int k = d2.days_range(d1);
	std::cout << k << " days" << std::endl;

	std::cout << "d1: "; d1.print();
	std::cout << "d2: "; d2.print();
	cmp_dates cmp;  
	cmp(d1, d2) ? std::cout << "d1 is greater" << std::endl : std::cout << "d2 is greater" << std::endl;
	std::sort(dates.begin(), dates.end(), cmp_dates());
	print_vector(dates);

	std::cout << "Days to exams: " << days_to_exams(d4) << std::endl;

	Date d_copy(d2);
	std::cout << "copy of d2: "; d_copy.print();

	std::cout << "Today is " << d4.define_weekday();

	_getch();
	return 0;
}

void print_vector(std::vector<Date> v) {
	std::for_each(v.begin(), v.end(), [](Date d) {d.print(); });
}

int days_to_exams(Date date) {
	Date exam;
	return date.days_range(exam.set_date(14, 1, 2019));
}