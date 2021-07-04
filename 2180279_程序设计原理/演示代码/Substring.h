char * substring(const char * const s, int start, int end)
{
  char * pNewString = new char[end - start + 1 + 1];

  int j = 0;
  for (int i = start; i < end; i++, j++)
  {
    pNewString[j] = s[i];
  }

  pNewString[j] = '\0'; // Set a null terminator

  return pNewString;
}
