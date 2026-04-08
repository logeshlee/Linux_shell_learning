class Myerror(Exception):
      def __init__(self, msg):
            super().__init__(msg)


x = int( input("enter any number:"))
try:
  if x not in range(1,5):
      raise Myerror("number is not in range 1-5")
except Exception as e:
  print(e)
