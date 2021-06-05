//return an array that contains the shortest combination of numbers that add up to exatly the target
//in recursion, we assume that the children calls will perform properly

function bestSum(targetSum,numbers){
    if(targetSum == 0) return [];
    if(targetSum < 0) return null;

    //array to store the best combination
    let bestCombo = null;
    for(let num of numbers){
        let aWay = bestSum(targetSum-num,numbers);
        if(aWay !== null){
            //add the num that made it zero
            aWay = [...aWay,num];
            if(bestCombo === null || bestCombo.length > aWay.length) bestCombo = aWay;
        }
    }
    return bestCombo;
}

console.log(bestSum(7,[2,3,7]));
