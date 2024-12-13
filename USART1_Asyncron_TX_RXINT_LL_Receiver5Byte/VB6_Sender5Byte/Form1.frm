VERSION 5.00
Object = "{648A5603-2C6E-101B-82B6-000000000014}#1.1#0"; "MSCOMM32.OCX"
Begin VB.Form Form1 
   BackColor       =   &H00C0E0FF&
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Sender 5-Byte"
   ClientHeight    =   4770
   ClientLeft      =   5100
   ClientTop       =   3675
   ClientWidth     =   3780
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   4770
   ScaleWidth      =   3780
   Begin VB.Frame Frame1 
      BackColor       =   &H00C0C0FF&
      Caption         =   "Setting"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   178
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   3465
      Left            =   0
      TabIndex        =   5
      Top             =   1320
      Width           =   3800
      Begin VB.CommandButton Command1 
         Caption         =   "Send"
         Height          =   375
         Left            =   120
         TabIndex        =   13
         Top             =   3000
         Width           =   3615
      End
      Begin VB.TextBox In4 
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   12
            Charset         =   178
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   2520
         TabIndex        =   12
         Text            =   "253"
         Top             =   2160
         Width           =   855
      End
      Begin VB.TextBox In3 
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   12
            Charset         =   178
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   2520
         TabIndex        =   11
         Text            =   "0"
         Top             =   1200
         Width           =   855
      End
      Begin VB.TextBox In2 
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   12
            Charset         =   178
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   2520
         TabIndex        =   10
         Text            =   "0"
         Top             =   720
         Width           =   855
      End
      Begin VB.TextBox In1 
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   12
            Charset         =   178
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   2520
         TabIndex        =   9
         Text            =   "254"
         Top             =   240
         Width           =   855
      End
      Begin VB.Label Label_CS 
         BackColor       =   &H00C0C0FF&
         Caption         =   "0"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   12
            Charset         =   178
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   2520
         TabIndex        =   18
         Top             =   1680
         Width           =   855
      End
      Begin VB.Label Label8 
         BackColor       =   &H00C0C0FF&
         Caption         =   "Stop Byte"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   9.75
            Charset         =   178
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Left            =   240
         TabIndex        =   17
         Top             =   2160
         Width           =   1500
      End
      Begin VB.Label Label7 
         BackColor       =   &H00C0C0FF&
         Caption         =   "Check Sum"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   9.75
            Charset         =   178
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Left            =   240
         TabIndex        =   16
         Top             =   1680
         Width           =   1500
      End
      Begin VB.Label Label6 
         BackColor       =   &H00C0C0FF&
         Caption         =   "Date 2"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   9.75
            Charset         =   178
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Left            =   240
         TabIndex        =   15
         Top             =   1200
         Width           =   1500
      End
      Begin VB.Label Label5 
         BackColor       =   &H00C0C0FF&
         Caption         =   "Date 1"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   9.75
            Charset         =   178
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Left            =   240
         TabIndex        =   14
         Top             =   720
         Width           =   1500
      End
      Begin VB.Label Label2 
         BackStyle       =   0  'Transparent
         Caption         =   "GitHub.com/AliRezaJoodi"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   9.75
            Charset         =   178
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H8000000B&
         Height          =   255
         Left            =   120
         TabIndex        =   8
         Top             =   2640
         Width           =   2535
      End
      Begin VB.Label Label3 
         BackColor       =   &H00C0C0FF&
         Caption         =   "Start Byte"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   9.75
            Charset         =   178
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   250
         Left            =   240
         TabIndex        =   7
         Top             =   250
         Width           =   1500
      End
      Begin VB.Label Label4 
         BackColor       =   &H00C0C0FF&
         Caption         =   "MSB:"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   9.75
            Charset         =   178
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   250
         Left            =   240
         TabIndex        =   6
         Top             =   600
         Width           =   15
      End
   End
   Begin VB.Frame Frame4 
      BackColor       =   &H00FFFFC0&
      Caption         =   "Communication"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   178
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   1320
      Left            =   0
      TabIndex        =   0
      Top             =   0
      Width           =   3800
      Begin VB.CommandButton Button2 
         Caption         =   "Disconnect"
         Height          =   375
         Left            =   2160
         TabIndex        =   4
         Top             =   840
         Width           =   1500
      End
      Begin VB.CommandButton Button1 
         Caption         =   "Connect"
         Height          =   375
         Left            =   120
         TabIndex        =   3
         Top             =   840
         Width           =   1500
      End
      Begin VB.ComboBox Combo1 
         BeginProperty Font 
            Name            =   "Times New Roman"
            Size            =   11.25
            Charset         =   178
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   2400
         TabIndex        =   1
         Text            =   "1"
         Top             =   350
         Width           =   1215
      End
      Begin MSCommLib.MSComm MSComm1 
         Left            =   120
         Top             =   240
         _ExtentX        =   1005
         _ExtentY        =   1005
         _Version        =   393216
         CommPort        =   9
         DTREnable       =   -1  'True
         InputLen        =   1
         RThreshold      =   1
         SThreshold      =   1
      End
      Begin VB.Label Label1 
         BackColor       =   &H00FFFFC0&
         Caption         =   "COM Port Number"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   9.75
            Charset         =   178
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   250
         Left            =   240
         TabIndex        =   2
         Top             =   350
         Width           =   1815
      End
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'GitHub Account: GitHub.com/AliRezaJoodi

Dim number As Integer
Dim number_lsb As Byte
Dim number_msb  As Byte
Dim cs As Byte

Private Sub Form_Load()
    MSComm1.Settings = "9600,N,8,1"
    MSComm1.RThreshold = 1
    MSComm1.SThreshold = 1
    MSComm1.InputLen = 1
    
    For CPN = 1 To 16
        Combo1.AddItem Str(CPN)
    Next CPN
    Combo1.Text = Combo1.List(0)
    
    Call Setting_Default
End Sub
Public Sub Setting_Default()
    Combo1.Enabled = True
    Button1.Enabled = True: Button2.Enabled = False
    
    Call CalculateCheckSum
    'Frame1.Enabled = False
    Command1.Enabled = False
End Sub
Public Sub Setting_Work()
    Combo1.Enabled = False
    Button1.Enabled = False: Button2.Enabled = True
    
    Call CalculateCheckSum
    'Frame1.Enabled = True
    Command1.Enabled = True
End Sub
Private Sub Button1_Click()
    Dim CPN As Byte
    CPN = Val(Combo1.Text): MSComm1.CommPort = CPN: MSComm1.PortOpen = True
      
    Call Setting_Work
End Sub
Private Sub Button2_Click()
    MSComm1.PortOpen = False
    
    Call Setting_Default
End Sub
Private Sub Command1_Click()
    Call CalculateCheckSum
    Call Sender
End Sub
Private Sub Sender()
    MSComm1.Output = Chr$(Val(In1.Text))
    MSComm1.Output = Chr$(Val(In2.Text))
    MSComm1.Output = Chr$(Val(In3.Text))
    MSComm1.Output = Chr$(cs)
    MSComm1.Output = Chr$(Val(In4.Text))
End Sub
Private Sub CalculateCheckSum()
    Dim cs_int As Integer
    cs_int = Val(In1.Text) + Val(In2.Text) + Val(In3.Text)
    cs = cs_int Mod 256
    
    Label_CS.Caption = cs
End Sub
