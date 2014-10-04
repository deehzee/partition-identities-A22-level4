/**************************************************************\

File: verify.c
Author: Debajyoti Nandi
Email: nandi@math.rutgers.edu

Description: 
  Verifies the three partition identities (up to n <= 200).
  The program implements Kelleher's accelAscRule algorithm
  to generate partitions. Once a partition is generated,
  the function fltrCnt() then checks to see if the partition
  is allowed in each of the  three level 4 standard modules,
  and counts.
  
Note(1):
  To compile with cc and run 
    $ cc -std=c99 verify.c -o verify
    $ ./verify
  
  Enter the min and max of the range over which to check,
  (min <= n <= max).
  
Note(2):
	Compile with -DPRINT flag to display the "allowed"
	partitions. 
	
Warning: The above is only useful for debugging with
	small values of n. Otherwise, the output will be 
	overwhelmingly verbose.

\**************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "data.h"

/* 
 * visitor function type to be called after a partition
 * has been generated.
 */
typedef void (*Visitor) (int p[], int k, long *counts);

/*
 * Kelleher's [Kel06] accelerated ascending rule algorithm
 * to generate partitions of 'n' > 0. The visitor
 * function 'f' is called once a partition is generated.
 * 'counts' is an array, used by 'f' to counts the number
 * of "allowed" partitions in each of the three cases.
 */
long long accelAsc(int n, Visitor f, long *counts);

/* 
 * Prints the partition (which is produced as a
 * non-decreasing sequence) in reverse order, ie,
 * in the non-increasing order. 'k' is the length
 * of the generated partition.
 */ 
void printRev(int p[], int k);

/*
 * 'fltrCnt()' is the visitor function implementation
 * to check if the partitions are "allowed" or not
 * for each of the three cases. If a partition is allowed,
 * it is then counted for the appropriate module.
 */
void fltrCnt(int p[], int k, long *counts);

/* Various states, used in the definition of fltrCnt() */
enum states_fltrCnt {
  F40 = 1,  /* reducible for (4,0)-module */
  F21 = 2,  /* reducible for (2,1)-module */
  F02 = 4,  /* reducible for (0,2)-module */
  FL4 = 7,  /* reducible for all level 4 modules */
  S03 = 8,  /* entered [2*,3,0] diff condn */
  S2 = 16,  /* entered [2*] diff condn starting at 2 */
  ODD = 32, /* current entry is odd */
};


int main(int argc, char *argv[]) {
  int min, max;
  long cnts[3];
  long long count;
  
  printf("Starting from: ");
  scanf("%d", &min);
  printf("Ending at: ");
  scanf("%d", &max);
  for (int n=min; n<=max; n++) {
    printf("Computing Partitions of n=%d...\n", n);
    count = accelAsc(n, fltrCnt, cnts);  
    if (X[n] != count) printf("**");
    printf("\tAll=%13lld\tGot=%13lld\n", X[n], count);
    if (X40[n] != cnts[0]) printf("**");
    printf("\tX40=%13ld\tGot=%13ld\n", X40[n], cnts[0]);
    if (X21[n] != cnts[1]) printf("**");
    printf("\tX21=%13ld\tGot=%13ld\n", X21[n], cnts[1]);
    if (X02[n] != cnts[2]) printf("**");
    printf("\tX02=%13ld\tGot=%13ld\n", X02[n], cnts[2]);
    printf("\n");
  }
  return 0;
}


void printRev(int a[], int k) {
  int i;
  printf("[");
  for (i=0; i<k; i++) {
    if (i>0) {
      printf(",");
    }
    printf("%d", a[k-i-1]);
  }
  printf("]\n");
}


long long accelAsc(int n, Visitor f, long *counts) {
  int k, j, i, x, y;
  int a[n];
  long long count=0;
  counts[0] = counts[1] = counts[2] = 0;
  if (n == 0) {
    f(a, 0, counts); /* null partition */
    return 1;
  }
  for (i=0; i<n; i++) {
    a[i] = 0;
  }
  k = 1;
  y = n-1;
  while (k != 0) {
    x = a[k-1] + 1;
    k--;
    while (2*x <= y) {
      a[k] = x;
      y = y - x;
      k++;
    }
    j = k + 1;
    while (x <= y) {
      a[k] = x;
      a[j] = y;
      f(a, k+2, counts); /* generated a partition */
      count++;
      x++;
      y--;
    }
    a[k] = x + y;
    y = x + y - 1;
    f(a, k+1, counts); /* generated a partition */
    count++;
  }
  return count;
} /* End of accelAsc() */


void fltrCnt(int p[], int k, long *counts) {
  /*
  Partitions are represented as non-decreasing lists.
  (2,5,6) <=> (6,5,2) read R to L
    if currently reading the 3rd index (6), then
      cur = 6
      prv = 5
      d = 1
      d1 = 3
      
  States:
    ODD => Whether cur is odd or not
    S03 => current diff condn is [2*,3,0]
    S2  => current diff condn is [2*] starting at 2
    F40 => partition is reducible for (4,0)-module
    F21 => partition is reducible for (2,1)-module
    F02 => partition is reducible for (0,2)-module
    FL4 => partition is reducible for all level 4 modules.
      
  IC:
    (1) => sets F40 & F02
    (3) => sets F02
    (1,1), (3,3) => sets F21
    (2,2) => sets F21 & F02
    [3-,2*] starting with 2 => sets F02
  
  ALL:
    [1],
    [0,0], [0,2], [2,0], [0,3],
    [3-,0], [0-,4], [4-,0],
    [3-,2*,3,0] 
      => sets FL4 (ie, returns)
      
  States switching:
    S03: 
      sets when diff conds reaches [3,0],
      resets when
        d == 3 and cur is ODD => sets FL4
        otherwise if d != 2.
        
    S02:
      sets when the first entry is 2,
      resets when
        d == 3 (no need to check ODD) => sets F02
        otherwise if d != 2.
        
    ODD:
      sets when cur is odd,
      resets when cur is even.
  */
  int cur;     /* current part being read */
  int prv;     /* previous part read */
  int d;       /* difference = cur - prv */
  int d1 = -1; /* last difference */
  char s = 0;  /* Bits of "s" represent different states */

  for (int i=0; i<k; i++) {
    cur = p[i];
    if (cur % 2) 
      s |= ODD;
    else 
      s &= ~ODD;
    if (i == 0) { /* we are reading the 1st entry */
      switch(cur) {
        case 1:
          s |= (F40|F02);
          break;
        case 2:
          s |= S2;
          break;
        case 3:
          s |= F02;
          break;
        default:
          break;
      } 
    } else { /* reading 2nd or further to the left */
      d = cur - prv;
      if ((d==1) || (d==0 && d1==0) || (d==0 && d1==2) 
         || (d==2 && d1==0) || (d==0 && d1==3) 
         || ((s & ODD) && d==3 && d1==0)
         || ((s & ODD) && d==0 && d1==4)
         || ((s & ODD) && d==4 && d1==0)
         || ((s & S03) && d==3 && (s & ODD))) 
        return;
      if (s & S2) {
        switch (d) {
          case 2:
            break;
          case 3:
            s |= F02;
            if ((s & FL4)==FL4) return;
            s &= ~S2;
            break;
          default:
            s &= ~S2;
            break;
        }
      } 
      if ((s & S03) && d != 2) 
        s &= ~S03;
      else if (d==3 && d1==0) 
        s |= S03;  
      if ((i==1)&&(cur==prv)&&(cur==1 || cur==3)) {
        s |= F21;
        if ((s & FL4)==FL4) return;
      } else if ((i==1)&&(cur==prv)&&(cur==2)) {
        s |= (F21|F02);
        if ((s & FL4)==FL4) return;
      }
      d1 = d; 
    } /* End of if (i==0) */
    prv = cur;
  } /* End of for(i) */
  if (!(s & F40)) {
    counts[0]++;
    #ifdef PRINT
    printf("(4,0)-module: ");
    printRev(p, k);
    #endif
  }
  if (!(s & F21)) {
    counts[1]++;
    #ifdef PRINT
    printf("(2,1)-module: ");
    printRev(p, k);
    #endif
  }
  if (!(s & F02)) {
    counts[2]++;
    #ifdef PRINT
    printf("(0,2)-module: ");
    printRev(p, k);
    #endif
  }
} /* End of fltrCnt() */
