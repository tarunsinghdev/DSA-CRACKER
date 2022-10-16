// Find Minimum and Maximum Element from Array

// Time Complexity  = O(n)
function minMax(array){
    let min = Number.POSITIVE_INFINITY
    let max = Number.NEGATIVE_INFINITY

    for( let i=0; i< array.length ;i++){
        if(array[i] < min){
            min = array[i]
        }
        if( array[i] > max){
            max = array[i]
        }
    }

    console.log("Min" , min);
    console.log("Max", max);    
}

minMax([1000, 11, 445, 1, 330, 3000])