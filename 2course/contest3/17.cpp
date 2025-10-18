#include <iostream>

struct Log
{
    int id;
    float neural_activity;
};

void print_log(Log log)
{
    std::cout << log.id << " " << log.neural_activity << std::endl;
}

void print_all_logs(Log *logs, int size)
{
    for (int i = 0; i < size; ++i)
    {
        print_log(logs[i]);
    }
}
int main()
{
    int n_logs;
    std::cin >> n_logs;

    Log logs[1000];
    float dummy_float;
    int dummy_int;
    for (int i = 0; i < n_logs; ++i)
    {
        std::cin >> dummy_int; // time_stamp
        std::cin >> logs[i].id;
        std::cin >> dummy_float;
        std::cin >> dummy_float;
        std::cin >> dummy_float;
        std::cin >> logs[i].neural_activity;
        std::cin >> dummy_float;
    }
    print_all_logs(logs, n_logs);
}