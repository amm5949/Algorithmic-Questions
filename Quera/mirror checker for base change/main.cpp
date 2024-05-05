#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int pow (int number, int power) {
    
    if (power == 0) {
        return 1;
    }
    else {
        return number * pow(number, power - 1);
    }
}

int base_to_ten (int base, int number) {
    int original_number = 0;
    int place = 0;
    while (number > 0) {
        int remainder = number % 10;
        original_number += remainder * pow(base, place);

        place++;
        number = number / 10;
    }
    return original_number;
}

int ten_to_base (int number, int target_base) {
    stack<int> myStack;
    int original_number = 0;
    int place = 0;
    while (number > 0) {
        int remainder = number % target_base;
        myStack.push(remainder);
        number = number / target_base;
    }
    while (!myStack.empty()) {
        original_number += myStack.top() * pow(10, myStack.size() - 1);
        myStack.pop();
    }
    
    return original_number;
}

bool check_palindrome(int number) {
    string number_string = to_string(number);
    string::iterator iter_start = number_string.begin();
    string::iterator iter_end = number_string.end();
    bool is_palindrome = true;
    // cout << *iter_start << endl;
    // cout << *(iter_end - 2) << endl;
    // printf("%d\n", iter_start + 1);
    // printf("%d\n", iter_end - 2);
    // cout << number_string.length();

    int len = number_string.length();
    iter_end--;
    int mid = floor(len / 2);
    bool results[mid];
    int i = 0;
    while (iter_start <= iter_end) {
        if (*iter_start == *iter_end) {
            results[i] = true;
        }
        else{
            results[i] = false;
        }
        iter_start++;
        iter_end--;
        i++;
    }
    for (int i = 0 ; i < mid; i++) {
        if (results[i] == false) {
            is_palindrome = false;
        }
    }
    return is_palindrome;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    
    int ten_version = base_to_ten(b, a);
    // cout << ten_version << endl;
    int tagrget_base = ten_to_base(ten_version, c);
    // cout << tagrget_base << endl;
    bool is_palindrome = check_palindrome(tagrget_base);

    if (is_palindrome) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    


    return 0;
}