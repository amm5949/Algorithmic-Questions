#include <bits/stdc++.h>
using namespace std;

// All of the results will be saved in this array
int scoreboard[2] = {0, 0};

// In this function, we check to which team this player belongs. 
int belongs_to_what_team(int team)
{
    int membership = 0;
    if (team >= 1 && team <= 4)
    {
        membership = 1;     // CS members
    }
    else if (team >= 5 && team <= 8)
    {
        membership = 2;     // CE members
    }
    return membership;
}

// In this function, we check whether we can give extra credits to a team. 
bool grant_additional_scores(int difference_between_two_records, int player_now, int player_past)
{
    bool granted = false;
    if (player_now == player_past)
    {
        if (difference_between_two_records <= 10) 
        {
            granted = true;
        }
    }
    return granted;
}


void solve(int a[][3], int how_many_records)
{
    
    int membership = belongs_to_what_team(a[0][1]);
    scoreboard[membership - 1] += 100;

    for (int i = 1; i < how_many_records; i++)
    {
        int difference = a[i][0] - a[i - 1][0];
        membership = belongs_to_what_team(a[i][1]);
        if (grant_additional_scores(difference, a[i][1], a[i - 1][1])) 
        {
            scoreboard[membership - 1] += 100 + 50;
        }
        else 
        {
            scoreboard[membership - 1] += 100;
        }
    }

    // printing the results
    for (int i = 0; i < 2; i++) 
    {
        cout << scoreboard[i] << " ";
    }
}

int main () 
{
    
    int n;
    cin >> n;
    int records [n][3];
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            cin >> records[i][j];
        }
    }
    solve(records, n);
    
    return 0;
}