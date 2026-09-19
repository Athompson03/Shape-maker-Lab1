#include <iostream>
#include "shapemaker.h"

using namespace std;

// Default initialization
void ShapeMaker::Initialize()
{
    canvasWidth = 21;
    canvasHeight = 21;
    drawingSymbol = '*';
}

// Custom initialization
void ShapeMaker::Initialize(int width, int height, char symbol)
{
    canvasWidth = width;
    canvasHeight = height;
    drawingSymbol = symbol;
}

// Get functions
int ShapeMaker::GetCanvasWidth() const
{
    return canvasWidth;
}

int ShapeMaker::GetCanvasHeight() const
{
    return canvasHeight;
}

char ShapeMaker::GetDrawingSymbol() const
{
    return drawingSymbol;
}

// Set functions
void ShapeMaker::SetCanvasWidth(int width)
{
    canvasWidth = width;
}

void ShapeMaker::SetCanvasHeight(int height)
{
    canvasHeight = height;
}

void ShapeMaker::SetDrawingSymbol(char symbol)
{
    drawingSymbol = symbol;
}

// Draw horizontal line through the middle of the canvas
void ShapeMaker::DrawHorizontalLine() const
{
    int middle = canvasHeight / 2;

    for (int row = 0; row < canvasHeight; row++)
    {
        for (int col = 0; col < canvasWidth; col++)
        {
            if (row == middle)
                cout << drawingSymbol;
            else
                cout << ' ';
        }
        cout << endl;
    }
}

// Draw vertical line through the middle of the canvas
void ShapeMaker::DrawVerticalLine() const
{
    int middle = canvasWidth / 2;

    for (int row = 0; row < canvasHeight; row++)
    {
        for (int col = 0; col < canvasWidth; col++)
        {
            if (col == middle)
                cout << drawingSymbol;
            else
                cout << ' ';
        }
        cout << endl;
    }
}

// Draw a filled square
void ShapeMaker::DrawFilledSquare() const
{
    for (int row = 0; row < canvasWidth; row++)
    {
        for (int col = 0; col < canvasWidth; col++)
        {
            cout << drawingSymbol;
        }
        cout << endl;
    }
}

// Draw an open square
void ShapeMaker::DrawOpenSquare() const
{
    for (int row = 0; row < canvasWidth; row++)
    {
        for (int col = 0; col < canvasWidth; col++)
        {
            if (row == 0 ||
                row == canvasWidth - 1 ||
                col == 0 ||
                col == canvasWidth - 1)
            {
                cout << drawingSymbol;
            }
            else
            {
                cout << ' ';
            }
        }
        cout << endl;
    }
}

// Draw a smiley face inside a block head
void ShapeMaker::DrawSmileyFace() const
{
    int size = canvasWidth;

    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            bool border =
                row == 0 ||
                row == size - 1 ||
                col == 0 ||
                col == size - 1;

            bool leftEye =
                row == size / 3 &&
                col == size / 3;

            bool rightEye =
                row == size / 3 &&
                col == (2 * size) / 3;

            bool nose =
                row == size / 2 &&
                col == size / 2;

            bool mouth =
                row == (2 * size) / 3 &&
                col >= size / 3 &&
                col <= (2 * size) / 3;

            if (border || leftEye || rightEye || nose || mouth)
                cout << drawingSymbol;
            else
                cout << ' ';
        }

        cout << endl;
    }
}


// TEST DRIVER
int main()
{
    ShapeMaker shape;

    cout << "DEFAULT INITIALIZATION" << endl;
    shape.Initialize();

    cout << "Width: "
         << shape.GetCanvasWidth() << endl;

    cout << "Height: "
         << shape.GetCanvasHeight() << endl;

    cout << "Drawing Symbol: "
         << shape.GetDrawingSymbol() << endl;


    cout << "\nHORIZONTAL LINE\n";
    shape.DrawHorizontalLine();

    cout << "\nVERTICAL LINE\n";
    shape.DrawVerticalLine();

    cout << "\nFILLED SQUARE\n";
    shape.DrawFilledSquare();

    cout << "\nOPEN SQUARE\n";
    shape.DrawOpenSquare();

    cout << "\nSMILEY FACE\n";
    shape.DrawSmileyFace();


    // Test setter functions
    cout << "\nTESTING SET FUNCTIONS\n";

    shape.SetCanvasWidth(11);
    shape.SetCanvasHeight(11);
    shape.SetDrawingSymbol('#');

    cout << "New Width: "
         << shape.GetCanvasWidth() << endl;

    cout << "New Height: "
         << shape.GetCanvasHeight() << endl;

    cout << "New Symbol: "
         << shape.GetDrawingSymbol() << endl;


    // Test custom Initialize function
    cout << "\nCUSTOM INITIALIZATION\n";

    shape.Initialize(15, 15, '@');

    cout << "Width: "
         << shape.GetCanvasWidth() << endl;

    cout << "Height: "
         << shape.GetCanvasHeight() << endl;

    cout << "Symbol: "
         << shape.GetDrawingSymbol() << endl;

    cout << "\nCUSTOM OPEN SQUARE\n";
    shape.DrawOpenSquare();

    return 0;
}