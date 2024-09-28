#normal way of generating a factorial

def generate_factorial(num):
    for i in range(1, num):
        num = num * i

    return num


print(generate_factorial(6))


#generating a factorial using recursion

def recursive_factorial(num):
    if num == 1 : return 1

    num =  num * recursive_factorial(num -1)

    return num


print(recursive_factorial(6))