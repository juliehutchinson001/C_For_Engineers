1 // p16_11.H
2 #ifndef P16_11_H
3 #define P16_11_H
4
5 class TicTacToe {
6 private: 
7 enum Status { WIN, DRAW, CONTINUE };
8 int board[ 3 ][ 3 ];
9 public:
10 TicTacToe();
11 void makeMove( void );
12 void printBoard( void );
13 bool validMove( int, int );
14 bool xoMove( int );
15 Status gameStatus( void );
16 };
17
18 #endif
19 // P16_11M.cpp
20 // member function definitions for p16_9.cpp
21 #include <iostream> 
22
23 using std::cout; 
24 using std::cin; 
25
26 #include <iomanip> 
27
28 using std::setw; 
29
30 #include "p16_11.h"
31
32 TicTacToe::TicTacToe()
33 {
34 for ( int j = 0; j < 3; ++j ) // initialize board
35 for ( int k = 0; k < 3; ++k )
36 board[ j ][ k ] = ' ';
37 }
38
39 bool TicTacToe::validMove( int r, int c )
40 {
41 return r >= 0 && r < 3 && c >= 0 && c < 3 && board[ r ][ c ] == ' ';
42 }
43
44 // must specify that type Status is part of the TicTacToe class.
45 // See Chapter 21 for a discussion of namespaces.
46 TicTacToe::Status TicTacToe::gameStatus( void )
47 { 
48 int a;
49
50 // check for a win on diagonals
51 if ( board[ 0 ][ 0 ] != ' ' && board[ 0 ][ 0 ] == board[ 1 ][ 1 ] &&
52 board[ 0 ][ 0 ] == board[ 2 ][ 2 ] )
53 return WIN;
54 else if ( board[ 2 ][ 0 ] != ' ' && board[ 2 ][ 0 ] == 
55 board[ 1 ][ 1 ] && board[ 2 ][ 0 ] == board[ 0 ][ 2 ] )
56 return WIN;
57
58 // check for win in rows
59 for ( a = 0; a < 3; ++a )
60 if ( board[ a ][ 0 ] != ' ' && board[ a ][ 0 ] == 
61 board[ a ][ 1 ] && board[ a ][ 0 ] == board[ a ][ 2 ] )
62 return WIN;
63
64 // check for win in columns
65 for ( a = 0; a < 3; ++a )
66 if ( board[ 0 ][ a ] != ' ' && board[ 0 ][ a ] == 
67 board[ 1 ][ a ] && board[ 0 ][ a ] == board[ 2 ][ a ] )
68 return WIN;
69
70 // check for a completed game
71 for ( int r = 0; r < 3; ++r )
72 for ( int c = 0; c < 3; ++c )
73 if ( board[ r ][ c ] == ' ' )
74 return CONTINUE; // game is not finished
75
76 return DRAW; // game is a draw
77 }
78
79 void TicTacToe::printBoard( void ) 
80 {
81 cout << " 0 1 2\n\n";
82
83 for ( int r = 0; r < 3; ++r ) {
84 cout << r;
85
86 for ( int c = 0; c < 3; ++c ) {
87 cout << setw( 3 ) << static_cast< char > ( board[ r ][ c ] );
88
89 if ( c != 2 )
90 cout << " |";
91 }
92
93 if ( r != 2 )
94 cout << "\n ____|____|____"
95 << "\n | | \n";
96 }
97
98 cout << "\n\n";
99 }
100
101 void TicTacToe::makeMove( void )
102 {
103 printBoard();
104
105 while ( true ) {
106 if ( xoMove( 'X' ) )
107 break;
108 else if ( xoMove( 'O' ) )
109 break;
110 }
111 }
112
113 bool TicTacToe::xoMove( int symbol )
114 {
115 int x, y;
116 
117 do {
118 cout << "Player " << static_cast< char >( symbol ) 
119 << " enter move: ";
120 cin >> x >> y;
121 cout << '\n';
122 } while ( !validMove( x, y ) );
123
124 board[ x ][ y ] = symbol;
125 printBoard();
126 Status xoStatus = gameStatus();
127
128 if ( xoStatus == WIN ) {
129 cout << "Player " << static_cast< char >( symbol ) << " wins!\n";
130 return true;
131 }
132 else if ( xoStatus == DRAW ) {
133 cout << "Game is a draw.\n";
134 return true;
135 }
136 else // CONTINUE
137 return false; 
138 }
139 // driver for p16_11.cpp
140 #include "p16_11.h"
141
142 int main()
143 {
144 TicTacToe g;
145 g.makeMove();
146
147 return 0;
148 }