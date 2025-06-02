#include <iostream>
#include <string>
#include <vector>
using namespace std;

class prac {
public:
    /// @brief 
    /// @param s 
    /// @return 
    bool checkValidString(string s) {
        int minOpen = 0; // Minimum possible unmatched '('
        int maxOpen = 0; // Maximum possible unmatched '('
        
        for (char c : s) {
            if (c == '(') {
                minOpen++; // '(' always increases minOpen
                maxOpen++; // '(' always increases maxOpen
            } else if (c == ')') {
                minOpen--; // ')' decreases minOpen
                maxOpen--; // ')' decreases maxOpen
            } else { // c == '*'
                minOpen = max(0, minOpen - 1); // Treat '*' as ')' or empty
                maxOpen++; // Treat '*' as '('
            }           
            // If maxOpen becomes negative, there's an unmatched ')'
            if (maxOpen < 0) {
                return false;
            }
        }        
        // For the string to be valid, minOpen must be 0 (all '(' matched)
        return minOpen == 0;
    }
};

int main() {
    prac solution;
    string s1 = "()";
        bool result = solution.checkValidString(s1);
        cout << "Input: \"" << s1 << "\", Output: " 
                  << (result ? "Valid" : "Invalid") << "\n";
    return 0;
}
