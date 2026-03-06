#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter a number between 3 and 9: ";
    cin >> n;

    for (int i = 1; i <= 2*n - 1; i++) {
        int k;

        if (i <= n)
            k = i;
        else
            k = 2*n - i;

        for (int j = 1; j <= k; j++) {
            cout << j;
        }

        cout << endl;
    }

    return 0;
}