// Link: https://leetcode.com/problems/design-parking-system/?envType=study-plan&id=programming-skills-i

#include <iostream>
using namespace std;

class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        this->big = big;
        this->medium = medium;
        this->small = small;
    }
    
    bool addCar(int carType) {
        if (carType == 1) {
            if (big > 0) {
                big--;
                return true;
            }
        } else if (carType == 2) {
            if (medium > 0) {
                medium--;
                return true;
            }
        } else if (carType == 3) {
            if (small > 0) {
                small--;
                return true;
            }
        }
        return false;
    }

private:

    int big;
    int medium;
    int small;
};

int main() {
    ParkingSystem* obj = new ParkingSystem(1, 1, 0);
    cout << obj->addCar(1) << endl;
    cout << obj->addCar(2) << endl;
    cout << obj->addCar(3) << endl;
    cout << obj->addCar(1) << endl;
    return 0;
}