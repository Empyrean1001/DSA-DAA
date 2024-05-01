#include <iostream>
using namespace std;

int c_step(int n){
    // time complexity : O(n)
    // space complexity : O(n)
    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int c_step_opt(int n){
    // time complexity : O(n)
    // space complexity : O(1)
    int a = 1, b = 1, c;
    for(int i = 2; i<=n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main(){
    int n;
    cout << "Enter the number of steps to climb: ";
    cin >> n;
    cout << "result from normal dp code - " << endl;
    cout << c_step(n) << endl;
    cout << "result from optimized dp code - " << endl;
    cout << c_step_opt(n);

}
