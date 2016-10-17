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

// O(N) solution
/*
The idea is that you separate elements into buckets depending on their mod k. For example, you have the elements: 1 3 2 6 4 5 9 and 
k = 3
mod 3 == 0 : 3 6 9
mod 3 == 1 : 1 4
mod 3 == 2 : 2 5
Now, you can make pairs like so: Elements with mod 3 == 0 will match with elements with (3 - 0) mod k = 0, so other elements in 
the mod 3 == 0 list, like so:
(3, 6) (3, 9) (6, 9)
There will be n * (n - 1) / 2 such pairs, where n is length of the list, because the list is the same and i != j. 
Elements with mod 3 == 1 will match with elements with (3 - 1) mod k = 2, so elements in the mod 3 == 2 list, like so:
(1, 2) (1, 5) (4, 2) (4, 5)
There will be n * k such elements, where n is the length of the first list, and k of the second.
Because you don't need to print the actual pairs, you need to store only the number of elements in each list.
*/
int pairs(vector<int>& input, vector<int>& bucket, int k) {
    auto size = input.size();    
    int res = 0;       
    
    res += (bucket[0]*(bucket[0]-1))/2;
    
    for (auto i = 1; i<=k/2 && i != k-i; ++i)
        res += bucket[i]*bucket[k-i];
    
    if (k%2 == 0)
        res += (bucket[k/2]*(bucket[k/2]-1))/2;
    return res;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> input;
    vector<int> bucket(k, 0);
    while(n--) {
        int i = 0;
        cin >> i;
        ++bucket[i%k];
        input.emplace_back(i);
    }
    cout << pairs(input, bucket, k);   
    return 0;
}


// O(N^2) solution
/*int pairs(vector<int>& input, int k) {     
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
}*/
