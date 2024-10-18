class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
    if (a > 0) pq.push({a, 'a'});
    if (b > 0) pq.push({b, 'b'});
    if (c > 0) pq.push({c, 'c'});
    
    string result = "";
    
    while (!pq.empty()) {
        // Take the character with the highest count
        auto [count1, char1] = pq.top(); pq.pop();
        
        // If the last two characters in the result are the same as char1, try the next one
        if (result.size() >= 2 && result[result.size() - 1] == char1 && result[result.size() - 2] == char1) {
            if (pq.empty()) break;  // No other characters left to choose
            
            auto [count2, char2] = pq.top(); pq.pop();
            
            // Add char2 to result
            result += char2;
            count2--;
            
            // Push char2 back to the heap if it still has remaining counts
            if (count2 > 0) pq.push({count2, char2});
            
            // Push char1 back as well to be used later
            pq.push({count1, char1});
        } else {
            // Add char1 to result if it's safe
            result += char1;
            count1--;
            
            // Push char1 back if it still has remaining counts
            if (count1 > 0) pq.push({count1, char1});
        }
    }
    
    return result;
        
    }
};