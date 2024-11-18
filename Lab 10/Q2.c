#include <stdio.h>
#include <math.h>

// Define a structure to represent a point in 2D space
typedef struct {
    int x;
    int y;
} coordinates;


typedef struct {    //nested struct that uses coordinates entered before to get rectangle points
    coordinates topLeft;
    coordinates bottomRight;
} rectangle;


float calc_dist(coordinates p1, coordinates p2) {
    int xDiff = p2.x - p1.x;
    int yDiff = p2.y - p1.y;
    return sqrt(pow(xDiff, 2) + pow(yDiff, 2));
}

int is_within_boundary(coordinates p, rectangle rect) {
    if (p.x >= rect.topLeft.x && p.x <= rect.bottomRight.x &&
        p.y >= rect.topLeft.y && p.y <= rect.bottomRight.y) {
        return 1; // point lies within the boundary
    }
    return 0; // P\point is outside the boundary
}

int main() {
    coordinates p1, p2;
    rectangle boundary;
    float distance;
    
    printf("Enter x and y coordinates of the first point (p1): ");
    scanf("%d %d", &p1.x, &p1.y);
    
    printf("Enter x and y coordinates of the second point (p2): ");
    scanf("%d %d", &p2.x, &p2.y);
    
    distance = calc_dist(p1, p2);
    printf("Distance between the two points: %.2f\n", distance);
    
    printf("\nDefine a rectangular boundary:\n");
    printf("Enter x and y coordinates of the top-left corner: ");
    scanf("%d %d", &boundary.topLeft.x, &boundary.topLeft.y);
    
    printf("Enter x and y coordinates of the bottom-right corner: ");
    scanf("%d %d", &boundary.bottomRight.x, &boundary.bottomRight.y);
    
    if (is_within_boundary(p1, boundary)) {
        printf("The first point (p1) lies within the boundary.\n");
    } else {
        printf("The first point (p1) is outside the boundary.\n");
    }
    
    if (is_within_boundary(p2, boundary)) {
        printf("The second point (p2) lies within the boundary.\n");
    } else {
        printf("The second point (p2) is outside the boundary.\n");
    }

    return 0;
}
