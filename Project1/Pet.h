#pragma once

#include "fullstd.h"
#include "mystd.h"

namespace hw25_10_25 {

    class Pet {
    protected:
        String name;
    public:
        Pet(const String& name)
            : name(name) {}

        virtual void showInfo() const = 0;
        virtual ~Pet() = default;
    };

    class Dog : public Pet {
        String species; //Порода, вид
    public:
        Dog(const String& name, const String& species)
            : Pet(name), species(species) {}

        void showInfo() const override {
            cout 
                << "Собака"   << endl
                << "Имя: "    << name << endl
                << "Порода: " << species << endl;
        }
    };

    class Cat : public Pet {
        String color;
    public:
        Cat(const String& name, const String& color)
            : Pet(name), color(color) {}

        void showInfo() const override {
            cout
                << "Кошка"  << endl
                << "Имя: "  << name << endl
                << "Цвет: " << color << endl;
        }
    };

    class Parrot : public Pet {
        bool canSpeak;
    public:
        Parrot(const String& name, bool canSpeak)
            : Pet(name), canSpeak(canSpeak) {
        }

        void showInfo() const override {
            cout
                << "Попугай" << endl
                << "Имя: " << name << endl
                << "Умеет говорить: " << canSpeak << endl;
        }
    };

}