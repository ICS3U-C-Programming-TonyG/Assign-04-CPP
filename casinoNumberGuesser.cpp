// Copyright (c) 2020 Tony G All rights reserved.
//
// Created by: Tony G

// Created on: 2025-03-1

// Casino number guessing game

#include <iostream>
#include <random>
#include <string>

int main() {
    // This program is a casino number guessing game

    std::string name;
    std::string response;
    std::string playResponse;
    std::string confirmation;
    int chips;
    int cost;
    int reward;
    int luck;
    int level;
    int randomNumber;
    std::string guessInput;  // Use a string to validate input
    int guess;

    // Start of the program
    std::cout << "Hello, what is your name?" << std::endl;
    std::cin >> name;

    while (true) {
        std::cout << "Alright, " << name
                  << ", do you have money to spend in the casino (Y/N)?"
                  << std::endl;
        std::cin >> response;

        if (response == "N" || response == "n" || response == "No" ||
            response == "no" || response == "NO") {
            std::cout << "Broke bum. Luckily, I am feeling generous, so I am "
                         "willing to lend you 100 chips. However, I am "
                         "expecting repayment, with interest."
                      << std::endl;
        } else if (response == "Y" || response == "y" || response == "Yes" ||
                   response == "yes" || response == "YES") {
            while (true) {
                std::cout << "Are you sure?" << std::endl;
                std::cin >> confirmation;

                if (confirmation == "N" || confirmation == "n" ||
                    confirmation == "No" || confirmation == "no" ||
                    confirmation == "NO") {
                    std::cout << "Broke bum. Luckily, I am generous, so "
                                 "I am willing to lend you 100 chips. However, "
                                 "I am expecting repayment, with interest."
                              << std::endl;
                    break;  // Exit the "Are you sure?" loop
                } else if (confirmation == "Y" || confirmation == "y" ||
                           confirmation == "Yes" || confirmation == "yes" ||
                           confirmation == "YES") {
                    std::cout << "Alright, let's proceed." << std::endl;
                    break;  // Exit the "Are you sure?" loop
                } else {
                    std::cout << "Invalid response. Please answer with Y/N."
                              << std::endl;
                }
            }
        } else {
            std::cout << "Invalid response. Please answer with Y/N."
                      << std::endl;
            continue;  // Go back to asking about money
        }

        // Game logic starts here
        while (true) {
            std::cout << "Do you want to play 'guess the number' (Y/N)?"
                      << std::endl;
            std::cin >> playResponse;

            if (playResponse == "Y" || playResponse == "y" ||
                playResponse == "Yes" || playResponse == "yes" ||
                playResponse == "YES") {
                // Initialize game variables
                chips = 100;
                cost = 10;
                reward = 50;
                luck = 10;
                level = 1;

                // Display game details
                std::cout << "You have " << chips << " chips." << std::endl;
                std::cout << "Entry fee: " << cost << " chips." << std::endl;
                std::cout << "Reward: " << reward << " chips." << std::endl;
                std::cout << "Chances of winning: 1 in " << luck << "."
                          << std::endl;

                // Generate random number using <random>
                std::random_device rseed;
                std::mt19937 rgen(rseed());
                std::uniform_int_distribution<int> idist(1, luck);
                randomNumber = idist(rgen);

                while (true) {
                    std::cout << "Please guess a number between 1 and " << luck
                              << std::endl;
                    std::cin >> guessInput;

                    try {
                        // Convert input to integer
                        guess = std::stoi(guessInput);

                        chips -= cost;

                        if (chips < cost) {
                            std::cout << "You are out of chips. The game is "
                                         "over."
                                      << std::endl;
                            break;  // Exit the guessing game loop
                        }

                        if (guess == randomNumber) {
                            std::cout << "I can't believe you won, GET OUT!!!"
                                      << std::endl;
                            chips += reward;
                            return 0;  // End the program when the user wins
                        } else {
                            std::cout << "That was not it, try again."
                                      << std::endl;
                        }
                    } catch (std::invalid_argument) {
                        std::cout << "Invalid input. Enter a valid number."
                                  << std::endl;
                        continue;  // Prompt the user again
                    }
                }

                if (chips < cost) {
                    break;  // Exit the "Do you want to play" loop
                }
            } else if (playResponse == "N" || playResponse == "n" ||
                       playResponse == "No" || playResponse == "no" ||
                       playResponse == "NO") {
                while (true) {
                    std::cout << "Are you sure?" << std::endl;
                    std::cin >> confirmation;

                    if (confirmation == "Y" || confirmation == "y" ||
                        confirmation == "Yes" || confirmation == "yes" ||
                        confirmation == "YES") {
                        break;  // Exit the "Are you sure?" loop and continue
                    } else if (confirmation == "N" || confirmation == "n" ||
                               confirmation == "No" || confirmation == "no" ||
                               confirmation == "NO") {
                        // Keep looping until the user confirms with "Yes"
                    } else {
                        std::cout << "Invalid response. Please answer with Y/N."
                                  << std::endl;
                    }
                }
            } else {
                std::cout << "Invalid response. Please answer with Y/N."
                          << std::endl;
            }
        }

        if (chips < cost) {
            std::cout << "You have no chips left. Exiting the program."
                      << std::endl;
            break;  // Exit the outermost loop to end the program
        }
    }
}
