#pragma once
#include "Request.h"
#include "set"

typedef std::multiset<Request> RequestSet;

void addRequest(RequestSet& requests);
void deleteRequest(RequestSet& requests);
void printByDestination(const RequestSet& requests);
void countRequests(const RequestSet& requests);
void printAllRequests(const RequestSet& requests);
