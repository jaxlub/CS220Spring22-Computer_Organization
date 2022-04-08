
int mypow (int x, int y){
	int answer;	
	// base case y = 0, return 1
	if(y == 0){
		return 1;
	}	
	// base case y = 1, return x
	if (y == 1){
		return x;
	}
	// general case 1: y is even
	if((y % 2) == 0){
		answer = mypow(x, (y/2)) * mypow(x, (y/2));
	} else {
		// general case 2: y is odd
		answer = x * mypow(x, (y-1));
	}
	return answer;	
}