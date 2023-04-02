// Activity selection problem using priority queue and recursive greedy
#include <iostream>
#include <bits/stdc++.h>
#include <ctime>
using namespace std;

void printMaxActivities(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p, int k, int n)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q = p;
    ++k;
    if (k < n)
    {
        auto it = q.top();
        int start1 = it.second;
        int end1 = it.first;
        q.pop();
        auto itr = q.top();
        int start2 = itr.second;
        int end2 = itr.first;
        q.pop();
        if (start2 >= end1)
        {
            cout << start2 << ", " << end2 << endl;
            q.push(make_pair(end2, start2));
            printMaxActivities(q, k, n);
        }
        else
        {
            q.push(make_pair(end1, start1));
            printMaxActivities(q, k, n);
        }
    }
}

int main()
{
    int n, st, fn;
    cout << "Enter the number of activities performed: ";
    cin >> n;

    vector<int> s, f;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the start time and finish time of the activity " << i + 1 << ": ";
        cin >> st >> fn;
        s.push_back(st);
        f.push_back(fn);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(make_pair(f[i], s[i]));
    }
    auto it = pq.top();
    int sr = it.second;
    int fl = it.first;
    cout << "The following activities are selected: " << endl
         << sr << ", " << fl << endl;
    int k = 0;
    clock_t tstart = clock();
    printMaxActivities(pq, k, n);
    double time1 = (double)(clock() - tstart) / CLOCKS_PER_SEC;
    cout << "Time taken by the algorithm is: " << time1 << endl;
}