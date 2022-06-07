#include <bits/stdc++.h> 

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int row = 0,col = 0;
    int prev,cr;

   while(row < n && col < m)
   {
       if(row+1==n || col+1==m)
           break; 
       prev=mat[row+1][col];
       for (int i = col; i < m; i++)
       {
           cr = mat[row][i];
           mat[row][i] = prev;
           prev = cr;
       }

       row++;

        for (int i = row; i < n; i++)
       {

           cr = mat[i][m-1];

           mat[i][m-1] = prev;

           prev = cr;

       }

       m--;

         if (r < n)

       {

           for (int i = m-1; i >= c; i--)

           {

               cr = mat[n-1][i];

               mat[n-1][i] = prev;

               prev = cr;

           }

       }

       n--;

       if (c < m)

       {

           for (int i = n-1; i >= r; i--)

           {

               cr = mat[i][c];

               mat[i][c] = prev;

               prev = cr;

           }

       }

       c++;

     

   }
}