//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit4.h"
#include <math.h>
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
int a1 = 500, b1 = 530, a2 = 530, b2 = 560;
bool FL = false;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}

void __fastcall TForm3::Button1Click(TObject *Sender)
{
	Form4 -> Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button2Click(TObject *Sender)
{
	Form3 -> Canvas -> Brush -> Color = clBlue;
	Form3 -> Canvas -> Pen -> Color = clBlue;
	Form3 -> Canvas -> Ellipse(400, 530, 430, 560);
}
//---------------------------------------------------------------------------


void __fastcall TForm3::FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	if (X < 430 & X > 400 & Y < 560 & Y > 530) {
		 TRect r;
	r.left = 400;
	r.top = 530;
	r.right = 430;
	r.bottom = 560;
	::InvalidateRect(Form3 -> Handle, &r, true);
	Form3 -> Repaint();
	}
	if (X < a2 & X > a1 & Y < b2 & Y > b1) {
		FL = true;
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm3::FormMouseMove(TObject *Sender, TShiftState Shift, int X, int Y)

{
	 if (FL) {
		 TRect r;
		r.left = a1;
		r.top = b1;
		r.right = a2;
		r.bottom = b2;
		::InvalidateRect(Form3 -> Handle, &r, true);
		Form3 -> Refresh();
		a1 = X;
		b1 = Y;
		a2 = X + 30;
		b2 = Y + 30;

		Form3 -> OnPaint(Sender);
	 }
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	if ((FL)) {
	a1 = X;
	b1 = Y;
	a2 = X + 30;
	b2 = Y + 30;
	Form3 -> OnPaint(Sender);
	}
	FL = false;

}
//---------------------------------------------------------------------------


void __fastcall TForm3::FormPaint(TObject *Sender)
{
    	Form3 -> Canvas -> Brush -> Color = (TColor)RGB(221, 255, 254);
	Form3 -> Canvas -> FloodFill(1, 1, (TColor)RGB(135, 206, 235), fsBorder);
	Form3 -> Canvas -> Pen -> Color = (TColor)RGB(101, 67, 33);
	Form3 -> Canvas -> Pen -> Width = 6;
	Form3 -> Canvas -> Brush -> Color = clGreen;
	Form3 -> Canvas -> Rectangle(400, 87, 1013, 436);
	Form3 -> Canvas -> Pen -> Color = clBlack;
	Form3 -> Canvas -> Pen -> Width = 1;
	Form3 -> Canvas -> Brush -> Color = clWhite;
	Form3 -> Canvas -> Rectangle(400, 27, 1013, 67);
	Form3 -> Canvas -> Pen -> Color = (TColor)RGB(255, 165, 0);
	Form3 -> Canvas -> MoveTo(0, 560);
	Form3 -> Canvas -> LineTo(1100, 560);
	Form3 -> Canvas -> Brush -> Color = (TColor)RGB(227, 160, 0);
	Form3 -> Canvas -> FloodFill(0, 699, (TColor)RGB(255, 165, 0), fsBorder);
    Canvas -> Font -> Name = "Times New Roman";
	Canvas -> Font -> Color = clBlack;
	Canvas -> Font -> Size = 10;
	Canvas -> TextOut(850, 650, "Урок в школе. Автор: Коротаев Евгений");
	Form3 -> Canvas -> Brush -> Color = (TColor)RGB(253, 216, 85);
	Form3 -> Canvas -> Pen -> Width = 3;
	Form3 -> Canvas -> Pen -> Color = (TColor)RGB(205, 133, 63);
	Form3 -> Canvas -> Rectangle(0, 400, 200, 486);
	Form3 -> Canvas -> MoveTo(0, 486);
	Form3 -> Canvas -> LineTo(0, 572);
	Form3 -> Canvas -> MoveTo(199, 486);
	Form3 -> Canvas -> LineTo(199, 572);
	Form3 -> Canvas -> Brush -> Color = clBlack;
	Form3 -> Canvas -> Pen -> Width = 0;
	Form3 -> Canvas -> Pen -> Color = clBlack;
	Form3 -> Canvas -> Rectangle(95, 380, 105, 400);
	Form3 -> Canvas -> Rectangle(50, 320, 150, 380);
	Form3 -> Canvas -> MoveTo(165, 572);
	Form3 -> Canvas -> LineTo(185, 572);
	Form3 -> Canvas -> LineTo(190, 537);
	Form3 -> Canvas -> LineTo(160, 537);
	Form3 -> Canvas -> LineTo(165, 572);
	Form3 -> Canvas -> FloodFill(167, 570, clBlack, fsBorder);
	Form3 -> Canvas -> Brush -> Color = (TColor)RGB(234, 189, 157);
	Form3 -> Canvas -> Pen -> Width = 0;
	Form3 -> Canvas -> Pen -> Color = (TColor)RGB(234, 189, 157);
	Form3 -> Canvas -> Ellipse(280, 250, 320, 300);
	Form3 -> Canvas -> Rectangle(295, 290, 305, 308);
	Form3 -> Canvas -> Brush -> Color = clRed;
	Form3 -> Canvas -> Pen -> Color = clRed;
	Form3 -> Canvas -> MoveTo(250, 308);
	Form3 -> Canvas -> LineTo(350, 308);
	Form3 -> Canvas -> LineTo(300, 455);
	Form3 -> Canvas -> LineTo(250, 308);
	Form3 -> Canvas -> FloodFill(255, 315, clRed, fsBorder);
	Form3 -> Canvas -> LineTo(250, 430);
	Form3 -> Canvas -> LineTo(264, 430);
	Form3 -> Canvas -> LineTo(264, 308);
	Form3 -> Canvas -> MoveTo(350, 308);
	Form3 -> Canvas -> LineTo(350, 430);
	Form3 -> Canvas -> LineTo(336, 430);
	Form3 -> Canvas -> LineTo(336, 308);
	Form3 -> Canvas -> FloodFill(255, 427, clRed, fsBorder);
	Form3 -> Canvas -> FloodFill(338, 427, clRed, fsBorder);
	Form3 -> Canvas -> Rectangle(276, 380, 294, 550);
	Form3 -> Canvas -> Rectangle(307, 380, 325, 550);
	Form3 -> Canvas -> Brush -> Color = clBlack;
	Form3 -> Canvas -> Pen -> Color = clBlack;
	Form3 -> Canvas -> Rectangle(261, 550, 294, 560);
	Form3 -> Canvas -> Rectangle(307, 550, 340, 560);
	Form3 -> Canvas -> Brush -> Color = (TColor)RGB(234, 189, 157);
	Form3 -> Canvas -> Pen -> Color = (TColor)RGB(234, 189, 157);
	Form3 -> Canvas -> Rectangle(336, 430, 350, 440);
	Form3 -> Canvas -> Pen -> Color = (TColor)RGB(150, 75, 0);
	Form3 -> Canvas -> Pen -> Width = 2;
	Form3 -> Canvas -> MoveTo(252, 431);
	Form3 -> Canvas -> LineTo(290, 490);
	Form3 -> Canvas -> Pen -> Width = 0;
	Form3 -> Canvas -> Pen -> Color = (TColor)RGB(234, 189, 157);
	Form3 -> Canvas -> Rectangle(251, 430, 265, 440);
	Form3 -> Canvas -> Brush -> Color = clBlack;
	Form3 -> Canvas -> Pen -> Color = clBlack;
	Form3 -> Canvas -> Ellipse(306, 266, 312, 270);
	Form3 -> Canvas -> Ellipse(288, 266, 294, 270);
	Form3 -> Canvas -> MoveTo(300, 275);
	Form3 -> Canvas -> LineTo(297, 280);
	Form3 -> Canvas -> LineTo(300, 280);
	Form3 -> Canvas -> MoveTo(295, 288);
	Form3 -> Canvas -> LineTo(305, 288);
	Form3 -> Canvas -> Rectangle(270, 251, 330, 255);
	Form3 -> Canvas -> Rectangle(290, 241, 310, 251);
	Form3 -> Canvas -> Pen -> Width = 3;
	Form3 -> Canvas -> MoveTo(300, 370);
	Form3 -> Canvas -> LineTo(300, 330);
	Form3 -> Canvas -> LineTo(280, 330);
	Form3 -> Canvas -> LineTo(320, 330);
	Form3 -> Canvas -> Pen -> Width = 1;
	Form3 -> Canvas -> Brush -> Color = clWhite;
	Form3 -> Canvas -> MoveTo(265, 281);
	Form3 -> Canvas -> LineTo(190, 260);
	Form3 -> Canvas -> MoveTo(265, 281);
	Form3 -> Canvas -> LineTo(240, 260);
	Form3 -> Canvas -> LineTo(190, 260);
	Form3 -> Canvas -> FloodFill(240, 270, clBlack, fsBorder);
	Form3 -> Canvas -> Ellipse(175, 241, 265, 281);
	Canvas -> Font -> Name = "Times New Roman";
	Canvas -> Font -> Color = clBlack;
	Canvas -> Font -> Size = 10;
	Canvas -> TextOut(182, 254, "Привет, Дети!");
	Canvas -> Font -> Size = 12.5;
	Canvas -> TextOut(413, 35, "\"Математику уж затем учить надо, что она ум в порядок приводит\" - М.В. Ломоносов.");
    int x = 0;
	int y = 0;
	int w = PaintBox1 -> Width;
	int h = PaintBox1 -> Height;
	int ax = - 7;
	int bx = 7;
	int ay = -7;
	int by = 12;
	int deltax = abs(bx - ax);
	int deltay = abs(by - ay);
	float k = w / deltax;
	float j = h / deltay;
	PaintBox1 -> Canvas -> Brush -> Color = clGreen;
	PaintBox1 -> Font -> Name = "Times New Roman";
	PaintBox1 -> Font -> Color = clWhite;
	PaintBox1 -> Font -> Size = 14;
	PaintBox1 -> Canvas -> TextOut(10, 10, "Тема урока: Графики функций");
	PaintBox1 -> Canvas -> Pen -> Color = clBlack;
	PaintBox1 -> Canvas -> Pen -> Width = 0;
	PaintBox1 -> Canvas -> MoveTo(x + w / 2, y);
	PaintBox1 -> Canvas -> LineTo(x + w / 2 - 5, y + 5);
	PaintBox1 -> Canvas -> MoveTo(x + w / 2, y);
	PaintBox1 -> Canvas -> LineTo(x + w / 2 + 5, y + 5);

	PaintBox1 -> Canvas -> MoveTo(x + w, y + j * 12);
	PaintBox1 -> Canvas -> LineTo(x + w - 5, y + j * 12 - 5);
	PaintBox1 -> Canvas -> MoveTo(x + w, y + j * 12);
	PaintBox1 -> Canvas -> LineTo(x + w - 5, y + j * 12 + 5);

	PaintBox1 -> Canvas -> MoveTo(x + w / 2, y);
	PaintBox1 -> Canvas -> LineTo(x + w / 2, y + j * 12);
	PaintBox1 -> Canvas -> MoveTo(x, y + j * 12);
	PaintBox1 -> Canvas -> LineTo(x + w, y + j * 12);
	PaintBox1 -> Canvas -> MoveTo(x + w / 2, y + j * 12);
	PaintBox1 -> Canvas -> LineTo(x + w / 2, y + h);


	for (int i = x + w / 2; i <= x + w; i+=k) {
		PaintBox1 -> Canvas -> MoveTo(i, y + j * 12);
		PaintBox1 -> Canvas -> LineTo(i, y + j * 12 + 3);
		PaintBox1 -> Canvas -> LineTo(i, y + j * 12 - 3);
	}
	for (int i = x + w / 2; i >= x; i-=k) {
		PaintBox1 -> Canvas -> MoveTo(i, y + j * 12);
		PaintBox1 -> Canvas -> LineTo(i, y + j * 12 + 3);
		PaintBox1 -> Canvas -> LineTo(i, y + j * 12 - 3);
	}

	for (int i = y + h / 2; i <= y + h; i+=j) {
		PaintBox1 -> Canvas -> MoveTo(x + w / 2, i);
		PaintBox1 -> Canvas -> LineTo(x + w / 2 + 3, i);
		PaintBox1 -> Canvas -> LineTo(x + w / 2 - 3, i);
	}
	for (int i = y + h / 2; i >= y; i-=j) {
		PaintBox1 -> Canvas -> MoveTo(x + w / 2, i);
		PaintBox1 -> Canvas -> LineTo(x + w / 2 + 3, i);
		PaintBox1 -> Canvas -> LineTo(x + w / 2 - 3, i);
	}

	float xf = -7;
	float yf;
	PaintBox1 -> Canvas -> Pen -> Width = 3;
	PaintBox1 -> Canvas -> Pen -> Color = clRed;
	while (xf <= 7) {
		yf = xf/2 * exp(xf/9 + 0.8) * cos(xf+1.2);
		if (xf == -7) {
			PaintBox1 -> Canvas -> MoveTo(x + w / 2 + xf*k, (y + j * 12 - yf*j));
			xf += 0.1;
		}
		else {
			xf += 0.1;
		PaintBox1 -> Canvas -> LineTo(x + w / 2 + xf*k, (y + j * 12 - yf*j));
		}
	}
    Form3 -> Canvas -> Brush -> Color = clBlue;
	Form3 -> Canvas -> Pen -> Color = clBlue;
	Form3 -> Canvas -> Ellipse(a1, b1, a2, b2);
}
//---------------------------------------------------------------------------

