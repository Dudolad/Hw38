#include "RequestManager.h"
#include <iostream>

using namespace std;

int main() {
    RequestSet requests;
    int choice;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Add request\n";
        cout << "2. Delete request\n";
        cout << "3. Print requests by destination\n";
        cout << "4. Count requests by destination and date range\n";
        cout << "5. Print all requests\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addRequest(requests); break;
        case 2: deleteRequest(requests); break;
        case 3: printByDestination(requests); break;
        case 4: countRequests(requests); break;
        case 5: printAllRequests(requests); break;
        case 0: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}