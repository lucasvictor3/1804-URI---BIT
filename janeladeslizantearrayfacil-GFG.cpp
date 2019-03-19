#include <iostream>
#include<stdio.h>
using namespace std;

int main() {
	int T;

    scanf("%d", &T);

	for(int i = 0; i < T; i++){
	    int tam, sum;
	    scanf("%d %d",&tam, &sum);


	    int arr[tam];
	    for(int j = 0; j < tam; j++){
	        scanf("%d", &arr[j]);
	    }

	    int currSum = arr[0];
	    int k = 0;

	    int firstIndex = 0;
	    int lastIndex = 1;

	    while(currSum != sum && firstIndex < tam && lastIndex < tam){
    	    while(currSum < sum){
    	        currSum += arr[lastIndex];
    	        lastIndex++;
    	    }
            while(currSum > sum){
                currSum -= arr[firstIndex];
                firstIndex++;
            }
	    }
        if(currSum == sum){
            cout << firstIndex + 1 << " " << lastIndex  << endl;
        } else {
            cout << -1 << endl;
        }


	}




	return 0;
}
