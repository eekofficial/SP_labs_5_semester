object Form4: TForm4
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Form4'
  ClientHeight = 175
  ClientWidth = 112
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 19
    Width = 40
    Height = 13
    Caption = #1064#1080#1088#1080#1085#1072
  end
  object Label2: TLabel
    Left = 8
    Top = 46
    Width = 37
    Height = 13
    Caption = #1042#1099#1089#1086#1090#1072
  end
  object Button1: TButton
    Left = 8
    Top = 120
    Width = 95
    Height = 43
    Caption = #1047#1072#1082#1088#1099#1090#1100
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 54
    Top = 16
    Width = 49
    Height = 21
    HideSelection = False
    NumbersOnly = True
    TabOrder = 1
    Text = '400'
  end
  object Edit2: TEdit
    Left = 54
    Top = 43
    Width = 49
    Height = 21
    TabOrder = 2
    Text = '300'
  end
  object Button2: TButton
    Left = 8
    Top = 71
    Width = 95
    Height = 43
    Caption = #1059#1089#1090#1072#1085#1086#1074#1080#1090#1100
    TabOrder = 3
    OnClick = Button2Click
  end
end
