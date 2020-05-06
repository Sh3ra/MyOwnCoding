import java.lang.Math;
import java.util.ArrayList;

class Solution {
    public static int[] solution(int area) {
        int n= (int) Math.sqrt(area);
        //System.out.println(area);
        ArrayList<Integer> ans=new ArrayList<Integer>();
        while(n>0){
            //System.out.println(n);
            ans.add(n*n);
            area-=n*n;
            n= (int) Math.sqrt(area);
        }
        int[] res=new int[ans.size()];
        int i=0;
        for (Integer x:ans){
            res[i]=(int)x;
            i++;
        }
        return res;
    }
