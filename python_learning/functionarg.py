import sys

def func1():
  print("func1")
  return


def func2():
  print("func2")
  return


if __name__ == "__main__": #used to mention a condition that if run directly the variable will hold the file name if imported it won't hold and it fails 
    if sys.argv[1] == "f1":
       func1()
    elif sys.argv[1] == "f2":
       func2()

#if run directly __name = main if imported name = script name that is imported 
