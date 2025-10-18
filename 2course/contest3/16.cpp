#include <iostream>
#include <algorithm>

struct Log
{
    int ship_id;
    int run_id;
    int time_stamp;
    int event_type;
};

void print_log(Log log)
{
    std::cout << log.ship_id << " " << log.run_id << " " << log.time_stamp << " " << log.event_type << std::endl;
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
    Log logs[10000];
    for (int i = 0; i < n_logs; ++i)
    {
        std::cin >> logs[i].ship_id;
        std::cin >> logs[i].run_id;
        std::cin >> logs[i].time_stamp;
        std::cin >> logs[i].event_type;
    }

    // print_all_logs(logs, n_logs);
    // std::cout << "------------------" << std::endl;
    int ship_id;
    std::cin >> ship_id;
    int idx = 0;
    for (int i = 0; i < n_logs; ++i)
    {
        if (logs[i].ship_id == ship_id)
        {
            logs[idx] = logs[i];
            idx++;
        }
    }
    int size = idx;
    // print_all_logs(logs, size);
    std::sort(logs, logs + size, [](const Log &log1, const Log &log2)
              { return log1.time_stamp < log2.time_stamp; });
    // print_all_logs(logs, size);

    int block_size = 4;
    int n_blocks = size / block_size;
    int residual = size % block_size;

    for (int i = 0; i < n_blocks; ++i)
    {
        int run_id = logs[i * block_size + 0].run_id;
        if (!(logs[i * block_size + 1].run_id == run_id &&
              logs[i * block_size + 2].run_id == run_id &&
              logs[i * block_size + 3].run_id == run_id))
        {
            std::cout << "NO" << std::endl;
            return 0;
        }
        if (!(logs[i * block_size + 0].event_type == 0 &&
              logs[i * block_size + 1].event_type == 1 &&
              logs[i * block_size + 2].event_type == 2 &&
              logs[i * block_size + 3].event_type == 3))
        {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }
    int cnt = 0;
    int run_id = 0;
    if (residual > 0)
    {
        run_id = logs[n_blocks * 4].run_id;
    }
    for (int i = n_blocks * 4; i < size; ++i)
    {
        if (logs[i].event_type != cnt || logs[i].run_id != run_id)
        {
            std::cout << "NO" << std::endl;
            return 0;
        }
        cnt++;
    }
    std::cout << "YES" << std::endl;
}