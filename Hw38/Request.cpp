#include "Request.h"

int Request::counter = 0;

Request::Request(const std::string& dest, const std::string& pass, const Date& date)
    : destination(dest), passenger(pass), flightDate(date) {
    id = ++counter;
}

int Request::getId() const {
    return id;
}

std::string Request::getDestination() const {
    return destination;
}

Date Request::getFlightDate() const {
    return flightDate;
}

void Request::print() const {
    std::cout << "ID: " << id
        << " | Destination: " << destination
        << " | Passenger: " << passenger
        << " | Date: ";
    flightDate.print();
    std::cout << std::endl;
}

bool Request::operator<(const Request& other) const {
    if (destination != other.destination)
        return destination < other.destination;
    if (flightDate < other.flightDate)
        return true;
    if (flightDate.day == other.flightDate.day &&
        flightDate.month == other.flightDate.month &&
        flightDate.year == other.flightDate.year)
        return id < other.id;
    return false;
}                                                        