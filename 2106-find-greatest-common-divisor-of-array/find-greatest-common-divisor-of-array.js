/**
 * @param {number[]} nums
 * @return {number}
 */
function GCD(a,b){
    if(b==0){
        return a;
    }
    return GCD(b,a%b);
}
var findGCD = function(nums) {
    let min=1000000000;
    let max=-1;
    for(let i=0;i<nums.length;i++){
        if(min>nums[i]){
            min=nums[i];
        }
        if(max<nums[i]){
            max=nums[i];
        }
    }
    let gcd=GCD(max,min);
    return gcd;
};