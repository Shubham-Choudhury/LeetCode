// Link: https://leetcode.com/problems/generate-random-point-in-a-circle/

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    Solution(double radius, double x_center, double y_center) {
        this->radius = radius;
        this->x_center = x_center;
        this->y_center = y_center;
    }
    
    vector<double> randPoint() {
        double x = x_center - radius + 2 * radius * (double)rand() / RAND_MAX;
        double y = y_center - radius + 2 * radius * (double)rand() / RAND_MAX;
        while((x - x_center) * (x - x_center) + (y - y_center) * (y - y_center) > radius * radius) {
            x = x_center - radius + 2 * radius * (double)rand() / RAND_MAX;
            y = y_center - radius + 2 * radius * (double)rand() / RAND_MAX;
        }
        return {x, y};
    }
private:
    double radius;
    double x_center;
    double y_center;
};

int main()
{
    Solution s(1, 0, 0);
    for(int i = 0; i < 10; i++) {
        vector<double> v = s.randPoint();
        cout << v[0] << " " << v[1] << endl;
    }
    return 0;
}
