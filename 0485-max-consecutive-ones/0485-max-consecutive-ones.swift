class Solution {
    func findMaxConsecutiveOnes(_ nums: [Int]) -> Int {
       var m = 0
       var res = 0
        for n in nums {
            if n == 1 {
                m = m + 1
                res=max(res,m)
        } else {
                m=0
            }     
        }
        return res
    }
}