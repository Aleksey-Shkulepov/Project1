#pragma once

#include "mystd.h"
namespace hw22_10_25 {

    class DAI {
    private:
        BTree<String, List<String>> base;

        static void printRecord(const String& plate, const List<String>& violations) {
            cout << "Машина: " << plate << endl;
            for (auto& v : violations)
                cout << "  - " << v << endl;
        }

    public:
        void addFine(const String& plate, const String& fine) {
            List<String>* existing = base.getValue(plate);
            if (existing) {
                existing->push_back(fine);
            }
            else {
                List<String> list;
                list.push_back(fine);
                base.push(plate, list);
            }
        }

        void printAll() {
            base.traverseInOrder(printRecord);
        }

        void printByPlate(const String& plate) {
            List<String>* fines = base.getValue(plate);
            if (!fines) {
                cout << "Не найдено" << endl;
                return;
            }
            printRecord(plate, *fines);
        }

        void printByRange(const String& from, const String& to) {
            base.traverseRange(from, to, printRecord);
        }
    };

}