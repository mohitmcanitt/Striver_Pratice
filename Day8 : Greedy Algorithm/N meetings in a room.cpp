/*
https://takeuforward.org/data-structure/n-meetings-in-one-room/
1. Sort by start time
2. Keep track of prev meeting end time
3. If current meetings starts after end time of prev meeting, consider this meetings and update prev_meeting_end_time
  
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxNonOverlappingMeetings(vector<int>& startTimes, vector<int>& endTimes) {
    int n = startTimes.size();
    vector<int> meetingIndices(n);
    
    // Assign meeting indices from 0 to n-1
    for (int i = 0; i < n; i++) {
        meetingIndices[i] = i;
    }

    // Sort meeting indices based on their corresponding end times
    sort(meetingIndices.begin(), meetingIndices.end(), [&](int i, int j) {
        return endTimes[i] < endTimes[j];
    });

    int meetingCount = 0;
    int lastMeetingEndTime = -1;  // Initial invalid time to ensure first meeting is selected

    // Traverse through the meetings and select non-overlapping ones
    for (int i = 0; i < n; i++) {
        int currentMeetingStartTime = startTimes[meetingIndices[i]];
        int currentMeetingEndTime = endTimes[meetingIndices[i]];

        // Select the meeting if it starts after the last selected meeting ends
        if (currentMeetingStartTime > lastMeetingEndTime) {
            meetingCount++;
            lastMeetingEndTime = currentMeetingEndTime;
        }
    }

    return meetingCount;
}

int main() {
    vector<int> startTimes{1, 3, 0, 5, 8, 5};
    vector<int> endTimes{2, 4, 6, 7, 9, 9};

    cout << maxNonOverlappingMeetings(startTimes, endTimes) << endl;
    return 0;
}
