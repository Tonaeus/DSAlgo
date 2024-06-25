def format_string(input_string):
    lowercase = input_string.lower()  
    with_dashes = lowercase.replace(" ", "-") 
    return lowercase, with_dashes

def main():
    user_input = input("Enter a problem title: ")
    lowercase_version, with_dashes_version = format_string(user_input)
    print(lowercase_version)
    print(with_dashes_version)

if __name__ == "__main__":
    main()