class Solution {
    
    public int[] avoidFlood(int[] rains) {
        TreeSet<Integer> emptyDays = new TreeSet<Integer>();
        int [] ans = new int[rains.length];
        HashMap<Integer, Integer> lop = new HashMap<Integer, Integer>(); 
                
        for(int i = 0; i< rains.length; ++i){
            if(rains[i] == 0){
                emptyDays.add(i);
            } else {
                ans[i] = -1;
                if(lop.containsKey(rains[i])){
                    Integer dryDay = emptyDays.ceiling((Integer) lop.get(rains[i]));
                    if(dryDay != null) {
                        emptyDays.remove(dryDay);
                        ans[dryDay] = rains[i];
                    } else {
                        return new int [0];
                    }
                }
                lop.put(rains[i], i);
            }
        }
        
        for(int i = 0; i < rains.length; ++i){
            if(ans[i] == 0){
                ans[i] = 1;
            }
        }
        return ans;
    }
}
