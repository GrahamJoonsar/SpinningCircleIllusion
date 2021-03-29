#include "raylib.h"
#include "math.h"

const int screenWidth = 500;
const int screenHeight = 500;
float fakeTime = 0;

// This uses some complex math, and it would be hard to explain here, so this link might help.
// https://www.mathsisfun.com/polar-cartesian-coordinates.html

void drawBaseLines(int divisions){
    // This creates the outer ring
    DrawCircle(screenWidth/2, screenHeight/2, 175, WHITE);
    DrawCircle(screenWidth/2, screenHeight/2, 170, BLACK);
    // This creates the lines
    for (int i = 0; i < divisions; i++){
        // Hard math
        int x1 = 175 * cos(((2 * M_PI) / divisions) * i) + screenWidth/2; // The angle in radians is determined by i and the number of divisions
        int y1 = 175 * sin(((2 * M_PI) / divisions) * i) + screenHeight/2;
        int x2 = 175 * cos(((2 * M_PI) / divisions) * i + M_PI) + screenWidth/2;
        int y2 = 175 * sin(((2 * M_PI) / divisions) * i + M_PI) + screenHeight/2;
        DrawLine(x1, y1, x2, y2, WHITE);
    }
}

void drawBaseCircles(int circles){
    for (int i = 0; i < circles ; i++){
        // Hard math
        float x = (sin(fakeTime + i/M_PI/5) * 175) * cos(((2 * M_PI) / circles) * i) + screenWidth/2; // The way this works is that it uses a sin wave to stretch and shrink the radius,
        float y = (sin(fakeTime + i/M_PI/5) * 175) * sin(((2 * M_PI) / circles) * i) + screenWidth/2; // so the circles go along the path
        DrawCircle(x, y, 5, {(i * 5)%255, 0, 200, 255}); // Color is dependent of i
    }
}

int main(void){
    int divisions = 100;
    
    InitWindow(screenWidth, screenHeight, "TEST");

    SetTargetFPS(60);
    
    while (!WindowShouldClose())
    {  
        // Update variables and objects
        fakeTime += 0.05; // Updating time
        
        BeginDrawing();

        ClearBackground(BLACK);
        
        drawBaseLines(divisions);
        drawBaseCircles(divisions);
            
        EndDrawing();
    }

    CloseWindow();
}