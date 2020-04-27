#include <vector>
#include <iostream>

using namespace std;

// Both are sorted
int count(vector<int> &a, vector<int> &b)
{
    int left = a.size();
    int right = b.size();
    vector<int> result;
    int acc = 0;
    for(
        int lindex = 0, rindex = 0; 
        (lindex < a.size()) && (rindex < b.size()); 
        
    )
    {
        if(a[lindex] <= b[rindex])
        {
            result.push_back(a[lindex]);
            lindex++;
        }
        else
        {
            result.push_back(b[lindex]);
            rindex++;
            acc += a.size() - lindex;
            cout << a[lindex] << " ";
        }
    }
    cout << endl;
    return acc;
}

int main()
{
    vector<int> a = {2, 7, 9, 10};
    vector<int> b = {2, 3, 4};
    cout << count(a, b) << endl;
}