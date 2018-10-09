#include<iostream>
#include<vector>
#include<algorithm>
int find(int *p,int begin,int end,int value)
{
	if (end == begin)
		return -1;
	int mid = (begin + end) / 2;
	if (p[mid] == value)
		return mid;
	else if(p[mid]<value)
		return find(p, begin, mid - 1, value);
	else
		return find(p, mid+1,end, value);
}
int compare(const void *a, const void *b)
{
	return (*(int*)a - *(int*)b);
}
int main()
{
	//std::vector<int> arr;
	//int i=0;
	/*
	while (std::cin.get() != '\r')
	{
		std::cin >> arr[i];
		i++;
	}
	*/
	
	//std::sort(arr.begin(), arr.end(), std::less<int>());
	int arr[] = { 1,2.3 };
	int result = find(arr, 0, 3, 3);
	std::cout << result << std::endl;
	return 0;
}