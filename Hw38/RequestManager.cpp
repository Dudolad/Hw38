#include "RequestManager.h"
#include <iostream>
#include <iomanip>

using namespace std;

void addRequest(RequestSet& requests) {
    string dest, pass;
    Date date;
    cout << "Enter destination: ";
    cin.ignore();
    getline(cin, dest);
    cout << "Enter passenger name (Surname I.I.): ";
    getline(cin, pass);
    cout << "Enter flight date (day month year): ";
    cin >> date.day >> date.month >> date.year;

    requests.insert(Request(dest, pass, date));
    cout << "Request added successfully!\n";
}

void deleteRequest(RequestSet& requests) {
    int id;
    cout << "Enter request ID to delete: ";
    cin >> id;

    for (auto it = requests.begin(); it != requests.end(); ++it) {
        if (it->getId() == id) {
            requests.erase(it);
            cout << "Request deleted.\n";
            return;
        }
    }
    cout << "Request not found.\n";
}

void printByDestination(const RequestSet& requests) {
    string dest;
    cout << "Enter destination: ";
    cin.ignore();
    getline(cin, dest);

    bool found = false;
    for (const auto& r : requests) {
        if (r.getDestination() == dest) {
            r.print();
            found = true;
        }
    }
    if (!found) cout << "No requests for this destination.\n";
}

void countRequests(const RequestSet& requests) {
    string dest;
    Date start, end;
    cout << "Enter destination: ";
    cin.ignore();
    getline(cin, dest);
    cout << "Enter start date (day month year): ";
    cin >> start.day >> start.month >> start.year;
    cout << "Enter end date (day month year): ";
    cin >> end.day >> end.month >> end.year;

    int count = 0;
    for (const auto& r : requests) {
        if (r.getDestination() == dest && !(r.getFlightDate() < start) && !(end < r.getFlightDate())) {
            count++;
        }
    }
    cout << "Number of requests: " << count << endl;
}

void printAllRequests(const RequestSet& requests) {
    if (requests.empty()) {
        cout << "No requests available.\n";
        return;
    }
    for (const auto& r : requests) {
        r.print();
    }
}