// Activity selection problem using priority queue and iterative greedy
#include <iostream>
#include <bits/stdc++.h>
#include <ctime>
using namespace std;

void printMaxActivities(vector<int> s, vector<int> f, int n)
{
    vector<pair<int, int>> ans;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push(make_pair(f[i], s[i]));
    }

    auto it = pq.top();
    int start = it.second;
    int finish = it.first;
    pq.pop();
    ans.push_back(make_pair(start, finish));

    while (!pq.empty())
    {
        auto itr = pq.top();
        pq.pop();
        if (itr.second >= finish)
        {
            start = itr.second;
            finish = itr.first;
            ans.push_back(make_pair(start, finish));
        }
    }
    cout << "The following activities are selected: " << endl;
    for (auto itr = ans.begin(); itr != ans.end(); itr++)
    {
        cout << (*itr).first << ", " << (*itr).second << endl;
    }
}

int main()
{
    int n, start, finish;
    cout << "Enter the number of activities taking place: ";
    cin >> n;
    vector<int> s, f;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the Start time and Finish time of activity " << i + 1 << ": ";
        cin >> start >> finish;
        s.push_back(start);
        f.push_back(finish);
    }
    // int s[] = {1, 3, 0, 5, 8, 5};
    // int f[] = {2, 4, 6, 7, 9, 9};
    // int n = sizeof(s) / sizeof(s[0]);

    clock_t tstart = clock();
    printMaxActivities(s, f, n);
    double time1 = (double)(clock() - tstart) / CLOCKS_PER_SEC;
    cout << "Time taken by algorithm is: " << time1 << endl;
    return 0;
}