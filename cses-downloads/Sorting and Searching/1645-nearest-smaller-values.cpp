#include <bits/stdc++.h>
#define ll long long int

using namespace std;

// function to find the position of left smaller element for
// all indices
void solve(vector<ll>& arr, ll N)
{
	// Stack to store indices of previous smaller elements
	stack<ll> prevSmaller;

	for (int i = 0; i < N; i++) {
		// Pop from the stack till there are elements in the
		// stack and the element at index =
		// prevSmaller.top() is greater than the current
		// element
		while (!prevSmaller.empty()
			&& arr[prevSmaller.top()] >= arr[i]) {
			prevSmaller.pop();
		}
		// If there is no position with smaller element on
		// the left side
		if (prevSmaller.empty())
			cout << 0 << " ";
		// If there is a position with smaller element on
		// the left side, print it
		else
			cout << prevSmaller.top() + 1 << " ";

		// Push the current position to the stack
		prevSmaller.push(i);
	}
}

int main()
{
	// Sample Input
	ll N ;
	cin>>N;
	vector<ll> arr;
	ll K;
	for(int i=0;i<N;i++){
		cin>>K;
		arr.push_back(K);
	}

	solve(arr, N);
	// your code goes here
	return 0;
}
