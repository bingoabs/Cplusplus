#include <vector>
#include <iostream>

using namespace std;

void buble(vector<int> &input)
{
    for(int i = 0; i < input.size(); i++)
    {
        for(int j = input.size() - 1; j > i; j--)
        {
            if(input[j] < input[j-1])
            {
                int temp = input[j];
                input[j] = input[j-1];
                input[j-1] = temp;
            }
        }
    }
}

int main()
{
    vector<int> one = {1, 3, 2, 1, 5, 8, 2, 5};
    buble(one);
    for(auto i : one)
        cout << i << " ";
}