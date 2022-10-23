class Solution {
    func findErrorNums(_ nums: [Int]) -> [Int] {
         let n = nums.count
    var b: [Int] = []
    var dict: [Int: Int] = [:]
    
    for ele in nums {
        if let val = dict[ele] {
            print(val)
            dict[ele] = val + 1
            if val >= 1 {
                b.append(ele)
            }
        } else {
            dict[ele] = 1
        }
    }
    for i in 1...n {
        if let _ = dict[i]{
        } else {
            b.append(i)
            break
        }
    }
    return b
    }
}