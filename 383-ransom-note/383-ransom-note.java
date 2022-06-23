class Solution {
    public boolean canConstruct(String a, String b) {
        HashMap<Character,Integer> m = new HashMap<Character,Integer>();
        for(int i=0;i<b.length();i++){
            char c = b.charAt(i);
            if(m.containsKey(c)){
                m.put(c, m.get(c)+1);
            }
            else m.put(c, 1);
        }
         for(int i=0;i<a.length();i++){
            char c = a.charAt(i);
            if(m.containsKey(c)){
                if(m.get(c)<=0) return false;
                else m.put(c,m.get(c)-1);
            }
            else return false;
        }
        return true;
    }
}