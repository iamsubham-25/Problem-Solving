class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n + 1, 0);
        for (auto& b : bookings) {
            int first = b[0], last = b[1], seats = b[2];
            diff[first - 1] += seats;   // range starts here
            diff[last] -= seats;        // range ends just after 'last'
        }
        vector<int> answer(n);
        answer[0] = diff[0];
        for (int i = 1; i < n; i++) {
            answer[i] = answer[i - 1] + diff[i];   // prefix sum materializes the range updates
        }
        return answer;
    }
};