# Maze size 
import numpy as np
rows=int(input("Enter Rows: "))
cols=int(input("Enter Columns: "))
rarray = np.random.randint(2,size=(rows,cols))
f = open("maze.txt", "w")

print("\nThis is your randomly generated array\n\n", rarray)
print("\nThis is your randomly generated array\n\n", file=f)
print(rarray, file=f)


# A utility function to print solution matrix sol 
def printSolution( sol ): 
	
	for i in sol: 
		for j in i: 
			print(str(j) + " ", end ="")
			print(str(j)+ " ", end ="", file=f)
		print("")
		print("", file=f)

# A utility function to check if x, y is valid 
# index for rows * cols Maze 
def isSafe( maze, x, y ): 
	
	if x >= 0 and x < rows and y >= 0 and y < cols and maze[x][y] == 1: 
		return True
	
	return False

""" This function solves the Maze problem using Backtracking. 
	It mainly uses solveMazeUtil() to solve the problem. It 
	returns false if no path is possible, otherwise return 
	true and prints the path in the form of 1s.  """
def solveMaze( maze ): 
	
	# Creating a rows * cols 2-D list 
	sol = [ [ 0 for j in range(cols) ] for i in range(rows) ] 
	
	if solveMazeUtil(maze, 0, 0, sol) == False: 
		print("\nSolution doesn't exist")
		print("\nSolution doesn't exist", file=f) 
		return False
	if maze[0][0]==0:
	    print("\nNo Entry point, Solution doesn't exist")
	    print("\nNo Entry point, Solution doesn't exist", file=f)
	    return False
	
	print ("\nYour path out is given below\n")
	print ("\nYour path out is given below\n", file=f)
	printSolution( sol ) 
	return True
	
# A recursive utility function to solve Maze problem 
def solveMazeUtil(maze, x, y, sol): 
	
	# if (x, y is goal) return True 
	if x == rows - 1 and y == cols - 1: 
		sol[x][y] = 1
		return True
		
	# Check if maze[x][y] is valid 
	if isSafe(maze, x, y) == True: 
		# mark x, y as part of solution path 
		sol[x][y] = 1
		
		# Move forward in x direction 
		if solveMazeUtil(maze, x + 1, y, sol) == True: 
			return True
			
		# If moving in x direction doesn't give solution 
		# then Move down in y direction 
		if solveMazeUtil(maze, x, y + 1, sol) == True: 
			return True
		
		# If none of the above movements work then 
		# BACKTRACK: unmark x, y as part of solution path 
		sol[x][y] = 0
		return False

# Driver program to test above function 
if __name__ == "__main__": 
	# Initialising the maze 
	
	maze = rarray#[[1, 1, 1, 1, 1], 
			#[1, 0, 0, 0, 0], 
			#[1, 1, 1, 1, 1], 
			#[0, 1, 0, 0, 1],
			#[1, 1, 1, 0, 1]]#rarray 
	        
			
	solveMaze(maze) 

f.close()
