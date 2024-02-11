void sort_arr(int arr[], int i, int n)
{
    if(n==0)
    {
        return;
    }

    int j=i;
    while(j>0 && arr[j-1]>arr[j])
    {
        int temp=arr[j-1];
        arr[j-1]=arr[j];
        arr[j]=temp;
        j--;
    }

    sort_arr(arr,i+1,n-1);
}

void insertionSort(int arr[], int n)
{
    //write your code here
    sort_arr(arr,0,n);
}