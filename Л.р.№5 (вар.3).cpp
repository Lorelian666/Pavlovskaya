
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

struct STUDENT {
	std::string FIO;
	int group;
	int marks[5];
};

STUDENT Copy(STUDENT st) {
	STUDENT newSt;
	newSt.FIO = st.FIO;
	for (int i = 0; i < 5; i++) {
		newSt.marks[i] = st.marks[i];
	}
	newSt.group = st.group;
	return newSt;
}

void Input(STUDENT &st) {
	std::cout << "Введите ФИО: ";
	std::cin >> st.FIO;
	std::cout << "Введите номер группы: ";
	std::cin >> st.group;
	std::cout << "Введите оценку:\n";
	for (int i = 0; i < 5; i++) {
		std::cout << "\tВведите " << i + 1 << " оценку: ";
		std::cin >> st.marks[i];
	}
}

void Output(STUDENT &st) {
	std::cout << "Студент " << st.FIO << ", " << st.group << ",";
	for (int j = 0; j < 5; j++) {
		std::cout << st.marks[j] << " ";
	}
	std::cout << std::endl;
}

void Sort(STUDENT studs[], int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			if (studs[i].FIO.compare(studs[j].FIO) > 0) {
				STUDENT buf = Copy(studs[i]);
				studs[i] = studs[j];
				studs[j] = buf;
			}
		}
	}
}


bool Bad(STUDENT st) {
	for (int i = 0; i < 5; i++)
		if (st.marks[i] == 2)
			return true;
	return false;
}


int _tmain(int argc, _TCHAR* argv[])
{
	const int len = 4;
	STUDENT students[len];
	for (int i = 0; i < len; i++) {
		Input(students[i]);
	}

	std::cout << "Студенты:" << std::endl;
	for (int i = 0; i < len; i++) {
		Output(students[i]);
	}

	Sort(students, len);

	std::cout << "Студенты после сортировки :" << std::endl;

	for (int i = 0; i < len; i++) {
		Output(students[i]);
	}

	int badCount = 0;
	std::cout << "Плохие студенты: \n";
	for (int i = 0; i < len; i++) {
		if (Bad(students[i])) {
			Output(students[i]);
			badCount++;
		}
	}

	if (badCount == 0) {
		std::cout << "не найдено\n";
	}
	system("pause");

	return 0;
}
