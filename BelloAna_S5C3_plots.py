import numpy as np
import matplotlib.pylab as plt

datos=np.genfromtxt("datosresorte.txt")
t=datos[:,0]
x=datos[:,1]
v=datos[:,2]

plt.figure()

plt.subplot(2,1,1)
plt.plot(t,x,color='purple' ,label='posicion')
plt.xlabel("t")
plt.ylabel("x")
plt.legend()
plt.title("Posicion en funcion de t")

plt.subplot(2,1,2)
plt.plot(t,v,color='c' ,label='vel')
plt.xlabel("t")
plt.ylabel("v")
plt.legend()
plt.title("Posicion en funcion de t")

plt.savefig("BelloAnaResorte.pdf")