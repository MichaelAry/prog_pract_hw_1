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

void outResults(std::string *result, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << result[i];
        if (i < size - 1)
            std::cout << ", ";
    }
}

int main()
{
    std::string *list1, *list2;
    int size1, size2;

    std::cout << "enter the number of words for list1: ";
    std::cin >> size1;

    list1 = new std::string[size1];
    std::cout << "enter the names of the words for list1 (one per line):" << std::endl;
    for (int i = 0; i < size1; ++i)
    {
        std::cin >> list1[i];
    }

    std::cout << "enter the number of words for list2: ";
    std::cin >> size2;

    list2 = new std::string[size2];
    std::cout << "enter the names of the words for list2 (one per line):" << std::endl;
    for (int i = 0; i < size2; ++i)
    {
        std::cin >> list2[i];
    }

    int returnSize;
    std::string *result = findRest(list1, size1, list2, size2, &returnSize);
    std::cout << "output: ";
    outResults(result, returnSize);
    delete[] result;
    delete[] list1;
    delete[] list2;

    return 0;
}