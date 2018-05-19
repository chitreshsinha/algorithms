#https://www.geeksforgeeks.org/print-left-view-binary-tree/
#https://practice.geeksforgeeks.org/problem_submissions.php?pid=700174&isSolved=ALL&lang=ALL&user=Self

''' Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above. '''

'''
class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None
'''
# your task is to complete this function
# function should print the left view of the binary tree
# Note: You aren't required to print a new line after every test case
def printLeftView(root):
    q = []
    q.append(root)
    result = []
    while(1):
        nodeCount = len(q)
        if(nodeCount == 0):
            break
        flag = True
        
        while(nodeCount > 0):
            x = q.pop(0)
            if(flag):
                result.append(x.data)
                flag = False
            
            if(x.left!=None):
                q.append(x.left)
            if(x.right!=None):
                q.append(x.right)
            nodeCount -= 1
        
    print (result)

# Example:
# Input:
# 2
# 2
# 1 2 R 1 3 L
# 4
# 10 20 L 10 30 R 20 40 L 20 60 R

# Output:
# 1 3
# 10 20 40