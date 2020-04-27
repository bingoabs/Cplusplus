#include <vector>
#include <tuple>
#include <iostream>

using namespace std;
using ThreeInts = tuple<int, int, int>;

ThreeInts find_max_crossing_subarray(vector<int> &a, int low, int mid, int high)
{
    int left_sum = INT_MIN;
    int sum = 0;
    int start = mid;
    for(int i = mid; i >= low; --i)
    {
        sum += a[i];
        if(sum > left_sum)
        {
            left_sum = sum;
            start = i;
        }
    }
    int right_sum = INT_MIN;
    sum = 0;
    int end = mid;
    for(int i = mid + 1; i <= high; ++i)
    {
        sum += a[i];
        if(sum > right_sum)
        {
            right_sum = sum;
            end = i;
        }
    }
    return ThreeInts(start, end, left_sum + right_sum);
}

ThreeInts find_maximum_subarray(vector<int> &a, int low, int high)
{
    if(low == high)
        return tuple<int, int, int>(low, high, a[low]);
    int mid = (low + high) / 2;
    ThreeInts lefts = find_maximum_subarray(a, low, mid);
    ThreeInts rights = find_maximum_subarray(a, mid + 1, high);
    ThreeInts mids = find_max_crossing_subarray(a, low, mid, high);
    int left_sum = get<2>(lefts);
    int mid_sum = get<2>(mids);
    int right_sum = get<2>(rights);
    if((left_sum >= mid_sum)&& (left_sum >= right_sum))
        return ThreeInts(get<0>(lefts), get<1>(lefts), left_sum);
    if((mid_sum >= left_sum) && (mid_sum >= right_sum))
        return ThreeInts(get<0>(mids), get<1>(mids), mid_sum);
    return ThreeInts(get<0>(rights), get<1>(rights), right_sum);
}

ThreeInts brute_one(vector<int> &a, int low, int high)
{
    //(result, start_index, end_index)
    ThreeInts result = ThreeInts(INT_MIN, 0, 0);
    for(int i = low; i <= high; ++i)
    {
        int sum = 0;
        for(int j = i; j <= high; ++j)
        {
            sum += a[j];
            if(sum > get<0>(result))
                result = ThreeInts(sum, i, j);
        }
    }
    if(get<0>(result) < 0)
        return ThreeInts(0, 0, 0);
    return result;
}

ThreeInts Linear(vector<int> &a, int low, int high)
{
    /*
    说明：
        数组：[a1, a2, a3, a4];
        result结果元组: {子序列代数和, 起点, 终点}
        sum最长子序列第一个元素至当前元素代数和
    过程：
        假定已经获取[a1, a2]序列的最长子序列， 则进一步向右扩展元素
        如果sum > 0, 则sum累加当前元素值，
            如果 更新后sum大于子序列代数和， 即当前元素大于0， 那么更新结果
            如果 更新后sum小于子序列代数和， 即当前元素小于0， 则仅更新了sum的值
        如果sum <= 0, 则重置sum与最长子序列的起点，
            如果重置后sum大于子序列代数和， 那么表明当前元素是更好的起点， 重置子序列
            如果充值后sum小于子序列代数和， 那么当前元素并非更好的起点， 那么抛弃重置sum值，继续
            检查下一个元素， 直至找到某个大于子序列代数和的元素，或者连续为正的一段子序列并且代数和大于
            原子序列的序列。
    */
   // init the signal with the first element
    ThreeInts result = ThreeInts(INT_MIN, 0, 0);
    int sum = INT_MIN;
    for(int index = low; index <= high; ++index)
    {
        int low = get<1>(result);
        int high = index;
        if(sum > 0)
            sum += sum + a[index];
        else 
        {
            low = index;
            sum = a[index];
        }
        if (sum > get<0>(result))
            result = ThreeInts(sum, low, high);
    }
    return result;
}

int main()
{
    vector<int> a = {-10, -3, -1, -4, -2};
    // ThreeInts resp = find_maximum_subarray(a, 0, 4);
    // ThreeInts brut = brute_one(a, 0, 4);
    // cout << get<0>(resp) << " " << get<1>(resp) << " " << get<2>(resp) << endl;
    // cout << get<0>(brut) << " " << get<1>(brut) << " " << get<2>(brut) << endl;
    ThreeInts li = Linear(a, 0, 4);
    cout << get<0>(li) << " " << get<1>(li) << " " << get<2>(li) << endl;
}