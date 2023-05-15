// Vince Japheth F. Loable  

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <chrono>
#include <cmath>

using namespace std;

void thirdMax_Sorted(){

    // cout << "Algorithm #1: Sort-it-First Thirdmax Algorithm" << endl;
    // cout << "---------------------" << endl;
    const int ARR_SIZE = 100;
    int arrOne[ARR_SIZE];                                                       //  TESTER
    for (int i = 0; i < ARR_SIZE; i++){                                         //  TESTER
        arrOne[i] = rand() % ARR_SIZE;                                          //  TESTER
    }                                                                           //  TESTER
    // int arrOne[12] = {8, 10, 1, 30, 140, 145, 70, 19, 323, 434, 3, 69};
    // cout << "arrOne: \n";
    // for (int i = 0; i < (sizeof(arrOne) / sizeof(int)) - 1; i++)
    // {
    //     cout << arrOne[i] << " ";
    // }
    // cout << arrOne[(sizeof(arrOne) / sizeof(int))-1] << " " << endl;

    auto start = chrono::high_resolution_clock::now();                          //  TESTER
    sort(arrOne, arrOne + (sizeof(arrOne) / sizeof(int)), greater<int>());

    // cout << "\narrOne (Sorted): \n";
    // for (int i = 0; i < (sizeof(arrOne) / sizeof(int)) - 1; i++)
    // {
    //     cout << arrOne[i] << " ";
    // }
    // cout << arrOne[(sizeof(arrOne) / sizeof(int)) - 1] << " " << endl;

    cout << "\n   Third Max: " << arrOne[2] << endl;
    auto stop = chrono::high_resolution_clock::now();                           //  TESTER
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);   //  TESTER
    cout << duration.count() << endl;                                           //  TESTER

    // cout << "\n---------------------\n\n" << endl;
    
}

void thirdMax_Arrays(){

    // cout << "Algorithm #2: Array-Extraction Thirdmax Algorithm" << endl;
    // cout << "---------------------" << endl;
    const int ARR_SIZE = 100;                                                       //  TESTER
    int arrA[ARR_SIZE];                                                             //  TESTER
    for (int i = 0; i < ARR_SIZE; i++)                                              //  TESTER
    {                                                                               //  TESTER
        arrA[i] = rand() % ARR_SIZE;                                                //  TESTER
    }                                                                               //  TESTER
    // int arrA[12] = {8, 10, 1, 30, 140, 145, 70, 19, 323, 434, 3, 69};
    int arrB[(sizeof(arrA) / sizeof(int)) - 1];
    int arrC[(sizeof(arrB) / sizeof(int)) - 1];
    int max = arrA[0];
    int ii = 0;

    // cout << "arrA:  ";
    // for (int i = 0; i < (sizeof(arrOne) / sizeof(int)) - 1; i++)
    // {
    //     cout << arrA[i] << " ";
    // }
    // cout << arrA[(sizeof(arrA) / sizeof(int)) - 1] << " " << endl;

    auto start = chrono::high_resolution_clock::now();                              //  TESTER
    for (int i = 1; i < sizeof(arrA) / sizeof(int); i++){
        if (max < arrA[i]){
            max = arrA[i];
        }
    }
    // cout << "max:   " << max << "\n" << endl;
    // cout << "arrB:  ";
    for (int i = 0; i < sizeof(arrA) / sizeof(int); i++)
    {
        if (arrA[i] != max)
        {
            arrB[ii] = arrA[i];
            // cout << arrB[ii] << " ";
            ii++;
        }
    }
    // cout << endl;
    max = arrB[0];
    for (int i = 1; i < sizeof(arrB) / sizeof(int); i++)
    {
        if (max < arrB[i])
        {
            max = arrB[i];
        }
    }
    // cout << "max:   " << max << "\n" << endl;
    // cout << "arrC:  ";
    ii = 0;
    for (int i = 0; i < sizeof(arrB) / sizeof(int); i++)
    {
        if (arrB[i] != max)
        {
            arrC[ii] = arrB[i];
            // cout << arrC[ii] << " ";
            ii++;
        }
    }

    // cout << endl;
    max = arrC[0];
    for (int i = 1; i < sizeof(arrC) / sizeof(int); i++)
    {
        if (max < arrC[i])
        {
            max = arrC[i];
        }
    }

    // cout << "max:   " << max << "\n" << endl;

    cout<<"\n   Third Max: "<< max << endl;
    auto stop = chrono::high_resolution_clock::now();                         //  TESTER
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start); //  TESTER
    cout << duration.count() << endl;                                         //  TESTER

    // cout << "\n---------------------\n\n"<< endl;
    
}

void thirdMax_Vince(){
    // cout << "Algorithm #3: My (Vince's) /  ThirdMax  Algorithm" << endl;
    // cout << "---------------------" << endl;
    const int ARR_SIZE = 100;                                                  //  TESTER
    int arrThree[ARR_SIZE];                                                     //  TESTER
    for (int i = 0; i < ARR_SIZE; i++)                                          //  TESTER
    {                                                                           //  TESTER
        arrThree[i] = rand() % ARR_SIZE;                                        //  TESTER
    }                                                                           //  TESTER
    // int arrThree[12] = {8, 10, 1, 30, 140, 145, 70, 19, 323, 434, 3, 69};

    auto start = chrono::high_resolution_clock::now();                          //  TESTER

    int *least;
    int maxA = arrThree[0];
    int maxB = arrThree[1];
    int maxC = arrThree[2];
    int thirdMax;
    (maxA > maxB) ? (least = &maxB) : (least = &maxA);
    if (*least > maxC)
        least = &maxC;
    // int loop = 1;
    for (int i = 3; i < (sizeof(arrThree) / sizeof(int)); i = i + 3)
    {
        // cout << "\n Loop " << loop << ":" << endl;
        // cout << "    maxA = " << maxA << "    " << &maxA << "\n    maxB = " << maxB << "    " << &maxB << "\n    maxC = " << maxC << "    " << &maxC << endl;
        // cout << "    least: " << least << endl;

        if (arrThree[i] > *least){
            *least = arrThree[i];
        }

        if (maxA < maxB && maxA < maxC) {
            least = &maxA;
        } else if (maxB < maxA && maxB < maxC) {
            least = &maxB;
        } else if (maxC < maxA && maxC < maxB) {
            least = &maxC;
        }

        // cout << "    maxA = " << maxA << "    " << &maxA << "\n    maxB = " << maxB << "    " << &maxB << "\n    maxC = " << maxC << "    " << &maxC << endl;
        // cout << "    least: " << least << endl;
        if (arrThree[i+1] > *least)
        {
            *least = arrThree[i+1];
        }

        if (maxA < maxB && maxA < maxC)
        {
            least = &maxA;
        }
        else if (maxB < maxA && maxB < maxC)
        {
            least = &maxB;
        }
        else if (maxC < maxA && maxC < maxB)
        {
            least = &maxC;
        }

        // cout << "    maxA = " << maxA << "    " << &maxA << "\n    maxB = " << maxB << "    " << &maxB << "\n    maxC = " << maxC << "    " << &maxC << endl;
        // cout << "    least: " << least << endl;
        if (arrThree[i+2] > *least)
        {
            *least = arrThree[i+2];
        }

        if (maxA < maxB && maxA < maxC)
        {
            least = &maxA;
        }
        else if (maxB < maxA && maxB < maxC)
        {
            least = &maxB;
        }
        else if (maxC < maxA && maxC < maxB)
        {
            least = &maxC;
        }
        // cout << "    maxA = " << maxA << "    " << &maxA << "\n    maxB = " << maxB << "    " << &maxB << "\n    maxC = " << maxC << "    " << &maxC << endl;
        // cout << "    least: " << least << endl;
        // loop++;
    }

    cout<<"\n   Third Max: "<< *least << endl;

    auto stop = chrono::high_resolution_clock::now();                           //  TESTER
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);   //  TESTER
    cout << duration.count() << endl;                                           //  TESTER
    // cout << "\n---------------------" << endl;

}

//////////////////////////////////////////////////////////////////////////////////////////////////////

struct node
{
    int data;
    node *next;
};

// function for creating a new node in the linked list
struct node *create(int x)
{
    node *temp = new node();
    temp->data = x;
    temp->next = NULL;

    return temp;
}

// utility function to append node in the linked list
// here head is passed by reference, to know more about this
// search pass by reference
void insert(node *&head, int n)
{
    if (head == NULL)
    {
        head = create(n);
        return;
    }

    node *t = head;
    while (t->next != NULL)
        t = t->next;
    t->next = create(n);
}

// utility function to pop an element from front in the list
// for the sake of stability in sorting
int del(node *&head)
{
    if (head == NULL)
        return 0;
    node *temp = head;
    // storing the value of head before updating
    int val = head->data;

    // updation of head to next node
    head = head->next;

    delete temp;
    return val;
}

// utility function to get the number of digits in the
// max_element
int digits(int n)
{
    int i = 1;
    if (n < 10)
        return 1;

    while (n > (int)pow(10, i))
        i++;
    return i;
}

void radix_sort()
{
    const int ARR_SIZE = 10;            //  TESTER
    int arrFour[ARR_SIZE];              //  TESTER
    int max_val = 0;
    for (int i = 0; i < ARR_SIZE; i++)   //  TESTER
    {                                    //  TESTER
        arrFour[i] = rand() % ARR_SIZE; //  TESTER
        cout << arrFour[i] << endl;
        if (arrFour[i] > max_val){
            max_val = arrFour[i];
        }
    }

    auto start = chrono::high_resolution_clock::now(); //  TESTER
    // getting digits in the maximum element
    int d = digits(max_val);

    // creating buckets to store the pointers
    node **bins;

    // array of pointers to linked list of size 10 as
    // integers are decimal numbers so they can hold numbers
    // from 0-9 only, that's why size of 10

    bins = new node *[10];

    // initializing the hash array with null to all
    for (int i = 0; i < 10; i++)
        bins[i] = NULL;

    // first loop working for a constant time only and inner
    // loop is iterating through the array to store elements
    // of array in the linked list by their digits value
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < ARR_SIZE; j++) // bins updation
            insert(bins[(arrFour[j] / (int)pow(10, i)) % 10],
                   arrFour[j]);

        int x = 0, y = 0;
        // write back to the array after each pass

        while (x < 10)
        {
            while (bins[x] != NULL)
                arrFour[y++] = del(bins[x]);
            x++;
        }
    }
    cout << "\n   Third Max: " << arrFour[(sizeof(arrFour) / sizeof(int)) - 2] << endl;
    auto stop = chrono::high_resolution_clock::now();                         //  TESTER
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start); //  TESTER
    cout << duration.count() << endl;
}



    int main()
{
    thirdMax_Sorted();
    thirdMax_Arrays();
    thirdMax_Vince();
    radix_sort();
    return 0;
}