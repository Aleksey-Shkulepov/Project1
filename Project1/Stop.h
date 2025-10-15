#pragma once

#include "mystd.h"
#include "fullstd.h"

#include "Random.h"

#include "Passenger.h"
#include "Minibus.h"
#include "StopType.h"

using namespace RandomUtils;

namespace hw08_10_25
{
    class Stop
    {
        // Ms - милисекунды

        size_t durationMs;
        size_t passengerIntervalMs;
        size_t minibusIntervalMs;
        size_t maxPeopleAtStop;
        StopType stopType;

        Queue<Passenger> queue;

        size_t totalWaitTimeMs = 0;
        size_t servedPassengers = 0;
        size_t maxQueueSize = 0;

    public:
        /// Ms - милисекунды
        Stop(
            size_t durationMs,
            size_t passengerIntervalMs,
            size_t minibusIntervalMs,
            size_t maxPeopleAtStop,
            StopType stopType
        ) :
            durationMs(durationMs),
            passengerIntervalMs(passengerIntervalMs),
            minibusIntervalMs(minibusIntervalMs),
            maxPeopleAtStop(maxPeopleAtStop),
            stopType(stopType)
        {
        }

        void run() {
            size_t currentTimeMs = 0;
            size_t nextPassengerTimeMs = Random::get(passengerIntervalMs / 2, passengerIntervalMs * 2);
            size_t nextMinibusTimeMs = Random::get(minibusIntervalMs / 2, minibusIntervalMs * 2);
            size_t nextEventTime;

            while (true) {
                if (nextPassengerTimeMs < nextMinibusTimeMs)
                    nextEventTime = nextPassengerTimeMs;
                else 
                    nextEventTime = nextMinibusTimeMs;
                
                if (nextEventTime >= durationMs) break;

                currentTimeMs = nextEventTime;

                if (currentTimeMs == nextPassengerTimeMs) {
                    queue.enqueue(Passenger(currentTimeMs));

                    size_t q_size = queue.get_size();
                    if (q_size > maxQueueSize) maxQueueSize = q_size;

                    size_t delta = Random::get(passengerIntervalMs / 2, passengerIntervalMs * 2);
                    nextPassengerTimeMs = currentTimeMs + delta;
                }

                if (currentTimeMs == nextMinibusTimeMs) {
                    size_t freeSeats = Random::get(1, 15);

                    while (!queue.isEmpty() && freeSeats > 0) {
                        Passenger* p = queue.front();
                        if (p != nullptr) {
                            totalWaitTimeMs += (currentTimeMs - p->arrivalTimeMs);
                            servedPassengers++;
                        }
                        queue.dequeue();
                        freeSeats--;
                    }

                    size_t qsize = queue.get_size();
                    if (qsize > maxQueueSize) maxQueueSize = qsize;

                    size_t delta = Random::get(minibusIntervalMs / 2, minibusIntervalMs * 2);
                    nextMinibusTimeMs = currentTimeMs + delta;
                }
            }
        }

        void printResult() const {
            cout << "Время: " << (durationMs / 1000) << " секунд" << endl;
            cout << "общее кол-во пассажиров: " << servedPassengers << endl;
            cout << "Макс кол-во людей на остановке: " << maxQueueSize << endl;
            double avgWaitSeconds = (totalWaitTimeMs / 1000.0) / servedPassengers;
            cout << "Сред время ожидания маршруточки: " << avgWaitSeconds << " секунд" << endl;
            cout << "Макс кол-во пассажиров на остановке(" << maxQueueSize << "/" << maxPeopleAtStop << ")" << endl;
        }
    };
}