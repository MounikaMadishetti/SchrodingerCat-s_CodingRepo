class Solution {
    public String minWindow(String s, String t) {
          if(s.length() < t.length()) return "";
        Map<Character,Integer> ref = new HashMap<>();
        for(char ch: t.toCharArray()){
            ref.put(ch, ref.getOrDefault(ch,0)+1);            
        }
        int expected = ref.size();
        Map<Character, Integer> curr = new HashMap<>();
        int l = 0;
        int r = 0;
        long minWindow = Long.MAX_VALUE;
        String res = "";
        while(r < s.length()){
            
            int rcount = curr.getOrDefault(s.charAt(r),0);
            curr.put(s.charAt(r), rcount+1);
            if(ref.containsKey(s.charAt(r)) && curr.get(s.charAt(r)).equals(ref.get(s.charAt(r)))){
                expected--;
            }
            
            while(expected == 0 && l<=r){
                
                if((r-l+1) < minWindow){
                    minWindow = (r-l+1);
                    res = s.substring(l, r+1);
                }
                int lcount = curr.get(s.charAt(l));
                curr.put(s.charAt(l), lcount-1);
                if(ref.containsKey(s.charAt(l)) && curr.get(s.charAt(l)) < ref.get(s.charAt(l))){
                    expected++;
                }
                l++;
            }
            
            r++;
        }
        return res;
    }
}