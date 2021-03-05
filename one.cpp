#include <bits/stdc++.h> 
using namespace std; 

int longestSubarray(int arr[],int n,int k) 
{ 
	int i, j, result = 1; 
	set<int> s; 

	for (i = 0; i < n - 1; i++)
    { 
		s.insert(arr[i]); 
		for (j = i + 1; j < n; j++)
        { 
			if (abs(arr[i] - arr[j]) == 0 || abs(arr[i] - arr[j]) == k) 
            { 
				if (s.count(arr[j])==0) 
                { 
					if (s.size() == 2) 
						break; 
					else
						s.insert(arr[j]); 
				} 
			} 
			else
				break; 
		}

		if (s.size() == 2) 
        { 
			result = max(result, j - i); 
			s.clear(); 
		} 
		else
			s.clear(); 
	} 

	return result; 
} 


int main() 
{ 
	int arr[] = {0, 0, 1, 1, 3, 3, 3}; 

	int N = sizeof(arr)/sizeof(arr[0]); 
	int K = 1; 

	int length = longestSubarray(arr, N, K); 

	if (length == 1) 
		cout << -1; 
	else
		cout << length; 

	return 0; 
} 
