class Solution {
    func checkIfPangram(_ sentence: String) -> Bool {
       var charHash: [Character: Int] = [:]
        
        for chars in "abcdefghijklmnopqrstuvwxyz" {
            charHash[chars] = 0
        }
        sentence.forEach { ele in
                          charHash[ele] = charHash[ele]! + 1
            print("\(ele) -> \(charHash[ele])")
        }
        return !charHash.values.contains(0) ?? false
    }
}