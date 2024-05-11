// #include <iostream>
#include <bits/stdc++.h>
// #include <vector>
using namespace std;

int check_col(int current, int next)
{
    int guards = 0;
    if (current != next)
    {
        guards++;
    }
    return guards;
}

int check_row(int current, int next)
{
    int guards = 0;
    if (current != next)
    {
        guards++;
    }
    return guards;
}

int check_around(int current, int i, int j, int x_dim, int y_dim)
{
    int guards = 0;
    if (current) 
    {
        if ((i == 0 || i == x_dim - 1) && (j > 0 && j < y_dim - 1))
        {
            guards++;
        }
        if ((i == 0 || i == x_dim - 1) && (j == 0 || j == y_dim - 1))
        {
            guards += 2;
        }
        if ((j == 0 || j == y_dim - 1) && (i > 0 && i < x_dim - 1)) 
        {
            guards++;
        }
        // if ((i == 0 || i == x_dim - 1) && (j > 0 && j < y_dim - 1))
        // {
        //     guards++;
        // }
        // if ((i == 0 || i == x_dim - 1) && (j == 0 || j == y_dim - 1))
        // {
        //     guards += 2;
        // }
    }
    return guards;
}

int main() 
{
    int x_dim, y_dim;
    
    cin >> x_dim >> y_dim;
    int lake [x_dim][y_dim];
    // cout << x_dim;
    for (int i = 0; i < x_dim; i++) 
    {
        for (int j = 0 ; j < y_dim; j++) 
        {
            cin >> lake[i][j];
        }
    }

    int sum = 0;
    for (int i = 0; i < x_dim - 1; i++) 
    {
        for (int j = 0 ; j < y_dim - 1; j++) 
        {
            sum += check_row(lake[i][j], lake[i][j + 1]);
            sum += check_col(lake[i][j], lake[i + 1][j]);
            sum += check_around(lake[i][j], i, j, x_dim, y_dim);
        }
    }
    for (int i = 0; i < x_dim - 1; i++) {
        sum += check_col(lake[i][y_dim - 1], lake[i + 1][y_dim - 1]);
        sum += check_around(lake[i][y_dim - 1], i, y_dim - 1, x_dim, y_dim);
    }
    for (int j = 0; j < y_dim - 1; j++) {
        sum += check_row(lake[x_dim - 1][j], lake[x_dim - 1][j + 1]);
        sum += check_around(lake[x_dim - 1][j], x_dim - 1, j, x_dim, y_dim);
    }
    sum += check_around(lake[x_dim - 1][y_dim - 1], x_dim - 1, y_dim - 1, x_dim, y_dim);
    cout << sum << endl;
    return 0;
}