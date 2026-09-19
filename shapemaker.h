#ifndef SHAPEMAKER_H
#define SHAPEMAKER_H

class ShapeMaker
{
private:
    int canvasWidth;
    int canvasHeight;
    char drawingSymbol;

public:
    void Initialize();
    void Initialize(int width, int height, char symbol);

    int GetCanvasWidth() const;
    int GetCanvasHeight() const;
    char GetDrawingSymbol() const;

    void SetCanvasWidth(int width);
    void SetCanvasHeight(int height);
    void SetDrawingSymbol(char symbol);

    void DrawHorizontalLine() const;
    void DrawVerticalLine() const;
    void DrawFilledSquare() const;
    void DrawOpenSquare() const;
    void DrawSmileyFace() const;
};

#endif