#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Narrow parking garage = Stack (LIFO: Last In, First Out)
class ParkingGarage {
private:
    static const int CAPACITY = 5;   // maximum cars the garage can hold
    string cars[CAPACITY];
    int top;

public:
    ParkingGarage() : top(-1) {}

    bool isEmpty() const { return top == -1; }
    bool isFull() const { return top == CAPACITY - 1; }

    // Car enters the garage (push)
    void enter(const string& carNumber) {
        if (isFull()) {
            cout << "Garage is FULL. Car " << carNumber << " cannot enter.\n";
            return;
        }
        cars[++top] = carNumber;
        cout << "Car " << carNumber << " entered the garage.\n";
    }

    // Car leaves the garage (pop) - only the last car that entered can leave
    void leave() {
        if (isEmpty()) {
            cout << "Garage is EMPTY. No car to leave.\n";
            return;
        }
        cout << "Car " << cars[top] << " left the garage.\n";
        top--;
    }

    // Show which car will leave next
    void peek() const {
        if (isEmpty())
            cout << "Garage is EMPTY.\n";
        else
            cout << "Next car to leave: " << cars[top] << "\n";
    }

    // Display all cars (from the gate side to the inside)
    void display() const {
        if (isEmpty()) {
            cout << "Garage is EMPTY.\n";
            return;
        }
        cout << "\n----- Cars in Garage -----\n";
        cout << "(Gate / Exit side)\n";
        for (int i = top; i >= 0; i--) {
            cout << cars[i];
            if (i == top) cout << "   <-- will leave first";
            cout << "\n";
        }
        cout << "(Inner end of garage)\n";
        cout << "--------------------------\n";
    }
};

int main() {
    ParkingGarage garage;
    int choice = 0;
    string carNumber;

    do {
        cout << "\n===== PARKING GARAGE MENU =====\n";
        cout << "1. Car enters\n";
        cout << "2. Car leaves\n";
        cout << "3. Show next car to leave\n";
        cout << "4. Display all cars\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Enter a number between 1 and 5.\n";
            choice = 0;
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                cout << "Enter car number: ";
                getline(cin, carNumber);
                if (carNumber.empty()) cout << "Car number cannot be empty.\n";
                else garage.enter(carNumber);
                break;
            case 2:
                garage.leave();
                break;
            case 3:
                garage.peek();
                break;
            case 4:
                garage.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Enter 1 to 5.\n";
        }
    } while (choice != 5);

    return 0;
}
