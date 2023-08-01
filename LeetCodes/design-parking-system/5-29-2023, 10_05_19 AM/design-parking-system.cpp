// Link: https://leetcode.com/problems/design-parking-system

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: design-parking-system
 *  RUNTIME: 59 ms
 *  MEMORY: 33 MB
 *  DATE: 5-29-2023, 10:05:19 AM
 *
 */

// Solution:

class ParkingSystem {
public:
    vector<int> space;
    ParkingSystem(int big, int medium, int small) {
        space.resize(3, 0);
        space[0] = big;
        space[1] = medium;
        space[2] = small;
    }
    
    bool addCar(int carType) {
        int rem = --space[carType-1];
        if(rem < 0) return false;
        return true;
    }

};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
