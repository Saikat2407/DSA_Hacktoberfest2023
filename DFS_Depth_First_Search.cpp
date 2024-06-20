#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector< vector<ll> > v;
vector< bool > isVisited;

void dfs(ll nodes,ll parent){

	isVisited[nodes]=true;
	cout<< nodes <<" --> ";

	for(ll child : v[nodes]){

		if( ! isVisited[child] ){
			dfs( child , nodes );// recusively called dfs for child if not visited in graph
		}
	}
}

int main()
{
	ll nodes , edges ;
	cout <<"Enter Number of nodes in graph: ";
	cin >> nodes;
	cout << "Enter Number of edges in graph: ";
	cin >> edges;

	v.resize( nodes+1);    // nodes+1 is taken as indexing starts from 0
	isVisited.resize( nodes+1,false);   // For checking node traversed previously or not

	//Inputting the graph
	cout <<"Enter the pair of nodes containing edge with spaces in next "<<edges<<" line :\n";
	for(ll i = 1 ; i <= edges ; i++ ){
		ll x,y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
		//for directed edges you just need to comment one of these above line
	}
	
	ll source;
	cout << "\nEnter Source where the dfs starts from : ";
	cin>>source;

	cout <<"\nDFS Traversal is : ";
	dfs(source,-1);//since there is no parent of source so taken -1
	
	return 0;
}
