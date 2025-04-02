#include <iostream>
#include <ctime>

void matrixOut(int *matrix, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << *(matrix + i * cols + j) << " ";
        }
        std::cout << std::endl;
    }
}

int *reshapeMatrix(int *matr, int m, int n, int r, int c)
{
    if (m * n != r * c)
    {
        return matr;
    }
    int *reshaped = new int[r * c];
    int *origPtr = matr;
    int *reshPtr = reshaped;
    for (int i = 0; i < m * n; ++i)
    {
        *(reshPtr++) = *(origPtr++);
    }
    return reshaped;
}

int main()
{
    int m, n, r, c;
    std::srand(std::time(0));
    std::cout << "rows and columns for the original matrix: ";
    std::cin >> m >> n;
    int *matr = new int[m * n];
    std::cout << "Original matrix:" << std::endl;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            matr[i * n + j] = std::rand() % 100;
            std::cout << matr[i * n + j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "rows and columns for the reshaped matrix: ";
    std::cin >> r >> c;
    int *reshaped = reshapeMatrix(matr, m, n, r, c);
    std::cout << "Reshaped matrix:" << std::endl;
    matrixOut(reshaped, r, c);

    delete[] matr;
    delete[] reshaped;

    return 0;
}
