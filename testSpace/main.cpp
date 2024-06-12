#include "hutils.h"

#include<vector>
#include <algorithm>

using namespace std;

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;

        sort(intervals.begin(), intervals.end(), [] (const auto& l, const auto& r) { return l[0] < r[0];});

        const size_t size = intervals.size();
        size_t i = 0;
        int lowest{};
        int highest{};

        while(i < size)
        {
            lowest = intervals[i][0];
            highest = intervals[i][1];
            int j = i+1;
            while(j < intervals.size() && highest >= intervals[j][0])
            {
                highest = highest > intervals[j][1] ? highest : intervals[j][1];
                j++;
            }
            merged.push_back(vector<int>{lowest, highest});
            i = j;
        }
        return merged;
        
    }

int main()
{
    vector<vector<int>> test{{2,3},{4,5},{6,7},{8,9},{1,10}};
    merge(test);
}

