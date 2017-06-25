#include "user_info.h"

Date GetCurrentDate()
{
	auto current_time = time(NULL);
	auto current_date = *gmtime(&current_time);
	Date date;
	date.year = current_date.tm_year + 1900;
	date.month = current_date.tm_mon + 1;
	date.day = current_date.tm_mday;
	return date;
}
