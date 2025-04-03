#include <iostream>
#include <string>

std::string *findRest(std::string *list1, int list1Size,
                      std::string *list2, int list2Size,
                      int *returnSize)
{
    int maxPossible = list1Size < list2Size ? list1Size : list2Size;
    std::string *result = new std::string[maxPossible];
    int resultIndex = 0;
    int maxVal = 2147483647;
    for (int i = 0; i < list1Size; ++i)
    {
        for (int j = 0; j < list2Size; ++j)
        {
            if (list1[i] == list2[j])
            {
                int curSum = i + j;
                if (curSum < maxVal)
                {
                    maxVal = curSum;
                    resultIndex = 0;
                    result[resultIndex++] = list1[i];
                }
                else if (curSum == maxVal)
                {
                    result[resultIndex++] = list1[i];
                }
            }
        }
    }
    *returnSize = resultIndex;
    return result;
}

void printResults(std::string *result, int size)
{
    std::cout << "[";
    for (int i = 0; i < size; ++i)
    {
        std::cout << "\"" << result[i] << "\"";
        if (i < size - 1)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

int main()
{

    std::string list1[] = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    std::string list2[] = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
    int size1 = 4, size2 = 4;
    int returnSize;
    std::string *result = findRest(list1, size1, list2, size2, &returnSize);
    std::cout << "Example 1 Output: ";
    printResults(result, returnSize);
    delete[] result;
    std::string list3[] = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    std::string list4[] = {"KFC", "Shogun", "Burger King"};
    int size3 = 4, size4 = 3;
    result = findRest(list3, size3, list4, size4, &returnSize);
    std::cout << "Example 2 Output: ";
    printResults(result, returnSize);
    delete[] result;
    return 0;
}