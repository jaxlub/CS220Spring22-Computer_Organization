#include <stdio.h>

int sequence(long long n){
long long tracker = n;
int counter = 1;   
while(tracker != 1){
	if((tracker%2)==0){
		counter++;
		tracker = tracker/2;
	}else{
		counter++;
		tracker = (tracker*3) +1;
	}
}
return counter;
}

int longest(void){
	//variable to remember the number with the longest sequence found yet
	int longest = 1;
	int long_sequence = sequence(longest); 	
	for(int x = 2; x <= 1000000; x++){		
		int x_sequence = sequence(x);
		if(x_sequence > long_sequence){
			long_sequence = x_sequence;
			longest = x;		
		}
	}
	return longest;
}