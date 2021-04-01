import os
path = 'C:\\Users\\prate\\Desktop\\Competitive-Programming\\Contest\\Codeforces\\'


# print(os.listdir(path))
for f in os.listdir(path):
   if f[0:3] == "gcr":
      lst = int(f[3:])
      os.rename(f, "Global Round " + str(lst))