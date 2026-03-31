i = [1,2,3,4]

print("use case in list")
for ind in i:
 print(ind)
print("use case in range")
for ind in range(1,3):
 print(ind)
for ind in range(0,0):
 print(ind)

#use with dictonary
print("use case in dict")
d = dict({'x':123,'y':354})
for ind in d:
 print(d[ind])

print("use case in set")
s = {1,2,3,4}
for ind in s:
 print(ind)

t = (1,2,3)
print("use case in tuple")
for ind in t:
 print(ind)
