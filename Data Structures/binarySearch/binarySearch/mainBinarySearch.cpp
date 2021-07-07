int binarySearch(const int anArray[], int first, int last, int target){
int index;
if (first > last)
index = -1;
else
{
	int mid = (first + last) / 2;
	if (target == anArray[mid])
		index = mid;
	else if (target < anArray[mid])
		index = binarySearch(anArray, first, mid - 1, target);
	else
		index = binarySearch(anArray, mid + 1, last, target);
}
return index;
}