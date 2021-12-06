
// https://leetcode.com/problems/reverse-integer/
// Link to the question in leetcode

/*** Question ***/

// 7. Reverse Integer


// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

// Example 1:

// Input: x = 123
// Output: 321

// Example 2:

// Input: x = -123
// Output: -321

// Example 3:

// Input: x = 120
// Output: 21

// Example 4:

// Input: x = 0
// Output: 0

 

// Constraints:

//     -231 <= x <= 231 - 1


/*** End of Question ***/




class Solution {
public:
    int reverse(int x) {
        
        int outputs = 0; //init

        if (x < 2147483647 && -2147483648 < x) {
            
            string output = "";
            int negative = 0; //init

            if (x < 0) {
                negative = 1;
                x *= -1; //turns negative num into postive, as I will concatenate the num into a string
            }
            else if (x == 0) {
                return 0;
            }

            while (x != 0) {
                int y = x % 10;
                output += to_string(y);

                //update x
                x /= 10;
            }

            
            try {
                = stoi(output);
            }
            catch(std :: out_of_range){
                return 0;
            }
            

            if (negative) {outputs *= -1;}

        }
        else {return 0;}
        
        return outputs;
    }
};