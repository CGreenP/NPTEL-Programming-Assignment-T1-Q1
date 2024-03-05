#include <stdio.h>
#include <stdlib.h>

int mostFrequent(int arr[], int n)
{
	int c=0,d=0,position=0,swap=0;
	for (c = 0; c < (n-1); c++)
    {
        position = c;
        for (d = c + 1; d < n; d++)
        {
            if (arr[position] > arr[d])
            {
                position = d;
            }
        }
        if (position != c)
        {
             swap = arr[c];
             arr[c] = arr[position];
             arr[position] = swap;
        }
    }

	int max_count = 1, res = arr[0], curr_count = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i] == arr[i - 1])
			curr_count++;
		else {
			if (curr_count > max_count) {
				max_count = curr_count;
				res = arr[i - 1];
			}
			curr_count = 1;
		}
	}

	if (curr_count > max_count)
	{
		max_count = curr_count;
		res = arr[n - 1];
	}

	return res;
}
int main()
{
    int inp,i=0,size=0;
    int arr[100];
    scanf("%d",&inp);
    while(inp!=(-1))
    {
        arr[i]=inp;
        i++;
        scanf("%d",&inp);
    }
    size=i;
    printf("%d",mostFrequent(arr,size));
    return 0;
}
