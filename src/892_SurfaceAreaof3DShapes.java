class Solution {
  public int surfaceArea(int[][] grid) {
    int n=grid.length;
    int res=0;
    for(int i=0; i<n; i++) {
      int tep=0;
      for(int j=0; j<n; j++) {
        if(grid[i][j] > 0) tep += 2;
        if(i==0) {
          tep += grid[i][j];
        }
        else {
          if(grid[i][j] >= grid[i-1][j]) tep += grid[i][j] - grid[i-1][j];
        }
        if(i==n-1) tep += grid[i][j];
        else {
          if(grid[i][j] >= grid[i+1][j]) tep += grid[i][j] - grid[i+1][j];
        }
        if(j==0) tep+=grid[i][j];
        else { if(grid[i][j] >= grid[i][j-1]) tep+=grid[i][j]-grid[i][j-1];}
        if(j==n-1) tep += grid[i][j];
        else { if(grid[i][j] >= grid[i][j+1]) tep += grid[i][j] - grid[i][j+1];}
        //System.out.println(tep);
      }
      res += tep;
    }
    return res;
  }
}
