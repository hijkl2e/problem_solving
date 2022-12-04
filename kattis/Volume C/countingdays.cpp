#include "countingdays.h"

int last_hours;
int last_minutes;
int day = 1;

void lookAtClock(int hours, int minutes) {
	if (hours < last_hours || (hours == last_hours && minutes < last_minutes)) {
		++day;
	}
	last_hours = hours;
	last_minutes = minutes;
}

int getDay() {
	return day;
}
