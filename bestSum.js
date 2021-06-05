//return an array that contains the shortest combination of numbers that add up to exatly the target
//in recursion, we assume that the children calls will perform properly

function bestSum(targetSum,numbers){
    if(targetSum == 0) return [];
    if(targetSum < 0) return null;

    //array to store the best combination
    let bestCombo = [];
    for(let num of numbers){
        let aWay = bestSum(targetSum-num,numbers);
        if()
    }
}
