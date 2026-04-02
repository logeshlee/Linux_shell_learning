def read_lin(file_1):
    with open(file_1,"r") as f:
         for line in f:
            if "wifi" in line:
                yield line



file_1 = input("enter the filename: ")
for line in read_lin(file_1):
   print(line)
