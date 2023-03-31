// #include <bits/stdc++.h>
// #include <ctime>
// #include <stdio.h>
// #include <iostream>
// using namespace std;
// bool isValidShift(string T, string P, int s)
// {
//     int m = P.length();
//     for (int i = 0; i < m; i++)
//     {
//         if (P[i] != T[s + i])
//             return false;
//     }
//     return true;
// }
// vector<int> naiveStringMatcher(string T, string P)
// {
//     int n = T.length();
//     int m = P.length();
//     vector<int> R;
//     for (int s = 0; s <= n - m; s++)
//     {
//         if (isValidShift(T, P, s))
//             R.push_back(s);
//     }
//     return R;
// }
// int main()
// {
//     string T, P;
//     cin >> T >> P;
//     clock_t tStart = clock();
//     auto A = naiveStringMatcher(T, P);
//     double t = (double)(clock() - tStart) / CLOCKS_PER_SEC;
//     cout << endl
//          << "Time taken (in seconds) : " << t << endl;
//     if (A.size() == 0)
//     {
//         cout << "No match" << endl;
//         return 0;
//     }
//     // cout << "Valid Shifts: ";
//     // for ( int i = 0; i < A.size(); i++ ) {
//     //  cout << A[i] << ", ";
//     // }
//     cout << endl;
//     return 0;
// }

#include <bits/stdc++.h>
#include <ctime>
using namespace std;

const int d = 256; // size of the character set
const int q = 101; // prime number used for hashing

void rabinKarp(string pattern, string text)
{
    int m = pattern.length();
    int n = text.length();
    int p = 0; // hash value for pattern
    int t = 0; // hash value for text
    int h = 1;

    // calculate h as d^(m-1) modulo q
    for (int i = 0; i < m - 1; i++)
    {
        h = (h * d) % q;
    }

    // calculate initial hash values for pattern and text
    for (int i = 0; i < m; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // slide the pattern over the text one by one
    for (int i = 0; i <= n - m; i++)
    {
        // check if the hash values for current window match
        if (p == t)
        {
            bool match = true;
            // compare characters one by one
            for (int j = 0; j < m; j++)
            {
                if (pattern[j] != text[i + j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                cout << "Pattern found at index " << i << endl;
            }
        }
        // calculate hash value for next window
        if (i < n - m)
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0)
            {
                t += q;
            }
        }
    }
}

int main()
{
    string pattern, text;
    cin >> text >> pattern;
    clock_t tstart = clock();
    rabinKarp(pattern, text);
    double time1 = (double)(clock() - tstart) / CLOCKS_PER_SEC;
    cout << "Time taken by Rabin Karp Algorithm is: " << time1;
    return 0;
}

// #include <iostream>
// #include <string>
// #include <vector>
// #include <ctime>

// using namespace std;

// vector<int> computePrefix(string pattern)
// {
//     int n = pattern.size();
//     vector<int> prefix(n);
//     prefix[0] = 0;
//     int j = 0;
//     for (int i = 1; i < n; i++)
//     {
//         while (j > 0 && pattern[i] != pattern[j])
//         {
//             j = prefix[j - 1];
//         }
//         if (pattern[i] == pattern[j])
//         {
//             j++;
//         }
//         prefix[i] = j;
//     }
//     return prefix;
// }

// vector<int> kmpSearch(string text, string pattern)
// {
//     vector<int> matches;
//     int n = text.size();
//     int m = pattern.size();
//     vector<int> prefix = computePrefix(pattern);
//     int j = 0;
//     for (int i = 0; i < n; i++)
//     {
//         while (j > 0 && text[i] != pattern[j])
//         {
//             j = prefix[j - 1];
//         }
//         if (text[i] == pattern[j])
//         {
//             j++;
//         }
//         if (j == m)
//         {
//             matches.push_back(i - m + 1);
//             j = prefix[j - 1];
//         }
//     }
//     return matches;
// }

// int main()
// {
//     string text, pattern;
//     cin >> text >> pattern;
//     clock_t tstart = clock();
//     vector<int> matches = kmpSearch(text, pattern);
//     for (int i = 0; i < matches.size(); i++)
//     {
//         cout << "Match found at index " << matches[i] << endl;
//     }
//     double time1 = (double)(clock() - tstart) / CLOCKS_PER_SEC;
//     cout << "Time taken by the KMP algorithm is: " << time1 << endl;
//     return 0;
// }
