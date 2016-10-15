/*
Alice is taking a cryptography class and finding anagrams to be very useful. We consider two strings to be anagrams of each other if 
the first string's letters can be rearranged to form the second string. In other words, both strings must contain the same exact letters 
in the same exact frequency For example, bacdc and dcbac are anagrams, but bacdc and dcbad are not.

Alice decides on an encryption scheme involving two large strings where encryption is dependent on the minimum number of character 
deletions required to make the two strings anagrams. Can you help her find this number?

Given two strings,  and , that may or may not be of the same length, determine the minimum number of character deletions required 
to make  and  anagrams. Any characters can be deleted from either of the strings.

This challenge is also available in the following translations:

Chinese
Russian
Input Format

The first line contains a single string, . 
The second line contains a single string, .

Constraints

It is guaranteed that  and  consist of lowercase English alphabetic letters (i.e.,  through ).
Output Format

Print a single integer denoting the number of characters you must delete to make the two strings anagrams of each other.

Sample Input

cde
abc
Sample Output

4
Explanation

We delete the following characters from our two strings to turn them into anagrams of each other:

Remove d and e from cde to get c.
Remove a and b from abc to get c.
We must delete  characters to make both strings anagrams, so we print 4 on a new line.

https://www.hackerrank.com/challenges/ctci-making-anagrams
*/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int number_needed(string a, string b) {
    //unordered_map<char, int> mapA;
    //unordered_map<char, int> mapB;
    auto sizeA = a.size(), sizeB = b.size();
    auto larger = sizeA >= sizeB ? sizeA : sizeB;
    int delCount = 0;
    vector<int> freq(26);
    for (auto i = 0; i<larger; ++i) {
        if (i < sizeA)
            ++freq[a[i] - 'a'];
        if (i < sizeB)
            --freq[b[i] - 'a'];
    }
    for_each(freq.begin(), freq.end(), [&] (int n) {
        delCount += abs(n);
    });
    /*for (auto i = 0; i<larger; ++i) {
        if (i < sizeA) 
            ++mapA[a[i]];
        if (i < sizeB)
            ++mapB[b[i]];
    }
    
    for (char i = 'a'; i<='z'; ++i) {
        if (mapA.count(i)>0 && mapB.count(i)>0) 
            delCount += abs(mapA[i] - mapB[i]);
        else if (mapA.count(i) == 0 && mapB.count(i) > 0)
            delCount += mapB.count(i);
        else if (mapB.count(i) == 0 && mapA.count(i) > 0)
            delCount += mapA.count(i);
    }*/
    return delCount;
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
