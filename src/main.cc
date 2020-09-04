#include <chrono>
#include <iostream>
#include <math.h>
#include <vector>

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

    double dist{};
    auto startTime = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < totalData; i++)
      for (int j = 0; j < totalData; j++)
      {
        dist = 0;
        for (int k = 0; k < dimensions; k++)
        {
          long long tmp = data[i][k] - data[j][k];
          dist += tmp * tmp;
        }
        dist = sqrt(dist);
      }
    auto endTime = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(
                        endTime - startTime)
                        .count();
    std::cout << "Time taken for " << totalData << " values with " << dimensions
              << " dimensions: " << duration << "ms.\n";
  }

  return 0;
}
