/*
You are given a 0-indexed integer array nums. An index i is part of a hill in nums if the closest non-equal neighbors of i are smaller than nums[i]. Similarly, an index i is part of a valley in nums if the closest non-equal neighbors of i are larger than nums[i]. Adjacent indices i and j are part of the same hill or valley if nums[i] == nums[j].

Note that for an index to be part of a hill or valley, it must have a non-equal neighbor on both the left and right of the index.

Return the number of hills and valleys in nums.
*/


    int countHillValley(vector<int>& n) {
         vector<int> v;
    v.push_back(n[0]);
    for (int i = 1; i < n.size(); i++)
    {
        if (n[i] != n[i - 1])
            v.push_back(n[i]);
    }
      int i=1;
        int c=0;
        while(i<v.size()-1)
        {
            if(v[i]>v[i-1] && v[i]>v[i+1])
            c++;
            else if(v[i]<v[i-1] && v[i]<v[i+1])
            c++;
            i++;
        }
        return c;   
    }