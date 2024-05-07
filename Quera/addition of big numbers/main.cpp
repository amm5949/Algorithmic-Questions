#include <iostream>
#include <vector>
#include <string>
using namespace std;

string insert(string str, int number_of_added) {
    for (int i = 0; i < number_of_added; i++) {
        str.insert(0, "0");
    }
    
    return str;
}

int determine_the_number_length(vector<string> str) {
    
    
    int max_length = str[0].length();
    for (int i = 1; i < str.size(); i++) {
        int length_of_current_string = str[i].length();
        if (length_of_current_string > max_length) {
            max_length = length_of_current_string;
        }
    }
    return max_length + 1;
}

void solve (vector<string> numbers) {

    string result;
    int length_of_string = determine_the_number_length(numbers);
    
    for (int i = 0; i < numbers.size(); i++) {
        numbers[i] = insert(numbers[i], length_of_string - numbers[i].length());
    }
    int sum = 0;
    int carry = 0;
    
    for(int j = numbers[0].length() - 1; j >= 0; j--) {
        sum = 0;
        for (int i = 0; i < numbers.size(); i++) {
            
            int number = numbers[i][j] - '0';
            sum += number;
            if (i == numbers.size() - 1) {
                sum += carry;
                carry = sum / 10;
                int remainder = sum % 10;
                string remainder_in_string = to_string(remainder);
                
                result.insert(0, remainder_in_string);
            }
        }
        
    }
    
    if (result.at(0) == '0') {
        cout << result.erase(0, 1) << endl;
    }
    else {
        cout << result << endl;
    }
} 

int main() {
    int n;
    cin >> n;
    
    vector<string> numbers;
    for (int i = 0; i < n ; i++) {
        string number;
        cin >> number;
        numbers.push_back(number);
    }
    
    solve(numbers);
    return 0;
}