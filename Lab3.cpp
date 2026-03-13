#include <iostream>


using namespace std;

int* createArray(int size) {

    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        cout << "Enter element " << i+1 <<" : " <<endl;
        cin >> arr[i];
    }
    return arr;

}

int maxValue(int* arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int swapValue(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
    return 0;
}

void reverseArray(int* arr) {
    for (int i = 0, j = sizeof(arr)/sizeof(arr[0]); i < j; i++, j--) {
        swapValue(&arr[i],&arr[j]);
    }
}

int main() {
    cout << "Enter array size:" << endl;
    int size;
    cin >> size;

    int* arr = createArray(size);
    cout << "Array elements" <<endl;
    for (int i = 0; i < size; i++) {

        cout << arr[i]<< ", ";
    }
    cout << "Max value: " << maxValue(arr, size);

    int x = 5;
    int y = 10;
    cout << "Swapping two random integers: ";
    swapValue(&x, &y);
    cout << x << ", " << y << endl;

    cout << "Reversing array..." << endl;
    reverseArray(arr);
    cout << "Array elements after reversing:" <<endl;
    for (int i = 0; i < size; i++) {

        cout << arr[i]<< ", ";
    }

    cout << "Deleting array..." << endl;
    delete[] arr;
    return 0;


}

