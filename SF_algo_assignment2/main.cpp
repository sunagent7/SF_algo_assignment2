#include<iostream>
#include "quickSort.h"

using namespace std;

#define DATASIZE 10000
#define FILENAME "QuickSort.txt"

int main()
{
	FILE *fp;
	char *filename = FILENAME;
	int i;
	int data[DATASIZE];

	fopen_s(&fp, filename, "rt");

	for (i = 0; i < DATASIZE; i++)
	{
		fscanf_s(fp, "%d", &data[i]);
	}
	fclose(fp);

	quickSort(data, 0, DATASIZE-1);

	/*for (i = 0; i < DATASIZE; i++)
	{
		cout << data[i] << "\n";
	}*/

	system("pause");
	return 0;
}