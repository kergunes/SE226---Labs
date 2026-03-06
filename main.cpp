#include <iostream>
using namespace std;

int main() {
    int x;
    cout << "Enter a number that is between 10 and 100, inclusive: " << endl;
    cin >> x;
    while (x > 100 || x < 10) {
        cout << "Enter a number that is between 10 and 100, inclusive: " << endl;
        cin >> x;
    }
    int fizz = 0;
    int buzz = 0;
    int fizzbuzz = 0;

    for (int i = 1; i <= x; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            cout << "FizzBuzz" << endl;
            fizzbuzz++;
        }
        else if (i % 3 == 0) {
            cout << "Fizz" << endl;
            fizz++;
        }
        else if (i % 5 == 0) {
            cout << "Buzz" << endl;
            buzz++;
        }
        else {
            cout << i << endl;
        }
    }
    cout << endl;
    cout << "Fizz : " << fizz << endl;
    cout << "Buzz : " << buzz << endl;
    cout << "FizzBuzz : " << fizzbuzz << endl;

    return 0;
}