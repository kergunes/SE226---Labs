#include <iostream>
using namespace std;

int main() {
    int n;
    int steps = 0;

    cout << "Please enter a positive integer greater than 9: ";
    cin >> n;

    cout << n;

    while (n >= 10) {
        int sum = 0;
        int temp = n;

        while (temp > 0) {
            sum += temp % 10;
            temp = temp / 10;
        }

        n = sum;
        steps++;

        cout << " ---> " << n;
    }

    cout << endl;
    cout << "Total steps: " << steps << endl;

    return 0;
}