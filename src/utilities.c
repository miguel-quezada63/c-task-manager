#include "utilities.h"

size_t get_str_arr_size(string *arr)
{
  size_t size = 0;
  while (arr[++size])
    ;
  return size;
}