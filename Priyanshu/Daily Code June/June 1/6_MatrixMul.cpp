// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
	void Mutliply(vector<vector<int>> &matrixA, vector<vector<int>> &matrixB)
	{
		int n = matrixA.size();
		vector<vector<int>> matrixC(n, vector<int>(n, 0));

		for (int i = 0; i < matrixA.size(); i++)
		{
			for (int j = 0; j < matrixB.size(); j++)
			{
				for (int k = 0; k < matrixA.size(); k++) // Genertaes 1 element in new array
					matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
			}
		}

		for (int i = 0; i < matrixA.size(); i++)
		{
			for (int j = 0; j < matrixA.size(); j++)
			{
				matrixA[i][j] = matrixC[i][j];
			}
		}
	}
};

// { Driver Code Starts.
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		vector<vector<int>> matrixA(n, vector<int>(n, 0));
		vector<vector<int>> matrixB(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> matrixA[i][j];
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> matrixB[i][j];
			}
		}
		Solution ob;
		ob.Mutliply(matrixA, matrixB);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << matrixA[i][j] << " ";
			cout << "\n";
		}
	}
	return 0;
} // } Driver Code Ends