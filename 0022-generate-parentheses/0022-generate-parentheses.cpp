class Solution {
public:
    void parenth(int n, int left, int right, vector<string>& ans, string &temp) {
        // Base case: when the string reaches length 2 * n, we've formed a valid sequence
        if (temp.length() == 2 * n) {
            ans.push_back(temp);
            return;
        }

        // Add an opening bracket if we haven't used all n left brackets
        if (left < n) {
            temp.push_back('(');
            parenth(n, left + 1, right, ans, temp);
            temp.pop_back(); // backtrack
        }

        // Add a closing bracket if there are unmatched opening brackets
        if (right < left) {
            temp.push_back(')');
            parenth(n, left, right + 1, ans, temp);
            temp.pop_back(); // backtrack
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        parenth(n, 0, 0, ans, temp);
        return ans;
    }
};