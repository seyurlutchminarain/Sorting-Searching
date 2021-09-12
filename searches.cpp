#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cmath>

using namespace std;

vector<int> genInput(int N)
{
    vector<int> myList;
    for (int i = 0; i < N; i++)
    {
        random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<> dist(1,10);
        int number = dist(generator);

        myList.push_back(number);
    }

    return myList;

}

void printList(vector<int> myList)
{
    for (int x : myList)
    {
        cout << x << " ";
    }
    cout << endl;
}

int linearSearch(vector<int> myList, int key)
{
    int index = 0;
    while (index <= (myList.size()-1) && myList[index] != key)
    {
        index++;
    }
    if (index > myList.size()-1)
    {
        index = -1;
    }

    return index;
    
}

int binarySearch(vector<int> myList, int key) // here the list needs to be in sorted order
{
    int low = 0;
    int high = myList.size()-1;
    bool found = false;
    int mid;

    while (low <= high && found == false)
    {
        mid = floor((low+high)/2);
        if (key == myList[mid])
        {
            found = true;
        }
        else
        {
            if (key < myList[mid])
            {
                high = mid - 1; 
            }
            else
            {
                low = mid + 1;
            }
        }
    }

    if (found == false)
    {
        mid = -1;
    }

    return mid;
}


int main()
{
    int N , key;
    cout << "Enter length of list:" << endl;
    cin >> N;


    vector<int> inputs = genInput(N);
    printList(inputs);
    
    cout << "Enter key (in the range 1-10):" << endl;
    cin >> key;

    auto start = chrono::high_resolution_clock::now();
    int index = linearSearch(inputs, key);
    auto finish = chrono::high_resolution_clock::now();
    long long timeTaken =  chrono::duration_cast<chrono::nanoseconds>(finish-start).count();
    
    if (index != -1)
    {
        cout << "key found at index "<< index <<endl;
        cout << "Search took " << timeTaken << " ns" << endl;
    }
    else{
        cout << "key not found" <<endl;
    }

    return 0;
}