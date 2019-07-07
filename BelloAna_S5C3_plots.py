import numpy as np
import matplotlib.pylab as plt

datos=np.genfromtxt("datosresorte.txt")
t=datos[:,0]
x=datos[:,1]
v=datos[:,2]

plt.figure()
plt.plot(t,x, label='vel',marker='1')
#plt.plot(t,v, label='pos')
plt.xlabel("t")
plt.ylabel("x")
plt.legend()
plt.title("Spring and mass")
plt.savefig("BelloAnaResorte.pdf")