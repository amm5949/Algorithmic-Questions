#include <iostream>
#include <cmath>
using namespace std;

int ceiling (int a, int divisor)
{
    if (a % divisor == 0) 
    {
        return a / divisor;
    }
    else
    {
        a = a / divisor;
        return a + 1;
    }
}

bool check_palindrome(string str) 
{
    string::iterator start_itr = str.begin();
    string::iterator from_end_itr = str.end() - 1; // the pointer to end is null, so it is not desirable
    int dimensions = ceiling(str.length(), 2);
    bool is_palindrome [dimensions];
    bool is_finally_palindrome = false;
    int i = 0;
    // printf("%d \n", start_itr);
    // printf("%d \n", from_end_itr);
    while (start_itr <= from_end_itr) 
    {
        if (*start_itr == *from_end_itr) 
        {
            is_palindrome[i++] = true;
        }
        else
        {
            is_palindrome[i++] = false;
        }
        start_itr++;
        from_end_itr--;
    }
    int len = sizeof(is_palindrome) / sizeof(is_palindrome[0]);
    int count = 0;
    for (i = 0; i < len; i++) 
    {
        if (is_palindrome[i]) 
        {
            count++;
        }
    }
    if (count == len) 
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

int main() {
    string the_string;
    int number_of_queries;
    cin >> the_string;
    cin >> number_of_queries;
    int indices[number_of_queries][2];
    for (int i = 0; i < number_of_queries; i++) 
    {
        cin >> indices[i][0];
        cin >> indices[i][1];
    }
    for (int i = 0; i < number_of_queries; i++) 
    {
        string new_substr_string = the_string.substr(indices[i][0] - 1, indices[i][1] - indices[i][0] + 1);
        if (check_palindrome(new_substr_string)) 
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    // the_string = "ama";
    // cout << check_palindrome(the_string) << endl;;
    // the_string = "amma";
    // cout << check_palindrome(the_string) << endl;;
    return 0;
}