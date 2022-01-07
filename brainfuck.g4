grammar brainfuck;

file_
   : statement*
   ;

statement
: opcode
| LPAREN statement* RPAREN
;

opcode
   : GT | LT | PLUS | MINUS | DOT | COMMA
   ;


GT
   : '>'
   ;


LT
   : '<'
   ;


PLUS
   : '+'
   ;


MINUS
   : '-'
   ;


DOT
   : '.'
   ;


COMMA
   : ','
   ;


LPAREN
   : '['
   ;


RPAREN
   : ']'
   ;


WS
   : . -> skip
   ;
