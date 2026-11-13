#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstdint>
#include <cstdio>
#include <limits>
#include <omp.h>

using namespace std;

/*
 콜라츠 추측을 이용한 컴퓨터 성능 테스터
 */

struct Result {
    uint64_t number;
    uint64_t steps;
};

uint64_t collatz(uint64_t n, unordered_map<uint64_t, uint64_t>& cache) {
    vector<uint64_t> path;

    uint64_t current = n;

    while (current != 1) {
        auto it = cache.find(current);

        if (it != cache.end()) {
            uint64_t steps = it->second;

            for (auto p = path.rbegin(); p != path.rend(); ++p) {
                cache[*p] = ++steps;
            }

            return cache[n];
        }

        path.push_back(current);

        if ((current & 1) == 0) {
            current >>= 1;
        } else {
            if (current > (numeric_limits<uint64_t>::max() - 1) / 3) {
                return 0;
            }

            current = current * 3 + 1;
        }
    }

    uint64_t steps = 0;

    for (auto p = path.rbegin(); p != path.rend(); ++p) {
        cache[*p] = ++steps;
    }

    return cache[n];
}

int main() {
    constexpr uint64_t BATCH_SIZE = 100000;

    vector<unordered_map<uint64_t, uint64_t>> caches(omp_get_max_threads());

    for (auto& cache : caches) {
        cache[1] = 0;
        cache.reserve(100000);
    }

    uint64_t current = 1;

    while (true) {
        uint64_t start = current;
        uint64_t end = start + BATCH_SIZE;

        if (end < start) {
            end = numeric_limits<uint64_t>::max();
        }

        uint64_t verified = 0;
        uint64_t overflows = 0;
        uint64_t maxSteps = 0;
        uint64_t maxNumber = 0;

        #pragma omp parallel for reduction(+:verified,overflows) reduction(max:maxSteps)
        for (uint64_t i = start; i < end; ++i) {
            int thread = omp_get_thread_num();

            uint64_t steps = collatz(i, caches[thread]);

            if (steps == 0 && i != 1) {
                ++overflows;
                continue;
            }

            ++verified;

            if (steps > maxSteps) {
                maxSteps = steps;
            }
        }

        printf(
            "\r[COLLATZ] Checked: %llu | Verified: %llu | Overflow: %llu | Max Steps: %llu",
            static_cast<unsigned long long>(end - 1),
            static_cast<unsigned long long>(verified),
            static_cast<unsigned long long>(overflows),
            static_cast<unsigned long long>(maxSteps)
        );

        fflush(stdout);

        if (end == numeric_limits<uint64_t>::max()) {
            break;
        }

        current = end;
    }

    return 0;
}