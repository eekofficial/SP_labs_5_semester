//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button1Click(TObject *Sender)
{
    Form4 -> Close();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TForm4::Button2Click(TObject *Sender)
{
    Form3 -> PaintBox1 -> Width = StrToInt(Form4 -> Edit1 -> Text);
	Form3 -> PaintBox1 -> Height = StrToInt(Form4 -> Edit2 -> Text);
	Form3 -> FormPaint(Sender);
}
//---------------------------------------------------------------------------
