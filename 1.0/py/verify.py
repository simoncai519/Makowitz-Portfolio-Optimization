import pandas as pd
import numpy as np

data = pd.read_csv('../asset_returns.csv',header = None)
train = data.iloc[:100,:]
valid = data.iloc[100:112,:]

mean = train.mean()
cov = train.cov()

cov_pi = np.linalg.inv(cov)

tag_mu = mean.dot(cov_pi.dot(mean)) / cov_pi.dot(mean).sum()

weight = cov_pi.dot(mean) /mean.dot(cov_pi.dot(mean))*(0.02/250)

# check for solve algo

Q = np.zeros([85,85])
for i in range(Q.shape[0]-2):
	Q[i] = np.append(
		np.append(cov[i], -mean[i])
		,(-1))

newrow = list(-mean)
newrow.extend([0,0])
Q[83] = np.array(newrow)

newrow = [-1]*(Q.shape[0]-2)
newrow.extend([0,0])
Q[84] = np.array(newrow)

b = [0]*83+[-0.1,-1]
b = np.array(b)

x = (np.linalg.inv(Q))\
	.dot(b)

