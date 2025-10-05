#pragma once

#include "Printer.h";

namespace hw04_10_25
{
    void main() {
        Printer printer;

        printer.add_job({ "Іван", "Курсова_робота.docx", 10 }, 3);
        printer.add_job({ "Олег", "Фото_1.png", 2 }, 1);
        printer.add_job({ "Марія", "Звіт_2025.pdf", 5 }, 2);
        printer.add_job({ "Анна", "Резюме.docx", 3 }, 4);

        printer.process_jobs();
        printer.show_stats();
    }
}