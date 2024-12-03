#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the polynomial term structure (node of the circular linked list)
struct Term {
    int coefficient;    // Coefficient of the term
    int expX, expY, expZ;  // Exponents of x, y, and z
    struct Term *next;  // Pointer to the next term (circular)
};

// Header node
struct Term *header = NULL;

// Function to create a new term node and insert it at the end of the circular list
void insertTerm(int coefficient, int expX, int expY, int expZ) {
    struct Term *newTerm = (struct Term *)malloc(sizeof(struct Term));
    newTerm->coefficient = coefficient;
    newTerm->expX = expX;
    newTerm->expY = expY;
    newTerm->expZ = expZ;
    newTerm->next = newTerm;  // Circular link initially points to itself

    if (header == NULL) {
        header = newTerm;
    } else {
        struct Term *temp = header;
        while (temp->next != header) {
            temp = temp->next;
        }
        temp->next = newTerm;
        newTerm->next = header;
    }
}

// Function to display the polynomial
void displayPolynomial(struct Term *header) {
    if (header == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }
    
    struct Term *temp = header;
    do {
        printf("%d", temp->coefficient);
        if (temp->expX != 0) printf("x^%d", temp->expX);
        if (temp->expY != 0) printf("y^%d", temp->expY);
        if (temp->expZ != 0) printf("z^%d", temp->expZ);
        printf(" ");
        temp = temp->next;
    } while (temp != header);
    printf("\n");
}

// Function to evaluate the polynomial for given values of x, y, and z
int evaluatePolynomial(struct Term *header, int x, int y, int z) {
    int result = 0;
    struct Term *temp = header;
    do {
        result += temp->coefficient * pow(x, temp->expX) * pow(y, temp->expY) * pow(z, temp->expZ);
        temp = temp->next;
    } while (temp != header);
    return result;
}

// Function to add two polynomials and return the sum as a new polynomial
struct Term* addPolynomials(struct Term *poly1, struct Term *poly2) {
    struct Term *result = NULL, *temp1 = poly1, *temp2 = poly2;
    
    // Loop until we have traversed both polynomials
    while (temp1 != NULL || temp2 != NULL) {
        int coefficientSum = 0;
        int expX, expY, expZ;
        
        if (temp1 != NULL && temp2 != NULL && 
            temp1->expX == temp2->expX && temp1->expY == temp2->expY && temp1->expZ == temp2->expZ) {
            
            coefficientSum = temp1->coefficient + temp2->coefficient;
            expX = temp1->expX;
            expY = temp1->expY;
            expZ = temp1->expZ;
            
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if (temp1 != NULL) {
            coefficientSum = temp1->coefficient;
            expX = temp1->expX;
            expY = temp1->expY;
            expZ = temp1->expZ;
            temp1 = temp1->next;
        } else {
            coefficientSum = temp2->coefficient;
            expX = temp2->expX;
            expY = temp2->expY;
            expZ = temp2->expZ;
            temp2 = temp2->next;
        }
        
        if (coefficientSum != 0) {
            insertTerm(coefficientSum, expX, expY, expZ);
        }
    }

    return result;
}

int main() {
    // Create the first polynomial POLY1(x, y, z) = 6x^2y^2z - 4yz^5 + 3x^3yz + 2xy^5 - 2xyz^3
    insertTerm(6, 2, 2, 1);
    insertTerm(-4, 0, 1, 5);
    insertTerm(3, 3, 1, 1);
    insertTerm(2, 1, 5, 0);
    insertTerm(-2, 1, 1, 3);
    
    // Create the second polynomial POLY2(x, y, z) = 5x^2y - 3y^2z + 4x^3z^2
    insertTerm(5, 2, 1, 0);
    insertTerm(-3, 0, 2, 1);
    insertTerm(4, 3, 0, 2);

    printf("Polynomial 1:\n");
    displayPolynomial(header);
    
    printf("Polynomial 2:\n");
    displayPolynomial(header);

    // Evaluate the polynomial for x=1, y=2, z=3
    int result = evaluatePolynomial(header, 1, 2, 3);
    printf("\nEvaluation of Polynomial 1 at x=1, y=2, z=3: %d\n", result);

    // Add the two polynomials and display the result
    struct Term *sumPoly = addPolynomials(header, header);  // Adding both POLY1 and POLY2
    
    printf("Sum of Polynomial 1 and Polynomial 2:\n");
    displayPolynomial(sumPoly);

    return 0;
}
