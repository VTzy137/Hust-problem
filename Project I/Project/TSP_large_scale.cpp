
// Include all library needed
#include "include.h"

int main(){

	input();

	initialize();

	// For graph small scale, use complete search path
    if(n < 20){
        complete_search(1);
	}

	// 
	else{
		greedy_algorithm();
		local_beam();
	}

	output();
}
