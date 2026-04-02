def my_decorator(my_func):
    def my_wrapper(): #arg can be used inside *arg etc..
         print("wrapper start")
         my_func() #should be called 
         print("wrapper end")
         return 10
    return my_wrapper 

@my_decorator
def hello():
  print("hi")

result = hello()
print(result)


#first outer function return object of function and then inner function return the result of called func
#so first we call the wrapper func logic and then it calls hello and prints hi and then prints wrapper end and return the 


