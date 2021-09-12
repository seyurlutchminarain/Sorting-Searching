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
        std::uniform_int_distribution<> dist(1,1000);
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

vector<int> maxSort(vector<int> myList, long long &timeTaken)
{
    auto start = chrono::high_resolution_clock::now();
    int n = myList.size();

    for (int i = n -1; i > 0; i--)
    {
        int maxPos = i;
        for (int j = 0; j < i; j++)
        {
            if (myList[j] > myList[maxPos])
            {
                maxPos = j;
            }
        }

        int temp = myList[maxPos];
        myList[maxPos] = myList[i];
        myList[i] = temp;
    }
    auto finish = chrono::high_resolution_clock::now();
    timeTaken =  chrono::duration_cast<chrono::nanoseconds>(finish-start).count();

    return myList;

}

vector<int> selectionSort(vector<int> myList, long long &timeTaken)
{
    auto start = chrono::high_resolution_clock::now();
    int n = myList.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minPos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (myList[j] < myList[minPos])
            {
                minPos = j;
            }
        }
        int temp = myList[minPos];
        myList[minPos] = myList[i];
        myList[i] = temp;
    }
    auto finish = chrono::high_resolution_clock::now();
    timeTaken =  chrono::duration_cast<chrono::nanoseconds>(finish-start).count();

    return myList;
}

vector<int> bubbleSort(vector<int> myList, long long &timeTaken)
{
    auto start = chrono::high_resolution_clock::now();
    int n = myList.size();

    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (myList[j] > myList[j+1])
            {
                int temp = myList[j];
                myList[j] = myList[j+1];
                myList[j+1] = temp;
            }
        }
    }    
    
    auto finish = chrono::high_resolution_clock::now();
    timeTaken =  chrono::duration_cast<chrono::nanoseconds>(finish-start).count();


    return myList;
}

int main()
{
    int N , key;
    long long time = 0;
    cout << "Enter length of list:" << endl;
    cin >> N;


    vector<int> inputs = genInput(N);
    printList(inputs);

    vector<int> sorted = maxSort(inputs, time);
    cout << "List sorted using Max Sort:" << endl;
    printList(sorted);
    cout << "Time taken: " << time << " ns" << endl;

    sorted = selectionSort(inputs, time);
    cout << "List sorted using Selection Sort:" << endl;
    printList(sorted);
    cout << "Time taken: " << time << " ns" << endl;

    sorted = bubbleSort(inputs, time);
    cout << "List sorted using Bubble Sort:" << endl;
    printList(sorted);
    cout << "Time taken: " << time << " ns" << endl;

 

    return 0;
}