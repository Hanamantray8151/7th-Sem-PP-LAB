#include <bits/stdc++.h>
#include <omp.h>
using namespace std;

void merge(int *arr, int s, int m1, int m2, int e)
{
    int p = s, q = m2, k = 0, temp[1000], i, j;
    while (p <= m1 && q <= e)
    {
        if (arr[p] < arr[q])
            temp[k++] = arr[p++];
        else
            temp[k++] = arr[q++];
    }

    while (p <= m1)
        temp[k++] = arr[p++];
    while (q <= e)
        temp[k++] = arr[q++];
    for (i = s, j = 0; i <= e; i++, j++)
        arr[i] = temp[j];
}

void mergesort(int *arr, int s, int e)
{
    int mid = 0;
    if (s < e)
    {
        mid = (s + e) / 2;
#pragma omp parallel sections
        {
#pragma omp section
            {
                cout << "Process handing left recursion is " << omp_get_thread_num() << endl;
                mergesort(arr, s, mid);
            }
#pragma omp section
            {
                cout << "Process handing right recursion is " << omp_get_thread_num() << endl;
                mergesort(arr, mid + 1, e);
            }
        }
        merge(arr, s, mid, mid + 1, e);
    }
}

int main()
{
    int n;
    cout << "Enter number of elements for sorting" << endl;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
    cout << "Unsorted Array is" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    mergesort(arr, 0, n - 1);
    cout << "Sorted Array is" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}