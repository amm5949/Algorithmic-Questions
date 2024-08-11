#include <iostream>
#define MAX 200000
using namespace std;

void count_valid_substring(char* c, int start_index, int end_index) { // remmeber to get the start and endindex
    int count = 0;
    int total_count = 0;
    bool crossedOverLetter = false;
    for (int i = start_index; i <= end_index; i++) {
        char in_array = *(c + i);
        if (isdigit(in_array)){
            if (crossedOverLetter) {
                count = 0;
                crossedOverLetter= false;
            }
            count++;
        }
        else {
            total_count += count;
            crossedOverLetter = true;
        }
    }
    cout << total_count << endl;
}

void chnage_the_string(char *c, int index, char replaced) {
    *(c + index) = replaced;
}

int main () {
    int n, q;
    cin >> n >> q;

    char theString [MAX];
    for (int i = 0; i < n; i++) {
        cin >> theString[i];
    }

    int theQueries[q][3];
    char queries_characters[q];

    for (int i = 0; i < q; i++) {
        int q1, q2;
        cin >> q1 >> q2;
        theQueries[i][0] = q1;
        theQueries[i][1] = q2;
        if (q1 == 2) {
            char temp;
            cin >> temp;
            // scanf("%c", &temp);
            queries_characters[i] = temp;
        }
        else {
            int temp;
            cin >> temp;
            theQueries[i][2] = temp;
        }
    }

    for (int i = 0; i < q; i++) {
        int type = theQueries[i][0];
        int start_index = theQueries[i][1];
        start_index--;
        if (type == 1) {
            int end_index = theQueries[i][2];
            end_index--;
            count_valid_substring(theString, start_index, end_index);
        }
        else {
            char replaced = queries_characters[i];
            chnage_the_string(theString, start_index, replaced);
        }
    }

    // cout << endl;
    // for (int i = 0; i < q; i++) {
    //     for (int j = 0; j < 3; j++) {
    //         cout << theQueries[i][j] << " ";
    //     }
    //     cout << endl;
        
    // }

    // for (int i = 0; i < q; i++) {
    //     cout << queries_characters[i] << endl;
    // }


    // cout << n << " " << q << endl;
    return 0;
}