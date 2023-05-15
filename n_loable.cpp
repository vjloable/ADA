#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <cmath>
using namespace std;

int getMax(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

void bin_bucketSort(int arr[], int size) 
{
    int max = getMax(arr, size);
    int bucket[max], i;
    for (int i = 0; i <= max; i++)
    {
        bucket[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        bucket[arr[i]]++;
    }
    for (int i = 0, j = 0; i <= max; i++)
    {
        while (bucket[i] > 0)
        {
            arr[j++] = i;
            bucket[i]--;
        }
    }
}

void countingSort(int arr[], int size)
{
    int output[size + 1];
    int max = getMax(arr, size);
    int count[max + 1];

    for (int i = 0; i <= max; ++i)
    {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        count[arr[i]]++;
    }

    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }
}

void countingSort(int a[], int n, int place)
{
    int output[n + 1];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(a[i] / place) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(a[i] / place) % 10] - 1] = a[i];
        count[(a[i] / place) % 10]--;
    }

    for (int i = 0; i < n; i++)
        a[i] = output[i];
}

void radixSort(int arr[], int size)
{
    int max = getMax(arr, size);

    for (int place = 1; max / place > 0; place *= 10)
        countingSort(arr, size, place);
}

int main()
{
    const int ARR_SIZE = 10;
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
    bin_bucketSort(arrA, ARR_SIZE);
    auto stopA = chrono::high_resolution_clock::now();
    auto durationA = chrono::duration_cast<chrono::nanoseconds>(stopA - startA);
    cout << "\n" << durationA.count() << endl;

    auto startB = chrono::high_resolution_clock::now();
    countingSort(arrB, ARR_SIZE);
    auto stopB = chrono::high_resolution_clock::now();
    auto durationB = chrono::duration_cast<chrono::nanoseconds>(stopB - startB);
    cout << "\n" << durationB.count() << endl;

    auto startC = chrono::high_resolution_clock::now();
    radixSort(arrC, ARR_SIZE);
    auto stopC = chrono::high_resolution_clock::now();
    auto durationC = chrono::duration_cast<chrono::nanoseconds>(stopC - startC);
    cout << "\n" << durationC.count() << endl;
}