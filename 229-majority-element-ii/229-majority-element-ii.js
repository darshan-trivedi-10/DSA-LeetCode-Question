/**
 * @param {number[]} nums
 * @return {number[]}
 */
var majorityElement = function(nums) {
       let n = nums.length;
        let num1, num2;
        let occ1 = 0, occ2 = 0;
        for (let i = 0; i < n; i++)
        {
            if (occ1 == 0 && nums[i] != num2)
            {
                num1 = nums[i];
                occ1++;
            }
            else if (nums[i] == num1)
            {
                occ1++;
            }
            else if (occ2 == 0)
            {
                num2 = nums[i];
                occ2++;
            }
            else if (nums[i] == num2)
            {
                occ2++;
            }
            else
            {
                occ1--, occ2--;
            }
        }

        let c1 = 0, c2 = 0;
        for (let i = 0; i < n; i++)  
        {
            if (num1 == nums[i])
            {
                c1++;
            }
            else if (num2 == nums[i])
            {
                c2++;
            }
        }

        var ans = [];
        if (c1 > (n / 3))
        {
            ans.push(num1);
        }

        if (c2 > (n / 3))
        {
            ans.push(num2);
        }

        return ans;
    
    
};