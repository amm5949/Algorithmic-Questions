#include <iostream>
using namespace std;
#define MAX 1000000
int fib [MAX];
int the_last_index = 0;

void initialization () {
    for (int i = 0; i < MAX; i++) {
        fib[i] = -1;
    }
}

void ShowFibNth(long int n, long int n_next) {
    fib[0] = 1;
    fib[1] = 1;
    int temp = 0;
    for (int i = 2; i < MAX; i++) {
        temp = fib[i - 1] + fib[i - 2];
        fib[i] = temp;
        if (temp == n) {
            
            the_last_index = i;
            break;
        }
    }
}


int main() {
    // cout << "I am Maghrebi";
    long int n, n_next;
    cin >> n >> n_next;
    initialization();
    ShowFibNth(n, n_next);
    // int len = sizeof()
    for (int i = the_last_index; i >= 0; i--) {
        cout << fib[i] << endl;
    }
    // cout << n << endl << n_next << endl;
    return 0;
}