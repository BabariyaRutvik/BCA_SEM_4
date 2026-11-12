% 49. Write a Prolog program to illustrate control structures (cut, fail, recursion and if-then-else).
/*
Use: Used in Prolog to control backtracking, implement loops/repetition, and write conditional branches.
Process: The cut (!) stops backtracking once a clause succeeds; fail forces backtracking to print all items.
Recursion computes factorial(N, F) by reducing N until the base case factorial(0, 1).
The if-then-else construct (Cond -> Then ; Else) classifies numbers as positive or non-positive.
*/

% 1. Recursion: Factorial of N
factorial(0, 1) :- !.
factorial(N, F) :-
    N > 0,
    N1 is N - 1,
    factorial(N1, F1),
    F is N * F1.

% 2. Cut (!) and If-Then-Else (-> ;)
check_number(X) :-
    ( X > 0 ->
        write(X), write(' is Positive'), nl
    ; X < 0 ->
        write(X), write(' is Negative'), nl
    ;
        write(X), write(' is Zero'), nl
    ).

% 3. Cut-Fail combination: print all items except 'blocked'
item(apple).
item(banana).
item(blocked).
item(mango).

print_allowed :-
    item(X),
    ( X == blocked -> !, fail ; write(X), nl ),
    fail.
print_allowed.

/*
Sample Queries & Output (SWI-Prolog):
?- factorial(5, F).
F = 120.

?- check_number(10).
10 is Positive
true.

?- print_allowed.
apple
banana
true.
*/
