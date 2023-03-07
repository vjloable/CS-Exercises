// Vince Japheth F. Loable  

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cout << "Algorithm #1: Sort-it-First Thirdmax Algorithm" << endl;
    cout << "---------------------" << endl;
    int arrOne[12] = {8, 10, 1, 30, 140, 145, 70, 19, 323, 434, 3, 69};
    cout << "arrOne: \n";
    for (int i = 0; i < (sizeof(arrOne) / sizeof(int)) - 1; i++)
    {
        cout << arrOne[i] << " ";
    }
    cout << arrOne[(sizeof(arrOne) / sizeof(int))-1] << " " << endl;
    sort(arrOne, arrOne + (sizeof(arrOne) / sizeof(int)), greater<int>());
    cout << "\narrOne (Sorted): \n";
    for (int i = 0; i < (sizeof(arrOne) / sizeof(int)) - 1; i++)
    {
        cout << arrOne[i] << " ";
    }
    cout << arrOne[(sizeof(arrOne) / sizeof(int)) - 1] << " " << endl;
    cout << "\n   Third Max: " << arrOne[2] << endl;
    cout << "\n---------------------\n\n" << endl;

    cout << "Algorithm #2: Array-Extraction Thirdmax Algorithm" << endl;
    cout << "---------------------" << endl;
    int arrA[12] = {8, 10, 1, 30, 140, 145, 70, 19, 323, 434, 3, 69};
    int arrB[(sizeof(arrA) / sizeof(int)) - 1];
    int arrC[(sizeof(arrB) / sizeof(int)) - 1];
    int max = arrA[0];
    int ii = 0;

    cout << "arrA:  ";
    for (int i = 0; i < (sizeof(arrOne) / sizeof(int)) - 1; i++)
    {
        cout << arrA[i] << " ";
    }
    cout << arrA[(sizeof(arrA) / sizeof(int)) - 1] << " " << endl;
    for (int i = 1; i < sizeof(arrA) / sizeof(int); i++){
        if (max < arrA[i]){
            max = arrA[i];
        }
    }
    cout << "max:   " << max << "\n" << endl;
    cout << "arrB:  ";
    for (int i = 0; i < sizeof(arrA) / sizeof(int); i++)
    {
        if (arrA[i] != max)
        {
            arrB[ii] = arrA[i];
            cout << arrB[ii] << " ";
            ii++;
        }
    }
    cout << endl;
    max = arrB[0];
    for (int i = 1; i < sizeof(arrB) / sizeof(int); i++)
    {
        if (max < arrB[i])
        {
            max = arrB[i];
        }
    }
    cout << "max:   " << max << "\n" << endl;
    cout << "arrC:  ";
    ii = 0;
    for (int i = 0; i < sizeof(arrB) / sizeof(int); i++)
    {
        if (arrB[i] != max)
        {
            arrC[ii] = arrB[i];
            cout << arrC[ii] << " ";
            ii++;
        }
    }

    cout << endl;
    max = arrC[0];
    for (int i = 1; i < sizeof(arrC) / sizeof(int); i++)
    {
        if (max < arrC[i])
        {
            max = arrC[i];
        }
    }
    
    cout << "max:   " << max << "\n" << endl;

    cout<<"\n   Third Max: "<< max << endl;

    cout << "\n---------------------\n\n"<< endl;
    cout << "Algorithm #3: My (Vince's) /  ThirdMax  Algorithm" << endl;
    cout << "---------------------" << endl;
    int arrThree[12] = {8, 10, 1, 30, 140, 145, 70, 19, 323, 434, 3, 69};
    int *least;
    int maxA = arrThree[0];
    int maxB = arrThree[1];
    int maxC = arrThree[2];
    int thirdMax;
    (maxA > maxB) ? (least = &maxB) : (least = &maxA);
    if (*least > maxC)
        least = &maxC;
    int loop = 1;
    for (int i = 3; i < (sizeof(arrThree) / sizeof(int)); i = i + 3)
    {
        cout << "\n Loop " << loop << ":" << endl;
        cout << "    maxA = " << maxA << "    " << &maxA << "\n    maxB = " << maxB << "    " << &maxB << "\n    maxC = " << maxC << "    " << &maxC << endl;
        cout << "    least: " << least << endl;

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
        
        cout << "    maxA = " << maxA << "    " << &maxA << "\n    maxB = " << maxB << "    " << &maxB << "\n    maxC = " << maxC << "    " << &maxC << endl;
        cout << "    least: " << least << endl;
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

        cout << "    maxA = " << maxA << "    " << &maxA << "\n    maxB = " << maxB << "    " << &maxB << "\n    maxC = " << maxC << "    " << &maxC << endl;
        cout << "    least: " << least << endl;
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
        cout << "    maxA = " << maxA << "    " << &maxA << "\n    maxB = " << maxB << "    " << &maxB << "\n    maxC = " << maxC << "    " << &maxC << endl;
        cout << "    least: " << least << endl;
        loop++;
    }

    cout<<"\n   Third Max: "<< *least << endl;
    cout << "\n---------------------" << endl;
    
    return 0;
}