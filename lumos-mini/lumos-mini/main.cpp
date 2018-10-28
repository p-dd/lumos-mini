#define _CRT_SECURE_NO_DEPRECATE
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::cout << "::Testing system lumos-mini::" << std::endl;
	std::cout << "1.Main menu\n2.Compile solution\n3.Generate tests\n4.Run tests\n5.Exit\n";
	while (1)
	{
		int task;
		std::cout << ">";
		std::cin >> task;
		switch (task)
		{
		case 1:
			{
				std::cout << "1.Main menu\n2.Compile solution\n3.Generate tests\n4.Run tests\n5.Exit\n";
				break;
			}
		case 2:
			{
				system(R"(g++ E:\SoftGrader\lumos-mini\lumos-mini\task_for_testing_system\sol.cpp E:\SoftGrader\lumos-mini\lumos-mini\task_for_testing_system\before_code.cpp -o E:\SoftGrader\lumos-mini\lumos-mini\simple_testing_system\sol.exe)");
				if (freopen(R"(E:\SoftGrader\lumos-mini\lumos-mini\simple_testing_system\sol.exe)", "r", stderr))
				{
					std::cout << "sol.exe created!" << std::endl;
					fclose(stderr);
				}
				else
				{
					std::cout << "error! sol.exe don`t created!" << std::endl;
				}
				break;
			}
		case 3:
			{
				int rep1, rep2;
				for (int i = 0; i < 5; ++i)
				{
					std::string str = "E:\\SoftGrader\\lumos-mini\\lumos-mini\\simple_testing_system\\testGen E:\\SoftGrader\\lumos-mini\\lumos-mini\\tests\\";
					str += std::to_string(i + 1);
					char *cstr = new char[str.length() + 1];
					strcpy(cstr, str.c_str());
					rep1 = system(cstr);
					delete[] cstr;

					str = "E:\\SoftGrader\\lumos-mini\\lumos-mini\\simple_testing_system\\standart E:\\SoftGrader\\lumos-mini\\lumos-mini\\tests\\";
					str += std::to_string(i + 1) + " ";
					str += "E:\\SoftGrader\\lumos-mini\\lumos-mini\\tests\\";
					str += std::to_string(i + 1) + ".ans";
					cstr = new char[str.length() + 1];
					strcpy(cstr, str.c_str());
					rep2 = system(cstr);
					delete[] cstr;
				}
				if (!rep1 && !rep2)
				{
					std::cout << "tests ready to use!" << std::endl;
				}
				else
				{
					std::cout << "fail! try again :(" << std::endl;
				}

				break;
			}
		case 4:
			{
				for (int i = 0; i < 5; ++i)
				{
					std::string str = "E:\\SoftGrader\\lumos-mini\\lumos-mini\\simple_testing_system\\sol E:\\SoftGrader\\lumos-mini\\lumos-mini\\tests\\";
					str += std::to_string(i + 1) + " ";
					str += "E:\\SoftGrader\\lumos-mini\\lumos-mini\\ans_user\\";
					str += std::to_string(i + 1) + ".out";
					char *cstr = new char[str.length() + 1];
					strcpy(cstr, str.c_str());
					system(cstr);
					delete[] cstr;
					str = "E:\\SoftGrader\\lumos-mini\\lumos-mini\\simple_testing_system\\cheker E:\\SoftGrader\\lumos-mini\\lumos-mini\\tests\\";
					str += std::to_string(i + 1) + " ";
					str += "E:\\SoftGrader\\lumos-mini\\lumos-mini\\ans_user\\";
					str += std::to_string(i + 1) + ".out E:\\SoftGrader\\lumos-mini\\lumos-mini\\result.txt E:\\SoftGrader\\lumos-mini\\lumos-mini\\tests\\";
					str += std::to_string(i + 1) + ".ans";
					cstr = new char[str.length() + 1];
					strcpy(cstr, str.c_str());
					system(cstr);
				}
				break;
			}
		case 5:
			{
				return 0;
			}
		default:
			{
				std::cout << "error input! try again :)" << std::endl;
				break;
			}
		}
	}
}
