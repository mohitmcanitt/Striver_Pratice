/*
https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findPlatform(vector<int>& arr, vector<int>& dep) {
    int n = arr.size();
    
    // Sort arrival and departure times
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    
    int platforms_needed = 1; // At least one platform is needed for the first train
    int result = 1; // Store the result for the maximum platforms needed
    
    int i = 1, j = 0; // Pointers for arrival and departure times
    
    // Traverse through all trains
    while (i < n && j < n) {
        // If next event is an arrival
        if (arr[i] <= dep[j]) {
            platforms_needed++;  // Increase platform count
            i++;  // Move to the next arrival
        }
        // If next event is a departure
        else {
            platforms_needed--;  // Decrease platform count
            j++;  // Move to the next departure
        }
        
        // Update the result if we need more platforms
        result = max(result, platforms_needed);
    }
    
    return result;
}

int main() {
    vector<int> arr = {646, 1812, 1953, 1859, 46, 1935, 1624, 617, 1645, 628};
    vector<int> dep = {805, 2200, 2106, 2333, 1554, 2047, 2020, 1900, 2048, 2351};
    
    cout << "Minimum platforms required: " << findPlatform(arr, dep) << endl;
    
    return 0;
}
