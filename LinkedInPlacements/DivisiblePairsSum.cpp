/*
You are given an array of  integers, , and a positive integer, . Find and print the number of pairs where  and  +  is evenly divisible by .

Input Format

The first line contains  space-separated integers,  and , respectively. 
The second line contains  space-separated integers describing the respective values of .

Constraints

Output Format

Print the number of  pairs where  and  +  is evenly divisible by .

Sample Input

6 3
1 3 2 6 1 2
Sample Output

 5
Explanation

Here are the  valid pairs:

https://www.hackerrank.com/challenges/linkedin-practice-divisible-sum-pairs
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int pairs(vector<int>& input, int k) {
    auto size = input.size();
    int res = 0;
    for (auto i = 0; i<size-1; ++i) {
        for (auto j = i+1; j<size; ++j) {
            if ((input[i]+input[j])%k == 0)
                ++res;
        }
    }
    return res;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> input;
    while(n--) {
        int i = 0;
        cin >> i;
        input.emplace_back(i);
    }
    cout << pairs(input, k);   
    return 0;
}
