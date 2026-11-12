% 48. Write a Prolog program to represent a family tree and query relationships (parent, sibling, grandparent, uncle).
/*
Use: Used in logic programming and genealogy systems to infer family relationships from base facts.
Process: Base facts define gender (male/female) and parent(Parent, Child) relationships.
Logical rules derive sibling(X, Y), grandparent(X, Z), and uncle(U, N) from parent facts.
Prolog's unification and backtracking answer relationship queries automatically.
*/

% Gender facts
male(ramesh).
male(suresh).
male(mahesh).
male(rutvik).
female(meena).
female(priya).

% Parent facts: parent(Parent, Child)
parent(ramesh, suresh).
parent(ramesh, mahesh).
parent(meena, suresh).
parent(meena, mahesh).
parent(suresh, rutvik).
parent(suresh, priya).

% Sibling rule: X and Y share a parent P and are different people
sibling(X, Y) :-
    parent(P, X),
    parent(P, Y),
    X \= Y.

% Grandparent rule: X is parent of P, and P is parent of Z
grandparent(X, Z) :-
    parent(X, P),
    parent(P, Z).

% Uncle rule: U is male and sibling of N's parent P
uncle(U, N) :-
    male(U),
    parent(P, N),
    sibling(U, P).

/*
Sample Queries & Output (SWI-Prolog):
?- parent(suresh, rutvik).
true.

?- sibling(rutvik, priya).
true.

?- grandparent(ramesh, rutvik).
true.

?- uncle(mahesh, rutvik).
true.
*/
