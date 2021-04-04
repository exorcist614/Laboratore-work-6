#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <locale.h>
#include <cstdlib>
#include <time.h>
using namespace std;
 
int main()
{
    srand(time(0));
    int N, a, b;
    cout << "Enter a matrix size:" << "\n";
    cout << "N = ";
    cin >> N;
    cout << "Enter a left boundary:" << "\n";
    cout << "a = ";
    cin >> a;
    cout << "Enter a right boundary:" << "\n";
    cout << "b = ";
    cin >> b;
    int** arr = new int*[N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = new int[N];
    }
    cout << "A random matrix:" << "\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = a + rand() % (b - a);
            cout.width(3);
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < N - 1; i++)
    {
        swap(arr[0][i], arr[N-i-1][N-1]);
    }
    cout << "Target matrix:" << "\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
 
            cout.width(3);
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < N; i++)
    {
        delete [] arr[i];
    }
    delete [] arr;
    cin.get();
    return 0;
}
