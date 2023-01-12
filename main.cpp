#include<bits/stdc++.h>

using namespace std;

int main()
{
  string s_parent = "ACACACTA";
  string s_offsp="AGCACACA";
  int arr[s_offsp.length()+1][s_parent.length()+1];
  int col[s_offsp.length()+1][s_parent.length()+1];
  int row[s_offsp.length()+1][s_parent.length()+1];
  for(int i = 0 ; i<s_parent.length()+1;i++)
    {
      arr[0][i] = 0 ;
    }
  for(int j = 0 ; j <s_offsp.length()+1;j++)
    {
      arr[j][0] = 0 ;
    }
  for(int i = 1 ; i < s_offsp.length()+1;i++)
    {
      for(int j = 1 ;j<s_parent.length()+1;j++)
	{
	  arr[i][j] = -100 ;
	}
    }
    for(int i = 1 ; i<s_offsp.length()+1;i++)
    {
        for(int j= 1 ;j<s_parent.length()+1;j++)
        {
            if(s_parent[j-1]==s_offsp[i-1])
            {
                arr[i][j] = 2 + arr[i-1][j-1];
                row[i][j] = i-1 ;
                col[i][j] = j-1 ;
            }
            else
            {
                int x1 = arr[i-1][j-1] -1 ;//diag
                int x2 = arr[i-1][j] - 1 ;//top
                int x3 = arr[i][j-1] - 1; //left
                if(x1>x2)
                {
                    if(x1>x3)
                    {
                        arr[i][j] = x1 ;
                        row[i][j] = i-1 ;
                        col[i][j] = j-1 ;
                    }
                    else
                    {
                        arr[i][j] = x3 ;
                        row[i][j] = i;
                        col[i][j] = j-1 ;
                    }
                }
                else if(x2>x3)
                {
                    arr[i][j] = x2 ;
                    row[i][j] = i-1 ;
                    col[i][j] = j  ;
                }
                else
                {
                    arr[i][j] = x3 ;
                    row[i][j] = i ;
                    col[i][j] = j -1;
                }
            }
        }
    }
    int least = -100 ;
    int least_r = -100 ;
    int least_c = -100 ;
    for(int i = 0 ; i < s_offsp.length()+1;i++)
    {
        for(int j = 0 ;j<s_parent.length()+1;j++)
	    {
	        cout <<arr[i][j] <<" " ;
	        if(i!=0 || j!=0)
	        {
	            if(least<arr[i][j])
	            {
	                least_r = i ;
	                least_c = j ;
	            }
	        }
	    }
        cout <<"\n" ; 
    }
    int i = least_r;
    int j = least_c ;
    while(i!=0 && j !=0)
    {
        cout << arr[i][j];
        if(row[i][j]!=0 || col[i][j]!=0)
        {
            cout <<"->" ;
        }
        int i1=row[i][j] ; 
        int j1 = col[i][j] ; 
        i =i1 ;
        j =j1 ;
    }
    cout <<"\n" ; 
    string s_1  = "" ; 
    string s_2 = "" ; 
    i =least_r ; 
    j = least_c ;
    while(i!=0 && j !=0)
    {
        if(s_parent[j-1]==s_offsp[i-1])
        {
            s_1 = s_parent[j-1] + s_1 ;
            s_2 = s_offsp[i-1] + s_2 ;
        }
        else
        {
            int t = row[i][j] ;
            int p = col[i][j] ;
            if(p==j)
            {
                s_1 = '_' + s_1 ;
                s_2 = s_offsp[i-1] + s_2 ;
            }
            else
            {
                s_1 = s_parent[i-1] + s_1 ;
                s_2 = '_' + s_2 ;
            }
        }
        int i1=row[i][j] ; 
        int j1 = col[i][j] ; 
        i =i1 ;
        j =j1 ;
    }
    cout << s_1 <<"\n" ;
    cout <<s_2 <<"\n" ;
  return 0;
}