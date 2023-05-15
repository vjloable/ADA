#include <iostream>
#include <string>
using namespace std;

int safeMod(int dividend, int divisor){
    return (dividend % divisor + divisor) % divisor;
}

void linearHashing(int table[], int table_size, int arr[], int arr_size, int &probes)
{
    for (int i = 0; i < table_size; i++)
    {
        table[i] = -1;
    }

    cout << "Linear Hashing" << endl;
    for (int iterX = 0; iterX < arr_size; iterX++)
    {
        int hk = safeMod(arr[iterX], table_size); // int hk = arr[iterX] % table_size;
        if (table[hk] == -1) {
            table[hk] = arr[iterX];
        } else {
            for (int iterY = 0; iterY < table_size; iterY++)
            {
                int i = 1 + iterY;
                int index = safeMod(hk + i, table_size); // int index = (hk + i) % table_size;
                if (table[index] == -1)
                {
                    probes = probes + 1;
                    table[index] = arr[iterX];
                    break;
                }
            }
        }
    }
    for (int iterZ = 0; iterZ < table_size; iterZ++)
    {
        string result = "";
        if (table[iterZ] == -1){
            result = "_";
        }else{
            result = to_string(table[iterZ]);
        }
        cout << result << " ";
    }
    cout << "\nTotal Probes: " << probes << endl;
    probes = 0;
    cout << "\n" << endl;
}

void quadraticHashing(int table[], int table_size, int arr[], int arr_size, int &probes)
{
    for (int i = 0; i < table_size; i++)
    {
        table[i] = -1;
    }

    cout << "Quadratic Hashing" << endl;
    for (int iterX = 0; iterX < arr_size; iterX++)
    {
        int hk = safeMod(arr[iterX], table_size); // int hk = arr[iterX] % table_size;
        if (table[hk] == -1) {
            table[hk] = arr[iterX];
        } else {
            for (int iterY = 0; iterY < table_size; iterY++)
            {
                int i = 1 + iterY;
                int index = safeMod(hk+(i*i), table_size); // int index = (hk + i*i) % table_size;
                if (table[index] == -1)
                {
                    probes = probes + 1;
                    table[index] = arr[iterX];
                    break;
                }
            }
        }
    }
    for (int iterZ = 0; iterZ < table_size; iterZ++)
    {
        string result = "";
        if (table[iterZ] == -1)
        {
            result = "_";
        }
        else
        {
            result = to_string(table[iterZ]);
        }
        cout << result << " ";
    }
    cout << "\nTotal Probes: " << probes << endl;
    probes = 0;
    cout << "\n"
         << endl;
}

void doubleHashing(int table[], int table_size, int arr[], int arr_size, int &probes)
{
    for (int i = 0; i < table_size; i++)
    {
        table[i] = -1;
    }

    cout << "Double Hashing" << endl;
    for (int iterX = 0; iterX < arr_size; iterX++)
    {
        int hk = safeMod(arr[iterX], table_size); // int hk = arr[iterX] % table_size;
        if (table[hk] == -1){
            // cout << "\nDEBUG: Passed " << arr[iterX] << endl;
            // cout << "   DEBUG: index " << hk << endl;
            table[hk] = arr[iterX];
        }
        else
        {
            // cout << "\nDEBUG: Conflict " << arr[iterX] << " with " << table[hk] << endl;
            for (int iterY = 0; iterY < table_size; iterY++)
            {
                // cout<<iterY<<endl;
                // cout << "   DEBUG: iterX " << iterX << " -- iterY " << iterY << endl;
                int dk = safeMod(13 - arr[iterX], 13); // int dk = (13 - arr[iterX]) % 13; //-58
                // cout << "   DEBUG: 13 - k " << (13 - arr[iterX]) << endl;

                // cout << "   DEBUG: dk " << dk << endl;
                int index = safeMod(dk+(iterY*dk),17); //int index = (dk + (iterY * dk)) % 17; //
                // cout<<"   DEBUG: index "<<index<< endl; 
                if (table[index] == -1)
                {
                    probes = probes + 1;
                    table[index] = arr[iterX];
                    break;
                }
            }
        }
    }
    for (int iterZ = 0; iterZ < table_size; iterZ++)
    {
        string result = "";
        if (table[iterZ] == -1)
        {
            result = "_";
        }
        else
        {
            result = to_string(table[iterZ]);
        }
        cout << result << " ";
    }
    cout << "\nTotal Probes: " << probes << endl;
    probes = 0;
    cout << "\n"
         << endl;
}

// [ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16]
// [  ,  ,  ,88,38,  ,  ,20,25,  , 3,  ,  ,  ,  ,  ,  ] 
int main()
{
    int probes = 0;
    int arr[] = {25, 88, 3, 38, 20, 71, 55, 56, 50, 105};
    int N = 10;

    int L = 17;
    int hash_table[17];

    linearHashing(hash_table, L, arr, N, probes);
    quadraticHashing(hash_table, L, arr, N, probes);
    doubleHashing(hash_table, L, arr, N, probes);
    return 0;
}
