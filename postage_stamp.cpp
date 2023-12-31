// postage_stamp.cpp --- A C++ program for the stamp folding problem
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>
#include <numeric>

typedef std::vector<size_t> stamps_t;

bool is_crossing(const stamps_t& stamps)
{
    assert(stamps.size() > 0);

    const size_t n1 = stamps.size() - 1;
    for (size_t i = 0; i < n1; ++i)
    {
        for (size_t j = i + 2; j < n1; j += 2)
        {
            auto p1 = std::minmax(stamps[i], stamps[i + 1]);
            auto p2 = std::minmax(stamps[j], stamps[j + 1]);
            size_t m1 = p1.first, m2 = p2.first, m3 = p1.second, m4 = p2.second;
            if (m1 < m2 && m2 < m3 && m3 < m4)
                return true;
            if (m2 < m1 && m1 < m4 && m4 < m3)
                return true;
        }
    }

    return false;
}

size_t postal_stamp(size_t n)
{
    assert(n > 0);

    stamps_t stamps(n);
    std::iota(stamps.begin(), stamps.end(), 0);

    size_t count = 0;
    do
    {
        if (stamps[0] != 0)
            break;
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
