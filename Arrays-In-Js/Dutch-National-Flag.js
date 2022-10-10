// Given an array A[] consisting of only 0s, 1s, and 2s. The task is to write a function that sorts
// the given array. The functions should put all 0s first, then all 1s and all 2s in last.
// This Problem is also known as Dutch National Flag.

// First Sol --> Using Sort
// Second Sol ---> Count Sort

//Efficient Solution

function DutchNationalFlagSort(array){

    let low =0;
    let mid = 0;
    let high = array.length -1;
    let temp =0;
  
    while(mid <=high){
  
      if(array[mid] == 0){
          temp = array[low]
          array[low] = array[mid]
          array[mid] = temp
  
          low++;
          mid++;
      }else if(array[mid] == 1){
          mid++;
      }else{
          temp = array[mid]
          array[mid] = array[high]
          array[high] = temp
  
          high--
      }
    }
  
    return array;
  }
  
  
  console.log(DutchNationalFlagSort([0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 ]));