def findAns(N):

	# Base case
	if (N <= 2):
		print ("NO")
		return
	
	# Sum of first numbers upto N
	value = (N * (N + 1)) // 2

	# Answer don't exist
	if(value & 1):
		print ("NO")
		return

	# To store the first set
	v1 = []

	# To store the second set
	v2 = []

	# When N is even
	if (not (N & 1)):
		turn = 1
		start = 1
		last = N
		
		while (start < last):
			if (turn):
				v1.append(start)
				v1.append(last)
				turn = 0		
			else:
				v2.append(start)
				v2.append(last)
				turn = 1

			# Increment start
			start += 1

			# Decrement last
			last -= 1
	
	# When N is odd
	else:

		# Required sum of 
		# the subset
		rem = value // 2

		# Boolean array to keep
		# track of used elements
		vis = [False] * (N + 1)

		for i in range (1, N + 1):
			vis[i] = False

		vis[0] = True

		# Iterate from N to 1
		for i in range (N , 0, -1):
			if (rem > i):
				v1.append(i)
				vis[i] = True
				rem -= i		 
			else:
				v1.append(rem)
				vis[rem] = True
				break
			
		# Assigning the unused
		# elements to second subset
		for i in range (1, N + 1):
			if (not vis[i]):
			    v2.append(i)
	print("YES")
	print(len(v1))
	for c in v1:
	    print(c, end = " ")
	print("")
	print(len(v2))
	for c in v2:
	    print(c, end = " ")

# Driver Code
if __name__ == "__main__":

	# Given Number
	N = int(input())

	# Function Call
	findAns(N)