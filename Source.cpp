#include <iostream>
#include <algorithm>
#include <vector>
#include <conio.h>
#include "Date.h"
#include "cmp.h"

void print_vector(std::vector<Date>);

int main() {

	Date d1, d2, d3, d4;
	d1.setDate(1, 1, 1999);
	d2.setDate(21, 1, 1999);
	d3.setDate(26, 7, 2019);
	d4.setDate(8, 12, 2018);
	
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
	int k = d1.days_range(d2);
	std::cout << k << " days" << std::endl;

	std::cout << "d1: "; d1.print();
	std::cout << "d2: "; d2.print();
	cmp_dates cmp;  
	cmp(d1, d2) ? std::cout << "d1 is greater" << std::endl : std::cout << "d2 is greater" << std::endl;
	std::sort(dates.begin(), dates.end(), cmp_dates());
	print_vector(dates);

	std::cout << "Days to exams: " << d4.days_to_exams();

	_getch();
	return 0;
}

void print_vector(std::vector<Date> v) {
	std::for_each(v.begin(), v.end(), [](Date d) {d.print(); });
}