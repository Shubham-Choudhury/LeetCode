// Link: https://leetcode.com/problems/apply-discount-every-n-orders/

#include <bits/stdc++.h>
using namespace std;

class Cashier {
public:
    int n;
    int discount;
    int cnt;
    unordered_map<int, int> price;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        this->n = n;
        this->discount = discount;
        cnt = 0;
        for (int i = 0; i < products.size(); i++) {
            price[products[i]] = prices[i];
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        cnt++;
        double sum = 0;
        for (int i = 0; i < product.size(); i++) {
            sum += price[product[i]] * amount[i];
        }
        if (cnt % n == 0) {
            sum -= sum * discount / 100.0;
        }
        return sum;
    }
};

int main() {
    vector<int> products = {1, 2, 3, 4, 5, 6, 7};
    vector<int> prices = {100, 200, 300, 400, 300, 200, 100};
    Cashier sol(3, 50, products, prices);
    vector<int> product = {1, 2};
    vector<int> amount = {1, 2};
    cout << sol.getBill(product, amount) << endl;
    product = {3, 7};
    amount = {10, 10};
    cout << sol.getBill(product, amount) << endl;
    product = {1, 2, 3, 4, 5, 6, 7};
    amount = {1, 1, 1, 1, 1, 1, 1};
    cout << sol.getBill(product, amount) << endl;
    product = {4};
    amount = {10};
    cout << sol.getBill(product, amount) << endl;
    product = {7, 3};
    amount = {10, 10};
    cout << sol.getBill(product, amount) << endl;
    product = {7, 5, 3, 1, 6, 4, 2};
    amount = {10, 10, 10, 9, 9, 9, 7};
    cout << sol.getBill(product, amount) << endl;
    product = {2, 3, 5};
    amount = {5, 3, 2};
    cout << sol.getBill(product, amount) << endl;
    return 0;
}
