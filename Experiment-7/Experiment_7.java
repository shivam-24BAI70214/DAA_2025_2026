import java.util.*;
class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k){
        Map<Integer,List<int[]>> graph=new HashMap<>();
        for (int[] flight:flights){
            graph.putIfAbsent(flight[0],new ArrayList<>());
            graph.get(flight[0]).add(new int[]{flight[1],flight[2]});
        }
        PriorityQueue<int[]> pq=new PriorityQueue<>((a,b)->a[0]-b[0]);
        pq.offer(new int[]{0,src,0});
        Map<String, Integer> dist=new HashMap<>();
        while(!pq.isEmpty()){
            int[] curr=pq.poll();
            int cost=curr[0];
            int node=curr[1];
            int stops=curr[2];
            if (node==dst){
                return cost;
            }
            if(stops>k) continue;
            
            if(!graph.containsKey(node)) continue;
            for(int[] neighbor:graph.get(node)){
                int nextNode=neighbor[0];
                int price=neighbor[1];
                int newCost=cost+price;
                String key=nextNode+"-" +stops;
                if(!dist.containsKey(key) || newCost<dist.get(key)){
                    dist.put(key,newCost);
                    pq.offer(new int[]{newCost,nextNode,stops+1});
                }
            }
        }
        return -1;
    }
}
