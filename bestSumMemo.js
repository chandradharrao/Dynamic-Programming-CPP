function bestSum(targetSum,numbers,memo={}){
    if(targetSum in memo) return memo[targetSum];
    if(targetSum == 0) return [];
    if(targetSum < 0) return null;

    let allWays = null;
    for(let num of numbers){
        let aWay = bestSum(targetSum-num,numbers,memo);
        if(aWay !== null){
            aWay = [...aWay,num];
            if(allWays == null || allWays.length > aWay.length) allWays = aWay;
        }
    }
    return allWays;
}

console.log(bestSum(7,[2,3,7]));