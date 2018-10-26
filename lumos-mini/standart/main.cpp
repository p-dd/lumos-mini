#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <ctime>
#include <array>
#include <iostream>
#include <string>

int partition(int *arr, int first, int last)
{
	int x = *(arr + last); //last
	int i = first - 1; // index of smaller elem
	int tmp;
	for (int j = first; j < last; j++)
	{
		if (*(arr + j) <= x)
		{
			i++;
			//std::swap(arr[i], arr[j]);
			tmp = *(arr + i);
			*(arr + i) = *(arr + j);
			*(arr + j) = tmp;
		}
	}
	//std::swap(arr[i + 1], arr[last]);
	tmp = *(arr + last);
	*(arr + last) = *(arr + i + 1);
	*(arr + i + 1) = tmp;
	return i + 1;
}

void quicksort(int *a, int st, int fn)
{
	if (st < fn) {
		int q = partition(a, st, fn);
		quicksort(a, st, q - 1);
		quicksort(a, q + 1, fn);
	}
}

int main(int argc, char* argv[])
{
	int N;
	char const* file_in = argv[1];
	char const* file_out = argv[2];

	freopen(file_in, "rb", stdin);
	freopen(file_out, "wb", stdout);

	fread(&N, sizeof(N), 1, stdin);

	int* data = new int[5];

	fread(data, sizeof(*data), N, stdin);

	std::string s1 = "", s2 = "";
	for (int i = 0; i < N; ++i)
	{
		s1 += std::to_string(data[i]) + " ";
	}

	clock_t start, end;

	start = clock();

	quicksort(data, 0, N-1);

	end = clock();
	for (int i = 0; i < N; ++i)
	{
		s2 += std::to_string(data[i]) + " ";
	}
	double time = (double)((end - start) / CLOCKS_PER_SEC);

	fwrite(&time, sizeof(time), 1, stdout);
	fwrite(data, sizeof(*data), N, stdout);

	return 0;
}