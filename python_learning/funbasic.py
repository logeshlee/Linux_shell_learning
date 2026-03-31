def my_fun():
    return 5
def my_fun1(x, y=50):
	print("default arg x y:",x,y)
	return "success"
def my_fun2(x,y):
	print("keyname arg x y:",x,y)
	return "ok"
def my_fun3(x,y):
	print("positional arg x y:",x,y)
	return "nein"
def my_fun4(*x,**y):
	print("arbitary single value x keywords y:",x,y)
	return "ja"

print(my_fun())
print(my_fun1(2))
print(my_fun2(y=40,x=30))
print(my_fun3("right",45))
print(my_fun3(45,"left"))
print(my_fun4(1,2,3,4,first="geeks",second="for"))

c2 = lambda x: x*x*x
print("assign lambda and call:")
print(c2(4))

print("all arg as in fun is supported")
