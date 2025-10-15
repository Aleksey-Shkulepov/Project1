#pragma once

#include "PrintServer.h"

namespace hw11_10_25
{
    void main() 
    {
		string fName[] = { "file1.doc", "file2.xls", "file3.txt", "file4.pdf", "file5.ppt" };

		PrintServer ps("10.6.6.58");

		for (size_t i = 0; i < 20; i++)
		{
			if (i % 5 == 0)
			{
				ps.addTask(TaskPrint(fName[rand() % 5], rand() % 3 + 5, (DEPARTMENT)(rand() % 4)));
			}
			ps.work();
			Sleep(1000);
		}

		ps.showStats();
    }
}