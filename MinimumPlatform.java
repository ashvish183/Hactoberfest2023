class Pair{
    int arrival ;
    int depart ;
    Pair(int arrival , int depart){
        this.arrival = arrival ;
        this.depart = depart ;
    }
     public int compareTo(Pair p){
           return this.depart-p.depart;
       }
}


class Solution
{
  
    static int findPlatform(int arr[], int dep[], int n)
    {
      Arrays.sort(arr);
      Arrays.sort(dep);
      int count = 1 ;
      int i =1 ;
      int j =0 ;
      while(i<n && j<n){
          if(arr[i]<=dep[j]){
              count++ ;
              i++;
              
          }
          else if (arr[i]>dep[j]){
              j++ ;
              i++ ;
          }
      }
      return count ;
    }
    
}
