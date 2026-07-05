#include <iostream>
#include <string>
using namespace std;

const int TOTAL_ROOMS = 45;

int roomType[TOTAL_ROOMS];
bool booked[TOTAL_ROOMS];
string guestName[TOTAL_ROOMS];
string guestCNIC[TOTAL_ROOMS];
string guestPhone[TOTAL_ROOMS];
int daysStay[TOTAL_ROOMS];

int getPrice(int type) {
    if (type == 1) return 3000;
    else if (type == 2) return 5000;
    else if (type == 3) return 8000;
    return 0;
}

void initializeRooms() {
    for (int i = 0; i < TOTAL_ROOMS; i++) {
        booked[i] = 0;

        if (i < 15)
            roomType[i] = 1;
        else if (i < 30)
            roomType[i] = 2;
        else
            roomType[i] = 3;
    }
}

void checkAvailability() {
    cout << endl << "--- Available Rooms ---" << endl;

    bool anyFree = 0;

    cout << "Room No\t\tType\t\tPrice" << endl;
    cout << "----------------------------------" << endl;

    for (int i = 0; i < TOTAL_ROOMS; i++) {
        if (booked[i] == 0) {
            anyFree = 1;

            string typeName;

            if (roomType[i] == 1)
                typeName = "Single";
            else if (roomType[i] == 2)
                typeName = "Double";
            else
                typeName = "Suite";

            cout << "Room " << i + 1 << "\t\t"
                 << typeName << "\t\tRs. "
                 << getPrice(roomType[i]) << endl;
        }
    }

    if (anyFree == 0)
        cout << "No rooms available." << endl;
}

void bookRoom() {
    cout << endl << "Room Types:" << endl;
    cout << "1 - 15 : Single (Rs. 3000)" << endl;
    cout << "16 - 30 : Double (Rs. 5000)" << endl;
    cout << "31 - 45 : Suite (Rs. 8000)" << endl;

    int room;

    cout << endl << "Enter room number to book (1-45): ";
    cin >> room;

    if (room < 1 || room > TOTAL_ROOMS) {
        cout << "Invalid room number." << endl;
    }
    else {
        room--;

        if (booked[room] == 1) {
            cout << "Room already booked." << endl;
        }
        else {
            cin.ignore();

            cout << "Enter Guest Name: ";
            getline(cin, guestName[room]);

            cout << "Enter CNIC: ";
            cin >> guestCNIC[room];

            cout << "Enter Phone: ";
            cin >> guestPhone[room];

            cout << "Enter number of days: ";
            cin >> daysStay[room];

            booked[room] = 1;

            cout << "Room booked successfully!" << endl;
        }
    }
}

void checkOut() {
    int room;

    cout << endl << "Enter room number for check-out: ";
    cin >> room;

    if (room < 1 || room > TOTAL_ROOMS) {
        cout << "Invalid room number." << endl;
    }
    else {
        room--;

        if (booked[room] == 0) {
            cout << "Room is not booked." << endl;
        }
        else {
            int pricePerDay = getPrice(roomType[room]);
            int baseAmount = pricePerDay * daysStay[room];

            float tax = baseAmount * 0.10;
            float totalBill = baseAmount + tax;

            cout << endl << "--- BILL ---" << endl;
            cout << "Guest Name: " << guestName[room] << endl;
            cout << "Price per Day: Rs. " << pricePerDay << endl;
            cout << "Days Stayed: " << daysStay[room] << endl;
            cout << "Base Rent: Rs. " << baseAmount << endl;
            cout << "Service Tax (10%): Rs. " << tax << endl;
            cout << "Total Amount: Rs. " << totalBill << endl;

            booked[room] = 0;

            cout << "Check-out completed." << endl;
        }
    }
}

void viewBooked() {
    cout << endl << "--- Booked Rooms ---" << endl;

    bool any = false;

    for (int i = 0; i < TOTAL_ROOMS; i++) {
        if (booked[i] == 1) {
            any = true;

            string typeName;

            if (roomType[i] == 1)
                typeName = "Single";
            else if (roomType[i] == 2)
                typeName = "Double";
            else
                typeName = "Suite";

            cout << endl
                 << "Room " << (i + 1)
                 << " (" << typeName << ")" << endl;

            cout << "Guest: " << guestName[i] << endl;
            cout << "CNIC: " << guestCNIC[i] << endl;
            cout << "Phone: " << guestPhone[i] << endl;
            cout << "Days: " << daysStay[i] << endl;
        }
    }

    if (any == 0)
        cout << "No rooms are currently booked." << endl;
}

int main() {
    initializeRooms();

    int choice;

    do {
        cout << endl
             << "===== Hotel Booking System =====" << endl;

        cout << "1. Check Availability" << endl;
        cout << "2. Book Room" << endl;
        cout << "3. Check-out" << endl;
        cout << "4. View Booked Rooms" << endl;
        cout << "5. Exit" << endl;

        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                checkAvailability();
                break;

            case 2:
                bookRoom();
                break;

            case 3:
                checkOut();
                break;

            case 4:
                viewBooked();
                break;

            case 5:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid option." << endl;
        }

    } while (choice != 5);

    return 0;
}