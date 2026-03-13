import java.util.*;
class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> res=new ArrayList<>();
        btrack(s,0,new ArrayList<>(),res);
        return res;
    }
    public void btrack(String s,int st,List<String>p,List<List<String>> res){
        if(st==s.length()){
            res.add(new ArrayList<>(p));
            return;
        }
        for(int i=st;i<s.length();i++){
            if(IsPalindrome(s,st,i)){
                p.add(s.substring(st,i+1));
                btrack(s,i+1,p,res);
                p.remove(p.size()-1);
            }
        }
    }
    public boolean IsPalindrome(String s,int l,int r){
        while(l<r){
            if(s.charAt(l) != s.charAt(r)){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
}
