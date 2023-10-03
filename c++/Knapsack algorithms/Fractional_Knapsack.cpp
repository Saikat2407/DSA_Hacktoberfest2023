//FRACTIONAL KNAPSACK 

// greedy approach to solve the knapsack problem

#include<iostream>
using namespace std;

class greedy{
	public:
	int id;
	float weight;
	float profit;
	float pw;
	float amount;
	void ratio(){
		pw=profit/weight;
	}
	

};

int main(){
	int n;
	float cap,totalm=0,totalp=0;
	cout<<"enter the no.of objects:";
	cin>>n;
	cout<<"enter the bag capacity:";
	cin>>cap;
	
	greedy obj[n];									//creating an array of object of size n
	for(int i=0;i<n;i++){
		obj[i].id=i+1;
		obj[i].amount=0;
		cout<<"enter the weight of "<<i+1<<" : ";
		cin>>obj[i].weight;
		cout<<"enter the profit of "<<i+1<<" : ";
		cin>>obj[i].profit;
	}
	for(int i=0;i<n;i++){							//finding the profit to weight ratio of each object
		obj[i].ratio();
	}

	for(int i=0;i<n-1;i++){							//Sorting the objects in descending order according to profit to weight ratio
		for(int j=0;j<n-1-i;j++){
			if(obj[j].pw < obj[j+1].pw){
				greedy temp=obj[j];
				obj[j]=obj[j+1];
				obj[j+1]=temp;
			}
		}
	}
	
	int i=0;
	while(totalm<cap){										//Looping until totalweight of selected items doesn't  become equal to capacity of bag
		if (obj[i].weight <= (cap - totalm))
		{
			obj[i].amount = 1;								//if object fits in the bag with remaining capacity then it is taken as whole
			totalm = totalm + obj[i].weight;
			totalp = totalp + obj[i].profit;
		}
		else if (obj[i].weight > (cap - totalm))			//else we take fraction of it
		{
			obj[i].amount = (cap - totalm) / (obj[i].weight);
			totalm = totalm + (cap - totalm);
			totalp = totalp + (obj[i].profit) * (obj[i].amount);
		}
		i++;
	}
	
	cout<<"\n\nfinal table is::\n"<<"id  "<<"fract  "<<"weight  "<<"profit  "<<"pw ratio\n";
	for(int i=0;i<n;i++){
		cout<<obj[i].id<<"    "<<obj[i].amount<<"     ";
		cout<<obj[i].weight<<"       ";
		cout<<obj[i].profit<<"       ";
		cout<<obj[i].pw<<endl;
	}
	cout<<endl<<"total profit is::"<<totalp;
}