def card_num_valid(card_num):
    card_num = int(card_num)
    if card_num < 1e12:
        return False

    sum1 = 0
    sum2 = 0
    i = 0
    n = card_num
    while n > 0:
        i = n % 10
        n = int(n / 100)
        sum1 += i

    n = int(card_num / 10)
    while n > 0:
        i = n % 10 * 2
        n = int(n / 100)
        if i >= 10:
            j = i % 10
            i = int(i / 10)
            i = i + j
        sum2 += i

    sum_tot = sum1 + sum2

    if sum_tot % 10 == 0:
        return True
    else:
        return False
        
        
def card_type(card_number):
    if int(card_number / 1e13) == 34 or int(card_number / 1e13) == 37:
        return "AMEX"
    elif int(card_number / 1e14) >= 51 and int(card_number / 1e14) <= 55:
        return "MASTERCARD"
    elif int(card_number / 1e12) == 4 or int(card_number / 1e15) == 4:
        return "VISA"
    else:
        return "INVALID"


def main():

    while True:
        try:
            credit_card = int(input("Number: "))
            if credit_card > 0:
                break
        except ValueError:
            continue

    if not card_num_valid(credit_card):
        print("INVALID\n")

    print(card_type(credit_card))


if __name__ == "__main__":
    main()
