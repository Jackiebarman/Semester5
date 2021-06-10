import math
import numpy as np
import scipy.stats as st
import matplotlib.pyplot as plt 
x=[]
y=[]

def main():
	aa=(input("Enter A : "))
	bb=(input("Enter B : "))
	cc=(input("Enter C : "))

	f=0
	file= open("181IT211_IT302_P10_Output_TC1.txt","w+")
	for i in aa:
		if (i<'0' or i>'9') and i!='.':
			f=1
			print("Invalid Input!!!")
			file.write("Invalid Input!!")
			exit(0)
	for i in bb:
		if (i<'0' or i>'9') and i!='.':
			f=1
			print("Invalid Input!!!")
			file.write("Invalid Input!!")
			exit(0)
	for i in cc:
		if (i<'0' or i>'9') and i!='.':
			f=1
			print("Invalid Input!!!")
			file.write("Invalid Input!!")
			exit(0)	    	    
	a=float(aa)
	b=float(bb)
	c=float(cc)
	if c<0 or c>100:
		print("invalid test case")
		file.write("Invalid Input!!")
		exit(0)
	Z=st.norm.ppf(c*0.01)
	print("Intermediate Result:")
	print("Z-Score :",Z)
	print("Final Result:")
	res=a+(Z*b)
	strres=str(res)
	# file.write("Final Result:"+strres)
	print(res)
	
	yy=res
	tmp=Z
	xvals = np.arange(0, a*2, 0.001)
	yvals = st.norm.pdf(xvals, a, b)
	fig, graph = plt.subplots(figsize=(9, 6))
	shade_x = np.arange(0, res, 0.001)
	shade_y = st.norm.pdf(shade_x, a, b)
	graph.fill_between(shade_x, shade_y)
	graph.plot(xvals, yvals)
	graph.set_title('Normal Distribution', size=15)
	graph.set_ylabel('Probability density', size=15)
	graph.set_xlabel('X', size=15)

	plt.show()
	file.write("Invalid Input!!")
	# for i in range(1,30):
	# 	x.append(tmp)
	# 	t1=(-0.5)*pow((tmp-a)/b,2)
	# 	t2=math.exp(t1)
	# 	ex=1/(b*(math.sqrt(2*math.pi)))
	# 	t3=t2*ex
	# 	tmp=tmp-b
	# 	y.append(t3)



	# # while(yy>=0):
	# # 	x.append(Z)
	# # 	yy=a+(Z*b)
	# # 	y.append(yy)
	# # 	Z=Z-1
	# plt.plot(x, y, color='red', marker='o')
	# plt.title('Graph', fontsize=14)
	# plt.xlabel('x', fontsize=14)
	# plt.ylabel('p', fontsize=14)
	# plt.grid(True)
	# plt.show()	

main()