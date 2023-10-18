#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int divide_conquer(vector<int> &nums,int l,int r)
{
    if(l>r) return INT_MIN;
    if(l==r) return nums[l];
    int m=(l+r)/2;
    int tmp=0,l_sum=INT_MIN,r_sum=INT_MIN;
    // 算包含m之最大sum，橫跨左subproblem 和右subproblem之sum
    for(int i=m;i>=l;i--)
    {
        tmp+=nums[i];
        if(tmp>l_sum) l_sum=tmp;
    }
    tmp=0;
    for(int i=m;i<r;i++)
    {
        tmp+=nums[i];
        if(tmp>r_sum) r_sum=tmp;
    }
    tmp=max(r_sum,max(l_sum,l_sum+r_sum-nums[m]));
    return max(tmp,max(divide_conquer(nums,l,m-1),divide_conquer(nums,m+1,r)));
}

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n,0),nums2(n,0);
    for(int i=0;i<n;i++)
    {
        cin >> nums[i];
        nums2[i]=nums[i];
    }
    int ans1=divide_conquer(nums2,0,n-1);
    int ans2=nums[0];
    int sum=0;
    //dp
    for(int i=0;i<n;i++)
    {
        sum+=nums[i];
        if(sum>ans2) ans2=sum;
        if(sum<0)sum=0;
    }
    cout << ans1 << " " << ans2;
    return;
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    solve();
    return 0;
}