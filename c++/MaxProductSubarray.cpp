Maximum Product Subarray
long long contProd(int i,int j,vector<int>&arr)
{
    if(i>j){return 0;}

    long long prod=1;
    while(i<=j)
    {
        prod*=arr[i];
        i++;
    }
    return prod;
}

long long solve(int i,int j,vector<int>&arr)
{
    if(i>j){return 0;}
    if(i==j){return arr[i];}

    vector<int> negative;

    for(int k=i;k<=j;k++)
    {
        if(arr[k]<0)
        {
            negative.push_back(k);
        }
    }

    if(negative.size()%2==0)
    {
        return contProd(i,j,arr);
    }

    long long ans=0;
    for(auto it:negative)
    {
        ans=max(ans,max(contProd(i,it-1,arr),contProd(it+1,j,arr)));
    }
    return ans;
}

long long maxProduct(vector<int> arr,int n)
{
    if(n==1){return arr[0];}

    vector<int> zeros;
    zeros.push_back(-1);
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {
            zeros.push_back(i);
        }
    }
    zeros.push_back(n);

    long long ans=0;
    int m=zeros.size();

    for(int i=0;i<m-1;i++)
    {
        ans=max(ans,solve(zeros[i]+1,zeros[i+1]-1,arr));
    }
    return ans;
}

