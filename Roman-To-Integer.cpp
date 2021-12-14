
/* 
https://leetcode.com/problems/roman-to-integer/submissions/
*Links to the question in Leetcode*

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

    I can be placed before V (5) and X (10) to make 4 and 9. 
    X can be placed before L (50) and C (100) to make 40 and 90. 
    C can be placed before D (500) and M (1000) to make 400 and 900.

Given a roman numeral, convert it to an integer.

 

Example 1:

Input: s = "III"
Output: 3

Example 2:

Input: s = "IV"
Output: 4

Example 3:

Input: s = "IX"
Output: 9

Example 4:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

Example 5:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

 

Constraints:

    1 <= s.length <= 15
    s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
    It is guaranteed that s is a valid roman numeral in the range [1, 3999].

 */


#include<bits/stdc++.h>
using namespace std;

int romanToInt(string s) {
        long long output = 0;
        long long holder = 0;
        
        bool first = false; // used to determine whether we should check the previous roman in the string
        
        for (int i = 0; i < s.length(); i++) {
            
            
            switch (s[i]) {
                case 'I':
                     if (!first) {
                        first = true;
                    }                    
                    output += 1;
                    holder = 1 * 2;
                    break;
                    
                case 'V':
                    if (!first) {
                        first = true;
                        holder = 5 * 2;
                        output += 5;
                    }                    
                    else if (s[i-1] == 'I') {
                        output += 5;
                        output -= holder;
                    }
                    else {
                        output += 5;
                        holder = 5 * 2;
                    }                    
                    break;
                    
                case 'X':
                    if (!first) {
                        first = true;
                        holder = 10 * 2;
                        output += 10;
                    }            
                    else if (s[i-1] == 'I' || s[i-1] == 'V') {
                        output += 10;
                        output -= holder;
                    }
                    else {
                        output += 10;
                        holder = 10 * 2;
                    }
                    break;
                    
                case 'L':
                    if (!first) {
                        first = true;
                        holder = 50 * 2;
                        output += 50;
                        // no need check previous roman
                    }
                    else if (s[i-1] == 'I' || s[i-1] == 'V' || s[i-1] == 'X') {
                        output += 50;
                        output -= holder;
                    }
                    else {
                        output += 50;
                        holder = 50 * 2;
                    }
                    break;
                    
                case 'C':
                    if (!first) {
                        first = true;
                        holder = 100 * 2;
                        output += 100;
                    }                  
                    else if (s[i-1] == 'I' || s[i-1] == 'V' || s[i-1] == 'X' || s[i-1] == 'L') {
                        output += 100;
                        output -= holder;
                    }
                    else {
                        output += 100;
                        holder = 100 * 2;
                    }
                    break;
                    
                case 'D':
                    if (!first) {
                        first = true;
                        holder = 500 * 2;
                        output += 500;
                    }                   
                    else if (s[i-1] == 'I' || s[i-1] == 'V' || s[i-1] == 'X' || s[i-1] == 'L' || s[i-1] == 'C') {
                        output += 500;
                        output -= holder;
                    }
                    else {
                        output += 500;
                        holder = 500 *2;
                    }
                    break;
                    
                case 'M':
                    if (!first) {
                        first = true;
                        output += 1000;
                    } 
                    else if (s[i-1] == 'I' || s[i-1] == 'V' || s[i-1] == 'X' || s[i-1] == 'L' || s[i-1] == 'C' || s[i-1] == 'D') {
                        output += 1000;
                        output -= holder;
                    }
                    else {
                        output += 1000;
                    }
                    break;
            }            
        }
        return output;
    }



int main()
{
    string testcase1 = "MMD"; // equals to 2500, where M = 1000, D = 500
    cout <<"MMD -> " << romanToInt(testcase1) << endl;
    string testcase2 = "MCMXCIV"; // equals to 1994, where M = 1000, CM = 1000 - 100, XC = 100 - 10, IV = 5 - 1
    cout << "MCMXCIV -> " << romanToInt(testcase2) << endl;
    return 0;
}