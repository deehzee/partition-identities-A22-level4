# Programs used in "Partition identities arising from standard A(2)2-modules of level 4"

These are the computer programs used in my PhD thesis: 
"Partition identities arsing from the standard 
A(2)2-modules of level 4" (Rutgers University). The 
abstract and the introduction of the above thesis are
included in `thesisAbsIntro.pdf`.

A *partition* of a nonnegative integer *n* into *k* parts 
is a non-increasing *k*-tuple (*p_1, ..., p_k*) of 
nonnegative integers such that 
```
	n = p_1 + ... + p_k.
```
The number *n* will be referred to as the *size* of the 
partition. The number *k* is referred to as the *length* 
of the partition. And the entries *p_1*, ..., *p_k* are 
called the *parts* of the partition.

A partition *(p_1, ..., p_k)* is said to satisfy a 
difference condition *[d_1, ...,d_\{k−1\}]* if
*p_i − p_\{i+1\} = d_i* for all *i* such that 
_1 ≤ i ≤ (k−1)_.

For example, the partition _(7,2)_ satisfies the 
difference condition _[5]_. The partition _(11,8,8)_ 
satisfies the difference condition _[3,0]_, and so on.

Some times, we may use an `*` (asterisk) on an entry of the 
difference condition to denote *zero* or *more* occurrence 
of that entry. For example, consider the difference 
condition _[3,2\*,3,0]_. This may be expanded into the 
following difference conditions: _[3,3,0]_, _[3,2,3,0]_, 
_[3,2,2,3,0]_, ... and so on.


The three partition identities we proposed --- arising from the three inequivalent standard modules of level 4 for the affine Lie algebra A(2)2 --- may be stated as follows.

+ __(4,0)-module__:
The number of partitions of a nonnegative integer _n_ into 
parts different from _1_ and such that there is no 
sub-partition satisfying the difference
conditions _[1], [0,0], [0,2], [2,0]_ or _[0,3]_, 
and such that there is no sub-partition with an odd sum 
of parts satisfying the difference conditions 
_[3,0]_, _[0,4]_, _[4,0]_ or _[3,2\*,3,0]_
(where _2*_ indicates zero or more occurrence of _2_), 
is the same as the number of partitions of _n_ into parts 
congruent to _±2_, _±3_ or _±4_ modulo _14_.

+ __(2,1)-module__:
The number of partitions of a nonnegative integer _n_ such 
that _1_, _2_ and _3_ may occur at most once as a part, and 
such that there is no sub-partition satisfying the 
difference conditions _[1]_, _[0,0]_, _[0,2]_, _[2,0]_ or 
_[0, 3]_, and such that there is no sub-partition with an 
odd sum of parts satisfying the difference conditions 
_[3,0]_, _[0,4]_, _[4,0]_ or _[3,2*,3,0]_ 
(where _2\*_ indicates zero or more occurrence of _2_), 
is the same as the number of partitions of _n_ into parts
congruent to _±1_, _±4_ or _±6_ modulo _14_.

+ __(0,2)-module__:
The number of partitions of a nonnegative integer _n_ into 
parts different from _1_ and _3_, such that _2_ may occur 
at most once as a part, and such that there is no 
sub-partition satisfying the difference condition 
_[3,2\*]_ (where _2*_ denotes zero or more occurrence of 
_2_) ending with a _2_, and such that there is no 
sub-partition satisfying the difference conditions _[1]_, 
_[0,0]_, _[0,2]_, _[2,0]_ or _[0,3]_, and such that there 
is no sub-partition with an odd sum of parts satisfying the 
difference conditions _[3,0]_, _[0,4]_, _[4,0]_ or 
_[3,2\*,3,0]_, is the same as the number of partitions of 
_n_ into parts congruent to _±2_, _±5_ or _±6_ modulo _14_.


The codes are divided into three sections, corresponding to 
the appendices of the thesis.

## A: Maple programs used in the computation of relations

__Directory `maples/rels`:__ 
The directory containing the Maple codes, used in the 
computation of the relations.

+ __File `rels.mw`:__ The Maple worksheet showing
the computations.

+ __File `cha.txt`:__ The maple codes to generate
the partitions of a nonnegative integer _n_ into
_k_ parts (based on [[Cha11]](http://support.csis.pace.edu/CSISWeb/docs/techReports/techReport280.pdf)).

+ __File `coef.txt`:__ The maple codes to compute the
coefficients of various "standard monomials" in various
"product generating functions."

+ __File `test.txt`:__ Varous maple codes to automate
the analysis of various deg 2 and deg 3 relations.



## B: Computation in noncommutative algebra

__Directory `maple/noncomm`:__
The directory containing the computations related
to straightening out and substitution of non-commuting
variables.

+ __File `isom.mw`:__
The Maple worksheet showing the verification of the
isomorphism of the affine Lie algebra A(2)2 in terms of
the vertex operators.

+ __File `ini-A22-L4.mw`:__
The Maple worksheet showing the computations needed to
prove the initial conditions for the three level 4 
standard modules for A(2)2.

+ __File `npolyio.txt`:__
The Maple codes to convert polynomials in non-commuting
variables into the list representation and vice versa.
Based on 
[D. Zeilberger](http://www.math.rutgers.edu/~zeilberg/)'s [NCFPS maple](http://www.math.rutgers.edu/~zeilberg/tokhniot/NCFPS) package.

+ __File `npolyops.txt`:__
The file implementing operations on polynomials with
non-commuting variables. This file is slight modification
of Zeilberger's [NCFPS maple package](http://www.math.rutgers.edu/~zeilberg/tokhniot/NCFPS).

+ __File `npolysubs.txt`:__
The Maple codes to substitute and rewrite a noncommutative
polynomials based on substitution rules. The algorithm
and codes are modification of [M. Russell](http://www.math.rutgers.edu/russell2)'s code (see [[Rus13]](http://arxiv.org/abs/1311.1141v2)). 
It has been modified to accommodate indexed (infinitely
many) variables and infinitely many rules (indexed),
instead of finitely many variables and finitely many
rules.

+ __File `A22-rules.txt`:__
The maple codes implementing various rules related to
the Lie brakcets in A(2)2 and various straightening out
rules for the standard modules for A(2)2.
	
+ __File `A22-L4-iniRules.txt`:__
The maple codes implementing various rules corresponding
to the initial conditions as discovered in the Maple
worksheet `maple/noncomm/ini-A22-L4.mw`.
	
+ __File `misc.txt`:__
Miscellaneous maple codes used in the Maple worksheet
`maple/noncomm/ini-A22-L4.mw`.
	
This directory also contains the Maple worksheet file
`A22-level4-grdim.mw`, that computes the graded 
dimension for _n_ upto 200, using power series expansion.
The results have been copied to `c/verify/data.h`
to verify the identities.

## C: Verification of the partition identities

__Directory `c/verify`:__
The directory containing the C program to verify the
three proposed partition identities.

+ __File `verify.c`:__
The C program to verify the partition identities
(upto _n=200_). It generates the partitions (in 
ascending order) using Kelleher's 
_accelerated ascending rule_ algorithm
(see [[Kel06]](http://jeromekelleher.net/downloads/k06.pdf))
Once a partition
is generated, then it is scanned to see if it is reducible
or not for each of the three standard modules of level 4
for A(2)2.

+ __File `data.h`:__
The header file containing the data about the graded
dimensions of the three standard modules for A(2)2
of level 4. The data were computed in the Maple
worksheet `maple/A22-level4-grdim.mw`.

To compile and run:
```
	$ cc -std=c99 verify.c
	$ ./a.out
```

The program will ask for the _starting_ and _ending_
value of _n_. Then it will output the result of the
computations for these values. Note that, it takes more
than a day to verify the partition identities for
_n = 200_.

## References

[[Cha11]](http://support.csis.pace.edu/CSISWeb/docs/techReports/techReport280.pdf) S.-H. Cha, _Recursive algorithm for generating partitions of an integer_, tech. rep. 280, Pace University, Seidenberg School of Computer Science and
Information Systems, 2011.

[[Kel06]](http://jeromekelleher.net/downloads/k06.pdf)
J. Kelleher, “Encoding partitions as ascending compositions,” PhD thesis,
University College Cork, 2006.

[[NCFPS]](http://www.math.rutgers.edu/~zeilberg/tokhniot/NCFPS)
D. Zeilberger, _Noncommutative formal power series Maple package_, http://www.math.rutgers.edu/~zeilberg/tokhniot/NCFPS.

[[Rus13]](http://arxiv.org/abs/1311.1141v2) M. C. Russell, “Noncommutative recursions and the Laurent phenomenon,”
arXiv preprint arXiv:1311.1141v2 (2013), url: http://arxiv.org/abs/
1311.1141v2.

[[Russell]](http://www.math.rutgers.edu/~russell2)
Homepage of M. C. Russell:  http://www.math.rutgers.edu/~russell2

[[Zeilberger]](http://www.math.rutgers.edu/~zeilberg) Homepage of D. Zeilberger: http://www.math.rutgers.edu/~zeilberg

.


.