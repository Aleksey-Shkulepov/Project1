#pragma once

#include "mystd.h"
#include "fullstd.h"

#include "Client.h"
#include "PrintStat.h"

namespace hw04_10_25
{
    class Printer {
        PriorityQueue<Client, int> printQueue;
        Queue<PrintStat> printLog;

        String current_time() {
            time_t now = time(0);
            char buffer[26];
            ctime_s(buffer, sizeof(buffer), &now);
            return String(buffer);
        }

    public:
        void add_job(const Client& client, int priority) {
            printQueue.enqueue(client, priority);
        }

        void process_jobs() {
            while (!printQueue.isEmpty()) {
                Client* client = printQueue.front();
                cout << "Друкується: " << *client << endl;

                Sleep(2000);

                PrintStat stat{ client->name, client->document, current_time() };
                printLog.enqueue(stat);

                printQueue.dequeue();
            }
        }

        void show_stats() {
            printLog.print();
        }
    };
}
