#include <bits/stdc++.h>
using namespace std;

int find_the_max_in_the_citation(map<int, int>& citation, int total_sum)
{
    // int max = less_than_threshold[0];
    vector<int> all_lower_than_sum;
    map<int, int>::iterator itr = citation.begin();
    map<int, int>::iterator end = citation.end();
    while (itr != end)
    {
        if (itr->first <= total_sum)
        {
            all_lower_than_sum.push_back(itr->first);
        }
        itr++;
    }
    int max = all_lower_than_sum[0];
    for (int i = 0; i < all_lower_than_sum.size(); i++)
    {
        int temp = all_lower_than_sum[i];
        if (max < temp)
        {
            max = temp;
        }
    }
    // for (int i = 1; i < less_than_threshold.size(); i++) 
    // {
    //     int temp = less_than_threshold[i];
    //     if (temp > max)
    //     {
    //         max = temp;
    //     }
    // }
    return max;
}

// int check_the_h_index(int threshold, vector<int> citation, int q)
void check_the_h_index(int threshold, int publications [][2], int q)
{
    map<int, int> citation;
    // citation[publications[0][1]] = publications[0][0];
    for (int i = 0; i < q; i++)
    {

        citation[publications[i][1]] += publications[i][0];
        int total_sum = accumulate(citation.begin(), citation.end(),0, 
            [](const int prev_num, const pair<int, int>& entry)
            {
                return prev_num + entry.second;
            }
        );
        // if (citation[0])
        cout << find_the_max_in_the_citation(citation, total_sum) << endl;
    }

    

    // vector<int> less_than_threshold;
    // int h_index = 0;
    // int counter_upper = 0, counter_lower = 0;
    // for (int i = 0; i < q; i++)
    // {
    //     if (citation[i] <= threshold)
    //     {
    //         less_than_threshold.push_back(citation[i]);
    //         // h_index = find_the_max_in_the_vector(less_than_threshold);
    //         counter_lower++;
    //     }
    //     else 
    //     {
    //         h_index = threshold;
    //         counter_upper++;
    //     }
    // }
    // int len = q;
    // if (counter_upper == len)
    // {
    //     return h_index;
    // }
    // else
    // {
    //     h_index = find_the_max_in_the_vector(less_than_threshold);
    //     return h_index;
    // }
    
    // return h_index;
}

int main() 
{
    // int citation[] = {1041, 20, 3, 1, 1};
    // printf("%d\n", check_the_h_index(5, citation, 5));

    int q;
    cin >> q;
    int publications[q][2];
    for (int i = 0; i < q; i++) 
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> publications[i][j];
        }
    }
    // vector<int> citation;
    // citation.push_back(publications[0][1]);
    // int thresholds = publications[0][0];
    check_the_h_index();
    // cout << h_index << endl;
    // for (int i = 1; i < q; i++)
    // {
    //     thresholds += publications[i][0];
    //     citation.push_back(publications[i][1]);
    //     h_index = check_the_h_index(thresholds, citation, i + 1);
    //     cout << h_index << endl;
    // }
    // int sample = 1000000000;
    // cout << sample << endl;
    return 0;
}