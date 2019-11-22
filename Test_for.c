#include <stdio.h>

int main(int argc, char* argv[])
{
	int i=0;
	int nums[100];

	for (i=0 ; i<100 ; i++)
       	{
		printf("i is: %d \n",i);
            	nums[i]=i*i;
       	}

	printf("\n\n--------------------------------------------------------------------------------\n\n");
	
	for (i=0 ; i<100 ; i++)
	{
		if(nums[i]%2==0)
		{
			printf("%d is even.\n",nums[i]);
		}

		else
		{
			printf("%d is odd.\n",nums[i]);
		}
	}

  return 0;
}
