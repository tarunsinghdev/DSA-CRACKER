// Example : [1,2,3,4]  O/P : [4,3,2,1]


// Method 1 : TC : O(n)
function reverse(array){

    for(let i=array.length-1;i>=0 ;i--){
        console.log(array[i])
    }
}

reverse([1,2,3,4,5])