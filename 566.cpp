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

    int *reshaped = new int[r * c];
    int *origPtr = matr;
    int *reshPtr = reshaped;
    for (int i = 0; i < m * n; ++i)
    {
        *(reshPtr++) = *(origPtr++);
    }
    return reshaped;
}

void validateEnter(int &a, int &b)
{
    a = b = 0;
    while ((a <= 0) || (b <= 0))
    {
        std::cout << "enter the correct number of rows and columns for the matrix: ";
        std::cin >> a >> b;
    }
}

int main()
{
    int m{0}, n{0}, r{0}, c{0};
    std::srand(std::time(0));
    validateEnter(m, n);

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

    do
    {
        validateEnter(r, c);
    } while (r * c != m * n);

    int *reshaped = reshapeMatrix(matr, m, n, r, c);
    std::cout << "Reshaped matrix:" << std::endl;
    matrixOut(reshaped, r, c);

    delete[] matr;
    delete[] reshaped;

    return 0;
}
