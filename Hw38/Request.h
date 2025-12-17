#pragma once
#include <iostream>
#include <string>

struct Date {
	int day, month, year;

	bool operator < (const Date& other) const {
		if (year != other.year) return year < other.year;
		if (month != other.month) return month < other.month;
		return day < other.day;
	}

	void print() const {
		std::cout << (day < 10 ? "0" : "") << day << "."
			<< (month < 10 ? "0" : "") << month << "."
			<< year;
	}
};

class Request {
private:
	static int counter;
	int id;
	std::string destination;
	std::string passenger;
	Date flightDate;
public:

	Request(const std::string& dest, const std::string& pass, const Date& date);

	int getId() const;
	std::string getDestination() const;
	Date getFlightDate() const;

	void print() const;

	bool operator<(const Request& other) const;
};