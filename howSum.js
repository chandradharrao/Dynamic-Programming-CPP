//return a single way how the target sum can be achieved by adding elements of the combination rturned

function howSum(targetSum,numbers){
    //there is definetly one way
    if(targetSum == 0) return [];
    //there is no way
    if(targetSum < 0) return null;

    //iterate over all numbers and check if diff can be generated
    for(let num of numbers){
        let aWay = howSum(targetSum-num,numbers);
        //check if it resulted in zero
        if(aWay !== null){
            //early return
            return  [...aWay,num];
        }
    }
    //unable to find any combo
    return null;
}

console.log(howSum(7,[5,3,4,7]));