class Solution {
    func arrayStringsAreEqual(_ word1: [String], _ word2: [String]) -> Bool {
        var res1: String = ""
        var res2: String = ""
        for word in word1 {
            res1.append(word)
        }
         for word in word2 {
            res2.append(word)
        }
        return res1 == res2
    }
}