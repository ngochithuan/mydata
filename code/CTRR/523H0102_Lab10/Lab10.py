class Node(object):
    def __init__(self,data=None):
        self.left = None
        self.right = None
        self.data = data
        
root1 = Node(2)

temp1 = Node(5)

temp2 = Node(11)

temp3 = Node(4)

temp4 = Node(2)

temp5 = Node(6)
temp5.left = temp1
temp5.right = temp2

temp6 = Node(9)
temp6.left = temp3

temp7 = Node(7)
temp7.left = temp4
temp7.right = temp5

temp8 = Node(5)
temp8.right = temp6

root1.left = temp7
root1.right = temp8

def NLR(node):
    if node != None:
        print(node.data)
        NLR(node.left)
        NLR(node.right)
        
def LNR(node):
    if node != None:
        LNR(node.left)
        print(node.data)
        LNR(node.right)
        
def LRN(node):
    if node != None:
        LRN(node.left)
        LRN(node.right)
        print(node.data)

LNR(root1)


def getLevel(root, target, level):
    if root is None:
        return None

    if root.data == target:
        return level

    leftLevel = getLevel(root.left, target, level + 1)
    if leftLevel != -1:
        return leftLevel

    return getLevel(root.right, target, level + 1)

def breadthFirstSearch(A,Data):
    
    return

def depthFirstSearch(A,Data):
    return
