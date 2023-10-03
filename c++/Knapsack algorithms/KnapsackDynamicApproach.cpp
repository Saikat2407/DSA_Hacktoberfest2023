/*
Knapsack Algorithm Dynamic Approach

*/



#include<iostream>
#include<algorithm> 
using namespace std;

class dclass{
	public:
	int w;						//w stands for weight of object
	int p;						//p stands for profit of object
    int id;						//id is used to see wether object is used or not where intially its 0 means not used
};

int main(){
	int n,cap;
	cout<<"enter the no of objects:";
	cin>>n;
	cout<<"enter the capacity of bag:";
	cin>>cap;

	dclass obj[n+1];                                //declaring array of objects and matrix

	int mat[n+1][cap+1];                            //initializing matrix with rows equal to no. of objects and columns equal to capacity of bag
	
	obj[0].w=0;										//here we initialize attributes of 0th object which is considered by us for easy calculations
	obj[0].p=0;
    obj[0].id=0;
    
	for(int i=1;i<n+1;i++){
        obj[i].id=0;                                //for putting id=0 for all objects to denote that no object is used till now;
		cout<<"enter the weight of "<<i<<":";
		cin>>obj[i].w;
		cout<<"enter the profit of "<<i<<":";
		cin>>obj[i].p;
	}

	for(int i=0;i<n;i++){                           //sorting the objects in ascending order of weights
		for(int j=0;j<n-i;j++){
			if(obj[j].w >obj[j+1].w){
				dclass temp=obj[j];
				obj[j]=obj[j+1];
				obj[j+1]=temp;
			}
		}
	}

	for(int j=0;j<cap+1;j++){			//initializing first row and first column as 0 because if capacity of bag is 0 profit will be 0 and if 0 objects are selected profit will be 0
        if(j<n+1){
            mat[j][0]=0;
        }
		mat[0][j]=0;
	}

	for(int i=1;i<n+1;i++){
		for(int j=1;j<cap+1;j++){               //finding values of matrix
			int p= mat[i-1][j];
			int l= j-obj[i].w;
			int q=0;
			if(l<0){
				q=0;
			}
			else{
				q= mat[i-1][l]+obj[i].p;
			}			
			mat[i][j]=max(p,q);
		}
	}


    cout<<endl<<"matrix is::\n";
	for(int i=0;i<n+1;i++){                 //print matrix
		for(int j=0;j<cap+1;j++){
			cout<<mat[i][j]<<"  ";
		}cout<<endl;
	}

    



    int c=n,d=cap;                      //bottom up approach  used to find which object are selected
    int finalp=mat[c][d];
    while(finalp!=0){
		while (1)
		{
			if (mat[c - 1][d] == finalp)
			{
				c--;
			}
			else
			{
				obj[c].id = 1;
				finalp = finalp - obj[c].p;
				c--;
				break;
			}
		}
		for (int i = 0; i < cap + 1; i++)
		{
			if (mat[c][i] == finalp)
			{
				d = i;
				break;
			}
		}
	}


    cout<<"\nweight  "<<"profit   "<<"remark \n";
    for(int i=1;i<n+1;i++){
        cout<<"  "<<obj[i].w<<"       "<<obj[i].p;
		if(obj[i].id==1)
			cout<<"     Selected";
		else
			cout<<"         -";
		cout<<endl;
	}

	cout<<"\n\ntotal profit is::"<<mat[n][cap];

}