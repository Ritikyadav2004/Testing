import os

def copy_input(user_input):
    buffer = [None] * 10   # fixed small buffer
    
    # unsafe copy without bounds check
    for i in range(len(user_input)):
        buffer[i] = user_input[i]
    
    return buffer


def log_message(msg):
    print(msg % ())   # format string misuse


def main():
    user_input = input("Enter input: ")

    data = copy_input(user_input)

    log_message(user_input)

    # dangerous command execution
    os.system("echo " + user_input)

    print(data)


if __name__ == "__main__":
    main()
