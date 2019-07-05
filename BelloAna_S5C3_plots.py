import numpy as np
import matplotlib.pylab as plt

datos=np.genfromtxt("datosresorte.dat")
t=datos[:,0]
x=datos[:,1]

plt.figure()
plt.plot(t,x, label='x(t)')
plt.xlabel("t")
plt.ylabel("x")
plt.ylim(-0.2,2)
plt.title("Spring and mass")
plt.legend()
plt.savefig("BelloAnaResorte.pdf")