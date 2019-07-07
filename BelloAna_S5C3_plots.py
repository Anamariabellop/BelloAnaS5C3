import numpy as np
import matplotlib.pylab as plt

datos=np.genfromtxt("datosresorte.txt")
t=datos[:,0]
x=datos[:,1]
v=datos[:,2]

plt.figure()
plt.plot(t,x,color='purple' ,label='posicion')
#plt.plot(t,v, label='vel')
plt.xlabel("t")
plt.ylabel("x")
#plt.ylim(-0.15,0.15)
plt.legend()
plt.title("Posicion en funcion de t")
plt.savefig("BelloAnaResorte.pdf")