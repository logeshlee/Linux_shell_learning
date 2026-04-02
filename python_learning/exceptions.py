list1 = locals()['__builtins__']

for i in dir(list1):
   if "Error" in i:
        print(i)
