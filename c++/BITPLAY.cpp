// The problem statement for the below solution is 
// https://www.codechef.com/problems/BITPLAY


#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	    long long int count=1;
	    long long int m=pow(10,9)+7;
	    bool flag=true;
	    for(int i=3;i<=n;i++){
	        if(i%2!=0){
	            if(s[i-1]=='1'){
	                if(s[i-3]=='1' && s[i-2]=='0'){
	                    count=(count*2)%m;
	                    // Operation could be ^ or |
	                }else if(s[i-3] =='0' && s[i-2]=='0'){
	                    flag=false;
	                   
	                }else if(s[i-3] =='0' && s[i-2]=='1'){
	                     count=(count*2)%m;
	                   
	                }else{
	                    count=(count*2)%m;
	                   // Operation could be & or |
	                }
	                
	            }else if(s[i-1]=='0'){
	                if(s[i-3]=='1' && s[i-2]=='0'){
	                    count=(count*1)%m;
	                    // Operation could be &
	                }if(s[i-3]=='0' && s[i-2]=='1'){
	                    count=(count*1)%m;
	                    // Operation could be &
	                }else if(s[i-3] =='0' && s[i-2]=='0'){
	                   count=(count*3)%m;
	                   // Operation could be ^ or & or |
	                   
	                }else{
	                    count=(count*1)%m;
	                   // Operation could be ^
	                }
	            }
	            
	            
	        }
	    }
	    if(!flag){
	        cout<<0<<endl;
	    }else{
	        cout<<(count)%m<<endl;
	    }
	    
	}
	return 0;
}
