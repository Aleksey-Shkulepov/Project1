#pragma once

#include "Printer.h";

namespace hw04_10_25
{
    void main() {
        Printer printer;

        printer.add_job({ "����", "�������_������.docx", 10 }, 3);
        printer.add_job({ "����", "����_1.png", 2 }, 1);
        printer.add_job({ "����", "���_2025.pdf", 5 }, 2);
        printer.add_job({ "����", "������.docx", 3 }, 4);

        printer.process_jobs();
        printer.show_stats();
    }
}