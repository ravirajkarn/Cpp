#ifndef BUBBLE_SORT_HPP
#define BUBBLE_SORT_HPP

#include <vector>

class BUBBLE_SORT
{
private:
    std::vector<int> ordered_data;

public:
    BUBBLE_SORT(std::vector<int> &data);
    ~BUBBLE_SORT();
};

BUBBLE_SORT::BUBBLE_SORT(std::vector<int> &data)
{
    bool isSorted = true;
    int size = data.size();

    while (isSorted)
    {
        isSorted = false;
        for (int i = 0; i < size - 1; i++)
        {
            if (data[i] > data[i + 1])
            {
                std::swap(data[i], data[i + 1]);
                isSorted = true;
            }
        }
    }
}

BUBBLE_SORT::~BUBBLE_SORT()
{
}

#endif // BUBBLE_SORT_HPP