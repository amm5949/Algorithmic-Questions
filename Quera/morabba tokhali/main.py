import random 
a = int(input())

b = int(input())

ekhtelaf = abs(a - b)

if b >= a:
    print("Wrong order!")
elif ekhtelaf % 2 == 1:
    print("Wrong difference!")

else:
    # ekhtelaf = a - b
    faseleh_az_do_var = int(ekhtelaf / 2)
    for i in range(a):
        for j in range(a):
            faseleh_az_tah_dar_satr = a - i
            faseleh_az_tah_dar_sotoon = a - j
            if (i >= faseleh_az_do_var and faseleh_az_tah_dar_satr > faseleh_az_do_var) and (j >= faseleh_az_do_var and faseleh_az_tah_dar_sotoon > faseleh_az_do_var):
                print(" ", end="")
            else:
                print("*", end="")
            print(" ", end="")
        print()