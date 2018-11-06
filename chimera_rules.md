# _TENATIVE_ Chimeras Chess rules
Because every game needs rules

## Introduction:
### Standard Chess Pieces
1 king
1 queen
2 rooks
2 bishops
2 knights
8 pawns

### Chess Piece movement breakdown
Goal: Break the standard pieces into meta information, so that each chessman can be represented by some flags.
The chimeras will not act exactly like chess pieces, but we can start with something similar.

Knights go in one direction for one step, then another for two steps.
Pawns can only go diagonally if they will land on an enemy.
Rooks can switch with the king. 

```cpp
struct Movestep{
    // pawn, queen
    bool diagonal; 
    // King, bishop.
    bool can_retreat;
    // ex: pawn diagonals
    bool has_to_kill;
    // ex: rooks, queen
    bool unlimited_range;
};
struct Chessman{
    // player needs at least one piece with this flag
    bool king;
    // knight does both movesteps, one of them twice. Side effect: can jump over pieces
    bool knight_do_both;
    MoveStep a;
    MoveStep b;
};
//Flags not mentioned are just false
Chessman king(king=true,
 a=Movestep(can_retreat=true),
 b=Movestep(diagonal=true, can_retreat=true)
);
Chessman queen(
 a=Movestep(can_retreat=true, unlimited_range=true),
 b=Movestep(diagonal=true, can_retreat=true, unlimited_range=true)
);
//TODO: castling the king. add a flag? :P
Chessman rook(
 a=Movestep(can_retreat=true, unlimited_range=true),
 b=a
);
Chessman bishop(
 a=Movestep(diagonal=true, can_retreat=true, unlimited_range=true),
 b=a
);
Chessman knights(knight_do_both = true,
 a=Movestep(can_retreat=true),
 b=Movestep(can_retreat=true)
);
//TODO: Pawn double move forward thing?
Chessman pawns(
 a=Movestep(diagonal=true, has_to_kill=true),
 b=Movestep(),
);
//TODO: Figure out how to breed and promote Chessmen
```
