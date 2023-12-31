// postage_stamp.cpp --- A C++ program for the stamp folding problem
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>

typedef std::vector<size_t> stamps_t;
typedef std::pair<size_t, size_t> edge_t;

bool is_crossing(const stamps_t& stamps)
{
    assert(stamps.size() > 0);

    for (size_t i = 1; i < stamps.size() - 1; i += 2)
    {
        for (size_t j = i + 2; j < stamps.size() - 1; j += 2)
        {
            edge_t x1 = { i, i + 1 };
            edge_t x2 = { j, j + 1 };
            size_t m1 = std::min(stamps[x1.first], stamps[x1.second]);
            size_t m2 = std::min(stamps[x2.first], stamps[x2.second]);
            size_t m3 = std::max(stamps[x1.first], stamps[x1.second]);
            size_t m4 = std::max(stamps[x2.first], stamps[x2.second]);
            if (m1 < m2 && m2 < m3 && m3 < m4)
                return true;
            size_t m5 = std::min(stamps[x2.first], stamps[x2.second]);
            size_t m6 = std::min(stamps[x1.first], stamps[x1.second]);
            size_t m7 = std::max(stamps[x2.first], stamps[x2.second]);
            size_t m8 = std::max(stamps[x1.first], stamps[x1.second]);
            if (m5 < m6 && m6 < m7 && m7 < m8)
                return true;
        }
    }

    for (size_t i = 0; i < stamps.size() - 1; i += 2)
    {
        for (size_t j = i + 2; j < stamps.size() - 1; j += 2)
        {
            edge_t x1 = { i, i + 1 };
            edge_t x2 = { j, j + 1 };
            size_t m1 = std::min(stamps[x1.first], stamps[x1.second]);
            size_t m2 = std::min(stamps[x2.first], stamps[x2.second]);
            size_t m3 = std::max(stamps[x1.first], stamps[x1.second]);
            size_t m4 = std::max(stamps[x2.first], stamps[x2.second]);
            if (m1 < m2 && m2 < m3 && m3 < m4)
                return true;
            size_t m5 = std::min(stamps[x2.first], stamps[x2.second]);
            size_t m6 = std::min(stamps[x1.first], stamps[x1.second]);
            size_t m7 = std::max(stamps[x2.first], stamps[x2.second]);
            size_t m8 = std::max(stamps[x1.first], stamps[x1.second]);
            if (m5 < m6 && m6 < m7 && m7 < m8)
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
