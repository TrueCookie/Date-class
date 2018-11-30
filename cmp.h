#pragma once
#include "Date.h"
struct cmp_dates {
	bool operator()(Date date1, Date date2) {
		return date1.countDays() > date2.countDays();
	}
};