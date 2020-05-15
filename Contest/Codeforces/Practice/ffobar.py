from fractions import *

m = [
  [0,1,0,0,0,1,2,3,2,1],  
  [4,0,0,3,2,0,9,2,2,3],  
  [1,0,0,1,0,0,0,0,0,0],
  [0,1,0,0,1,0,0,0,0,0],
  [0,1,0,0,0,0,0,2,0,0],
  [0,0,0,0,0,0,0,0,0,0],
  [0,0,0,0,3,0,0,0,0,0],
  [0,0,4,0,0,3,0,0,0,0],
  [0,0,0,0,0,10,2,0,0,0],
  [0,0,0,0,0,0,0,0,0,0],
]

m = [[1, 2, 3, 0, 0, 0], [4, 5, 6, 0, 0, 0], [7, 8, 9, 1, 0, 0], [0, 0, 0, 0, 1, 2], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0]]


################################################################
### functions from s/o to find lcm, multiply/invert a matrix ###
################################################################
def gcd(a, b):
    while b:      
        a, b = b, a % b
    return a
    
def lcm(a, b):
    return a * b // gcd(a, b)

def lcmm(l):
		return reduce(lambda x, y: lcm(x, y), l)
   
def matmult(a,b):
    zip_b = zip(*b)
    return [[sum(ele_a*ele_b for ele_a, ele_b in zip(row_a, col_b)) 
             for col_b in zip_b] for row_a in a]

def transposeMatrix(m):
    t = []
    for r in range(len(m)):
        tRow = []
        for c in range(len(m[r])):
            if c == r:
                tRow.append(m[r][c])
            else:
                tRow.append(m[c][r])
        t.append(tRow)
    return t

def getMatrixMinor(m,i,j):
    return [row[:j] + row[j+1:] for row in (m[:i]+m[i+1:])]

def getMatrixDeterminant(m):
    #base case for 2x2 matrix
    if len(m) == 2:
        return m[0][0]*m[1][1]-m[0][1]*m[1][0]

    determinant = 0
    for c in range(len(m)):
        determinant += ((-1)**c)*m[0][c]*getMatrixDeterminant(getMatrixMinor(m,0,c))
    return determinant

def getMatrixInverse(m):
    determinant = getMatrixDeterminant(m)
    #special case for 2x2 matrix:
    if len(m) == 2:
        return [[m[1][1]/determinant, -1*m[0][1]/determinant],
                [-1*m[1][0]/determinant, m[0][0]/determinant]]

    #find matrix of cofactors
    cofactors = []
    for r in range(len(m)):
        cofactorRow = []
        for c in range(len(m)):
            minor = getMatrixMinor(m,r,c)
            cofactorRow.append(((-1)**(r+c)) * getMatrixDeterminant(minor))
        cofactors.append(cofactorRow)
    cofactors = transposeMatrix(cofactors)
    for r in range(len(cofactors)):
        for c in range(len(cofactors)):
            cofactors[r][c] = cofactors[r][c]/determinant
    return cofactors


###################
### actual code ###
###################

def solution(m):
	if len(m) == 1:
		return [1,1]
	abso = []
	nabso = []
	#find absorbing states
	for ind, val in enumerate(m):
		if sum(val) == 0:
			abso.append(ind)
		else:
			nabso.append(ind)
	
	if len(abso) == 1:
		return [1,1]

	order = abso + nabso
	#prepare limiting matrix
	limM = []
	n = 0
	for i in abso:
		limM.append(m[i])
		limM[n][n] = 1
		n += 1
	
	for i in nabso:
		temp, temp2 = [], []
		for n in order:
			temp.append(m[i][n])
		for ind, val in enumerate(temp):
			temp2.append(Fraction(val, sum(temp) ))  
		limM.append(temp2)
	
	#creating matrix subsets
	I, R, Q = [], [], []

	for p in range(len(abso),len(limM)):
		R.append(limM[p][:len(abso)])
		Q.append(limM[p][len(abso):])
		
	for u in range(0, len(Q)):
		temp = [0] * len(Q)
		temp[u] = 1
		I.append(temp)

	IQ = []
	for p in range(0, len(I)):
		temp = []
		for o in range(0, len(I[0])):
			temp.append(I[p][o]-Q[p][o])
		IQ.append(temp)

	F = getMatrixInverse(IQ)
	
	FR = matmult(F,R)
	
	#fraction to list
	alm = []
	for i in FR[0]:
		alm.append([i.numerator, i.denominator])
	

	lcm1 = lcmm([i[1] for i in alm])
	
	# make fractions common denominator and return
	ende = [ (lcm1/i[1]) * i[0] for i in alm ]
	return ende + [lcm1]

