
int sum3or5(int n){
// keep track of the sum in tracker variable
int tracker = 0;

// checks if each number is divisible by 3 or 5 and if so add it to the tracker counter
   for(int x = 0; x < n; x++){
	if(((x%3) == 0) || ((x%5) == 0)){
        tracker += x;
      } 
   }

return tracker;
}