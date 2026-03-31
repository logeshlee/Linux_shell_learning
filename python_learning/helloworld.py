print('python')
print('hello world')

print("enter a number:")
num = input()

print(num ,"is the entered number")
print("enter 2 numbers: ")
#num1,num2 = input().strip() #strip in same line value (44) used to split it 
num1,num2 = input().split() # split is used to get in single line val1 val2
print(num1,num2 ,"is the entered number")
