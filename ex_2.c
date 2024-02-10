// (838911013, Spring 2023, Assignment #2, Roie Amsalem, 322535436, roieams)
// wherever there are 'ugly' brackets it is because the 'submit' software required them.
#include <stdio.h>

int main() {
    // defining basic integers for the main menu loop
    char answer, cleanBuffer,bufferFour;
    int trueWhile = 1, COUNT_ENTER = 0;
    // creating the main menu loop, the user will come back here unless he answers 0
    while (trueWhile == 1) {
        printf("Choose an option:\n0. Exit\n1. Hourglass\n2. Reverse bits\n3. Reverse digits\n4. Convert to Decimal\n5. Base64 to Decimal\n6. Swap bits\n");
        //cleaning the buffer. in exercise 5 the buffer is cleaned by itself through the loop.
        if (COUNT_ENTER > 0 && answer != '5' && answer != '4') {
            scanf("%c", &cleanBuffer);
        }
        scanf("%c", &answer);
        scanf("%c", &cleanBuffer);
        // negating all options that are not between '0' and '6'
        while (answer < '0' || answer > '6') {
            printf("Invalid option\n");
            printf("Choose an option:\n0. Exit\n1. Hourglass\n2. Reverse bits\n3. Reverse digits\n4. Convert to Decimal\n5. Base64 to Decimal\n6. Swap bits\n");
            scanf("%c", &answer);
        }
        //ending program for 0.Exit
        if (answer == '0') {
            break;
        }
        if (answer == '1') {
            COUNT_ENTER++;
            // Declaring variables.
            int size, flag, modulu = 2, sizeDefine = 1, multiplier = 3;
            // user enters size
            printf("Enter size:\n");
            scanf("%d", &size);
            // checking size is valid.
            if (size < 3) {
                printf("Invalid Parameters\n");
                continue;
            }
            // user enters flag
            printf("Enter flag:\n");
            scanf("%d", &flag);
            // checking flag is valid.
            if (flag != 0 && flag != 1) {
                printf("Invalid Parameters\n");
                continue;
            }
            // for loop to make the "roof" of the hourglass
            for (int i = 0; i < size; i++) {
                printf("-");
            }
            // Going down a line after the roof
            printf("\n");
            // a nested for loop in relation to size.
            for (int i = 0; i < size; i++) {
                for (int k = 0; k < size; k++) {
                    // Every time k == i in every loop we print 1 '\'. We also check that size is even.
                    if (k == i && (k != size / modulu || size % modulu == 0)) {
                        printf("\\");
                        // checking if k = size - i - 1, - 1 because k and i reach up to size - 1.
                    } else if (k == size - i - sizeDefine && (k != size / modulu || size % modulu == 0)) {
                        printf("/");
                        // checking that k == i and that we are in the middle and that size is odd, thus printing the desired x shape.
                    } else if (k == size / modulu && i == size / modulu && size % modulu != 0) {
                        printf("X");
                        /* Printing the sand in the hourglass. flag == 1. k >= i will mostly be true and just make sure we are in the upper section.
                         * k <= size - i - 1 will tell us exactly where to print the dots and how many.
                         * important to notice this formula also returns k = 2, however at that location we already print 'x' so dots won't be printed. */
                    } else if (flag == 1 && k >= i && k <= size - i - sizeDefine) {
                        printf(".");
                    } else if (flag == 0 && k <= i && k >= size - i - sizeDefine) {
                        printf(".");
                        /* making sure we don't print extra ' ' with 2 checks.
                         * first one is: if we aren't at the bottom don't print up to size. */
                    } else if (k == i && (k != size - sizeDefine)) {
                        break;
                        // second one: a formula, for all hourglasses this works canceling extra ' ' with specific cases for the middle if size is odd or even.
                    } else if (k - i == size - (multiplier * i) + i - sizeDefine) {
                        break;
                        // the statement to print. the opposite of 1 or 2 itself resulting in the correct amount of ' '.
                    } else if (((k != i) && (k != size - sizeDefine)) || (k - i == (size - (multiplier * i) + i - sizeDefine))) {
                        // splitting to odd/even.
                        if (size % modulu != 0) {
                            // if we are in the middle and odd DON'T print extra ' '.
                            if (i == size / modulu && k <= i) {
                                printf(" ");
                            } else if (i != size / modulu) {
                                printf(" ");
                            }
                        }
                        if (size % modulu == 0) {
                            // same like before but for size = even. the middle part is 2 lines now.
                            if ((i == size / modulu && k <= i) || (i == (size / modulu - 1) && k <= (i + 1))) {
                                printf(" ");
                            } else if (i != size / modulu && i != (size / modulu - 1)) {
                                printf(" ");
                            }
                        }
                    }
                }   // outside of the nested loop, going down 1 line each loop.
                printf("\n");
            }
            for (int i = 0; i < size; i++) {
                printf("-");
            }
            printf("\n");
        }
        if (answer == '2') {
            COUNT_ENTER++;
            //declaring variables. num for input reversed_num for reversed output, index for the loop.
            int num, reversed_num = 0, index = 0;
            const int max_index = 32;
            printf("Enter a number:\n");
            scanf(" %d", &num);
            // a while loop for an int sized number (32Bit).
            while (index < max_index) {
                //Left shifting reversed_num to make room for the first digit
                reversed_num <<= 1;
                //using num & 1 to receive the rightmost bit of num and inserting it to reversed_num using bitwise or.
                reversed_num = reversed_num | (num & 1);
                num >>= 1;
                ++index;
            }
            printf("The reversed number is %d\n", reversed_num);
        }
        if (answer == '3') {
            COUNT_ENTER++;
            int num2, count = 0, limit = 0;
            long long int indexNum,num3, flippedNum = 0, divider = 1, multiplier = 1;
            printf("Enter a number:\n");
            scanf("%d", &num2);
            num3 = num2;
            // entering a loop to count the number of digits in num2 and getting our divider variable to the right size.
            while (num2 > limit) {
                num2 = num2 / 10;
                count++;
                divider *= 10;
            }
            // dividing divider by 10, when 1 <= num2 < 10 divider is getting multiplied by 10 again when he doesn't need to, so we make up for that.
            divider /= 10;
            // a for loop running count-times
            for (int i = 1; i <= count; i++) {
                // finding the left-most number in num3
                indexNum = num3 / divider;
                // removing the leftmost number from num3
                num3 = num3 - indexNum * divider;
                // adding the left-most number in num3 to be the right-most number in flipped_num
                flippedNum = flippedNum + indexNum * multiplier;
                divider /= 10;
                multiplier *= 10;
            }
            printf("The reversed number is %lld\n", flippedNum);
        }
        if (answer == '4') {
            COUNT_ENTER++;
            int base, decimalNum = 0, remainder, count = 0, counter = 0, count2 = 0, newBase, countDigit = 0, number2;
            int number, asciiConvert = 48, limit = 0;
            char checkNum = 0;
            const int max_base = 9, min_base = 2;
            long long int divider = 1, multiplier = 1, reverseNumber = 0, number3, indexNum;
            printf("Enter base:\n");
            scanf("%d", &base);
            newBase = base;
            //making sure the base is between 2 and 9, if it isn't user gets sent to the main menu
            if (base > max_base || base < min_base) {
                printf("Invalid Base\n");
                continue;
            }
            printf("Enter a number:\n");
            scanf("%d", &number);
            number2 = number;
            // using the formula to reverse the number from the previous question in order to check the digits from left to right.
            while (number2 > limit) {
                number2 = number2 / 10;
                countDigit++;
                divider *= 10;
            }
            divider /= 10;
            number3 = number;
            for (int i = 1; i <= countDigit; i++) {
                indexNum = number3 / divider;
                number3 = number3 - indexNum * divider;
                reverseNumber = reverseNumber + indexNum * multiplier;
                divider /= 10;
                multiplier *= 10;
            }
            //a while loop to count number's digits
            // using number in this loop because when reversing 1000 in any base counter doesn't work. we count according to number and check in reverse.
            number3 = number;
            while (number3 > limit) {
                ++counter;
                checkNum = reverseNumber % 10;
                //checking number's rightmost digit to see if it's in the base's range
                if ((checkNum >= base) || (checkNum < limit)) {
                    // ascii convert is used to print the invalid character in %c instead of %d.
                    checkNum = checkNum + asciiConvert;
                    printf("Invalid character %c in base %d\n", checkNum, base);
                    break;
                } else {
                    ++count2;
                }
                //dividing number1 by 10 and continuing to count.
                reverseNumber /= 10;
                number3 /= 10;
            }
            //a while loop to calculate the decimal number
            while (count < counter && count2 == counter) {
                //finding the rightmost digit of number, aka the remainder
                remainder = number % 10;
                // for 1 number we just store it and print.
                if (count < 1) {
                    decimalNum = remainder;
                    // for the second number we multiply by base
                } else if (count == 1) {
                    decimalNum = decimalNum + remainder * base;
                    // for every number after we use newBase for powers.
                } else if (count > 1) {
                    base = base * newBase;
                    decimalNum = decimalNum + remainder * base;
                }
                number /= 10;
                count++;

            }
            //using count2 to check whether the second loop happened, if not we don't print and go back to the main menu.
            if (count2 == counter) {
                printf("The converted number is %d\n", decimalNum);
            }
            //using bufferFour to clean the buffer in case the user inserted '1 2 3    4  5 6' for example.
            scanf("%c", &bufferFour);
            if (bufferFour == ' ') {
                scanf("%c", &bufferFour);
                if (bufferFour == '\n') {
                    continue;
                } else {
                    while (bufferFour != '\n'){
                        scanf("%c", &bufferFour);
                    }
                }
            }
        }
        if (answer == '5') {
            int holder, count = 0, anti_count = 0;
            const int base = 64, CAPITAL_DIFF = 65, SMALL_DIFF = 71, NUM_DIFF = 4, PLUS_DIFF = 19, SLASH_DIFF = 16;
            char num64;
            // a long long int for the result number to cover options where the number in num64 is > than int size.
            long long int decimalNum = 0;
            printf("Enter a number:\n");
            scanf("%c", &num64);
            // a while loop that ends when num64 is enter key.
            while (num64 != '\n') {
                // if else statements to determine which symbol num64 received, and whether it's valid or not.
                if (num64 >= 'A' && num64 <= 'Z') {
                    holder = num64 - CAPITAL_DIFF;
                } else if (num64 >= 'a' && num64 <= 'z') {
                    holder = num64 - SMALL_DIFF;
                } else if ('0'<= num64 && num64 <= '9') {
                    holder = num64 + NUM_DIFF;
                } else if (num64 == '+') {
                    holder = num64 + PLUS_DIFF;
                } else if (num64 == '/') {
                    holder = num64 + SLASH_DIFF;
                } else if (num64 >= '\0' && num64 <= '*') {
                    printf("invalid character %c in base 64\n", num64);
                    // adding anti count in all invalid options to make sure we dont print the decimal if one of the symbols was invalid
                    anti_count++;
                    break;
                } else if (num64 >= ',' && num64 <= '.') {
                    printf("invalid character %c in base 64\n", num64);
                    anti_count++;
                    break;
                } else if (num64 >= ':' && num64 <= '@') {
                    printf("invalid character %c in base 64\n", num64);
                    anti_count++;
                    break;
                } else if (num64 >= '[' && num64 < 'a') {
                    printf("invalid character %c in base 64\n", num64);
                    anti_count++;
                    break;
                } else if (num64 >= '{') {
                    printf("invalid character %c in base 64\n", num64);
                    anti_count++;
                    break;
                }
                // 2 if statements to "build" the number. first symbol is just kept. afterward * 64 + any N symbol.
                if (count >= 1) {
                    decimalNum = decimalNum * base + holder;
                } else if (count < 1) {
                    decimalNum = holder;
                }
                // scanf again to move to the next symbol
                scanf("%c", &num64);
                count++;
            }
            //out of the loop, making sure all symbols were valid with anti_count.
            if (anti_count == 0 && count > 0) {
                printf("The converted number is %lld\n", decimalNum);
            }
        }
        if (answer == '6') {
            COUNT_ENTER++;
            unsigned int num, num2, num3;
            int index1, index2, count = 0;
            const char MIN_INDEX = 0, MAX_INDEX = 31;
            printf("Enter a number:\n");
            scanf("%u", &num);
            // num2 and num3 equal to num so we can use them later to get the bits we want.
            num2 = num;
            num3 = num;
            printf("Enter indexes:\n");
            scanf("%d %d", &index1, &index2);
            // checking if the indexes received are valid. if not return to main menu.
            if (index1 < MIN_INDEX || index2 < MIN_INDEX || index1 > MAX_INDEX || index2 > MAX_INDEX) {
                printf("Invalid indexes\n");
                continue;
            }
            // right shifting num2 and 3 index 1 and 2 places accordingly.
            num2 >>= index1;
            num3 >>= index2;
            // checking if the bits are both 1 or 0 in num2 and num3 positions index1 and 2. If so there is no switch that is needed to be done.
            if ((num2 & num3) == 1 || (num2 | num3) == 0) {
                printf("The result is %u\n", num);
                count++;
                // another if statement so if the bits are 1 and 0 or 0 and 1 we swap them.
            } else if ((((num2 & 1) == 0) && ((num3 & 1) == 1)) || (((num2 & 1) == 1) && ((num3 & 1) == 0))) {
                // first we left shift 1 index1 and index2 times.
                // then we Xor our number with the 1 in index1 position and the 1 in index2 position, thus not interrupting the number's value in any other position.
                num = num ^ (1 << index1);
                num = num ^ (1 << index2);
            }
            // using count to make sure we didn't already print the number.
            if (count == 0) {
                printf("The result is %u\n", num);
            }
        }
    }
}