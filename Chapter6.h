
int fact(int val);

int odd[] = {1, 2, 4, 5, 7};
int oddNew[] = {1, 2, 4, 5, 7, 8};

decltype(odd) *arrPtr(int i)
{
    return &odd; // can't return &oddNew;
}
