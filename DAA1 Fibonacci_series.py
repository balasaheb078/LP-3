# Python program to display the Fibonacci sequence

def recur_fibo(n):
    if n <= 1:
        return n
    else:
        return recur_fibo(n - 1) + recur_fibo(n - 2)

def fibonacci_iterative(n):
    series = []
    a, b = 0, 1
    for _ in range(n):
        series.append(a)
        a, b = b, a + b
    return series

def main():
    print("Fibonacci Sequence Generator")
    print("Choose a method:")
    print("1. Recursive")
    print("2. Iterative")

    choice = input("Enter 1 or 2: ")
    nterms = int(input("Enter the number of terms in the Fibonacci sequence: "))

    # Check if the number of terms is valid
    if nterms <= 0:
        print("Please enter a positive integer.")
    else:
        if choice == '1':
            print("Fibonacci sequence (Recursive):")
            for i in range(nterms):
                print(recur_fibo(i), end=' ')
        elif choice == '2':
            print("Fibonacci sequence (Iterative):")
            series = fibonacci_iterative(nterms)
            print(' '.join(map(str, series)))
        else:
            print("Invalid choice. Please enter 1 or 2.")
    
if __name__ == "__main__":
    main()