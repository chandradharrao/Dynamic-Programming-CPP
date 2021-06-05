function howSum(targetSum,numbers,memo = {}){
    //if the targetSum key already in hashmap,return its value
    if(targetSum in memo) return memo[targetSum]; 

    if(targetSum == 0) return [];
    if(targetSum < 0) return null;

    for(let num of numbers){
        let aWay = howSum(targetSum-num,numbers,memo);
        if(aWay !== null){
            memo[targetSum] = [...aWay,num];
            return memo[targetSum];
        }
    }

    //no way to generate the targetSum using any elements of input array
    memo[targetSum] = null;
    return null;
}

console.log(howSum(7,[2,3]));