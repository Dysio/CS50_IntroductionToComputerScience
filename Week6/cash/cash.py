while True:
    try:
        cash = float(input("Change owed: "))
    except ValueError:
        continue
    if cash > 0:
        break

cash = int(cash * 100)

coins = [25, 10, 5, 1]

num_of_coins = 0
i = 0

while cash > 0:
    if cash - coins[i] >= 0:
        cash -= coins[i]
        num_of_coins += 1
    else:
        i += 1
    if i > len(coins) - 1:
        break
    
print(num_of_coins)
        
