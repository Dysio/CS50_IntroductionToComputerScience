def get_text():
    while True:
        text = input("Test: ")
        if text != "":
            return text
            
        
def calculate_index(text):
    num_of_letters = 0
    num_of_words = 1
    num_of_sentences = 0
    
    for letter in text:
        if ord(letter) >= 65 and ord(letter) <= 90:
            num_of_letters += 1
        elif ord(letter) >= 97 and ord(letter) <= 122:
            num_of_letters += 1
        elif letter == " ":
            num_of_words += 1
        elif letter in ('.', '!', '?'):
            num_of_sentences += 1
        else:
            continue
    
    col_liau_index = round(0.0588 * (num_of_letters * 100 / num_of_words) - 0.296 * (num_of_sentences * 100 / num_of_words) - 15.8)
    
    if col_liau_index < 1:
        print("Before Grade 1")
    elif col_liau_index < 16:
        print(f"Grade {col_liau_index}")
    else:
        print("Grade 16+")
        
        
def main():
    text = get_text()
    calculate_index(text)
    
    
if __name__ == "__main__":
    main()
