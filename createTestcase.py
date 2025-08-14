import random
import string

# Global variables for number of testcases and length of array/string
NUM_TESTCASES = 25
ARRAY_LENGTH = 5

def generate_int_testcases(num_cases, case_length, min_val=1, max_val=50):
    """Generate testcases of random integer arrays."""
    if min_val > max_val:
        raise ValueError("Minimum value cannot be greater than maximum value")
    testcases = []
    for _ in range(num_cases):
        arr = [random.randint(min_val, max_val) for _ in range(case_length)]
        testcases.append(arr)
    return testcases

def generate_char_testcases(num_cases, case_length, charset=None, min_char=None, max_char=None):
    """Generate testcases of random character arrays."""
    if min_char is not None and max_char is not None:
        charset = ''.join(chr(i) for i in range(ord(min_char), ord(max_char)+1))
    if charset is None:
        charset = string.ascii_lowercase
    testcases = []
    for _ in range(num_cases):
        arr = [random.choice(charset) for _ in range(case_length)]
        testcases.append(arr)
    return testcases

def generate_string_testcases(num_cases, case_length, charset=None, min_char=None, max_char=None):
    """Generate testcases of random strings."""
    if min_char is not None and max_char is not None:
        charset = ''.join(chr(i) for i in range(ord(min_char), ord(max_char)+1))
    if charset is None:
        charset = string.ascii_lowercase
    testcases = []
    for _ in range(num_cases):
        s = ''.join(random.choice(charset) for _ in range(case_length))
        testcases.append(s)
    return testcases

def write_testcases_to_file(testcases, output_file="output.txt", output_as_list=False):
    with open(output_file, "w") as f:
        for case in testcases:
            if output_as_list:
                f.write(f"{case}\n")
            else:
                if isinstance(case, str):
                    f.write(f"{case}\n")
                else:
                    f.write(" ".join(map(str, case)) + "\n")

def main_int():
    params = {
        'num_cases': NUM_TESTCASES,
        'case_length': ARRAY_LENGTH,
        'min_val': 1,
        'max_val': 50
    }
    all_cases = generate_int_testcases(**params)
    output_as_list = False
    write_testcases_to_file(all_cases, output_file="output.txt", output_as_list=output_as_list)

def main_char():
    params = {
        'num_cases': NUM_TESTCASES,
        'case_length': ARRAY_LENGTH,
        'charset': None,  # or string.ascii_lowercase, string.ascii_uppercase, etc.
        'min_char': None,  # e.g. 'a'
        'max_char': None,  # e.g. 'z'
    }
    all_cases = generate_char_testcases(**params)
    output_as_list = False
    write_testcases_to_file(all_cases, output_file="output.txt", output_as_list=output_as_list)

def main_string():
    params = {
        'num_cases': NUM_TESTCASES,
        'case_length': ARRAY_LENGTH,
        'charset': None,  # or string.ascii_lowercase, string.ascii_uppercase, etc.
        'min_char': 'a',  # e.g. 'a'
        'max_char': 'e',  # e.g. 'z'
    }
    all_cases = generate_string_testcases(**params)
    output_as_list = False
    write_testcases_to_file(all_cases, output_file="output.txt", output_as_list=output_as_list)

if __name__ == "__main__":
    # Uncomment the one you want to run
    main_int()
    # main_char()
    # main_string()
