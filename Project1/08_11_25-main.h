#pragma once

#include "RailwaySystem.h"
#include "Menu.h"

namespace hw08_11_25 {

    void main() {
        RailwaySystem rs;

        while (true) {
            int choiceAsc = Menu::select_vertical({ "Ввести данные", "Показать все поезда", "Поиск поезда", "Выход" }, Left);

            switch (choiceAsc) {
                case 0: { 
                    Train train; cin >> train; rs.addTrain(train); 
                    cout << "Train has been successfully added!" << endl; 
                    cout << "Press Enter..."; cin.get(); system("cls"); break; 
                }
                case 1: { rs.showAll(); cout << "Press Enter..."; cin.get(); system("cls"); break; }
                case 2: {
                    int searchByWhat = Menu::select_vertical({ "За номером", "За остановкой" }, Left);

                    switch (searchByWhat) {
                        case 0: { 
                            int num; cout << "Номер: "; cin >> num; cin.ignore();
                            const Train* tr = rs.searchTrainByNumber(num); 
                            if (tr) cout << *tr;
                            else cout << "Не найдено." << endl;
                            cout << "Press Enter..."; cin.get(); system("cls"); break; 
                        }
                        case 1: { 
                            String station; cout << "Станция: "; cin >> station;
                            const Train* tr =  rs.searchTrainByStation(station);
                            if (tr) cout << *tr;
                            else cout << "Не найдено." << endl;
                            cout << "Press Enter..."; cin.get(); system("cls"); break;
                        }
                    }
                    break;
                }
                case 3: { cout << "Выход"; return; }
            }
        }
    }

}