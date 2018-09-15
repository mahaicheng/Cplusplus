#include <iostream>
#include <algorithm>
#include <thread>

using namespace std;

template <typename Iterator, typename T>
struct accumulate_block
{
    void operator()(Iterator first, Iterator last, T &result)
    {
        result = std::accumulate(first, last, result);
    }
};

template <typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init)
{
    unsigned long const length = std::distance(first, last);
    if (!length) // 1
        return init;

    unsigned long const min_per_thread = 25;
    unsigned long const max_threads = (length + min_per_thread - 1) / min_per_thread; // 2
    unsigned long const hardware_threads = std::thread::hardware_concurrency();
    unsigned long const num_threads = std::min(hardware_threads != 0 ? hardware_threads : 2, max_threads); // 3
    unsigned long const block_size = length / num_threads;                                                 // 4
    std::vector<T> results(num_threads);
    std::vector<std::thread> threads(num_threads - 1); // 5

    Iterator block_start = first;
    for (unsigned long i = 0; i < (num_threads - 1); ++i)
    {
        Iterator block_end = block_start;
        std::advance(block_end, block_size); // 6
        threads[i] = std::thread(            // 7
            accumulate_block<Iterator, T>(), block_start, block_end, std::ref(results[i]));
        block_start = block_end; // 8
    }

    accumulate_block<Iterator, T>()(block_start, last, results[num_threads - 1]);   // 9
    std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join)); // 10

    return std::accumulate(results.begin(), results.end(), init); // 11
}

int main()
{
    vector<long> a(99999999);
    for (size_t i = 0; i < 99999999; ++i)
    {
        a[i] = i;
    }
    long result = 0;
    //cout << accumulate(a.cbegin(), a.cend(), result) << endl;
    cout << parallel_accumulate(a.cbegin(), a.cend(), result) << endl;
}
