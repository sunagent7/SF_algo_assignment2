#include<iostream>

void print(int a[], int l, int r)
{
	for (int j = l; j <= r; j++)
	{
	std::cout << a[j];
	}
	std::cout << "\n";
}

int median_of_three(int a[], int l, int r)
{
	int m = (r + l) / 2;
	if (a[l] < a[m] && a[m] < a[r])
		return m;
	else if (a[r] < a[m] && a[m] < a[l])
		return m;

	else if (a[r] < a[l] && a[l] < a[m])
		return l;
	else if (a[m] < a[l] && a[l] < a[r])
		return l;

	else if (a[m] < a[r] && a[r] < a[l])
		return r;
	else if (a[l] < a[r] && a[r] < a[m])
		return r;
}

void swap(int a[], int i, int j)
{
	int temp;
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

// get pivot from index n
int choosePivot(int a[], int l,int n)
{
	swap(a, l, n);
	return a[l];
}

void quickSort(int a[], int l, int r)
{
	static long long int count = 0;

	if (r - l < 1)
		return;

	count += r - l;

	std::cout << count << "\n";

	int pivot, i ,j;

	// question 3
	int m = median_of_three(a, l, r);
	// here we set the first element as pivot
	pivot = choosePivot(a, l, m);

	i = l + 1;
	for (j = l + 1; j <= r; j++)
	{
		if (a[j] < pivot)
		{
			swap(a, j, i);

			//print(a, l, r);

			i++;
		}
	}
	swap(a, l, i - 1);

	//print(a, l, r);

	//if (l < i-2)
		quickSort(a, l, i-2);
	//if (i < r)
		quickSort(a, i, r);
}