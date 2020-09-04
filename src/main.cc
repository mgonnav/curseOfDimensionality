#include <chrono>
#include <iostream>
#include <math.h>
#include <vector>

int calculateEuclideanDist(std::vector<int> a, std::vector<int> b)
{
  auto squareSum = 0LL;
  for (size_t i = 0; i < a.size(); i++)
    squareSum += (a[i] - b[i]) ^ 2;
  return sqrt(squareSum);
}

int main()
{
  srand(time(0));

  int tests;
  std::cin >> tests;
  while (tests-- > 0)
  {
    int totalData, dimensions;
    std::cin >> totalData >> dimensions;

    std::vector<std::vector<int>> data(totalData);
    for (auto& val : data)
    {
      val.resize(dimensions);
      for (auto& x : val)
        x = rand() % 32767;
    }

    auto startTime = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < totalData; i++)
      for (int j = i + 1; j < totalData; j++)
        calculateEuclideanDist(data[i], data[j]);
    auto endTime = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(
                        endTime - startTime)
                        .count();
    std::cout << "Time taken for " << totalData << " values with " << dimensions
              << " dimensions: " << duration << "ms.\n";
  }

  return 0;
}
