class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double r[101][101]={0.0};
        r[0][0]=poured;
        for(int i=0;i<100;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(r[i][j] >=1 )
                {
                    r[i+1][j]+= (r[i][j]-1)/(2.0);
                    r[i+1][j+1]+= (r[i][j]-1)/(2.0);
                    r[i][j]=1;
                }
            }
        }
        return r[query_row][query_glass];
    }
};
