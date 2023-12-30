// postage_stamp.cpp --- A C++ program for the postage stamp problem of math
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>

typedef std::vector<size_t> stamps_t;
typedef std::pair<size_t, size_t> edge_t;

void print_stamps(const stamps_t& stamps)
{
    std::printf("stamps: ");
    for (size_t i = 0; i < stamps.size(); ++i)
    {
        if (i == 0)
            std::printf("%d", (int)stamps[i]);
        else
            std::printf(", %d", (int)stamps[i]);
    }
    std::printf("\n");
}

bool is_crossing(const stamps_t& stamps)
{
    assert(stamps.size() > 0);

    stamps_t inverse;
    inverse.resize(stamps.size());
    for (size_t i = 0; i < stamps.size(); ++i)
    {
        inverse[stamps[i]] = i;
    }

    std::vector<edge_t> left_side, right_side;
    for (size_t i = 0; i < stamps.size() - 1; ++i)
    {
        if (i % 2 == 1)
            left_side.push_back(edge_t(i, i + 1));
        else
            right_side.push_back(edge_t(i, i + 1));
    }

    for (size_t i = 0; i < left_side.size(); ++i)
    {
        for (size_t j = 0; j < left_side.size(); ++j)
        {
            if (i == j)
                continue;

            edge_t x1 = left_side[i], x2 = left_side[j];
            size_t m1 = std::min(inverse[x1.first], inverse[x1.second]);
            size_t m2 = std::min(inverse[x2.first], inverse[x2.second]);
            size_t m3 = std::max(inverse[x1.first], inverse[x1.second]);
            size_t m4 = std::max(inverse[x2.first], inverse[x2.second]);
            if (m1 < m2 && m2 < m3 && m3 < m4)
                return true;
        }
    }

    for (size_t i = 0; i < right_side.size(); ++i)
    {
        for (size_t j = 0; j < right_side.size(); ++j)
        {
            if (i == j)
                continue;

            edge_t x1 = right_side[i], x2 = right_side[j];
            size_t m1 = std::min(inverse[x1.first], inverse[x1.second]);
            size_t m2 = std::min(inverse[x2.first], inverse[x2.second]);
            size_t m3 = std::max(inverse[x1.first], inverse[x1.second]);
            size_t m4 = std::max(inverse[x2.first], inverse[x2.second]);
            if (m1 < m2 && m2 < m3 && m3 < m4)
                return true;
        }
    }

    return false;
}

size_t postal_stamp(size_t n)
{
    assert(n > 0);

    stamps_t stamps;
    for (size_t i = 0; i < n; ++i)
    {
        stamps.push_back(i);
    }

    size_t count = 0;
    do
    {
        if (stamps[0] != 0)
            continue;
        if (is_crossing(stamps))
            continue;
        ++count;
    } while (std::next_permutation(stamps.begin(), stamps.end()));
    return count;
}

int main(void)
{
    for (size_t i = 1; i <= 10; ++i)
    {
        size_t number = postal_stamp(i);
        std::printf("postal_stamp(%d) = %d\n", (int)i, (int)number);
    }
    return 0;
}
