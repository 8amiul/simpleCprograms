/* It's a simple program written in C which sort an array in ascending order
  
   Usage: array_sorter [OPTION]
   -v    verbose output

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int n;
  printf("Length of array: ");
  scanf("%d", &n);
  
  int *array = malloc(n * sizeof(int));
  
  printf("Elements of array: ");
  
  for (int i = 0; i < n; i++)
    {
      scanf("%d", &array[i]);
    }

  int i = 0;
  int j = 0;
  while (1)
    {
      if (array[i] > array[i+1])
	{
	  if (strcmp(argv[1] ? argv[1] : "", "-v") == 0)
	    {
	      for (int *x = &array[0]; x < &array[n]; x++)
		{
		  printf("%d ", *x);
		}
	      printf("\n");
	    }

	  int tmp = array[i];
	  array[i] = array[i+1];
	  array[i+1] = tmp;
	  j = 0;
	}
      else
	{
	  j++;
	}
      
      // increment and breaking conditionals //
      i++;
      
      if (i == n - 1)
	i = 0;
      if (j == n - 1)
	break;
    }
  
  (strcmp(argv[1] ? argv[1] : "", "-v") == 0) ? printf("\n") : printf("");
    
  for (int *i = &array[0]; i < &array[n]; i++)
    {
      printf("%d ", *i);
    }
  printf("\n");
  
  free(array);
}
