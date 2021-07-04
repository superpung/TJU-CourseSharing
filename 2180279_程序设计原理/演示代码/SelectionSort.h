void selectionSort(double list[], int arraySize)
{
  for (int i = arraySize - 1; i >= 1; i--)
  {
    // Find the maximum in the list[0..i]
    double currentMax = list[0];
    int currentMaxIndex = 0;

    for (int j = 1; j <= i; j++)
    {
      if (currentMax < list[j])
      {
        currentMax = list[j];
        currentMaxIndex = j;
      }
    }

    // Swap list[i] with list[currentMaxIndex] if necessary;
    if (currentMaxIndex != i)
    {
      list[currentMaxIndex] = list[i];
      list[i] = currentMax;
    }
  }
}
