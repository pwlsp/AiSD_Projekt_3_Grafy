import os
import shutil
import sys

def generate_file(filename, n, saturation=70):
    with open(filename, 'w') as file:
        file.write(f"{n}\n{saturation}\n")

if __name__ == "__main__":

    if len(sys.argv) != 3:
        print("Usage: python generate.py <start_exponent> <end_exponent>")
        sys.exit(1)
    try:
        start_exponent = int(sys.argv[1])
        end_exponent = int(sys.argv[2])
    except ValueError as e:
        print(f"Error: {e}")
        print("Usage: python generate.py <start_exponent> <end_exponent>")
        sys.exit(1)

    # Directory where files will be saved
    directory = 'benchmark'

    # Clear the contents of the benchmark directory
    if os.path.exists(directory):
        shutil.rmtree(directory)
    os.makedirs(directory)

    max_n_length = len(str(2 ** end_exponent))  # Determine the length of the largest n
    for i in range(start_exponent, end_exponent + 1):
        n = 2 ** i
        filename = os.path.join(directory, f"generate.{n:0{max_n_length}}")
        generate_file(filename, n)
