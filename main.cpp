#include <iostream>
#include <string>
#include "Stack.h"
#include "Queue.h"
#include "Array.h"

using namespace std;

void parkCar(ParkingLotArray* lot) {
    int id; 
    string name;
    
    int laneIdx = lot->findAvailableLane();
    if (laneIdx == -1) {
        cout << "[ERROR] Parking Full!\n";
        return;
    }

    cout << "Enter Car ID: "; cin >> id;
    if (lot->findCarLane(id) != -1) {
        cout << "[ERROR] Car already exists.\n";
        return;
    }
    cout << "Enter Owner: "; cin >> name;

    Car newCar = { id, name };
    lot->getLane(laneIdx)->push(newCar);
    cout << "[SUCCESS] Parked in Lane " << (laneIdx + 1) << "\n";
}

void removeCar(ParkingLotArray* lot) {
    int id;
    cout << "Enter Car ID to remove: "; cin >> id;

    int laneIdx = lot->findCarLane(id);
    if (laneIdx == -1) {
        cout << "[ERROR] Car not found.\n";
        return;
    }

    Stack* lane = lot->getLane(laneIdx);
    Queue* tempQ = new Queue();
    bool found = false;
    Car target;

    // 1. Move blocking cars to Queue
    while (!lane->isEmpty()) {
        Car c = lane->pop();
        if (c.carNumber == id) {
            target = c;
            found = true;
            break;
        }
        tempQ->enqueue(c);
        cout << " -> Moving Car " << c.carNumber << " to temp storage.\n";
    }

    // 2. Move cars back from Queue to Stack
    while (!tempQ->isEmpty()) {
        lane->push(tempQ->dequeue());
    }
    delete tempQ;

    if (found) cout << "[SUCCESS] Removed Car " << target.carNumber << " (" << target.ownerName << ")\n";
}

void displayAll(ParkingLotArray* lot) {
    cout << "\n--- STATUS ---\n";
    for (int i = 0; i < lot->getNumLanes(); i++) {
        cout << "Lane " << (i + 1) << ": " << lot->getLane(i)->getSize() << " cars\n";
    }
    cout << "--------------\n";
}

int main() {
    int lanes, cap, choice;
    cout << "Enter Number of Lanes: "; cin >> lanes;
    cout << "Enter Capacity per Lane: "; cin >> cap;

    ParkingLotArray* lot = new ParkingLotArray(lanes, cap);

    while (true) {
        cout << "\n1. Park  2. Remove  3. Display  0. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) parkCar(lot);
        else if (choice == 2) removeCar(lot);
        else if (choice == 3) displayAll(lot);
        else if (choice == 0) break;
        else cout << "Invalid choice.\n";
    }

    delete lot;
    return 0;
}