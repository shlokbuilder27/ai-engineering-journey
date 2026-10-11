#include <iostream>

int main()
{
    int arr[5] = {10, 3, 6, 8, 2};
    int max_drop = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = i + 1; j < 6; j++)
        {
            int current_drop = arr[i] - arr[j];
            if (current_drop > max_drop)
            {
                max_drop = current_drop;
            }
        }
    }
    std::cout << "The biggest drop is: " << max_drop << std::endl;
    return 0;
}