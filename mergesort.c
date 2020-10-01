#include<stdio.h>

void Sort(int arr[],int l,int m,int r)
{
	int i,j,k;
	int n1=m+1-l;
	int n2=r-m;

	int left[n1],right[n2];

	for(i=0;i<n1;i++)
		left[i]=arr[l+i];
	for(j=0;j<n2;j++)
		right[j]=arr[m+1+j];
	i=0;
	j=0;
	k=l;

	while(i<n1 && j<n2)
	{
		if(left[i]<=right[j])
		{
			arr[k]=left[i];
			i++;
		}
		else
		{
			arr[k]=right[j];
			j++;
		}
		k++;
	}

	while(i<n1)
	{
		arr[k]=left[i];
		i++;
		k++;
	}

	while(j<n2)
	{
		arr[k]=right[j];
		j++;
		k++;
	}
}
void merge(int arr[],int l,int r)
{
	int m= l +(r-l)/2;
	if(l<r)
	{
		merge(arr,l,m);
		merge(arr,m+1,r);

		Sort(arr,l,m,r);
	}
}

int main()
{
	int i;
	int arr[4];
	for(i=0;i<4;i++)
	scanf("%d",&arr[i]);
	
	merge(arr,0,3);

	for(i=0;i<4;i++)
		printf("%d",arr[i]);

	return 0;
}
