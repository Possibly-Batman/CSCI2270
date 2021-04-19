int addToArrayAsc(float sortedArray[100], int numElements, float newValue) {
    sortedArray[numElements] = newValue; 
    numElements++;
    for(int i = 0; i < numElements-1; i++){
        for(int j = 0; j < numElements-i-1; j++){
            if(sortedArray[j] > sortedArray[j+1]){
                float tempVar = sortedArray[j];
                sortedArray[j] = sortedArray[j+1];
                sortedArray[j+1] = tempVar;
            }
        }
    }
    return(numElements);
}