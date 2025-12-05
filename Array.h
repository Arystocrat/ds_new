#ifndef ARRAY_H
#define ARRAY_H
#include "Stack.h"

class ParkingLotArray {
private:
    Stack** lanes;
    int numLanes;
    int laneCapacity;

public:
    ParkingLotArray(int n, int cap) {
        numLanes = n;
        laneCapacity = cap;
        lanes = new Stack*[numLanes];
        for (int i = 0; i < numLanes; i++) {
            lanes[i] = new Stack(laneCapacity);
        }
    }

    ~ParkingLotArray() {
        for (int i = 0; i < numLanes; i++) delete lanes[i];
        delete[] lanes;
    }

    Stack* getLane(int index) {
        if (index >= 0 && index < numLanes) return lanes[index];
        return nullptr;
    }

    // Returns index of first lane with space, or -1
    int findAvailableLane() {
        for (int i = 0; i < numLanes; i++) {
            if (!lanes[i]->isFull()) return i;
        }
        return -1;
    }

    // Returns index of lane containing the car, or -1
    int findCarLane(int carNum) {
        for (int i = 0; i < numLanes; i++) {
            if (lanes[i]->hasCar(carNum)) return i;
        }
        return -1;
    }
    
    int getNumLanes() { return numLanes; }
};
#endif