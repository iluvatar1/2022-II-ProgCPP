import numpy as np
import matplotlib.pyplot as plt
N, pi, reldiff = np.loadtxt("pivals.txt", unpack=True)
fig, ax = plt.subplots()
ax.loglog(N, reldiff, '-o')
ax.set_xlabel(f"Iter")
ax.set_ylabel(f"Relative difference")
plt.show()
fig.savefig("pivals.pdf", bbox_inches='tight')
