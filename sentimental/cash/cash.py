from cs50 import get_float

def calculate_change(cash):

  cents = round(cash * 100) # rouding the chash to the nearest benny

  coins = 0
  
  quarters = cents // 25
  cents = cents % 25
  coins += quarters

  # Calculate dimes (10¢)
  dimes = cents // 10
  cents = cents % 10
  coins += dimes

  # Calculate nickels (5¢)
  nickels = cents // 5
  cents = cents % 5
  coins += nickels

  # Remaining cents are pennies (1¢)
  pennies = cents
  coins += pennies

  return coins

def main():
    while True:
        try:
            cash = get_float("Change: ")
            if cash >= 0:
                break
            print("Please enter a positive number")
        except ValueError:
            print("Please enter a valid number")

    cents = calculate_change(cash)
    print(cents)


if __name__ == "__main__":
    main()
