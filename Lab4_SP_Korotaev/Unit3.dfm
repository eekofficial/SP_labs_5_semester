object Form3: TForm3
  Left = 0
  Top = 0
  BorderStyle = bsToolWindow
  Caption = 'Form3'
  ClientHeight = 700
  ClientWidth = 1100
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnMouseDown = FormMouseDown
  OnMouseMove = FormMouseMove
  OnMouseUp = FormMouseUp
  OnPaint = FormPaint
  PixelsPerInch = 96
  TextHeight = 13
  object PaintBox1: TPaintBox
    Left = 400
    Top = 87
    Width = 613
    Height = 349
  end
  object Button1: TButton
    Left = 1049
    Top = 368
    Width = 8
    Height = 25
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 1056
    Top = 368
    Width = 8
    Height = 25
    TabOrder = 1
    OnClick = Button2Click
  end
end
