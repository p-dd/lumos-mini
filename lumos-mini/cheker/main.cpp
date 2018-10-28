#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <cmath>
#include <string>
#include "result.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	const string way = string(argv[3]);
	result checker_result(way);
	// ��������� ���� ������� ������, ���� �������� ������ � ����� ���������
	FILE * bui = fopen(argv[1], "rb");
	FILE * buo = fopen(argv[2], "rb");
	FILE * bua = fopen(argv[4], "rb");

	int n;
	// ��������� ����������� ������
	fread(&n, sizeof(n), 1, bui);

	// �������� ������ ��� ������� ������ ���� � ������ ���������
	int * ans = new int[n], *res = new int[n], *input = new int[n];
	double ans_time, res_time;

	// ��������� ����� ������ ��������� ��������� � ������� ���������
	fread(&res_time, sizeof(res_time), 1, buo);
	fread(res, sizeof(*res), n, buo);

	fread(&ans_time, sizeof(ans_time), 1, bua);

	fread(ans, sizeof(*ans), n, bua);

	// ��������� ������, ��� ������� ����� �������� �������
	bool mistake = false;
	for(int i = 0; i < n; ++i)
	{
		if (ans[i] != res[i])
		{
			mistake = true;
			break;
		}
	}

	// ���������, ��� ������ ����, ����� ��������, ��� ������� ���������, ����� - �����������.
	if (!mistake)
	{
		checker_result.write_message("AC. Numbers are equal.");
		string tmp = string(argv[2]);
		const int size = tmp.length();
		std::cout << "test " << tmp[size - 5] << ": ";
		std::cout << "AC. Numbers are equal." << endl;
		//checker_result.write_verdict(verdict::AC);
	}
	else
	{
		checker_result.write_message("WA. Output is not correct.");
		string tmp = string(argv[2]);
		const int size = tmp.length();
		std::cout << "test " << tmp[size - 5] << ": ";
		std::cout << "WA. Output is not correct." << endl;
		//checker_result.write_verdict(verdict::WA);
	}

	fread(input, sizeof(*input), n, bui);

	string src = string(argv[2]);
	const int s = src.length();
	std::cout << "test " << src[s - 5] << ": input: ";
	for (int i = 0; i < n; ++i)
	{
		std::cout << input[i] << " ";
	}
	std::cout << " output: ";
	for (int i = 0; i < n; ++i)
	{
		std::cout << ans[i] << " ";
	}
	std::cout << "your output: ";
	for (int i = 0; i < n; ++i)
	{
		std::cout << res[i] << " ";
	}
	cout << endl << endl;
	// ���������� ����� � ���������� ����������� (��������� �� 100 �� = 10 ^ (-7) ���).
	//checker_result.write_time(res_time * 1e7);

	fclose(buo);

	return 0;
}