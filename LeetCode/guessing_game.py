import random


def hint():
    numbers = range(51)
    guess = random.choice(numbers)

    over = 0
    limit = 10
    user = ''
    out_of_guesses = False
    points = 10
    total_scores = points

    while user != guess and not out_of_guesses:
        if over < limit:
            print(f'You have {points} chances left')
            user = int(input('Guess a number from the range of 0 - 50\n> '))
            points -= 1
            over += 1
        else:
            out_of_guesses = True

        # To give the player a hint
        if user > guess:
            print("")
            print("The number is lower than what you guessed, try again")
        elif user < guess:
            print("")
            print("The number is greater than what you guessed, try again")

    # if the player is out of guess
    if out_of_guesses:
        print('You have 0 score, You lose!.')
    else:  # The else statement is when the player guess right
        print("\n")
        print('You get the number correctly, You win!.')
        print(f'It took you {over} guesses and your total scores is {points + 1} / {total_scores}')  # This is to print the number of guesses before getting it right,and also print out the player's scores


# calling the function
hint()

