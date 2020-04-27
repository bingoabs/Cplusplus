#include <vector>
#include <random>
#include <iostream>

using namespace std;

bool check(int target, vector<int> &a)
{
    int mid, start, end;
    start = 0;
    end = a.size();
    mid = (start + end) / 2;
    while(mid < end)
    {
        if (a[mid] < target)
            start = mid;
        else if (a[mid] == target)
            return 1;
        else
            end = mid;
        mid = (start + end) /2;
    }
    return 0;
}

int main()
{
    int argX = 10;
    int length = 10;
    default_random_engine e;
    uniform_int_distribution<int> u(0, 1000);
    vector<int> nums, left;
    nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for(int index = 0; index < length ; index++)
    {
        left.push_back(argX - nums[index]);
    }
    // int temp;
    // for(int index = 0; index < length; index++)
    // {
    //     temp = u(e);
    //     nums.push_back(temp);
    //     left.push_back(argX - temp);
    // }
    for(auto i : nums)
        cout << i << " ";
    cout << endl;
    for(auto i : left)
        cout << i << " ";
    cout << endl;
    for(int index = 0; index < length; index++)
    {
        if(check(left[index], nums))
            cout << index << endl;
    }
}