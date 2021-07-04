int binarySearch(int list[], int key, int arraySize)
{
  int low = 0;
  int high = arraySize - 1;

  while (high >= low)
  {
    int mid = (low + high) / 2;
    if (key < list[mid])
      high = mid - 1;
    else if (key == list[mid])
      return mid;
    else
      low = mid + 1;
  }

  return –low - 1;
}
