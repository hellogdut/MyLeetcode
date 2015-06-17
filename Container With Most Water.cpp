class Solution {
public:
   int maxArea(vector<int> &height) {
      int i = 0;
      int j = height.size() - 1;
      int maxV = 0;
      while (i < j)
      {
         int shortest = min(height[i], height[j]);
         int v = shortest * (j - i);
         maxV = max(maxV, v);
         if (height[i] < height[j])
            i++;
         else
            j--;
      }
      return maxV;
   }
   
};
