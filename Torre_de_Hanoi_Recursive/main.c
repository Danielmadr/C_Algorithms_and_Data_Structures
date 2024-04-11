/**
 * @file hanoi_tower.c
 * @brief Recursive solution for the Tower of Hanoi problem.
 *
 * This program solves the Tower of Hanoi problem using recursion.
 * The user inputs the number of discs, and the program displays the sequence of movements.
 *
 * @warning This code is for demonstration purposes only and should not be used in production.
 * @todo Implement error handling and input validation.
 * @bug No known bugs at the moment.
 */


#include <stdio.h>

/**
 * @brief Moves the discs between the poles.
 * @param quantityOfDiscs Number of discs.
 * @param initialPole Initial pole (A).
 * @param auxPole Auxiliary pole (B).
 * @param finalPole Final pole (C).
 */

void solveHanoiTowers(int quantityOfDiscs, char initialPole, char auxPole, char finalPole) {
    if (quantityOfDiscs == 1) {
        printf("\tMover disco 1 da coluna %c para coluna %c\n", initialPole, finalPole);
        return; }
    solveHanoiTowers(quantityOfDiscs-1, initialPole, finalPole, auxPole);
    printf("\tMover disco %d da coluna %c para coluna %c\n", quantityOfDiscs, initialPole, finalPole);
    solveHanoiTowers(quantityOfDiscs-1, auxPole, initialPole, finalPole); }


int main() {
    int quantityOfDiscs;

    printf("Qual a Quantidade de Discos na torre?\n");
    scanf ("%d", &quantityOfDiscs);

    printf("\nA sequencia de movimentos a seguir e':\n");
    solveHanoiTowers(quantityOfDiscs, 'A', 'B', 'C');

    system ("pause");
    return 0; }
