#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
using namespace std;

///////////////////////////////////////////////////////////////////////
int shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
    return 0;
}

///////////////////////////////////////////////////////////////////////

void merge(int array[], int const left, int const mid,
           int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
        {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

///////////////////////////////////////////////////////////////////////

void heapify(int arr[], int N, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < N && arr[l] > arr[largest])
        largest = l;
    if (r < N && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, N, largest);
    }
}

void heapSort(int arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
    for (int i = N - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

///////////////////////////////////////////////////////////////////////

int main()
{
    const int ARR_SIZE = 10000;
    int arrA[ARR_SIZE];
    int arrB[ARR_SIZE];
    int arrC[ARR_SIZE];

    for (int i = 0; i < ARR_SIZE; i++)
    {
        int randNum = rand() % ARR_SIZE;
        arrA[i] = randNum;
        arrB[i] = randNum;
        arrC[i] = randNum;
    }

    auto startA = chrono::high_resolution_clock::now();
    shellSort(arrA, ARR_SIZE);
    auto stopA = chrono::high_resolution_clock::now();
    auto durationA = chrono::duration_cast<chrono::milliseconds>(stopA - startA);
    cout << "\n"<< durationA.count() << endl;

    // auto startB = chrono::high_resolution_clock::now();
    // mergeSort(arrB, 0, ARR_SIZE - 1);
    // auto stopB = chrono::high_resolution_clock::now();
    // auto durationB = chrono::duration_cast<chrono::milliseconds>(stopB - startB);
    // cout << durationB.count() << endl;

    // auto startC = chrono::high_resolution_clock::now();
    // heapSort(arrC, ARR_SIZE);
    // auto stopC = chrono::high_resolution_clock::now();
    // auto durationC = chrono::duration_cast<chrono::milliseconds>(stopC - startC);
    // cout << durationC.count() << endl;

    return 0;
}