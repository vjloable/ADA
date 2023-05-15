// Vince Japheth F. Loable

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
using namespace std;

bool inAscendingOrder(int *arr, int size)
{
    bool isAscending = false;
    for (int idx = 1; idx < size; idx++)
    {
        if (arr[idx - 1] > arr[idx])
        {
            isAscending = false;
            break;
        }
        else
        {
            isAscending = true;
        }
    }
    return isAscending;
}

void printArray(int *arr, int size)
{
    for (int idx = 0; idx < size; idx++)
    {
        cout << arr[idx] << " ";
    }
    cout << endl;
}

void slowsort()
{
    const int ARR_SIZE = 20000;
    int arr[ARR_SIZE];
    int i = rand() % ARR_SIZE;
    int j = rand() % ARR_SIZE;
    int temp;

    for (int i = 0; i < ARR_SIZE; i++)
    {
        arr[i] = rand() % ARR_SIZE;
    }
    // printArray(arr, ARR_SIZE);                                                   // TESTING PURPOSES
    auto start = chrono::high_resolution_clock::now();                              // RUNTIME TESTER

    while(true){
        if(inAscendingOrder(arr, ARR_SIZE)){
            break;
        }
        i = rand() % ARR_SIZE;
        cout << "."; // TESTING PURPOSES
        j = rand() % ARR_SIZE;
        cout << "_";                                                                // TESTING PURPOSES
        if ((i < j) && (arr[i] > arr[j]))
        {
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            cout << "\nSwapped " << arr[i] << " and " << arr[j] << endl;            // TESTING PURPOSES
            // printArray(arr, ARR_SIZE);                                           // TESTING PURPOSES
        }
    }
    // printArray(arr, ARR_SIZE);                                                   // TESTING PURPOSES
    auto stop = chrono::high_resolution_clock::now();                               // RUNTIME TESTER
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);       // RUNTIME TESTER
    cout << duration.count() << endl;                                               // RUNTIME TESTER
}

int main()
{
    slowsort();
    return 0;
}