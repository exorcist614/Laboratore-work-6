#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <locale.h>
#include <cstdlib>
#include <time.h>
#include <iomanip>
#include <ctime>


using namespace std;

int main()
{
    srand((unsigned)time(NULL));
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
      // swap the elements of the main and secondary diagonals
      for( int i=0; i<N; i++){
		int tmp = arr[i][N-i-1];
		arr[i][N-i-1]=arr[i][i];
		arr[i][i]=tmp;
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
    
for (int count = 0; count < N; count++)
    delete [] arr[count];
    int max = arr[0][0];
    for(int i=1; i<N; ++i)
        if(arr[i][i]>max)
        max = arr[i][i];

cout<<"Main diagonals maximum value: "<<max<<endl;


int min=arr[0][0];
for(int i=0, j=0; i<N, j<N; ++i, ++j)
{
    if(arr[i][j]<min)
    min=arr[i][j];
}
printf("Main diagonals minimum value: %d\n", min);
for(int i=0; i<N; ++i)
free(arr[i]);
free(arr);


max = arr[0][N - 1];
for (int i = 0; i < N; i++)
    if (arr[i][N - 1 - i] > max)
        max = arr[i][N - 1 - i];
        
cout<<"Side diagonals maximum value: "<<max<<endl;

int j = N - 1;
min = arr[0][j];
    for(int i = 0; i < N; i++)
    {
        if(min > arr[i][j])
        {
            min = arr[i][j];
        }
        j--;
    }
cout << "Side diagonals minimum value:" << min << endl;

return 0;
}
