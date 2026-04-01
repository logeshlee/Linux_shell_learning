def fun_out():
    print("im inside outer function")
    def fun_in():
                print("inner function called")
                return
    print("outside function call")
    fun_in()
    return

fun_out()


