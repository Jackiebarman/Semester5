import math
import scipy.stats as st
import matplotlib.pyplot as plt 
i1=[]
no=[]
cu=[]


def printintermediateresults(u,sigma):
	print("Intermediate Result:")
	print("Mean(n*p): ",n*p)
	print("U = "+str(u))
	print("sigma = sqrt(n*p*(1-p))")
	print("sigma = "+str(sigma))
def fact(n): 
  
    res = 1
      
    for i in range(2, n+1): 
        res = res * i 
          
    return res 
def combine(n,r):
	return (fact(n) / (fact(r)* fact(n - r))) 
def calculate(u,sigma,n,p):
	for i in range(n):
		z1=((i-0.5)-u)/sigma
		z2=((i+0.5)-u)/sigma
		#print(str(i)+"  "+" p  "+str(st.norm.cdf(z2)-st.norm.cdf(z1)))
		#print(combine(n,i)*pow(p,i)*pow((1-p),n-i))
		i1.append(i)
		no.append(st.norm.cdf(z2)-st.norm.cdf(z1))
		cu.append(combine(n,i)*pow(p,i)*pow((1-p),n-i))
		print(str(i)+"      "+str(cu[i])+"     "+str(no[i]))

	plt.plot(i1, no, color='red', marker='o')
	plt.title('NORMAL APPROXIMATION', fontsize=14)
	plt.xlabel('x', fontsize=14)
	plt.ylabel('p', fontsize=14)
	plt.grid(True)
	plt.show()
	


def main():
	f=0
	file= open("181IT211_IT302_P9_Output_TC1.txt","w+")

	nn=(input("Enter n : "))
	for i in nn:
	    if i<'0' or i>'9':
		    f=1
		    print("Invalid Input!!!")
		    file.write("Invalid Input!!")
		    exit(0)
	n=int(nn)
	p=float(input("Enter p : "))
	if p>1 or p<0:
		print("invalid test case")
		file.write("Invalid Input!!")
		exit(0)

	q=1-p
	u=n*p
	u1=n*q;
	if u<=5 or u1<=5:
		print("We can not use the normal distribution as an approximation ")
		print("to solve this binomial problem because:")
		print("n*p :",n*p)
		print("n*(1-p) :",n*(1-p))
		print("Either n*p<5 or n*q<5")
		file.write("We can not use the normal distribution as an approximation to solve this binomial problem because Either n*p<5 or n*q<5")
		exit(0)
	sigma=math.sqrt(n*p*q)
	printintermediateresults(u,sigma)
	calculate(u,sigma,n)

main()