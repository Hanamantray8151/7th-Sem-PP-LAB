#include <bits/stdc++.h>
#include <omp.h>
#include <stdio.h>
using namespace std;

int main()
{
    int fact1 = 1, fact2 = 1, a, i;

    cout << "Enter a number to check its factorial" << endl;
    cin >> a;

#pragma omp parallel for firstprivate(a)
    for (i = 2; i <= a; i++)
        fact1 = fact1 * i;

    cout << "When first private is not used" << endl;
    cout << "Factorial of " << a << " is " << fact1 << endl;

#pragma omp parallel for firstprivate(a, fact2)
    for (i = 2; i <= a; i++)
        fact2 = fact2 * i;

    cout << "When first private is used" << endl;
    cout << "Factorial of " << a << " is " << fact2 << endl;
    return 0;
}